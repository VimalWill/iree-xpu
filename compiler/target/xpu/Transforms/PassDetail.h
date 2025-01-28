#ifndef _XPU_TRANSFORMS_PASS_DETAIL_H_
#define _XPU_TRANSFORMS_PASS_DETAIL_H_

namespace mlir::iree_compiler::XPU
{
#define GEN_PASS_DECL
#define GEN_PASS_DEF_XPUMATMULLOWERING
#include "xpu/Transforms/Passes.h.inc"
} // mlir::iree_compiler::XPU


#endif //_XPU_TRANSFORMS_PASS_DETAIL_H_

