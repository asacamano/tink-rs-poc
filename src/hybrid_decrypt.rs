use crate::wrapped_base::BorrowedBytes;
use crate::wrapped_base::OwnedTinkStatusOrBytes;
use crate::StatusCode;
use crate::TinkError;

use crate::hybrid_decrypt_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// The interface for hybrid decryption.
///
/// Implementations of this interface are secure against adaptive
/// chosen ciphertext attacks.  In addition to 'plaintext' the
/// encryption takes an extra parameter 'context_info', which usually
/// is public data implicit from the context, but should be bound to
/// the resulting ciphertext: upon decryption the ciphertext allows for
/// checking the integrity of 'context_info' (but there are no
/// guarantees wrt. to secrecy or authenticity of 'context_info').
///
/// WARNING: hybrid encryption does not provide authenticity, that is the
/// recipient of an encrypted message does not know the identity of the sender.
/// Similar to general public-key encryption schemes the security goal of
/// hybrid encryption is to provide privacy only. In other words, hybrid
/// encryption is secure if and only if the recipient can accept anonymous
/// messages or can rely on other mechanisms to authenticate the sender.
///
/// 'context_info' can be empty or null, but to ensure the correct
/// decryption of the ciphertext the same value must be provided
/// as was used during encryption operation (cf. HybridEncrypt-interface).
///
/// A concrete instantiation of this interface can implement the
/// binding of 'context_info' to the ciphertext in various ways, for
/// example:
///
/// - use 'context_info' as "associated data"-input for the employed
///   AEAD symmetric encryption (cf. https://tools.ietf.org/html/rfc5116).
/// - use 'context_info' as "CtxInfo"-input for HKDF (if the implementation uses
///   HKDF as key derivation function, cf. https://tools.ietf.org/html/rfc5869).
pub struct HybridDecrypt {
    pub(crate) xfer: OwnedHybridDecrypt,
}

impl HybridDecrypt {
    /// Decrypts 'ciphertext' verifying the integrity of 'context_info'.
    pub fn decrypt(&self, ciphertext: &[u8], context_info: &[u8]) -> Result<Vec<u8>, TinkError> {
        unsafe {
            let xfer_self: BorrowedHybridDecrypt = self.into();
            let xfer_ciphertext: BorrowedBytes = ciphertext.into();
            let xfer_context_info: BorrowedBytes = context_info.into();
            let result: OwnedTinkStatusOrBytes =
                wrapped_HybridDecrypt_Decrypt(xfer_self, xfer_ciphertext, xfer_context_info);
            result.into()
        }
    }
}

// --------------------------------------------------------------
//
// Basic type conversions to and from transfer types.
//

/// Converts from the Rust API class to an owned transfer class for passing as an owned value.
impl From<HybridDecrypt> for OwnedHybridDecrypt {
    fn from(mut src: HybridDecrypt) -> Self {
        let result = OwnedHybridDecrypt {
            cc_hybrid_decrypt: src.xfer.cc_hybrid_decrypt,
        };
        // Now the HybridDecrypt object is going out of scope, it will try to delete the pointer.
        // But if we clear it first, that won't happen and ownership has really passed to the transfer
        // layer.
        src.xfer.cc_hybrid_decrypt = std::ptr::null_mut();
        result
    }
}

impl From<OwnedTinkStatusOrHybridDecrypt> for Result<HybridDecrypt, TinkError> {
    fn from(status_or_owned: OwnedTinkStatusOrHybridDecrypt) -> Self {
        if status_or_owned.status.code != StatusCode::Ok {
            Err(status_or_owned.status.into())
        } else if status_or_owned.owned.cc_hybrid_decrypt.is_null() {
            Err(TinkError::new(
                StatusCode::Unknown as usize,
                "HybridDecrypt pointer is null",
            ))
        } else {
            Ok(HybridDecrypt {
                xfer: status_or_owned.owned,
            })
        }
    }
}

/// Converts a Rust reference to a BorrowedHybridDecrypt, useful for passing a Rust object into C++ code.
impl From<&HybridDecrypt> for BorrowedHybridDecrypt {
    fn from(hybrid_decrypt: &HybridDecrypt) -> Self {
        // Note that BorrowedHybridDecrypt is just passing a pointer along, which is owned by the Rust HybridDecrypt objects' OwnedHybridDecrypt.
        BorrowedHybridDecrypt {
            cc_hybrid_decrypt: hybrid_decrypt.xfer.cc_hybrid_decrypt,
        }
    }
}
