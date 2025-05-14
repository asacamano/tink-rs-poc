use crate::key_template_transfer::StaticKeyTemplate;
use crate::KeyTemplate;

use crate::hybrid_key_templates_transfer::*;

// --------------------------------------------------------------
//
// Public Rust API
//

/// Pre-generated KeyTemplate for hybrid key types. One can use these templates
/// to generate a new KeysetHandle object with fresh keys.
/// To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
/// one can do:
///
/// let status = HybridConfig::Register()?;
/// let handle =
///     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
pub struct HybridKeyTemplates {}
impl HybridKeyTemplates {
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over NIST P-256
    /// - DEM: AES128-CTR-HMAC-SHA256 with the following parameters:
    ///       * AES key size: 16 bytes
    ///       * AES CTR IV size: 16 bytes
    ///       * HMAC key size: 32 bytes
    ///       * HMAC tag size: 16 bytes
    /// - KDF: HKDF-HMAC-SHA256 with an empty salt
    /// - EC Point Format: Compressed
    /// - OutputPrefixType: TINK
    pub fn ecies_p256_compressed_hkdf_hmac_sha256_aes128_ctr_hmac_sha256() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesP256CompressedHkdfHmacSha256Aes128CtrHmacSha256();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over NIST P-256
    /// - DEM: AES128-GCM
    /// - KDF: HKDF-HMAC-SHA256 with an empty salt
    /// - EC Point Format: Compressed
    /// - OutputPrefixType: TINK
    pub fn ecies_p256_compressed_hkdf_hmac_sha256_aes128_gcm() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesP256CompressedHkdfHmacSha256Aes128Gcm();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over NIST P-256
    /// - DEM: AES128-CTR-HMAC-SHA256 with the following parameters:
    ///       * AES key size: 16 bytes
    ///       * AES CTR IV size: 16 bytes
    ///       * HMAC key size: 32 bytes
    ///       * HMAC tag size: 16 bytes
    /// - KDF: HKDF-HMAC-SHA256 with an empty salt
    /// - EC Point Format: Uncompressed
    /// - OutputPrefixType: TINK
    pub fn ecies_p256_hkdf_hmac_sha256_aes128_ctr_hmac_sha256() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128CtrHmacSha256();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over NIST P-256
    /// - DEM: AES128-GCM
    /// - KDF: HKDF-HMAC-SHA256 with an empty salt
    /// - EC Point Format: Uncompressed
    /// - OutputPrefixType: TINK
    pub fn ecies_p256_hkdf_hmac_sha256_aes128_gcm() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128Gcm();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over NIST P-256
    /// - DEM: AES128-GCM
    /// - KDF: HKDF-HMAC-SHA256 with an empty salt
    /// - EC Point Format: Compressed
    /// - OutputPrefixType: RAW
    pub fn ecies_p256_hkdf_hmac_sha256_aes128_gcm_compressed_without_prefix() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128GcmCompressedWithoutPrefix(
                );
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over NIST P-256
    /// - DEM: AES128-CTR-HMAC-SHA256 with the following parameters:
    ///       * AES key size: 16 bytes
    ///       * AES CTR IV size: 16 bytes
    ///       * HMAC key size: 32 bytes
    ///       * HMAC tag size: 16 bytes
    /// - KDF: HKDF-HMAC-SHA512 with an empty salt
    /// - EC Point Format: Uncompressed
    /// - OutputPrefixType: TINK
    pub fn ecies_p256_hkdf_hmac_sha512_aes128_ctr_hmac_sha256() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha512Aes128CtrHmacSha256();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over NIST P-256
    /// - DEM: AES128-GCM
    /// - KDF: HKDF-HMAC-SHA512 with an empty salt
    /// - EC Point Format: Uncompressed
    /// - OutputPrefixType: TINK
    pub fn ecies_p256_hkdf_hmac_sha512_aes128_gcm() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha512Aes128Gcm();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519
    /// - DEM: AES128-CTR-HMAC-SHA256 with the following parameters:
    ///       * AES key size: 16 bytes
    ///       * AES CTR IV size: 16 bytes
    ///       * HMAC key size: 32 bytes
    ///       * HMAC tag size: 16 bytes
    /// - KDF: HKDF-HMAC-SHA256 with an empty salt
    /// - EC Point Format: Compressed
    /// - OutputPrefixType: TINK
    pub fn ecies_x25519_hkdf_hmac_sha256_aes128_ctr_hmac_sha256() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes128CtrHmacSha256();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519
    /// - DEM: AES128-GCM
    /// - KDF: HKDF-HMAC-SHA256 with an empty salt
    /// - EC Point Format: Compressed
    /// - OutputPrefixType: TINK
    pub fn ecies_x25519_hkdf_hmac_sha256_aes128_gcm() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes128Gcm();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519
    /// - DEM: AES256-GCM
    /// - KDF: HKDF-HMAC-SHA256 with an empty salt
    /// - EC Point Format: Compressed
    /// - OutputPrefixType: TINK
    pub fn ecies_x25519_hkdf_hmac_sha256_aes256_gcm() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes256Gcm();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519
    /// - DEM: AES-SIV (Deterministic Aead)
    /// - KDF: HKDF-HMAC-SHA256 with an empty salt
    /// - EC Point Format: Compressed
    /// - OutputPrefixType: TINK
    pub fn ecies_x25519_hkdf_hmac_sha256_deterministic_aes_siv() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256DeterministicAesSiv();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// EciesAeadHkdfPrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519
    /// - DEM: XChaCha20-Poly1305 with the following parameters:
    ///       * XChaCha20 key size: 32 bytes
    ///       * IV size: 24 bytes
    /// - KDF: HKDF-HMAC-SHA256 with an empty salt
    /// - EC Point Format: Compressed
    /// - OutputPrefixType: TINK
    pub fn ecies_x25519_hkdf_hmac_sha256_x_cha_cha20_poly1305() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256XChaCha20Poly1305();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// HpkePrivateKey with the following parameters:
    /// - KEM: ECDH over curve P-256 plus HKDF-SHA256
    /// - KDF: HKDF-SHA256
    /// - AEAD: AES-128-GCM
    /// - OutputPrefixType: TINK
    pub fn hpke_p256_hkdf_sha256_aes128_gcm() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_HpkeP256HkdfSha256Aes128Gcm();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// HpkePrivateKey with the following parameters:
    /// - KEM: ECDH over curve P-256 plus HKDF-SHA256
    /// - KDF: HKDF-SHA256
    /// - AEAD: AES-128-GCM
    /// - OutputPrefixType: RAW
    pub fn hpke_p256_hkdf_sha256_aes128_gcm_raw() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_HpkeP256HkdfSha256Aes128GcmRaw();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// HpkePrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519 plus HKDF-SHA256
    /// - KDF: HKDF-SHA256
    /// - AEAD: AES-128-GCM
    /// - OutputPrefixType: TINK
    pub fn hpke_x25519_hkdf_sha256_aes128_gcm() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes128Gcm();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// HpkePrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519 plus HKDF-SHA256
    /// - KDF: HKDF-SHA256
    /// - AEAD: AES-128-GCM
    /// - OutputPrefixType: RAW
    pub fn hpke_x25519_hkdf_sha256_aes128_gcm_raw() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes128GcmRaw();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// HpkePrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519 plus HKDF-SHA256
    /// - KDF: HKDF-SHA256
    /// - AEAD: AES-256-GCM
    /// - OutputPrefixType: TINK
    pub fn hpke_x25519_hkdf_sha256_aes256_gcm() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes256Gcm();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// HpkePrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519 plus HKDF-SHA256
    /// - KDF: HKDF-SHA256
    /// - AEAD: AES-256-GCM
    /// - OutputPrefixType: RAW
    pub fn hpke_x25519_hkdf_sha256_aes256_gcm_raw() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes256GcmRaw();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// HpkePrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519 plus HKDF-SHA256
    /// - KDF: HKDF-SHA256
    /// - AEAD: ChaCha20-Poly1305
    /// - OutputPrefixType: TINK
    pub fn hpke_x25519_hkdf_sha256_cha_cha20_poly1305() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256ChaCha20Poly1305();
            result.into()
        }
    }
    /// Returns a KeyTemplate that generates new instances of
    /// HpkePrivateKey with the following parameters:
    /// - KEM: ECDH over curve 25519 plus HKDF-SHA256
    /// - KDF: HKDF-SHA256
    /// - AEAD: ChaCha20-Poly1305
    /// - OutputPrefixType: RAW
    pub fn hpke_x25519_hkdf_sha256_cha_cha20_poly1305_raw() -> KeyTemplate {
        unsafe {
            let result: StaticKeyTemplate =
                wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256ChaCha20Poly1305Raw();
            result.into()
        }
    }
}
