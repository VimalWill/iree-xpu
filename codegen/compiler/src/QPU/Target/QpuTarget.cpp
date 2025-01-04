#include "iree/compiler/PluginAPI/Client.h"
#include "iree/compiler/Codegen/Dialect/Codegen/IR/IREECodegenDialect.h"
#include "iree/compiler/Dialect/HAL/Target/TargetRegistry.h"
#include "mlir/Pass/PassManager.h"


#include <string>

using namespace mlir; 
using namespace mlir::iree_compiler; 
struct QPUTargetOptions {

}; 
class QPUTargetBackend final : public IREE::HAL::TargetBackend {
public:
    explicit QPUTargetBackend(QPUTargetOptions options)
        : options(std::move(options)) {}
    
    std::string getLegacyDefaultDeviceID() const override { return "qpu";}

    void getDefaultExecutableTargets(
        MLIRContext *context, StringRef deviceID, DictionaryAttr deviceConfigAttr, 
        SmallVectorImpl<IREE::HAL::ExecutableTargetAttr> &executableTargetAttrs
    ) const override {
        // todo: hardware data-layout
    }

    

private:
    QPUTargetOptions options;
}; 