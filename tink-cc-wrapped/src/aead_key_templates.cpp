#include "aead_key_templates.h"

StaticKeyTemplate wrapped_AeadKeyTemplates_Aes128CtrHmacSha256() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::Aes128CtrHmacSha256();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_AeadKeyTemplates_Aes128Eax() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::Aes128Eax();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_AeadKeyTemplates_Aes128Gcm() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::Aes128Gcm();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_AeadKeyTemplates_Aes128GcmNoPrefix() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::Aes128GcmNoPrefix();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_AeadKeyTemplates_Aes128GcmSiv() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::Aes128GcmSiv();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_AeadKeyTemplates_Aes256CtrHmacSha256() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::Aes256CtrHmacSha256();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_AeadKeyTemplates_Aes256Eax() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::Aes256Eax();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_AeadKeyTemplates_Aes256Gcm() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::Aes256Gcm();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_AeadKeyTemplates_Aes256GcmNoPrefix() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::Aes256GcmNoPrefix();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_AeadKeyTemplates_Aes256GcmSiv() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::Aes256GcmSiv();
    return StaticKeyTemplate { cc_key_template: &result };
}

StaticKeyTemplate wrapped_AeadKeyTemplates_XChaCha20Poly1305() {
    const google::crypto::tink::KeyTemplate& result = crypto::tink::AeadKeyTemplates::XChaCha20Poly1305();
    return StaticKeyTemplate { cc_key_template: &result };
}
