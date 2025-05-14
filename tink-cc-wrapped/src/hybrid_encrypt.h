#pragma once

#include "tink/hybrid_encrypt.h"
#include "wrapped_util.h"

extern "C" {
    // OwnedHybridEncrypt is passed between C++ and Rust and shows that the object is owned by the recipient.
    struct OwnedHybridEncrypt {
        // Note, this may be null.
        crypto::tink::HybridEncrypt *cc_hybrid_encrypt;
    };

    // How rust frees the underlying C++ object.
    void wrapped_DeleteHybridEncrypt(crypto::tink::HybridEncrypt *cc_hybrid_encrypt);
    
    // OwnedTinkStatusOrHybridEncrypt is returned by C++ to Rust when an object is the result of a function call.
    // This is a pattern throughout all of Tink's API.
    struct OwnedTinkStatusOrHybridEncrypt {
        OwnedTinkStatus status;
        OwnedHybridEncrypt owned;
    };
    // BorrowedHybridEncrypt is passed between C++ and Rust and shows that the object is borrowed by the recipient.
    struct BorrowedHybridEncrypt {
        // Note, this may never be null.
        const crypto::tink::HybridEncrypt *cc_hybrid_encrypt;
    };

    // Encrypts 'plaintext' binding 'context_info' to the resulting ciphertext.
    OwnedTinkStatusOrBytes wrapped_HybridEncrypt_Encrypt(const BorrowedHybridEncrypt xfer_self, const BorrowedBytes plaintext, const BorrowedBytes context_info);
}

// When a function returns an Aead object, this converts it to a transfer type.
OwnedTinkStatusOrHybridEncrypt toOwnedTinkStatusOrHybridEncrypt(absl::StatusOr<std::unique_ptr<crypto::tink::HybridEncrypt>> s);
