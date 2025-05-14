#include "wrapped_util.h"

void wrapped_DeleteString(char *value_data) {
    assert (value_data != nullptr);
    delete[] value_data;
}

std::string toStdString(OwnedString s) {
    return std::string(s.value_data, s.value_len);
}

OwnedString toOwnedString(std::string s) {
    // Copy the string, because in C++, the string does not own it's own buffer,
    // and it bound to the lifetime of of the absl:Status (which ends when control)
    // returns to Rust.
    char *owned_bytes = nullptr;
    if (s.data()) {
        owned_bytes = (char*)malloc(s.length());
        std::memcpy(owned_bytes, s.data(), s.length());
    }
    return OwnedString{
        s.data(),
        s.length()
    };
}

absl::string_view toStringView(BorrowedString s) {
    return absl::string_view(s.value_data, s.value_len);
}

void wrapped_DeleteBytes(char *value_data) {
    assert (value_data != nullptr);
    delete[] value_data;
}

std::string toStdString(OwnedBytes s) {
    return std::string(s.value_data, s.value_len);
}

OwnedBytes toOwnedBytes(std::string s) {
    char *owned_bytes = nullptr;
    if (s.data()) {
        owned_bytes = (char*)malloc(s.length());
        std::memcpy(owned_bytes, s.data(), s.length());
    }
    return OwnedBytes{
        owned_bytes,
        s.length()
    };
}

absl::string_view toStringView(BorrowedBytes s) {
    return absl::string_view(s.value_data, s.value_len);
}

OwnedTinkStatus toOwnedTinkStatus(absl::Status s) {
    if (s.ok()) {
        return OwnedTinkStatus{StatusCode::OK, nullptr, 0};
    } else {
        // Copy the string, because in C++, the string does not own it's own buffer,
        // and it bound to the lifetime of of the absl:Status (which ends when control)
        // returns to Rust.
        char *owned_bytes = nullptr;
        if (s.message().data()) {
            owned_bytes = (char*)malloc(s.message().length());
            std::memcpy(owned_bytes, s.message().data(), s.message().length());
        }
        return OwnedTinkStatus{
            static_cast<size_t>(s.raw_code()),
            owned_bytes,
            s.message().length()
        };
    }
}

OwnedTinkStatusOrBytes toOwnedTinkStatusOrBytes(absl::StatusOr<std::string> s) {
    if (s.ok()) {
        // std:string does not own it's buffer.
        // TODO - look into zero-copy / owned primitives.
        // Rust will free this.
        char *output = (char*)malloc(s.value().length());
        std::memcpy(output, s.value().data(), s.value().length());
        return OwnedTinkStatusOrBytes{
            OwnedTinkStatus{0, nullptr, 0},
            output,
            s.value().length()
        };
    } else {
        return OwnedTinkStatusOrBytes{
            toOwnedTinkStatus(s.status()),
            nullptr,
            0
        };
    }
}