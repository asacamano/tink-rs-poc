use crate::configuration_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// Configuration used to generate primitives using stored primitive wrappers and
/// key type managers.    
pub struct Configuration {
    pub(crate) xfer: StaticConfiguration,
}

/// Converts a Rust reference to a StaticConfiguration, useful for passing a Rust object into C++ code.
// Note - This is creating a new StaticConfiguration which has its own lifetime, but Rust is not managing
// the lifetime of the underlying objects, so this is OK.
impl From<&Configuration> for StaticConfiguration {
    fn from(configuration: &Configuration) -> Self {
        // Note that StaticConfiguration is just passing a pointer along, which must live for the duration of the program.
        StaticConfiguration {
            cc_ptr: configuration.xfer.cc_ptr,
        }
    }
}

// We're making a new Configuration object, which Rust can manage. The underlying pointers
// are to static memory managed by C++, and Rust will not clean them up, so this is safe.
impl From<StaticConfiguration> for Configuration {
    fn from(configuration: StaticConfiguration) -> Self {
        // The underlying Configuration is static, so this is actually safe.
        Configuration {
            xfer: configuration,
        }
    }
}
