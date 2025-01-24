#ifndef __QPU_IR_QPU_OPS_TD__
#define __QPU_IR_QPU_OPS_TD__

include "mlir/IR/OpBase.td"
include "QPU/IR/QPUDialect.td"

//base class for qpu-dialect ops
class QPU_Op<string mnemonic, list<Trait> traits = []> : op<QPU_Op, mnemonic, traits>; 

//===----------------------------------------------------------------------===//
// QPULinearOp
//===----------------------------------------------------------------------===//
def MatMul : QPU_Op<"matmul", [Pure]> {
    let name = "qpu-matmul"; 
    let description [{
        operator for handling 2D matrix 
        mutiplication operations within 
        QPU target

        ```
        qpu.matmul

        ```
    }]; 

    //todo: define ins and outs
}

#endif //__QPU_IR_QPU_OPS_TD__