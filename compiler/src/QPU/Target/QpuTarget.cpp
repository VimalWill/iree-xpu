#include "iree/compiler/Codegen/Dialect/Codegen/IR/IREECodegenDialect.h"
#include "iree/compiler/Dialect/HAL/Target/TargetRegistry.h"
#include "iree/compiler/Dialect/LinalgExt/IR/LinalgExtDialect.h"
#include "iree/compiler/PluginAPI/Client.h"
#include "mlir/Pass/PassManager.h"
#include "llvm/Support/SourceMgr.h"

#include "mlir/IR/DialectRegistry.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllExtensions.h"

#include "QPU/Target/TargetUtils.cpp"

#include <cstdint>
#include <string>

using namespace mlir;

namespace mlir::iree_compiler::QPU {
struct QPUTargetOptions {
  StringRef DeviceID = "qpu-device";
};

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

    uint32_t numPE = 4;
    uint32_t numCl = 8;

    auto addConfig = [&](StringRef name, Attribute value) {
      configItems.emplace_back(StringAttr::get(context, value), value);
    };

    addConfig("target_device", StringAttr::get(context, "qpu_v1"));
    addConfig("num_pe", IntegerAttr::get(IntegerType::get(context, 32), numPE));
    addConfig("num_cl", IntegerAttr::get(IntegerType::get(context, 32), numCl));
    auto configAttr = b.getDictionaryAttr(configItems);
    return IREE::HAL::ExecutableTargetAttr::get(
        context, b.getStringAttr("qpu"), b.getStringAttr("qpu-fb"), configAttr);
  }

  void getDependentDialects(DialectRegistry &registry) const override {
    registry.insert<mlir::iree_compiler::QPU::QPUDialect,
                    mlir::iree_compiler::IREE::Codegen::IREECodegenDialect,
                    IREE::LinalgExt::IREELinalgExtDialect>();

    mlir::registerBuiltinDialectTranslation(registry); // may break?!
  }

  void buildTranslationPassPipeline(IREE::HAL::ExecutableTargetAttr,
                                    OpPassManager &passManager) override {

    // todo: conversion LinalgExt -> QPUDialect
  }

private:
  QPUTargetOptions options_;
};

} // namespace mlir::iree_compiler::QPU