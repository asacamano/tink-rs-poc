#pragma once

#include "tink/aead_config.h"
#include "wrapped_util.h"

extern "C" {

    // Registers Aead primitive wrapper and key managers for all Aead key types
    // from the current Tink release.
    // Class comments:
    // Static functions and constants for registering with the Registry
    // all instances of Aead key types supported in a particular release of Tink.
    // 
    // To register all Aead key types from the current Tink release one can call
    // 
    // AeadConfig::Register()?
    OwnedTinkStatus wrapped_AeadConfig_Register();
}
