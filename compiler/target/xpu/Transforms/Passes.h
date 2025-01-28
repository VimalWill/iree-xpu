#ifndef _XPU_TRANSFORMS_PASSES_H_
#define _XPU_TRANSFORMS_PASSES_H_

#include "mlir/Pass/Pass.h"
#include "xpu/Transforms/PassDetail.h"

namespace mlir::iree_compiler::XPU {
    void addXPUTranslationPipeline(OpPassManager &pm); 
    std::unique_ptr<Pass> createXPUMatMulLoweringPass(); 
    void registerXPUPasses(); 
}
#endif //_XPU_TRANSFORMS_PASSES_H_