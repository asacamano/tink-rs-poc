#include "aead.h"
 
void wrapped_DeleteAead(crypto::tink::Aead *cc_aead) {
    assert(cc_aead != nullptr);
    delete cc_aead;
}

OwnedTinkStatusOrBytes wrapped_Aead_Decrypt(const BorrowedAead xfer_self, const BorrowedBytes ciphertext, const BorrowedBytes associated_data) {
    absl::string_view cc_ciphertext = toStringView(ciphertext);
    absl::string_view cc_associated_data = toStringView(associated_data);
    const crypto::tink::Aead* cc_self = xfer_self.cc_aead;
    absl::StatusOr<std::string> result = cc_self->Decrypt(cc_ciphertext, cc_associated_data);
    return toOwnedTinkStatusOrBytes(result);
}

OwnedTinkStatusOrBytes wrapped_Aead_Encrypt(const BorrowedAead xfer_self, const BorrowedBytes plaintext, const BorrowedBytes associated_data) {
    absl::string_view cc_plaintext = toStringView(plaintext);
    absl::string_view cc_associated_data = toStringView(associated_data);
    const crypto::tink::Aead* cc_self = xfer_self.cc_aead;
    absl::StatusOr<std::string> result = cc_self->Encrypt(cc_plaintext, cc_associated_data);
    return toOwnedTinkStatusOrBytes(result);
}

// Converts from the C++ idiomatic version to the Transfer version, propagating error information.
OwnedTinkStatusOrAead toOwnedTinkStatusOrAead(absl::StatusOr<std::unique_ptr<crypto::tink::Aead>> s) {
    if (s.ok()) {
        return OwnedTinkStatusOrAead{
            OwnedTinkStatus{0, nullptr, 0},
            OwnedAead{
                // This magic spell tells C++ to stop managing the memory for the object, but without deleting it.
                // From here on, Rust will manage the memory.
                cc_aead: s.value().release()
            }
        };
    } else {
        return OwnedTinkStatusOrAead{
            toOwnedTinkStatus(s.status()),
            OwnedAead{
                cc_aead: nullptr
            }
        };
    }
}
