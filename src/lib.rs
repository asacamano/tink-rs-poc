// ------------- Internal modules not exported for callers to use.
mod wrapped_base;

// ------------- Exported types and structs.
mod tink_error;
pub use tink_error::*;

// ------------- Core Tink types

mod cleartext_keyset_handle;
pub use cleartext_keyset_handle::CleartextKeysetHandle;
mod cleartext_keyset_handle_transfer;

mod configuration;
pub use configuration::Configuration;
mod configuration_transfer;

mod free_functions;
pub use free_functions::*;
mod free_functions_transfer;

mod json_keyset_reader;
pub use json_keyset_reader::JsonKeysetReader;
mod json_keyset_reader_transfer;

mod key_gen_configuration;
pub use key_gen_configuration::KeyGenConfiguration;
mod key_gen_configuration_transfer;

mod keyset_handle;
pub use keyset_handle::KeysetHandle;
mod keyset_handle_transfer;

mod keyset_reader;
pub use keyset_reader::KeysetReader;
mod keyset_reader_transfer;

mod key_template;
pub use key_template::KeyTemplate;
mod key_template_transfer;

// ------------- Primitives

//  AEAD
mod aead;
pub use aead::Aead;
mod aead_transfer;

mod aead_config;
pub use aead_config::AeadConfig;
mod aead_config_transfer;

mod aead_key_templates;
pub use aead_key_templates::AeadKeyTemplates;
mod aead_key_templates_transfer;

// Hybrid

mod hybrid_config;
pub use hybrid_config::HybridConfig;
mod hybrid_config_transfer;

mod hybrid_encrypt;
pub use hybrid_encrypt::HybridEncrypt;
mod hybrid_encrypt_transfer;

mod hybrid_decrypt;
pub use hybrid_decrypt::HybridDecrypt;
mod hybrid_decrypt_transfer;

mod hybrid_key_templates;
pub use hybrid_key_templates::HybridKeyTemplates;
mod hybrid_key_templates_transfer;
