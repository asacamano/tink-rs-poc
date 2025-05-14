#pragma once

#include "tink/hybrid/hybrid_config.h"
#include "wrapped_util.h"

extern "C" {

    // Registers HybridEncrypt and HybridDecrypt primitive wrappers, and key
    // managers for all implementations of HybridEncrypt and HybridDecrypt from
    // the current Tink release.
    // Class comments:
    // Static methods and constants for registering with the Registry
    // all instances of hybrid encryption key types supported in a particular
    // release of Tink, i.e. key types that correspond to primitives
    // HybridEncrypt and HybridDecrypt.
    // 
    // To register all hybrid encryption key types from the current Tink release
    // one can call
    // 
    // HybridConfig::Register()?
    OwnedTinkStatus wrapped_HybridConfig_Register();
}
