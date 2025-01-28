#include "xpu/Transforms/Passes.h"
#include "mlir/Pass/PassManager.h"

namespace mlir::iree_compiler::XPU {

void addXPUTranslationPipeline(OpPassManager &pm) {
  pm.addPass(createXPUMatMulLoweringPass());
}

namespace {
#define GEN_PASS_REGISTRATION
#include "xpu/Transforms/Passes.h.inc"
} // namespace

void registerXPUPasses() {
  // generated
  registerPasses();
}
} // namespace mlir::iree_compiler::XPU