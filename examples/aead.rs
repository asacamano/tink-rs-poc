const AEAD_GCM_KEYSET: &str = r#"{
  "key": [
    {
      "keyData": {
        "keyMaterialType": "SYMMETRIC",
        "typeUrl": "type.googleapis.com/google.crypto.tink.AesGcmKey",
        "value": "GiBWyUfGgYk3RTRhj/LIUzSudIWlyjCftCOypTr0jCNSLg=="
      },
      "keyId": 294406504,
      "outputPrefixType": "TINK",
      "status": "ENABLED"
    }
  ],
  "primaryKeyId": 294406504
}
"#;

const PLAINTEXT: &str = "Hello, world - but secret!";
const AD: &str = "I'm so memory-safe!";

fn main() {
    if let Err(e) = aead_round_trip() {
        eprintln!("Error in aead_round_trip: {:?}", e);
        std::process::exit(1);
    }
}

fn aead_round_trip() -> Result<(), tink_rs::TinkError> {
    tink_rs::AeadConfig::register()?;
    let keyset_reader = tink_rs::JsonKeysetReader::new(AEAD_GCM_KEYSET)?;
    let keyset_handle = tink_rs::CleartextKeysetHandle::read(keyset_reader)?;
    let configuration = tink_rs::config_global_registry();
    let aead: tink_rs::Aead = keyset_handle.get_primitive(&configuration)?;

    let ciphertext = aead.encrypt(PLAINTEXT.as_bytes(), AD.as_bytes())?;
    let roundtrip_bytes = aead.decrypt(&ciphertext, AD.as_bytes())?;
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
        let result = super::aead_round_trip();
        assert!(
            result.is_ok(),
            "Expected Ok but got error: {:?}",
            result.err()
        );
    }
}
