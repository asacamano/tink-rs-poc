#include "aead_config.h"

OwnedTinkStatus wrapped_AeadConfig_Register() {
    absl::Status result = crypto::tink::AeadConfig::Register();
    return toOwnedTinkStatus(result);
}
