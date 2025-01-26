iree_cc_library(
    NAME
        QPUDialect
    HDRS
        "QPUDialect.h"
        "QPUOps.h"
    TEXTUAL_HDRS
        "QPUDialect.h.inc"
        "QPUDialect.cpp.inc"
        "QPUOps.h.inc"
        "QPUOps.cpp.inc"
    SRCS
        "QPUOps.cpp"
    DEPS
        ::QPUDialectGen
        ::QPUOpsGen
        MLIRIR
        MLIRDialectUtils
        MLIRParser
        MLIRSupport
    PUBLIC 
)

iree_tablegen_library(
    NAME
        QPUDialectGen
    TD_FILE
        "QPUDialect.td"
    OUTS
        --gen-dialect-decls QPUDialect.h.inc
        --gen_dialect-decls QPUDialect.cpp.inc
)

iree_tablegen_library(
    NAME
        QPUOpsGen
    TD_FILE
        "QPUOps.td"
    OUTS 
        --gen-op-interface-decls QPUOps.h.inc
        --gen-op-interface-decls QPUOps.cpp.inc
)