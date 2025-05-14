use crate::key_template_transfer::StaticKeyTemplate;

// --------------------------------------------------------------
//
// Transfer layer between Rust and C++
//

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    pub(crate) fn wrapped_AeadKeyTemplates_Aes128CtrHmacSha256() -> StaticKeyTemplate;
    pub(crate) fn wrapped_AeadKeyTemplates_Aes128Eax() -> StaticKeyTemplate;
    pub(crate) fn wrapped_AeadKeyTemplates_Aes128Gcm() -> StaticKeyTemplate;
    pub(crate) fn wrapped_AeadKeyTemplates_Aes128GcmNoPrefix() -> StaticKeyTemplate;
    pub(crate) fn wrapped_AeadKeyTemplates_Aes128GcmSiv() -> StaticKeyTemplate;
    pub(crate) fn wrapped_AeadKeyTemplates_Aes256CtrHmacSha256() -> StaticKeyTemplate;
    pub(crate) fn wrapped_AeadKeyTemplates_Aes256Eax() -> StaticKeyTemplate;
    pub(crate) fn wrapped_AeadKeyTemplates_Aes256Gcm() -> StaticKeyTemplate;
    pub(crate) fn wrapped_AeadKeyTemplates_Aes256GcmNoPrefix() -> StaticKeyTemplate;
    pub(crate) fn wrapped_AeadKeyTemplates_Aes256GcmSiv() -> StaticKeyTemplate;
    pub(crate) fn wrapped_AeadKeyTemplates_XChaCha20Poly1305() -> StaticKeyTemplate;

}
