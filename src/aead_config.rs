use crate::wrapped_base::OwnedTinkStatus;
use crate::TinkError;

use crate::aead_config_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// Static functions and constants for registering with the Registry
/// all instances of Aead key types supported in a particular release of Tink.
///
/// To register all Aead key types from the current Tink release one can call
///
/// AeadConfig::Register()?
pub struct AeadConfig {}
impl AeadConfig {
    /// Registers Aead primitive wrapper and key managers for all Aead key types
    /// from the current Tink release.
    pub fn register() -> Result<(), TinkError> {
        unsafe {
            let result: OwnedTinkStatus = wrapped_AeadConfig_Register();
            result.into()
        }
    }
}
