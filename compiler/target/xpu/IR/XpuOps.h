#ifndef _XPU_IR_XPU_OPS_H_
#define _XPU_IR_XPU_OPS_H_

namespace mlir::iree_compiler::XPU {
namespace {
#define GET_OP_CLASSES
#include "xpu/IR/XpuOps.h.inc"
} // namespace
} // namespace mlir::iree_compiler::XPU

#endif //_XPU_IR_XPU_OPS_H_