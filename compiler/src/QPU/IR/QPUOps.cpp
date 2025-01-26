#include "QPU/IR/QPUOps.h"
#include "QPU/IR/QPUDialect.h"

namespace mlir::iree_compiler::QPU {

void QPUDialect::initializeQPUOps() {
    addOperations<
    #define GET_OP_LIST
    #include "QPU/IR/QPUOps.cpp.inc"
    >(); 
}
}

#define GET_OP_CLASSES
#include "QPU/IR/QPUOps.cpp.inc"