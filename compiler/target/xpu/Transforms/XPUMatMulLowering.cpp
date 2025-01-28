#include "xpu/IR/XpuDialect.h"
#include "xpu/Transforms/Passes.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"

namespace mlir::iree_compiler::XPU {

namespace {
class XPUMatMulLoweringPass
    : public impl::XPUMatMulLoweringBase<XPUMatMulLoweringPass> {
public:
  void getDependentDialects(DialectRegistry &registry) const override {
    registry.insert<XpuDialect>();
  }
  void runOnOperation() override;
};
} // namespace

// https://github.com/nod-ai/iree-amd-aie/blob/9f5d3553a75e76ca030953cfff950926ffc5ae09/compiler/plugins/target/AMD-AIE/iree-amd-aie/Transforms/AMDAIELowerToUKernels.cpp#L259
void XPUMatMulLoweringPass::runOnOperation() {
    MLIRContext *context = getContext(); 
}
} // namespace mlir::iree_compiler::XPU