use crate::keyset_reader_transfer::OwnedTinkStatusOrKeysetReader;
use crate::wrapped_base::BorrowedString;
use crate::KeysetReader;
use crate::TinkError;

use crate::json_keyset_reader_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// A KeysetReader that can read from some source cleartext or
/// encrypted keysets in proto JSON wire format, cf.
/// https://developers.google.com/protocol-buffers/docs/encoding
pub struct JsonKeysetReader {}
impl JsonKeysetReader {
    pub fn new(serialized_keyset: &str) -> Result<KeysetReader, TinkError> {
        unsafe {
            let xfer_serialized_keyset: BorrowedString = serialized_keyset.into();
            let result: OwnedTinkStatusOrKeysetReader =
                wrapped_JsonKeysetReader_New(xfer_serialized_keyset);
            result.into()
        }
    }
}
