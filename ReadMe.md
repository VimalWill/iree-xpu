## Extending IREE's Backend for Custom Target

The compiler can be extended through the ```plugin-infrastructure``` for the custom backend through MLIR-based dialect infrastructure. The expirement eventually can help in developing a well-defined custom backend in future.
This repo focuses on ```XPU```, a custom backend for IREE with passes to lower linalg operations from the stream and flow dialects.

reference:
1. [IREE's Plugin-API](https://github.com/iree-org/iree/tree/main/samples/compiler_plugins/simple_io_sample)