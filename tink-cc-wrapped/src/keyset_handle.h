#pragma once

#include "aead.h"
#include "configuration.h"
#include "hybrid_decrypt.h"
#include "hybrid_encrypt.h"
#include "key_gen_configuration.h"
#include "key_template.h"
#include "keyset_handle.h"
#include "tink/keyset_handle.h"
#include "wrapped_util.h"

extern "C" {
    // OwnedKeysetHandle is passed between C++ and Rust and shows that the object is owned by the recipient.
    struct OwnedKeysetHandle {
        // Note, this may be null.
        crypto::tink::KeysetHandle *cc_keyset_handle;
    };

    // How rust frees the underlying C++ object.
    void wrapped_DeleteKeysetHandle(crypto::tink::KeysetHandle *cc_keyset_handle);
    
    // OwnedTinkStatusOrKeysetHandle is returned by C++ to Rust when an object is the result of a function call.
    // This is a pattern throughout all of Tink's API.
    struct OwnedTinkStatusOrKeysetHandle {
        OwnedTinkStatus status;
        OwnedKeysetHandle owned;
    };
    // BorrowedKeysetHandle is passed between C++ and Rust and shows that the object is borrowed by the recipient.
    struct BorrowedKeysetHandle {
        // Note, this may never be null.
        const crypto::tink::KeysetHandle *cc_keyset_handle;
    };

    // Returns a KeysetHandle containing one new key generated according to
    // `key_template` using `config`. When specified, the keyset is annotated
    // for monitoring with `monitoring_annotations`.
    // 
    // `config` is the corresponding :key_gen_config_v0 for your primitive. For
    // example, use //tink/aead:key_gen_config_v0 for AEAD. If a single
    // GenerateNew call handles multiple primitives, use
    // //tink//config:key_gen_v0.
    OwnedTinkStatusOrKeysetHandle wrapped_KeysetHandle_GenerateNew(const StaticKeyTemplate key_template, const StaticKeyGenConfiguration config);

    // Creates a wrapped primitive using this keyset handle and config, which
    // stores necessary primitive wrappers and key type managers.
    // 
    // `config` is the corresponding :config_v0 for your primitive. For example,
    // use //tink/aead:config_v0 for AEAD. If a single GenerateNew call handles
    // multiple primitives, use //tink//config:v0.
    OwnedTinkStatusOrAead wrapped_KeysetHandle_GetPrimitive_Aead(const BorrowedKeysetHandle xfer_self, const StaticConfiguration config);

    // Creates a wrapped primitive using this keyset handle and config, which
    // stores necessary primitive wrappers and key type managers.
    // 
    // `config` is the corresponding :config_v0 for your primitive. For example,
    // use //tink/aead:config_v0 for AEAD. If a single GenerateNew call handles
    // multiple primitives, use //tink//config:v0.
    OwnedTinkStatusOrHybridDecrypt wrapped_KeysetHandle_GetPrimitive_HybridDecrypt(const BorrowedKeysetHandle xfer_self, const StaticConfiguration config);

    // Creates a wrapped primitive using this keyset handle and config, which
    // stores necessary primitive wrappers and key type managers.
    // 
    // `config` is the corresponding :config_v0 for your primitive. For example,
    // use //tink/aead:config_v0 for AEAD. If a single GenerateNew call handles
    // multiple primitives, use //tink//config:v0.
    OwnedTinkStatusOrHybridEncrypt wrapped_KeysetHandle_GetPrimitive_HybridEncrypt(const BorrowedKeysetHandle xfer_self, const StaticConfiguration config);

    // Returns a new KeysetHandle containing public keys corresponding to the
    // private keys in this handle. Relies on key type managers stored in `config`
    // to do so. Returns an error if this handle contains keys that are not
    // private keys.
    OwnedTinkStatusOrKeysetHandle wrapped_KeysetHandle_GetPublicKeysetHandle(const BorrowedKeysetHandle xfer_self, const StaticKeyGenConfiguration config);
}

// When a function returns an Aead object, this converts it to a transfer type.
OwnedTinkStatusOrKeysetHandle toOwnedTinkStatusOrKeysetHandle(absl::StatusOr<std::unique_ptr<crypto::tink::KeysetHandle>> s);
