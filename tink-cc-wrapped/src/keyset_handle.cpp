#include "keyset_handle.h"
 
void wrapped_DeleteKeysetHandle(crypto::tink::KeysetHandle *cc_keyset_handle) {
    assert(cc_keyset_handle != nullptr);
    delete cc_keyset_handle;
}

OwnedTinkStatusOrKeysetHandle wrapped_KeysetHandle_GenerateNew(const StaticKeyTemplate key_template, const StaticKeyGenConfiguration config) {
    const google::crypto::tink::KeyTemplate& cc_key_template = *(key_template.cc_key_template);
    const crypto::tink::KeyGenConfiguration& cc_config = *(config.cc_key_gen_configuration);
    absl::StatusOr<std::unique_ptr<crypto::tink::KeysetHandle>> result = crypto::tink::KeysetHandle::GenerateNew(cc_key_template, cc_config);
    return toOwnedTinkStatusOrKeysetHandle(std::move(result));
}

OwnedTinkStatusOrAead wrapped_KeysetHandle_GetPrimitive_Aead(const BorrowedKeysetHandle xfer_self, const StaticConfiguration config) {
    const crypto::tink::Configuration& cc_config = *(config.cc_configuration);
    const crypto::tink::KeysetHandle* cc_self = xfer_self.cc_keyset_handle;
    absl::StatusOr<std::unique_ptr<crypto::tink::Aead>> result = cc_self->GetPrimitive<crypto::tink::Aead>(cc_config);
    return toOwnedTinkStatusOrAead(std::move(result));
}

OwnedTinkStatusOrHybridDecrypt wrapped_KeysetHandle_GetPrimitive_HybridDecrypt(const BorrowedKeysetHandle xfer_self, const StaticConfiguration config) {
    const crypto::tink::Configuration& cc_config = *(config.cc_configuration);
    const crypto::tink::KeysetHandle* cc_self = xfer_self.cc_keyset_handle;
    absl::StatusOr<std::unique_ptr<crypto::tink::HybridDecrypt>> result = cc_self->GetPrimitive<crypto::tink::HybridDecrypt>(cc_config);
    return toOwnedTinkStatusOrHybridDecrypt(std::move(result));
}

OwnedTinkStatusOrHybridEncrypt wrapped_KeysetHandle_GetPrimitive_HybridEncrypt(const BorrowedKeysetHandle xfer_self, const StaticConfiguration config) {
    const crypto::tink::Configuration& cc_config = *(config.cc_configuration);
    const crypto::tink::KeysetHandle* cc_self = xfer_self.cc_keyset_handle;
    absl::StatusOr<std::unique_ptr<crypto::tink::HybridEncrypt>> result = cc_self->GetPrimitive<crypto::tink::HybridEncrypt>(cc_config);
    return toOwnedTinkStatusOrHybridEncrypt(std::move(result));
}

OwnedTinkStatusOrKeysetHandle wrapped_KeysetHandle_GetPublicKeysetHandle(const BorrowedKeysetHandle xfer_self, const StaticKeyGenConfiguration config) {
    const crypto::tink::KeyGenConfiguration& cc_config = *(config.cc_key_gen_configuration);
    const crypto::tink::KeysetHandle* cc_self = xfer_self.cc_keyset_handle;
    absl::StatusOr<std::unique_ptr<crypto::tink::KeysetHandle>> result = cc_self->GetPublicKeysetHandle(cc_config);
    return toOwnedTinkStatusOrKeysetHandle(std::move(result));
}

// Converts from the C++ idiomatic version to the Transfer version, propagating error information.
OwnedTinkStatusOrKeysetHandle toOwnedTinkStatusOrKeysetHandle(absl::StatusOr<std::unique_ptr<crypto::tink::KeysetHandle>> s) {
    if (s.ok()) {
        return OwnedTinkStatusOrKeysetHandle{
            OwnedTinkStatus{0, nullptr, 0},
            OwnedKeysetHandle{
                // This magic spell tells C++ to stop managing the memory for the object, but without deleting it.
                // From here on, Rust will manage the memory.
                cc_keyset_handle: s.value().release()
            }
        };
    } else {
        return OwnedTinkStatusOrKeysetHandle{
            toOwnedTinkStatus(s.status()),
            OwnedKeysetHandle{
                cc_keyset_handle: nullptr
            }
        };
    }
}
