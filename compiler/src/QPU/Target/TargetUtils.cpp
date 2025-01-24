#include "llvm/ADT/STLExtras.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "mlir/Pass/PassManager.h"

using mlir; 

struct DeviceModel {
    std::string deviceName = "qpu"; 
    const int numCore = 4; 
}device_model; 

namespace QPU {

    DeviceModel getDeviceModel(std::string& device_id) {
        if(std::strcmp(device_id, "qpu")) {
            return device_model; 
        } 

        return nullptr; 
    }

} //namespace