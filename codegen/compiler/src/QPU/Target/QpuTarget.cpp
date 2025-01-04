#include "iree/compiler/Codegen/Dialect/Codegen/IR/IREECodegenDialect.h"
#include "iree/compiler/Dialect/HAL/Target/TargetRegistry.h"
#include "iree/compiler/PluginAPI/Client.h"
#include "mlir/Pass/PassManager.h"

#include "QPU/Target/TargetUtils.cpp"

#include <string>

using namespace mlir;
using namespace mlir::iree_compiler;

struct QPUTargetOptions {};

class QPUTargetBackend final : public IREE::HAL::TargetBackend {
public:
  explicit QPUTargetBackend(QPUTargetOptions options)
      : options_(std::move(options)) {}

  std::string getLegacyDefaultDeviceID() const override { return "qpu-device"; }

  void getDefaultExecutableTargets(
      MLIRContext *context, StringRef deviceID, DictionaryAttr deviceConfigAttr,
      SmallVectorImpl<IREE::HALL::ExecutableTargetAttr> &executableTargetAttrs)
      const override {
    executableTargetAttrs.push_back(getExecutableTarget(context));
  }

  IREE::HAL::ExecutableTargetAttr
  getExecutableTarget(MLIRContext *context) const {
    Builder b(context);
    SmallVector<NamedAttribute> configItems;

    auto addConfig = [&](StringRef name, Attribute value) {
      configItems.emplace_back(StringAttr::get(context, name), value);
    };
  }

private:
  QPUTargetOptions options_;
};