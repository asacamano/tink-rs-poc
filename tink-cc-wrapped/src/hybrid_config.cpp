#include "hybrid_config.h"

OwnedTinkStatus wrapped_HybridConfig_Register() {
    absl::Status result = crypto::tink::HybridConfig::Register();
    return toOwnedTinkStatus(result);
}
