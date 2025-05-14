use crate::StatusCode;
use crate::TinkError;

use crate::keyset_reader_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// KeysetReader knows how to read a Keyset or an EncryptedKeyset
/// from some source.
pub struct KeysetReader {
    pub(crate) xfer: OwnedKeysetReader,
}

// --------------------------------------------------------------
//
// Basic type conversions to and from transfer types.
//

/// Converts from the Rust API class to an owned transfer class for passing as an owned value.
impl From<KeysetReader> for OwnedKeysetReader {
    fn from(mut src: KeysetReader) -> Self {
        let result = OwnedKeysetReader {
            cc_keyset_reader: src.xfer.cc_keyset_reader,
        };
        // Now the KeysetReader object is going out of scope, it will try to delete the pointer.
        // But if we clear it first, that won't happen and ownership has really passed to the transfer
        // layer.
        src.xfer.cc_keyset_reader = std::ptr::null_mut();
        result
    }
}

impl From<OwnedTinkStatusOrKeysetReader> for Result<KeysetReader, TinkError> {
    fn from(status_or_owned: OwnedTinkStatusOrKeysetReader) -> Self {
        if status_or_owned.status.code != StatusCode::Ok {
            Err(status_or_owned.status.into())
        } else if status_or_owned.owned.cc_keyset_reader.is_null() {
            Err(TinkError::new(
                StatusCode::Unknown as usize,
                "KeysetReader pointer is null",
            ))
        } else {
            Ok(KeysetReader {
                xfer: status_or_owned.owned,
            })
        }
    }
}
