#ifndef _XPU_IR_XPU_DIALECT_TD_
#define _XPU_IR_XPU_DIALECT_TD_

include "mlir/IR/DialectBase.td"

def XPU_Dialect : Dialect {
    let name = "xpu"; 
    let summary = "xpu-dialect to understand IREE stack"; 
    let cppNamespace = "::mlir::xpu"; 
}

#endif //_XPU_IR_XPU_DIALECT_TD_