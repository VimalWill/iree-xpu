#ifndef _CUSTOM_BC_DIALECT_H_
#define _CUSTOM_BC_DIALECT_H_

#include "mlir/IR/Dialect.td"

def Custom_Bc_Dialect : Dialect {
    let name = "custom_bc"; 
    let cppNamespace = "::mlir::iree_compiler::IREE::CustomBc"; 

    let description = [{
        custom backend dialect for IREE compiler to 
        understand the IREE's compiler plugin

        ```
        mlir.iree_compiler.IREE.CustomBc
        ```
    }]; 
}

#endif //_CUSTOM_BC_DIALECT_H_