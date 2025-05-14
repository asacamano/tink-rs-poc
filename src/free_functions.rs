use crate::configuration_transfer::StaticConfiguration;
use crate::key_gen_configuration_transfer::StaticKeyGenConfiguration;
use crate::Configuration;
use crate::KeyGenConfiguration;

use crate::free_functions_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// Used to generate primitives and keys using the global crypto::tink::Registry.
pub fn config_global_registry() -> Configuration {
    unsafe {
        let result: StaticConfiguration = wrapped_ConfigGlobalRegistry();
        result.into()
    }
}
/// Used to generate primitives and keys using the global crypto::tink::Registry.
pub fn key_gen_config_global_registry() -> KeyGenConfiguration {
    unsafe {
        let result: StaticKeyGenConfiguration = wrapped_KeyGenConfigGlobalRegistry();
        result.into()
    }
}
