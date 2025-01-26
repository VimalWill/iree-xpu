#ifndef __QPU_TRANSFORM_PASS_DETAIL_H__
#define __QPU_TRANSFORM_PASS_DETAIL_H__

#include "iree/compiler/Dialect/HAL/IR/HALOps.h"
#include "mlir/IR/Operation.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassOptions.h"

namespace mlir::iree_compiler::QPU {
    #define GEN_PASS_DECL
    #define GEN_PASS_DEF_QPUFORMMICROKERNEL
    #include "QPU/Transforms/Passes.h.inc"
}

#endif //__QPU_TRANSFORM_PASS_DETAIL_H__