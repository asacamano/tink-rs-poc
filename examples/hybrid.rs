const PLAINTEXT: &str = "Hello, world - but secret!";
const AD: &str = "I'm so memory-safe!";

fn main() {
    if let Err(e) = hybrid_round_trip() {
        eprintln!("Error in aead_round_trip: {:?}", e);
        std::process::exit(1);
    }
}

fn hybrid_round_trip() -> Result<(), tink_rs::TinkError> {
    tink_rs::HybridConfig::register()?;
    let configuration = tink_rs::config_global_registry();
    let key_gen_configuration = tink_rs::key_gen_config_global_registry();
    let private_keyset_handle = tink_rs::KeysetHandle::generate_new(
        &tink_rs::HybridKeyTemplates::ecies_x25519_hkdf_hmac_sha256_aes256_gcm(),
        &key_gen_configuration,
    )?;
    let public_keyset_handle =
        private_keyset_handle.get_public_keyset_handle(&key_gen_configuration)?;

    let encrypt: tink_rs::HybridEncrypt = public_keyset_handle.get_primitive(&configuration)?;
    let decrypt: tink_rs::HybridDecrypt = private_keyset_handle.get_primitive(&configuration)?;

    let ciphertext = encrypt.encrypt(PLAINTEXT.as_bytes(), AD.as_bytes())?;
    let roundtrip_bytes = decrypt.decrypt(&ciphertext, AD.as_bytes())?;
    let roundtrip = match std::str::from_utf8(&roundtrip_bytes) {
        Ok(v) => v,
        Err(e) => panic!("Invalid UTF-8 sequence: {}", e),
    };
    assert_eq!(PLAINTEXT, roundtrip);
    Ok(())
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_round_trip() {
        let result = super::hybrid_round_trip();
        assert!(
            result.is_ok(),
            "Expected Ok but got error: {:?}",
            result.err()
        );
    }
}
