#include "QPU/IR/QPUDialect.h"
#include "QPU/Transforms/Passes.h"
#include "iree/compiler/Dialect/LinalgExt/IR/LinalgExtDialect.h"

#include "mlir/Dialect/Linalg/IR/Linalg.h"
#include "mlir/IR/BuiltinDialect.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassRegistry.h"
#include "mlir/Transforms/DialectConversion.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"

using namespace mlir;
using namespace mlir::iree_compiler::QPU;
using namespace mlir::iree_compiler::IREE::LinalgExt;

namespace mlir::iree_compiler::QPU {

namespace {
class QPUMatMulFunctionLowerPass
    : public PassWrapper<QPUMatMulFunctionLowerPass, OperationPass<FuncOp>> {

public:
  QPUMatMulFunctionLowerPass() = default;
  void getDependentDialects(DialectRegistry &registry) const override {
    registry.insert<linalg::LinalgDialect>();
  }

  void runOnOperation() override;

private:
  LogicalResult isMatMul(linalg::LinalgOp computeOp) {
    // todo: logic to find matmul op
  }
};

void QPUMatMulFunctionLowerPass::runOnOperation() {
  ModuleOp moduleOp = getOperation();
  MLIRContext *context = &getContext();
  IRRewriter rewriter(context);
}

} // namespace
} // namespace mlir::iree_compiler::QPU
