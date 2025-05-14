#pragma once

#include "tink/key_gen_configuration.h"
#include "wrapped_util.h"

extern "C" {
    // StaticKeyGenConfiguration is passed between C++ and Rust and shows that the object is static and exists for the
    // lifetime of the program, so never needs to be freed/deleted.
    struct StaticKeyGenConfiguration {
        const crypto::tink::KeyGenConfiguration *cc_key_gen_configuration;
    };
}
