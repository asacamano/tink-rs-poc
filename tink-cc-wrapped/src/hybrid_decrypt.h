#pragma once

#include "tink/hybrid_decrypt.h"
#include "wrapped_util.h"

extern "C" {
    // OwnedHybridDecrypt is passed between C++ and Rust and shows that the object is owned by the recipient.
    struct OwnedHybridDecrypt {
        // Note, this may be null.
        crypto::tink::HybridDecrypt *cc_hybrid_decrypt;
    };

    // How rust frees the underlying C++ object.
    void wrapped_DeleteHybridDecrypt(crypto::tink::HybridDecrypt *cc_hybrid_decrypt);
    
    // OwnedTinkStatusOrHybridDecrypt is returned by C++ to Rust when an object is the result of a function call.
    // This is a pattern throughout all of Tink's API.
    struct OwnedTinkStatusOrHybridDecrypt {
        OwnedTinkStatus status;
        OwnedHybridDecrypt owned;
    };
    // BorrowedHybridDecrypt is passed between C++ and Rust and shows that the object is borrowed by the recipient.
    struct BorrowedHybridDecrypt {
        // Note, this may never be null.
        const crypto::tink::HybridDecrypt *cc_hybrid_decrypt;
    };

    // Decrypts 'ciphertext' verifying the integrity of 'context_info'.
    OwnedTinkStatusOrBytes wrapped_HybridDecrypt_Decrypt(const BorrowedHybridDecrypt xfer_self, const BorrowedBytes ciphertext, const BorrowedBytes context_info);
}

// When a function returns an Aead object, this converts it to a transfer type.
OwnedTinkStatusOrHybridDecrypt toOwnedTinkStatusOrHybridDecrypt(absl::StatusOr<std::unique_ptr<crypto::tink::HybridDecrypt>> s);
