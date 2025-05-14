use crate::key_template_transfer::StaticKeyTemplate;

// --------------------------------------------------------------
//
// Transfer layer between Rust and C++
//

#[link(name = "tink_cc_wrapped")]
unsafe extern "C" {
    pub(crate) fn wrapped_HybridKeyTemplates_EciesP256CompressedHkdfHmacSha256Aes128CtrHmacSha256(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesP256CompressedHkdfHmacSha256Aes128Gcm(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128CtrHmacSha256(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128Gcm() -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha256Aes128GcmCompressedWithoutPrefix(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha512Aes128CtrHmacSha256(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesP256HkdfHmacSha512Aes128Gcm() -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes128CtrHmacSha256(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes128Gcm(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256Aes256Gcm(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256DeterministicAesSiv(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_EciesX25519HkdfHmacSha256XChaCha20Poly1305(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_HpkeP256HkdfSha256Aes128Gcm() -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_HpkeP256HkdfSha256Aes128GcmRaw() -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes128Gcm() -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes128GcmRaw() -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes256Gcm() -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256Aes256GcmRaw() -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256ChaCha20Poly1305(
    ) -> StaticKeyTemplate;
    pub(crate) fn wrapped_HybridKeyTemplates_HpkeX25519HkdfSha256ChaCha20Poly1305Raw(
    ) -> StaticKeyTemplate;

}
