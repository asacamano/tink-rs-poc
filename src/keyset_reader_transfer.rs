use crate::wrapped_base::OwnedTinkStatus;

// --------------------------------------------------------------
//
// Transfer layer between Rust and C++
//

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    fn wrapped_DeleteKeysetReader(owned: *mut CCKeysetReaderOpaquePointer);

}

/// A specific type for opaque pointers to C++ KeysetReader objects, which helps ensure
/// type-safety throughout the transfer layer.
/// See https://doc.rust-lang.org/nomicon/ffi.html#representing-opaque-structs
#[repr(C)]
pub(crate) struct CCKeysetReaderOpaquePointer {
    _data: (),
    _marker: core::marker::PhantomData<(*mut u8, core::marker::PhantomPinned)>,
}

#[repr(C)]
/// OwnedKeysetReader that can be transferred between Rust and C++, and which is owned by the recipient.
///
/// Typically these are instantiated in C++ and then owned by Rust for the rest of the program,
/// e.g. for a primitive.  However, some of the setup processes are intended to create objects which
/// are then consumed (e.g. sometimes creating a keyset consumes the keyset reader used to read the data.)
/// In that case the owned object is transferred back to the C++ side and deleted there.
///
/// Note that in the actual OwnedKeysetReader itself is just a pass-by-value wrapper around the actual object.
pub(crate) struct OwnedKeysetReader {
    pub(crate) cc_keyset_reader: *mut CCKeysetReaderOpaquePointer,
}

/// Ensures that the C++ object is deleted when the Rust object is dropped.
impl Drop for OwnedKeysetReader {
    fn drop(&mut self) {
        unsafe {
            // TODO - switch this to an assert so tests are more likely to fail if this logic breaks.
            if !self.cc_keyset_reader.is_null() {
                wrapped_DeleteKeysetReader(self.cc_keyset_reader);
                // Just in case.
                self.cc_keyset_reader = std::ptr::null_mut();
            }
        }
    }
}

#[repr(C)]
pub(crate) struct OwnedTinkStatusOrKeysetReader {
    pub(crate) status: OwnedTinkStatus,
    pub(crate) owned: OwnedKeysetReader,
}
