#pragma once

#include "tink/keyset_handle.h"
#include "tink/keyset_reader.h"
#include "wrapped_util.h"

extern "C" {
    // OwnedKeysetReader is passed between C++ and Rust and shows that the object is owned by the recipient.
    struct OwnedKeysetReader {
        // Note, this may be null.
        crypto::tink::KeysetReader *cc_keyset_reader;
    };

    // How rust frees the underlying C++ object.
    void wrapped_DeleteKeysetReader(crypto::tink::KeysetReader *cc_keyset_reader);
    
    // OwnedTinkStatusOrKeysetReader is returned by C++ to Rust when an object is the result of a function call.
    // This is a pattern throughout all of Tink's API.
    struct OwnedTinkStatusOrKeysetReader {
        OwnedTinkStatus status;
        OwnedKeysetReader owned;
    };
}

// When a function returns an Aead object, this converts it to a transfer type.
OwnedTinkStatusOrKeysetReader toOwnedTinkStatusOrKeysetReader(absl::StatusOr<std::unique_ptr<crypto::tink::KeysetReader>> s);
