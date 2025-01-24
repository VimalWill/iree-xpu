#ifndef __QPU_IR_QPU_DIALECT_TD__
#define __QPU_IR_QPU_DIALECT_TD__

include "mlir/IR/DialectBase.td"

def QPU_Dialect : Dialect {

    let name = "qpu-dialect"; 
    let summary = "base dialect for qpu hardware target"; 
    let cppNamespace = "::mlir::qpu"; 
}


#endif //__QPU_IR_QPU_DIALECT_TD__