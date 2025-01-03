#include "iree/compiler/PluginAPI/Client.h"
#include "iree/compiler/Codegen/Dialect/Codegen/IR/IREECodegenDialect.h"
#include "iree/compiler/Dialect/HAL/Target/TargetRegistry.h"

class QpuTargetBackend final : public IREE::HAL::TargetBackend {
    // TODO: custom backend implementation
}; 