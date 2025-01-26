iree_add_all_subdirs()

iree_tablegen_library(
    NAME
        PassesIncGen
    TD_FILE
        Passes.td 
    OUTS
        --gen-pass-decls Passes.h.inc
)

iree_cc_library(
    NAME
        PassHeaders
    HDRS
        "PassDetails.h"
        "Passes.h"
        "Passes.h.inc"
    DEPS
        ::PassesIncGen
        iree::target::QPU::IR::QPUDialect
    PUBLIC 
)
