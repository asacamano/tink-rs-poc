use crate::key_template_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// KeyTemplate proto message.
pub struct KeyTemplate {
    pub(crate) xfer: StaticKeyTemplate,
}

/// Converts a Rust reference to a StaticKeyTemplate, useful for passing a Rust object into C++ code.
// Note - This is creating a new StaticKeyTemplate which has its own lifetime, but Rust is not managing
// the lifetime of the underlying objects, so this is OK.
impl From<&KeyTemplate> for StaticKeyTemplate {
    fn from(key_template: &KeyTemplate) -> Self {
        // Note that StaticKeyTemplate is just passing a pointer along, which must live for the duration of the program.
        StaticKeyTemplate {
            cc_ptr: key_template.xfer.cc_ptr,
        }
    }
}

// We're making a new KeyTemplate object, which Rust can manage. The underlying pointers
// are to static memory managed by C++, and Rust will not clean them up, so this is safe.
impl From<StaticKeyTemplate> for KeyTemplate {
    fn from(key_template: StaticKeyTemplate) -> Self {
        // The underlying KeyTemplate is static, so this is actually safe.
        KeyTemplate { xfer: key_template }
    }
}
