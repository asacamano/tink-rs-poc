use crate::configuration_transfer::StaticConfiguration;
use crate::key_gen_configuration_transfer::StaticKeyGenConfiguration;

// --------------------------------------------------------------
//
// Transfer layer between Rust and C++
//

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    pub(crate) fn wrapped_ConfigGlobalRegistry() -> StaticConfiguration;
    pub(crate) fn wrapped_KeyGenConfigGlobalRegistry() -> StaticKeyGenConfiguration;

}
