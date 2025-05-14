#pragma once

#include "tink/aead.h"
#include "wrapped_util.h"

extern "C" {
    // OwnedAead is passed between C++ and Rust and shows that the object is owned by the recipient.
    struct OwnedAead {
        // Note, this may be null.
        crypto::tink::Aead *cc_aead;
    };

    // How rust frees the underlying C++ object.
    void wrapped_DeleteAead(crypto::tink::Aead *cc_aead);
    
    // OwnedTinkStatusOrAead is returned by C++ to Rust when an object is the result of a function call.
    // This is a pattern throughout all of Tink's API.
    struct OwnedTinkStatusOrAead {
        OwnedTinkStatus status;
        OwnedAead owned;
    };
    // BorrowedAead is passed between C++ and Rust and shows that the object is borrowed by the recipient.
    struct BorrowedAead {
        // Note, this may never be null.
        const crypto::tink::Aead *cc_aead;
    };

    // Decrypts 'ciphertext' with 'associated_data' as associated data,
    // and returns the resulting plaintext.
    // The decryption verifies the authenticity and integrity
    // of the associated data, but there are no guarantees wrt. secrecy
    // of that data.
    OwnedTinkStatusOrBytes wrapped_Aead_Decrypt(const BorrowedAead xfer_self, const BorrowedBytes ciphertext, const BorrowedBytes associated_data);

    // Encrypts 'plaintext' with 'associated_data' as associated data,
    // and returns the resulting ciphertext.
    // The ciphertext allows for checking authenticity and integrity
    // of the associated data, but does not guarantee its secrecy.
    OwnedTinkStatusOrBytes wrapped_Aead_Encrypt(const BorrowedAead xfer_self, const BorrowedBytes plaintext, const BorrowedBytes associated_data);
}

// When a function returns an Aead object, this converts it to a transfer type.
OwnedTinkStatusOrAead toOwnedTinkStatusOrAead(absl::StatusOr<std::unique_ptr<crypto::tink::Aead>> s);
