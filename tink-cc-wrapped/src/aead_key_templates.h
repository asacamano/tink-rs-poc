#pragma once

#include "key_template.h"
#include "tink/aead/aead_key_templates.h"
#include "wrapped_util.h"

extern "C" {

    // Returns a KeyTemplate that generates new instances of AesCtrHmacAeadKey
    // with the following parameters:
    // - AES key size: 16 bytes
    // - AES IV size: 16 bytes
    // - HMAC key size: 32 bytes
    // - HMAC tag size: 16 bytes
    // - HMAC hash function: SHA256
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_Aes128CtrHmacSha256();

    // Returns a KeyTemplate that generates new instances of AesEaxKey
    // with the following parameters:
    // - key size: 16 bytes
    // - IV size: 16 bytes
    // - tag size: 16 bytes
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_Aes128Eax();

    // Returns a KeyTemplate that generates new instances of AesGcmKey
    // with the following parameters:
    // - key size: 16 bytes
    // - IV size: 12 bytes
    // - tag size: 16 bytes
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_Aes128Gcm();

    // Returns a KeyTemplate that generates new instances of AesGcmKey
    // with the following parameters:
    // - key size: 16 bytes
    // - IV size: 12 bytes
    // - tag size: 16 bytes
    // - OutputPrefixType: RAW
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_Aes128GcmNoPrefix();

    // Returns a KeyTemplate that generates new instances of AesGcmSivKey
    // with the following parameters:
    // - key size: 16 bytes
    // - IV size: 12 bytes
    // - tag size: 16 bytes
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_Aes128GcmSiv();

    // Returns a KeyTemplate that generates new instances of AesCtrHmacAeadKey
    // with the following parameters:
    // - AES key size: 32 bytes
    // - AES IV size: 16 bytes
    // - HMAC key size: 32 bytes
    // - HMAC tag size: 32 bytes
    // - HMAC hash function: SHA256
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_Aes256CtrHmacSha256();

    // Returns a KeyTemplate that generates new instances of AesEaxKey
    // with the following parameters:
    // - key size: 32 bytes
    // - IV size: 16 bytes
    // - tag size: 16 bytes
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_Aes256Eax();

    // Returns a KeyTemplate that generates new instances of AesGcmKey
    // with the following parameters:
    // - key size: 32 bytes
    // - IV size: 12 bytes
    // - tag size: 16 bytes
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_Aes256Gcm();

    // Returns a KeyTemplate that generates new instances of AesGcmKey
    // with the following parameters:
    // - key size: 32 bytes
    // - IV size: 12 bytes
    // - tag size: 16 bytes
    // - OutputPrefixType: RAW
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_Aes256GcmNoPrefix();

    // Returns a KeyTemplate that generates new instances of AesGcmSivKey
    // with the following parameters:
    // - key size: 32 bytes
    // - IV size: 12 bytes
    // - tag size: 16 bytes
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_Aes256GcmSiv();

    // Returns a KeyTemplate that generates new instances of XChaCha20Poly1305Key
    // with the following parameters:
    // - XChacha20 key size: 32 bytes
    // - IV size: 24 bytes
    // - OutputPrefixType: TINK
    // Class comments:
    // Pre-generated KeyTemplate for Aead key types. One can use these templates
    // to generate new KeysetHandle object with fresh keys.
    // To generate a new keyset that contains a single AesGcmKey, one can do:
    // 
    // let status = AeadConfig::Register()?;
    // let handle =
    //     KeysetHandle::GenerateNew(AeadKeyTemplates::Aes128Gcm())?;
    StaticKeyTemplate wrapped_AeadKeyTemplates_XChaCha20Poly1305();
}
