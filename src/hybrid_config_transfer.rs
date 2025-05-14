use crate::wrapped_base::OwnedTinkStatus;

// --------------------------------------------------------------
//
// Transfer layer between Rust and C++
//

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    pub(crate) fn wrapped_HybridConfig_Register() -> OwnedTinkStatus;

}
