#ifndef __QPU_TRANSFOR_PASSES_TD__
#define __QPU_TRANSFOR_PASSES_TD__

include "QPU/IR/QPUDialect.td"
include "mlir/Pass/PassBase.td"

def QPUFormMicroKernel : Pass<"iree-qpu-form-microkernel", ""> {
    let summary = "lowering linalg.matmul to qpu.matmul op"; 
    let constructor = "mlir::iree_compiler::QPU::createQPUFormMicroKernelPass()"; 
}

#endif //__QPU_TRANSFOR_PASSES_TD__