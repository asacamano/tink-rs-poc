use crate::wrapped_base::BorrowedBytes;
use crate::wrapped_base::OwnedTinkStatusOrBytes;
use crate::StatusCode;
use crate::TinkError;

use crate::aead_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// The interface for authenticated encryption with associated data.
/// Implementations of this interface are secure against adaptive
/// chosen ciphertext attacks.  Encryption with associated data ensures
/// authenticity and integrity of that data, but not its secrecy.
/// (see RFC 5116, https://tools.ietf.org/html/rfc5116)
///
/// Implementations are expected to be thread safe.
pub struct Aead {
    pub(crate) xfer: OwnedAead,
}

impl Aead {
    /// Decrypts 'ciphertext' with 'associated_data' as associated data,
    /// and returns the resulting plaintext.
    /// The decryption verifies the authenticity and integrity
    /// of the associated data, but there are no guarantees wrt. secrecy
    /// of that data.
    pub fn decrypt(&self, ciphertext: &[u8], associated_data: &[u8]) -> Result<Vec<u8>, TinkError> {
        unsafe {
            let xfer_self: BorrowedAead = self.into();
            let xfer_ciphertext: BorrowedBytes = ciphertext.into();
            let xfer_associated_data: BorrowedBytes = associated_data.into();
            let result: OwnedTinkStatusOrBytes =
                wrapped_Aead_Decrypt(xfer_self, xfer_ciphertext, xfer_associated_data);
            result.into()
        }
    }
    /// Encrypts 'plaintext' with 'associated_data' as associated data,
    /// and returns the resulting ciphertext.
    /// The ciphertext allows for checking authenticity and integrity
    /// of the associated data, but does not guarantee its secrecy.
    pub fn encrypt(&self, plaintext: &[u8], associated_data: &[u8]) -> Result<Vec<u8>, TinkError> {
        unsafe {
            let xfer_self: BorrowedAead = self.into();
            let xfer_plaintext: BorrowedBytes = plaintext.into();
            let xfer_associated_data: BorrowedBytes = associated_data.into();
            let result: OwnedTinkStatusOrBytes =
                wrapped_Aead_Encrypt(xfer_self, xfer_plaintext, xfer_associated_data);
            result.into()
        }
    }
}

// --------------------------------------------------------------
//
// Basic type conversions to and from transfer types.
//

/// Converts from the Rust API class to an owned transfer class for passing as an owned value.
impl From<Aead> for OwnedAead {
    fn from(mut src: Aead) -> Self {
        let result = OwnedAead {
            cc_aead: src.xfer.cc_aead,
        };
        // Now the Aead object is going out of scope, it will try to delete the pointer.
        // But if we clear it first, that won't happen and ownership has really passed to the transfer
        // layer.
        src.xfer.cc_aead = std::ptr::null_mut();
        result
    }
}

impl From<OwnedTinkStatusOrAead> for Result<Aead, TinkError> {
    fn from(status_or_owned: OwnedTinkStatusOrAead) -> Self {
        if status_or_owned.status.code != StatusCode::Ok {
            Err(status_or_owned.status.into())
        } else if status_or_owned.owned.cc_aead.is_null() {
            Err(TinkError::new(
                StatusCode::Unknown as usize,
                "Aead pointer is null",
            ))
        } else {
            Ok(Aead {
                xfer: status_or_owned.owned,
            })
        }
    }
}

/// Converts a Rust reference to a BorrowedAead, useful for passing a Rust object into C++ code.
impl From<&Aead> for BorrowedAead {
    fn from(aead: &Aead) -> Self {
        // Note that BorrowedAead is just passing a pointer along, which is owned by the Rust Aead objects' OwnedAead.
        BorrowedAead {
            cc_aead: aead.xfer.cc_aead,
        }
    }
}
