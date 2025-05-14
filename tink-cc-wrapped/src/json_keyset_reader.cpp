#include "json_keyset_reader.h"

OwnedTinkStatusOrKeysetReader wrapped_JsonKeysetReader_New(const BorrowedString serialized_keyset) {
    absl::string_view cc_serialized_keyset = toStringView(serialized_keyset);
    absl::StatusOr<std::unique_ptr<crypto::tink::KeysetReader>> result = crypto::tink::JsonKeysetReader::New(cc_serialized_keyset);
    return toOwnedTinkStatusOrKeysetReader(std::move(result));
}
