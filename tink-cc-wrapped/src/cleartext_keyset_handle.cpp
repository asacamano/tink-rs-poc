#include "cleartext_keyset_handle.h"

OwnedTinkStatusOrKeysetHandle wrapped_CleartextKeysetHandle_Read(OwnedKeysetReader reader) {
    std::unique_ptr<crypto::tink::KeysetReader> cc_reader(reader.cc_keyset_reader);
    absl::StatusOr<std::unique_ptr<crypto::tink::KeysetHandle>> result = crypto::tink::CleartextKeysetHandle::Read(std::move(cc_reader));
    return toOwnedTinkStatusOrKeysetHandle(std::move(result));
}
