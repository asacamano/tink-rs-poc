use crate::keyset_reader_transfer::OwnedTinkStatusOrKeysetReader;
use crate::wrapped_base::BorrowedString;

// --------------------------------------------------------------
//
// Transfer layer between Rust and C++
//

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    pub(crate) fn wrapped_JsonKeysetReader_New(
        serialized_keyset: BorrowedString,
    ) -> OwnedTinkStatusOrKeysetReader;

}
