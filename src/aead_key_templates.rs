use crate::key_template_transfer::StaticKeyTemplate;
use crate::KeyTemplate;

use crate::aead_key_templates_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// Pre-generated KeyTemplate for Aead key types. One can use these templates
/// to generate new KeysetHandle object with fresh keys.
/// To generate a new keyset that contains a single AesGcmKey, one can do:
///
/// let status = AeadConfig::Register()?;
/// let handle =
///     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
pub struct AeadKeyTemplates {}
impl AeadKeyTemplates {
    /// Returns a KeyTemplate that generates new instances of AesCtrHmacAeadKey
    /// with the following parameters:
    /// - AES key size: 16 bytes
    /// - AES IV size: 16 bytes
    /// - HMAC key size: 32 bytes
    /// - HMAC tag size: 16 bytes
    /// - HMAC hash function: SHA256
    /// - OutputPrefixType: TINK
    pub fn aes128_ctr_hmac_sha256() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_Aes128CtrHmacSha256();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of AesEaxKey
    /// with the following parameters:
    /// - key size: 16 bytes
    /// - IV size: 16 bytes
    /// - tag size: 16 bytes
    /// - OutputPrefixType: TINK
    pub fn aes128_eax() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_Aes128Eax();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of AesGcmKey
    /// with the following parameters:
    /// - key size: 16 bytes
    /// - IV size: 12 bytes
    /// - tag size: 16 bytes
    /// - OutputPrefixType: TINK
    pub fn aes128_gcm() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_Aes128Gcm();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of AesGcmKey
    /// with the following parameters:
    /// - key size: 16 bytes
    /// - IV size: 12 bytes
    /// - tag size: 16 bytes
    /// - OutputPrefixType: RAW
    pub fn aes128_gcm_no_prefix() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_Aes128GcmNoPrefix();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of AesGcmSivKey
    /// with the following parameters:
    /// - key size: 16 bytes
    /// - IV size: 12 bytes
    /// - tag size: 16 bytes
    /// - OutputPrefixType: TINK
    pub fn aes128_gcm_siv() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_Aes128GcmSiv();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of AesCtrHmacAeadKey
    /// with the following parameters:
    /// - AES key size: 32 bytes
    /// - AES IV size: 16 bytes
    /// - HMAC key size: 32 bytes
    /// - HMAC tag size: 32 bytes
    /// - HMAC hash function: SHA256
    /// - OutputPrefixType: TINK
    pub fn aes256_ctr_hmac_sha256() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_Aes256CtrHmacSha256();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of AesEaxKey
    /// with the following parameters:
    /// - key size: 32 bytes
    /// - IV size: 16 bytes
    /// - tag size: 16 bytes
    /// - OutputPrefixType: TINK
    pub fn aes256_eax() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_Aes256Eax();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of AesGcmKey
    /// with the following parameters:
    /// - key size: 32 bytes
    /// - IV size: 12 bytes
    /// - tag size: 16 bytes
    /// - OutputPrefixType: TINK
    pub fn aes256_gcm() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_Aes256Gcm();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of AesGcmKey
    /// with the following parameters:
    /// - key size: 32 bytes
    /// - IV size: 12 bytes
    /// - tag size: 16 bytes
    /// - OutputPrefixType: RAW
    pub fn aes256_gcm_no_prefix() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_Aes256GcmNoPrefix();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of AesGcmSivKey
    /// with the following parameters:
    /// - key size: 32 bytes
    /// - IV size: 12 bytes
    /// - tag size: 16 bytes
    /// - OutputPrefixType: TINK
    pub fn aes256_gcm_siv() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_Aes256GcmSiv();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of XChaCha20Poly1305Key
    /// with the following parameters:
    /// - XChacha20 key size: 32 bytes
    /// - IV size: 24 bytes
    /// - OutputPrefixType: TINK
    pub fn x_cha_cha20_poly1305() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate = wrapped_AeadKeyTemplates_XChaCha20Poly1305();
            result.into()
        }
    }
}
