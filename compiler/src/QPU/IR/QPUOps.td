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

    lets arguments = (ins
        TensorOf<[F32]>:$input_tensor, 
        TensorOf<[F32]>:$weight_tensor, 
        Optional<TensorOf<[F32]>>:$bias_tensor
    ); 

    lets results = (outs TensorOf<[FP32]>:$result); 
    lets builders = [
        OpBuilder<(ins "Value":$input_tensor,
                       "Value":$weight_tensor,
                       "Value":$bias_tensor)>
    ]; 
}

#endif //__QPU_IR_QPU_OPS_TD__