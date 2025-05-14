use crate::keyset_handle_transfer::OwnedTinkStatusOrKeysetHandle;
use crate::keyset_reader_transfer::OwnedKeysetReader;

// --------------------------------------------------------------
//
// Transfer layer between Rust and C++
//

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    pub(crate) fn wrapped_CleartextKeysetHandle_Read(
        reader: OwnedKeysetReader,
    ) -> OwnedTinkStatusOrKeysetHandle;

}
