#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "xpu/IR/XpuDialect.h"
#include "xpu/Transforms/Passes.h"

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

namespace {
struct MatMulLowering : OpRewritePattern<linalg::LinalgOp> {
  MatMulLowering(mlir::MLIRContext *ctx)
      : OpRewritePattern<linalg::LinalgOp>(ctx) {}

  LogicalResult matchAndRewrite(linalg::LinalgOp op,
                                mlir::PatternRewriter &rewriter) const override;
};
} // namespace

LogicalResult
MatMulLowering::matchAndRewrite(linalg::LinalgOp op,
                                mlir::PatternRewriter &rewriter) const {
  if (isa<linalg::MatMulOp>(op)) {

    bool isBias = false;
    Operation *xpuMatMul = nullptr;

    auto operandLs = op->getOperands();
    if (operandLs.size() < 2)
      return failure();
    if (operandLs.size() == 3)
      isBias = true;

    Value inputTensor = operandLs[0];
    Value weightTensor = operandLs[1];
    if (isBias) {
      Value biasTensor = operandLs[2];
      xpuMatMul = rewriter.create<mlir::xpu::MatMulOp>(
          op.getLoc(), inputTensor, weightTensor, biasTensor);
    } else {
      xpuMatMul = rewriter.create<mlir::xpu::MatMulOp>(op.getLoc(), inputTensor,
                                                       weightTensor);
    }

    rewriter.replaceOp(op, xpuMatMul->getResults());
    return success();

  } else {
    return failure();
  }
}


// https://github.com/nod-ai/iree-amd-aie/blob/9f5d3553a75e76ca030953cfff950926ffc5ae09/compiler/plugins/target/AMD-AIE/iree-amd-aie/Transforms/AMDAIELowerToUKernels.cpp#L259
void XPUMatMulLoweringPass::runOnOperation() {
  MLIRContext *context = &getContext();
  RewritePatternSet patterns(context);
  patterns.add<MatMulLowering>(context);

  if (failed(
          applyPatternsAndFoldGreedily(getOperation(), std::move(patterns)))) {
    signalPassFailure();
  }
}

} // namespace mlir::iree_compiler::XPU