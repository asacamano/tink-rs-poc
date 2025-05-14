use crate::key_gen_configuration_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// KeyGenConfiguration used to generate keys using stored key type managers.
pub struct KeyGenConfiguration {
    pub(crate) xfer: StaticKeyGenConfiguration,
}

/// Converts a Rust reference to a StaticKeyGenConfiguration, useful for passing a Rust object into C++ code.
// Note - This is creating a new StaticKeyGenConfiguration which has its own lifetime, but Rust is not managing
// the lifetime of the underlying objects, so this is OK.
impl From<&KeyGenConfiguration> for StaticKeyGenConfiguration {
    fn from(key_gen_configuration: &KeyGenConfiguration) -> Self {
        // Note that StaticKeyGenConfiguration is just passing a pointer along, which must live for the duration of the program.
        StaticKeyGenConfiguration {
            cc_ptr: key_gen_configuration.xfer.cc_ptr,
        }
    }
}

// We're making a new KeyGenConfiguration object, which Rust can manage. The underlying pointers
// are to static memory managed by C++, and Rust will not clean them up, so this is safe.
impl From<StaticKeyGenConfiguration> for KeyGenConfiguration {
    fn from(key_gen_configuration: StaticKeyGenConfiguration) -> Self {
        // The underlying KeyGenConfiguration is static, so this is actually safe.
        KeyGenConfiguration {
            xfer: key_gen_configuration,
        }
    }
}
