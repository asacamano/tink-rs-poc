#pragma once

#include "keyset_reader.h"
#include "tink/json/json_keyset_reader.h"
#include "tink/keyset_reader.h"
#include "wrapped_util.h"

extern "C" {

    // Class comments:
    // A KeysetReader that can read from some source cleartext or
    // encrypted keysets in proto JSON wire format, cf.
    // https://developers.google.com/protocol-buffers/docs/encoding
    OwnedTinkStatusOrKeysetReader wrapped_JsonKeysetReader_New(const BorrowedString serialized_keyset);
}
