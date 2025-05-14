#pragma once

#include "tink/configuration.h"
#include "wrapped_util.h"

extern "C" {
    // StaticConfiguration is passed between C++ and Rust and shows that the object is static and exists for the
    // lifetime of the program, so never needs to be freed/deleted.
    struct StaticConfiguration {
        const crypto::tink::Configuration *cc_configuration;
    };
}
