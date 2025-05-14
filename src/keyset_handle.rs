use crate::aead_transfer::OwnedTinkStatusOrAead;
use crate::configuration_transfer::StaticConfiguration;
use crate::hybrid_decrypt_transfer::OwnedTinkStatusOrHybridDecrypt;
use crate::hybrid_encrypt_transfer::OwnedTinkStatusOrHybridEncrypt;
use crate::key_gen_configuration_transfer::StaticKeyGenConfiguration;
use crate::key_template_transfer::StaticKeyTemplate;
use crate::keyset_handle_transfer::OwnedTinkStatusOrKeysetHandle;
use crate::Aead;
use crate::Configuration;
use crate::HybridDecrypt;
use crate::HybridEncrypt;
use crate::KeyGenConfiguration;
use crate::KeyTemplate;
use crate::StatusCode;
use crate::TinkError;

use crate::keyset_handle_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// KeysetHandle provides abstracted access to Keysets, to limit
/// the exposure of actual protocol buffers that hold sensitive
/// key material.
pub struct KeysetHandle {
    pub(crate) xfer: OwnedKeysetHandle,
}

impl KeysetHandle {
    /// Returns a KeysetHandle containing one new key generated according to
    /// `key_template` using `config`. When specified, the keyset is annotated
    /// for monitoring with `monitoring_annotations`.
    ///
    /// `config` is the corresponding :key_gen_config_v0 for your primitive. For
    /// example, use //tink/aead:key_gen_config_v0 for AEAD. If a single
    /// GenerateNew call handles multiple primitives, use
    /// //tink//config:key_gen_v0.
    pub fn generate_new(
        key_template: &KeyTemplate,
        config: &KeyGenConfiguration,
    ) -> Result<KeysetHandle, TinkError> {
        unsafe {
            let xfer_key_template: StaticKeyTemplate = key_template.into();
            let xfer_config: StaticKeyGenConfiguration = config.into();
            let result: OwnedTinkStatusOrKeysetHandle =
                wrapped_KeysetHandle_GenerateNew(xfer_key_template, xfer_config);
            result.into()
        }
    }
    /// Returns a new KeysetHandle containing public keys corresponding to the
    /// private keys in this handle. Relies on key type managers stored in `config`
    /// to do so. Returns an error if this handle contains keys that are not
    /// private keys.
    pub fn get_public_keyset_handle(
        &self,
        config: &KeyGenConfiguration,
    ) -> Result<KeysetHandle, TinkError> {
        unsafe {
            let xfer_self: BorrowedKeysetHandle = self.into();
            let xfer_config: StaticKeyGenConfiguration = config.into();
            let result: OwnedTinkStatusOrKeysetHandle =
                wrapped_KeysetHandle_GetPublicKeysetHandle(xfer_self, xfer_config);
            result.into()
        }
    }
}

// This trait is implemented by every type that can be returned by KeysetHandle.GetPrimitive.
// KeysetHandle.GetPrimitive will dispatch calls to the implementations of this trait.
pub trait KeysetHandleGetPrimitive<T>
where
    T: Sized,
{
    /// Creates a wrapped primitive using this keyset handle and config, which
    /// stores necessary primitive wrappers and key type managers.
    ///
    /// `config` is the corresponding :config_v0 for your primitive. For example,
    /// use //tink/aead:config_v0 for AEAD. If a single GenerateNew call handles
    /// multiple primitives, use //tink//config:v0.

    fn keyset_handle_get_primitive(
        keyset_handle: &KeysetHandle,
        config: &Configuration,
    ) -> Result<T, TinkError>;
}

impl KeysetHandle {
    /// Creates a wrapped primitive using this keyset handle and config, which
    /// stores necessary primitive wrappers and key type managers.
    ///
    /// `config` is the corresponding :config_v0 for your primitive. For example,
    /// use //tink/aead:config_v0 for AEAD. If a single GenerateNew call handles
    /// multiple primitives, use //tink//config:v0.

    pub fn get_primitive<T: KeysetHandleGetPrimitive<T>>(
        &self,
        config: &Configuration,
    ) -> Result<T, TinkError> {
        T::keyset_handle_get_primitive(&self, config)
    }
}

impl KeysetHandleGetPrimitive<Aead> for Aead {
    /// Creates a wrapped primitive using this keyset handle and config, which
    /// stores necessary primitive wrappers and key type managers.
    ///
    /// `config` is the corresponding :config_v0 for your primitive. For example,
    /// use //tink/aead:config_v0 for AEAD. If a single GenerateNew call handles
    /// multiple primitives, use //tink//config:v0.

    fn keyset_handle_get_primitive(
        keyset_handle: &KeysetHandle,
        config: &Configuration,
    ) -> Result<Self, TinkError> {
        unsafe {
            let xfer_keyset_handle: BorrowedKeysetHandle = keyset_handle.into();
            let xfer_config: StaticConfiguration = config.into();
            let result: OwnedTinkStatusOrAead =
                wrapped_KeysetHandle_GetPrimitive_Aead(xfer_keyset_handle, xfer_config);
            result.into()
        }
    }
}

impl KeysetHandleGetPrimitive<HybridEncrypt> for HybridEncrypt {
    /// Creates a wrapped primitive using this keyset handle and config, which
    /// stores necessary primitive wrappers and key type managers.
    ///
    /// `config` is the corresponding :config_v0 for your primitive. For example,
    /// use //tink/aead:config_v0 for AEAD. If a single GenerateNew call handles
    /// multiple primitives, use //tink//config:v0.

    fn keyset_handle_get_primitive(
        keyset_handle: &KeysetHandle,
        config: &Configuration,
    ) -> Result<Self, TinkError> {
        unsafe {
            let xfer_keyset_handle: BorrowedKeysetHandle = keyset_handle.into();
            let xfer_config: StaticConfiguration = config.into();
            let result: OwnedTinkStatusOrHybridEncrypt =
                wrapped_KeysetHandle_GetPrimitive_HybridEncrypt(xfer_keyset_handle, xfer_config);
            result.into()
        }
    }
}

impl KeysetHandleGetPrimitive<HybridDecrypt> for HybridDecrypt {
    /// Creates a wrapped primitive using this keyset handle and config, which
    /// stores necessary primitive wrappers and key type managers.
    ///
    /// `config` is the corresponding :config_v0 for your primitive. For example,
    /// use //tink/aead:config_v0 for AEAD. If a single GenerateNew call handles
    /// multiple primitives, use //tink//config:v0.

    fn keyset_handle_get_primitive(
        keyset_handle: &KeysetHandle,
        config: &Configuration,
    ) -> Result<Self, TinkError> {
        unsafe {
            let xfer_keyset_handle: BorrowedKeysetHandle = keyset_handle.into();
            let xfer_config: StaticConfiguration = config.into();
            let result: OwnedTinkStatusOrHybridDecrypt =
                wrapped_KeysetHandle_GetPrimitive_HybridDecrypt(xfer_keyset_handle, xfer_config);
            result.into()
        }
    }
}

// --------------------------------------------------------------
//
// Basic type conversions to and from transfer types.
//

/// Converts from the Rust API class to an owned transfer class for passing as an owned value.
impl From<KeysetHandle> for OwnedKeysetHandle {
    fn from(mut src: KeysetHandle) -> Self {
        let result = OwnedKeysetHandle {
            cc_keyset_handle: src.xfer.cc_keyset_handle,
        };
        // Now the KeysetHandle object is going out of scope, it will try to delete the pointer.
        // But if we clear it first, that won't happen and ownership has really passed to the transfer
        // layer.
        src.xfer.cc_keyset_handle = std::ptr::null_mut();
        result
    }
}

impl From<OwnedTinkStatusOrKeysetHandle> for Result<KeysetHandle, TinkError> {
    fn from(status_or_owned: OwnedTinkStatusOrKeysetHandle) -> Self {
        if status_or_owned.status.code != StatusCode::Ok {
            Err(status_or_owned.status.into())
        } else if status_or_owned.owned.cc_keyset_handle.is_null() {
            Err(TinkError::new(
                StatusCode::Unknown as usize,
                "KeysetHandle pointer is null",
            ))
        } else {
            Ok(KeysetHandle {
                xfer: status_or_owned.owned,
            })
        }
    }
}

/// Converts a Rust reference to a BorrowedKeysetHandle, useful for passing a Rust object into C++ code.
impl From<&KeysetHandle> for BorrowedKeysetHandle {
    fn from(keyset_handle: &KeysetHandle) -> Self {
        // Note that BorrowedKeysetHandle is just passing a pointer along, which is owned by the Rust KeysetHandle objects' OwnedKeysetHandle.
        BorrowedKeysetHandle {
            cc_keyset_handle: keyset_handle.xfer.cc_keyset_handle,
        }
    }
}
