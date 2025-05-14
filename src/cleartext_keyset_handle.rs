use crate::keyset_handle_transfer::OwnedTinkStatusOrKeysetHandle;
use crate::keyset_reader_transfer::OwnedKeysetReader;
use crate::KeysetHandle;
use crate::KeysetReader;
use crate::TinkError;

use crate::cleartext_keyset_handle_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// Creates keyset handles from cleartext keysets. This API allows
/// loading cleartext keysets, thus its usage should be restricted.
pub struct CleartextKeysetHandle {}
impl CleartextKeysetHandle {
    /// Creates a KeysetHandle with a keyset obtained via `reader`. Optionally
    /// allows to pass monitoring_annotations to attach additional data to the
    /// resulting KeysetHandle, which will be used for monitoring.
    pub fn read(reader: KeysetReader) -> Result<KeysetHandle, TinkError> {
        unsafe {
            let xfer_reader: OwnedKeysetReader = reader.into();
            let result: OwnedTinkStatusOrKeysetHandle =
                wrapped_CleartextKeysetHandle_Read(xfer_reader);
            result.into()
        }
    }
}
