#include "hybrid_decrypt.h"
 
void wrapped_DeleteHybridDecrypt(crypto::tink::HybridDecrypt *cc_hybrid_decrypt) {
    assert(cc_hybrid_decrypt != nullptr);
    delete cc_hybrid_decrypt;
}

OwnedTinkStatusOrBytes wrapped_HybridDecrypt_Decrypt(const BorrowedHybridDecrypt xfer_self, const BorrowedBytes ciphertext, const BorrowedBytes context_info) {
    absl::string_view cc_ciphertext = toStringView(ciphertext);
    absl::string_view cc_context_info = toStringView(context_info);
    const crypto::tink::HybridDecrypt* cc_self = xfer_self.cc_hybrid_decrypt;
    absl::StatusOr<std::string> result = cc_self->Decrypt(cc_ciphertext, cc_context_info);
    return toOwnedTinkStatusOrBytes(result);
}

// Converts from the C++ idiomatic version to the Transfer version, propagating error information.
OwnedTinkStatusOrHybridDecrypt toOwnedTinkStatusOrHybridDecrypt(absl::StatusOr<std::unique_ptr<crypto::tink::HybridDecrypt>> s) {
    if (s.ok()) {
        return OwnedTinkStatusOrHybridDecrypt{
            OwnedTinkStatus{0, nullptr, 0},
            OwnedHybridDecrypt{
                // This magic spell tells C++ to stop managing the memory for the object, but without deleting it.
                // From here on, Rust will manage the memory.
                cc_hybrid_decrypt: s.value().release()
            }
        };
    } else {
        return OwnedTinkStatusOrHybridDecrypt{
            toOwnedTinkStatus(s.status()),
            OwnedHybridDecrypt{
                cc_hybrid_decrypt: nullptr
            }
        };
    }
}
