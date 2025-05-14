#include "free_functions.h"

StaticConfiguration wrapped_ConfigGlobalRegistry() {
    const crypto::tink::Configuration& result = crypto::tink::ConfigGlobalRegistry();
    return StaticConfiguration { cc_configuration: &result };
}

StaticKeyGenConfiguration wrapped_KeyGenConfigGlobalRegistry() {
    const crypto::tink::KeyGenConfiguration& result = crypto::tink::KeyGenConfigGlobalRegistry();
    return StaticKeyGenConfiguration { cc_key_gen_configuration: &result };
}
