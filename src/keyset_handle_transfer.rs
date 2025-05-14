use crate::aead_transfer::OwnedTinkStatusOrAead;
use crate::configuration_transfer::StaticConfiguration;
use crate::hybrid_decrypt_transfer::OwnedTinkStatusOrHybridDecrypt;
use crate::hybrid_encrypt_transfer::OwnedTinkStatusOrHybridEncrypt;
use crate::key_gen_configuration_transfer::StaticKeyGenConfiguration;
use crate::key_template_transfer::StaticKeyTemplate;
use crate::wrapped_base::OwnedTinkStatus;

// --------------------------------------------------------------
//
// Transfer layer between Rust and C++
//

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    pub(crate) fn wrapped_KeysetHandle_GenerateNew(
        key_template: StaticKeyTemplate,
        config: StaticKeyGenConfiguration,
    ) -> OwnedTinkStatusOrKeysetHandle;
    pub(crate) fn wrapped_KeysetHandle_GetPrimitive_Aead(
        xfer_self: BorrowedKeysetHandle,
        config: StaticConfiguration,
    ) -> OwnedTinkStatusOrAead;
    pub(crate) fn wrapped_KeysetHandle_GetPrimitive_HybridDecrypt(
        xfer_self: BorrowedKeysetHandle,
        config: StaticConfiguration,
    ) -> OwnedTinkStatusOrHybridDecrypt;
    pub(crate) fn wrapped_KeysetHandle_GetPrimitive_HybridEncrypt(
        xfer_self: BorrowedKeysetHandle,
        config: StaticConfiguration,
    ) -> OwnedTinkStatusOrHybridEncrypt;
    pub(crate) fn wrapped_KeysetHandle_GetPublicKeysetHandle(
        xfer_self: BorrowedKeysetHandle,
        config: StaticKeyGenConfiguration,
    ) -> OwnedTinkStatusOrKeysetHandle;
    fn wrapped_DeleteKeysetHandle(owned: *mut CCKeysetHandleOpaquePointer);

}

/// A specific type for opaque pointers to C++ KeysetHandle objects, which helps ensure
/// type-safety throughout the transfer layer.
/// See https://doc.rust-lang.org/nomicon/ffi.html#representing-opaque-structs
#[repr(C)]
pub(crate) struct CCKeysetHandleOpaquePointer {
    _data: (),
    _marker: core::marker::PhantomData<(*mut u8, core::marker::PhantomPinned)>,
}

#[repr(C)]
/// OwnedKeysetHandle that can be transferred between Rust and C++, and which is owned by the recipient.
///
/// Typically these are instantiated in C++ and then owned by Rust for the rest of the program,
/// e.g. for a primitive.  However, some of the setup processes are intended to create objects which
/// are then consumed (e.g. sometimes creating a keyset consumes the keyset reader used to read the data.)
/// In that case the owned object is transferred back to the C++ side and deleted there.
///
/// Note that in the actual OwnedKeysetHandle itself is just a pass-by-value wrapper around the actual object.
pub(crate) struct OwnedKeysetHandle {
    pub(crate) cc_keyset_handle: *mut CCKeysetHandleOpaquePointer,
}

/// Ensures that the C++ object is deleted when the Rust object is dropped.
impl Drop for OwnedKeysetHandle {
    fn drop(&mut self) {
        unsafe {
            // TODO - switch this to an assert so tests are more likely to fail if this logic breaks.
            if !self.cc_keyset_handle.is_null() {
                wrapped_DeleteKeysetHandle(self.cc_keyset_handle);
                // Just in case.
                self.cc_keyset_handle = std::ptr::null_mut();
            }
        }
    }
}

#[repr(C)]
pub(crate) struct OwnedTinkStatusOrKeysetHandle {
    pub(crate) status: OwnedTinkStatus,
    pub(crate) owned: OwnedKeysetHandle,
}

/// BorrowedKeysetHandle that can be transferred between Rust and C++, and which is only borrowed.
///
/// The recipient is not expected to delete the underlying object.
///
/// Note that in the actual BorrowedKeysetHandle itself is just a pass-by-value wrapper around the actual object.
#[repr(C)]
pub(crate) struct BorrowedKeysetHandle {
    pub(crate) cc_keyset_handle: *mut CCKeysetHandleOpaquePointer,
}
