#pragma once

#include "proto/tink.pb.h"
#include "wrapped_util.h"

extern "C" {
    // StaticKeyTemplate is passed between C++ and Rust and shows that the object is static and exists for the
    // lifetime of the program, so never needs to be freed/deleted.
    struct StaticKeyTemplate {
        const google::crypto::tink::KeyTemplate *cc_key_template;
    };
}
