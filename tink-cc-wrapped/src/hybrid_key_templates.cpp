#include "hybrid_key_templates.h"

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256CompressedHkdfHmacSha256Aes128CtrHmacSha256() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesP256CompressedHkdfHmacSha256Aes128CtrHmacSha256();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256CompressedHkdfHmacSha256Aes128Gcm() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesP256CompressedHkdfHmacSha256Aes128Gcm();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128CtrHmacSha256() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128CtrHmacSha256();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128Gcm() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128Gcm();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128GcmCompressedWithoutPrefix() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesP256HkdfHmacSha256Aes128GcmCompressedWithoutPrefix();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha512Aes128CtrHmacSha256() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesP256HkdfHmacSha512Aes128CtrHmacSha256();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha512Aes128Gcm() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesP256HkdfHmacSha512Aes128Gcm();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes128CtrHmacSha256() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesX25519HkdfHmacSha256Aes128CtrHmacSha256();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes128Gcm() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesX25519HkdfHmacSha256Aes128Gcm();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes256Gcm() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesX25519HkdfHmacSha256Aes256Gcm();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256DeterministicAesSiv() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesX25519HkdfHmacSha256DeterministicAesSiv();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256XChaCha20Poly1305() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::EciesX25519HkdfHmacSha256XChaCha20Poly1305();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeP256HkdfSha256Aes128Gcm() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::HpkeP256HkdfSha256Aes128Gcm();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeP256HkdfSha256Aes128GcmRaw() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::HpkeP256HkdfSha256Aes128GcmRaw();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes128Gcm() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::HpkeX25519HkdfSha256Aes128Gcm();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes128GcmRaw() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::HpkeX25519HkdfSha256Aes128GcmRaw();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes256Gcm() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::HpkeX25519HkdfSha256Aes256Gcm();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes256GcmRaw() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::HpkeX25519HkdfSha256Aes256GcmRaw();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256ChaCha20Poly1305() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::HpkeX25519HkdfSha256ChaCha20Poly1305();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256ChaCha20Poly1305Raw() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::HybridKeyTemplates::HpkeX25519HkdfSha256ChaCha20Poly1305Raw();
    return StaticKeyTemplate { cc_key_template: &result };
}
