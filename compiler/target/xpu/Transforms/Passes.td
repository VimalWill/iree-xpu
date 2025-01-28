#ifndef _XPU_TRANSFORMS_PASSES_TD_
#define _XPU_TRANSFORMS_PASSES_TD_

include "mlir/Pass/PassBase.td"

def XPUMatMulLowering : Pass<"xpu_matmul_lowering", ""> {
    let description = [{
        lowers linalg.matmul to xpu.matmul 
    }]; 
    let constructor = "mlir::iree_compiler::XPU::createXPUMatMulLoweringPass()"; 
}

#endif //_XPU_TRANSFORMS_PASSES_TD_