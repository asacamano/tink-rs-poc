use crate::wrapped_base::BorrowedBytes;
use crate::wrapped_base::OwnedTinkStatus;
use crate::wrapped_base::OwnedTinkStatusOrBytes;

// --------------------------------------------------------------
//
// Transfer layer between Rust and C++
//

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    pub(crate) fn wrapped_Aead_Decrypt(
        xfer_self: BorrowedAead,
        ciphertext: BorrowedBytes,
        associated_data: BorrowedBytes,
    ) -> OwnedTinkStatusOrBytes;
    pub(crate) fn wrapped_Aead_Encrypt(
        xfer_self: BorrowedAead,
        plaintext: BorrowedBytes,
        associated_data: BorrowedBytes,
    ) -> OwnedTinkStatusOrBytes;
    fn wrapped_DeleteAead(owned: *mut CCAeadOpaquePointer);

}

/// A specific type for opaque pointers to C++ Aead objects, which helps ensure
/// type-safety throughout the transfer layer.
/// See https://doc.rust-lang.org/nomicon/ffi.html#representing-opaque-structs
#[repr(C)]
pub(crate) struct CCAeadOpaquePointer {
    _data: (),
    _marker: core::marker::PhantomData<(*mut u8, core::marker::PhantomPinned)>,
}

#[repr(C)]
/// OwnedAead that can be transferred between Rust and C++, and which is owned by the recipient.
///
/// Typically these are instantiated in C++ and then owned by Rust for the rest of the program,
/// e.g. for a primitive.  However, some of the setup processes are intended to create objects which
/// are then consumed (e.g. sometimes creating a keyset consumes the keyset reader used to read the data.)
/// In that case the owned object is transferred back to the C++ side and deleted there.
///
/// Note that in the actual OwnedAead itself is just a pass-by-value wrapper around the actual object.
pub(crate) struct OwnedAead {
    pub(crate) cc_aead: *mut CCAeadOpaquePointer,
}

/// Ensures that the C++ object is deleted when the Rust object is dropped.
impl Drop for OwnedAead {
    fn drop(&mut self) {
        unsafe {
            // TODO - switch this to an assert so tests are more likely to fail if this logic breaks.
            if !self.cc_aead.is_null() {
                wrapped_DeleteAead(self.cc_aead);
                // Just in case.
                self.cc_aead = std::ptr::null_mut();
            }
        }
    }
}

#[repr(C)]
pub(crate) struct OwnedTinkStatusOrAead {
    pub(crate) status: OwnedTinkStatus,
    pub(crate) owned: OwnedAead,
}

/// BorrowedAead that can be transferred between Rust and C++, and which is only borrowed.
///
/// The recipient is not expected to delete the underlying object.
///
/// Note that in the actual BorrowedAead itself is just a pass-by-value wrapper around the actual object.
#[repr(C)]
pub(crate) struct BorrowedAead {
    pub(crate) cc_aead: *mut CCAeadOpaquePointer,
}
