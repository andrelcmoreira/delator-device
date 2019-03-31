#include "gps_device.h"

namespace delator {

// TODO: place in another file?
struct GlobalPosition {
    uint8_t latitude;
    uint8_t longitude;
};

GpsDevice::GpsDevice(const std::string &dev_name)
{
    // TODO   
}
    
void GpsDevice::Configure() const
{
    // TODO
}

GlobalPosition GpsDevice::AcquirePosition() const
{
    GlobalPosition global_pos;
    // TODO
    return global_pos;
}
    
}  // namespace delator
