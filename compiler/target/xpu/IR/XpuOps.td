#ifndef _XPU_IR_XPU_OPS_TD_
#define _XPU_IR_XPU_OPS_TD_

include "mlir/IR/OpBase.td"
include "XPU/IR/XpuDialect.td"

class XPU_Op<string mnemonic, list<Traits> traits = []> : op<XPU_Dialect, mnemonic, traits>;

def MatMulOp : XPU_Op<"matmul", [Pure]> {
    let name = "matmulop"; 
    let description = [{
        operation to hold 2D matrix-multiplication,
        linalg.matmul -> xpu.matmul
    }]; 

    let arguments = (ins
        TensorOf<[F32]>:$input_tensor, 
        TensorOf<[F32]>:$weight_tensor,
        Optional<TensorOf<[F32]>>:$bias_tensor
    ); 

    let results = (outs TensorOf<[F32]>:$result); 
    let builders = [
        OpBuilder<("Value":$input_tensor, "Value":$weight_tensor, "Value":$bias_tensor)>
    ]; 
}

#endif //_XPU_IR_XPU_OPS_TD_
