#include "keyset_reader.h"
 
void wrapped_DeleteKeysetReader(crypto::tink::KeysetReader *cc_keyset_reader) {
    assert(cc_keyset_reader != nullptr);
    delete cc_keyset_reader;
}

// Converts from the C++ idiomatic version to the Transfer version, propagating error information.
OwnedTinkStatusOrKeysetReader toOwnedTinkStatusOrKeysetReader(absl::StatusOr<std::unique_ptr<crypto::tink::KeysetReader>> s) {
    if (s.ok()) {
        return OwnedTinkStatusOrKeysetReader{
            OwnedTinkStatus{0, nullptr, 0},
            OwnedKeysetReader{
                // This magic spell tells C++ to stop managing the memory for the object, but without deleting it.
                // From here on, Rust will manage the memory.
                cc_keyset_reader: s.value().release()
            }
        };
    } else {
        return OwnedTinkStatusOrKeysetReader{
            toOwnedTinkStatus(s.status()),
            OwnedKeysetReader{
                cc_keyset_reader: nullptr
            }
        };
    }
}
