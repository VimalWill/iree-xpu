#ifndef __QPU_TRANSFORM_PASSES_H__
#define __QPU_TRANSFORM_PASSES_H__

#include "mlir/Pass/Pass.h"
#include "QPU/Transforms/PassDetail.h"

namespace mlir::iree_compiler::QPU {
    std::unique_ptr<Pass> createQPUFormMicroKernelPass(); 
}

#endif //__QPU_TRANSFORM_PASSES_H__