iree_cc_library(
    NAME
        registration
    SRCS
        "QpuTarget.cpp"
    DEPS
        iree::compiler::HAL::Target
        iree::compiler::PluginAPI
        iree::target::QPU::QPUDialect
        iree::target::QPU::Transforms
        iree::target::QP::Target
        PUBLIC
)

iree_compiler_register_plugin(
    PLUGIN_ID
        qpu
    TARGET
        ::registration
)

add_subdirectory(IR)
add_subdirectory(Target)
add_subdirectory(Transforms)