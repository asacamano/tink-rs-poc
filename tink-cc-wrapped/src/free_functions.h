#pragma once

#include "configuration.h"
#include "key_gen_configuration.h"
#include "tink/config/global_registry.h"
#include "wrapped_util.h"

extern "C" {

    // Used to generate primitives and keys using the global crypto::tink::Registry.
    StaticConfiguration wrapped_ConfigGlobalRegistry();

    // Used to generate primitives and keys using the global crypto::tink::Registry.
    StaticKeyGenConfiguration wrapped_KeyGenConfigGlobalRegistry();
}
