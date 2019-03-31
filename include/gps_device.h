/**
 * \brief
 */
#ifndef GPS_DEVICE_H_
#define GPS_DEVICE_H_

#include <string>

namespace delator {

struct GlobalPosition;

/**
 * \brief This class represents a Gps device.
 */
class GpsDevice {
   public:
    /**
     * \brief Constructor.
     * \param dev_name
     */
    GpsDevice(const std::string &dev_name);
    
    /**
     * \brief Destructor.
     */
    ~GpsDevice() = default;
    
    /**
     * \brief
     */
    void Configure() const;
    
    /**
     * \brief
     * \return 
     */
    GlobalPosition AcquirePosition() const;
    
   private:
    std::string dev_name_; //!<
};

}  // namespace delator

#endif  // GPS_DEVICE_H_
