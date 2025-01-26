#include "iree/compiler/Codegen/Common/Passes.h"
#include "iree/compiler/Utils/ToolUtils.h"
#include "mlir/Transforms/Passes.h"
#include "mlir/Dialect/Linalg/Passes.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"

#include "QPU/IR/QPUOps.h"
#include "QPU/Transforms/Passes.h"

namespace mlir::iree_compiler::QPU {
namespace {
    
#define GEN_PASS_REGISTRATION
#include "QPU/Transforms/Passes.h.inc"

}
}
