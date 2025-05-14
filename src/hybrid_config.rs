use crate::wrapped_base::OwnedTinkStatus;
use crate::TinkError;

use crate::hybrid_config_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// Static methods and constants for registering with the Registry
/// all instances of hybrid encryption key types supported in a particular
/// release of Tink, i.e. key types that correspond to primitives
/// HybridEncrypt and HybridDecrypt.
///
/// To register all hybrid encryption key types from the current Tink release
/// one can call
///
/// HybridConfig::Register()?
pub struct HybridConfig {}
impl HybridConfig {
    /// Registers HybridEncrypt and HybridDecrypt primitive wrappers, and key
    /// managers for all implementations of HybridEncrypt and HybridDecrypt from
    /// the current Tink release.
    pub fn register() -> Result<(), TinkError> {
        unsafe {
            let result: OwnedTinkStatus = wrapped_HybridConfig_Register();
            result.into()
        }
    }
}
