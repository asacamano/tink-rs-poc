#pragma once

#include "keyset_handle.h"
#include "keyset_reader.h"
#include "tink/cleartext_keyset_handle.h"
#include "tink/keyset_reader.h"
#include "wrapped_util.h"

extern "C" {

    // Creates a KeysetHandle with a keyset obtained via `reader`. Optionally
    // allows to pass monitoring_annotations to attach additional data to the
    // resulting KeysetHandle, which will be used for monitoring.
    // Class comments:
    // Creates keyset handles from cleartext keysets. This API allows
    // loading cleartext keysets, thus its usage should be restricted.
    OwnedTinkStatusOrKeysetHandle wrapped_CleartextKeysetHandle_Read(OwnedKeysetReader reader);
}
