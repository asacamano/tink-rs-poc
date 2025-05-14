#pragma once

#include "key_template.h"
#include "tink/hybrid/hybrid_key_templates.h"
#include "wrapped_util.h"

extern "C" {

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over NIST P-256
    // - DEM: AES128-CTR-HMAC-SHA256 with the following parameters:
    //       * AES key size: 16 bytes
    //       * AES CTR IV size: 16 bytes
    //       * HMAC key size: 32 bytes
    //       * HMAC tag size: 16 bytes
    // - KDF: HKDF-HMAC-SHA256 with an empty salt
    // - EC Point Format: Compressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256CompressedHkdfHmacSha256Aes128CtrHmacSha256();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over NIST P-256
    // - DEM: AES128-GCM
    // - KDF: HKDF-HMAC-SHA256 with an empty salt
    // - EC Point Format: Compressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256CompressedHkdfHmacSha256Aes128Gcm();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over NIST P-256
    // - DEM: AES128-CTR-HMAC-SHA256 with the following parameters:
    //       * AES key size: 16 bytes
    //       * AES CTR IV size: 16 bytes
    //       * HMAC key size: 32 bytes
    //       * HMAC tag size: 16 bytes
    // - KDF: HKDF-HMAC-SHA256 with an empty salt
    // - EC Point Format: Uncompressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128CtrHmacSha256();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over NIST P-256
    // - DEM: AES128-GCM
    // - KDF: HKDF-HMAC-SHA256 with an empty salt
    // - EC Point Format: Uncompressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128Gcm();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over NIST P-256
    // - DEM: AES128-GCM
    // - KDF: HKDF-HMAC-SHA256 with an empty salt
    // - EC Point Format: Compressed
    // - OutputPrefixType: RAW
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128GcmCompressedWithoutPrefix();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over NIST P-256
    // - DEM: AES128-CTR-HMAC-SHA256 with the following parameters:
    //       * AES key size: 16 bytes
    //       * AES CTR IV size: 16 bytes
    //       * HMAC key size: 32 bytes
    //       * HMAC tag size: 16 bytes
    // - KDF: HKDF-HMAC-SHA512 with an empty salt
    // - EC Point Format: Uncompressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha512Aes128CtrHmacSha256();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over NIST P-256
    // - DEM: AES128-GCM
    // - KDF: HKDF-HMAC-SHA512 with an empty salt
    // - EC Point Format: Uncompressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha512Aes128Gcm();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519
    // - DEM: AES128-CTR-HMAC-SHA256 with the following parameters:
    //       * AES key size: 16 bytes
    //       * AES CTR IV size: 16 bytes
    //       * HMAC key size: 32 bytes
    //       * HMAC tag size: 16 bytes
    // - KDF: HKDF-HMAC-SHA256 with an empty salt
    // - EC Point Format: Compressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes128CtrHmacSha256();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519
    // - DEM: AES128-GCM
    // - KDF: HKDF-HMAC-SHA256 with an empty salt
    // - EC Point Format: Compressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes128Gcm();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519
    // - DEM: AES256-GCM
    // - KDF: HKDF-HMAC-SHA256 with an empty salt
    // - EC Point Format: Compressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes256Gcm();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519
    // - DEM: AES-SIV (Deterministic Aead)
    // - KDF: HKDF-HMAC-SHA256 with an empty salt
    // - EC Point Format: Compressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256DeterministicAesSiv();

    // Returns a KeyTemplate that generates new instances of
    // EciesAeadHkdfPrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519
    // - DEM: XChaCha20-Poly1305 with the following parameters:
    //       * XChaCha20 key size: 32 bytes
    //       * IV size: 24 bytes
    // - KDF: HKDF-HMAC-SHA256 with an empty salt
    // - EC Point Format: Compressed
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256XChaCha20Poly1305();

    // Returns a KeyTemplate that generates new instances of
    // HpkePrivateKey with the following parameters:
    // - KEM: ECDH over curve P-256 plus HKDF-SHA256
    // - KDF: HKDF-SHA256
    // - AEAD: AES-128-GCM
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeP256HkdfSha256Aes128Gcm();

    // Returns a KeyTemplate that generates new instances of
    // HpkePrivateKey with the following parameters:
    // - KEM: ECDH over curve P-256 plus HKDF-SHA256
    // - KDF: HKDF-SHA256
    // - AEAD: AES-128-GCM
    // - OutputPrefixType: RAW
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeP256HkdfSha256Aes128GcmRaw();

    // Returns a KeyTemplate that generates new instances of
    // HpkePrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519 plus HKDF-SHA256
    // - KDF: HKDF-SHA256
    // - AEAD: AES-128-GCM
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes128Gcm();

    // Returns a KeyTemplate that generates new instances of
    // HpkePrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519 plus HKDF-SHA256
    // - KDF: HKDF-SHA256
    // - AEAD: AES-128-GCM
    // - OutputPrefixType: RAW
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes128GcmRaw();

    // Returns a KeyTemplate that generates new instances of
    // HpkePrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519 plus HKDF-SHA256
    // - KDF: HKDF-SHA256
    // - AEAD: AES-256-GCM
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes256Gcm();

    // Returns a KeyTemplate that generates new instances of
    // HpkePrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519 plus HKDF-SHA256
    // - KDF: HKDF-SHA256
    // - AEAD: AES-256-GCM
    // - OutputPrefixType: RAW
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes256GcmRaw();

    // Returns a KeyTemplate that generates new instances of
    // HpkePrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519 plus HKDF-SHA256
    // - KDF: HKDF-SHA256
    // - AEAD: ChaCha20-Poly1305
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256ChaCha20Poly1305();

    // Returns a KeyTemplate that generates new instances of
    // HpkePrivateKey with the following parameters:
    // - KEM: ECDH over curve 25519 plus HKDF-SHA256
    // - KDF: HKDF-SHA256
    // - AEAD: ChaCha20-Poly1305
    // - OutputPrefixType: RAW
    // Class comments:
    // Pre-generated KeyTemplate for hybrid key types. One can use these templates
    // to generate a new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single EciesAeadHkdfPrivateKey,
    // one can do:
    // 
    // let status = HybridConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm())?;
    StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256ChaCha20Poly1305Raw();
}
