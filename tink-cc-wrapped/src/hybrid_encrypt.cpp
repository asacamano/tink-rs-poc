#include "hybrid_encrypt.h"
 
void wrapped_DeleteHybridEncrypt(crypto::tink::HybridEncrypt *cc_hybrid_encrypt) {
    assert(cc_hybrid_encrypt != nullptr);
    delete cc_hybrid_encrypt;
}

OwnedTinkStatusOrBytes wrapped_HybridEncrypt_Encrypt(const BorrowedHybridEncrypt xfer_self, const BorrowedBytes plaintext, const BorrowedBytes context_info) {
    absl::string_view cc_plaintext = toStringView(plaintext);
    absl::string_view cc_context_info = toStringView(context_info);
    const crypto::tink::HybridEncrypt* cc_self = xfer_self.cc_hybrid_encrypt;
    absl::StatusOr<std::string> result = cc_self->Encrypt(cc_plaintext, cc_context_info);
    return toOwnedTinkStatusOrBytes(result);
}

// Converts from the C++ idiomatic version to the Transfer version, propagating error information.
OwnedTinkStatusOrHybridEncrypt toOwnedTinkStatusOrHybridEncrypt(absl::StatusOr<std::unique_ptr<crypto::tink::HybridEncrypt>> s) {
    if (s.ok()) {
        return OwnedTinkStatusOrHybridEncrypt{
            OwnedTinkStatus{0, nullptr, 0},
            OwnedHybridEncrypt{
                // This magic spell tells C++ to stop managing the memory for the object, but without deleting it.
                // From here on, Rust will manage the memory.
                cc_hybrid_encrypt: s.value().release()
            }
        };
    } else {
        return OwnedTinkStatusOrHybridEncrypt{
            toOwnedTinkStatus(s.status()),
            OwnedHybridEncrypt{
                cc_hybrid_encrypt: nullptr
            }
        };
    }
}
