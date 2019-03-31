/**
 * \brief
 */
#ifndef GPRS_DEVICE_H_
#define GPRS_DEVICE_H_

#include <string>

namespace delator {

/**
 * \brief This class represents a Gprs device.
 */
class GprsDevice {
   public:
    /**
     * \brief Constructor.
     * \param dev_name
     * \param server_ip
     */
    GprsDevice(const std::string &dev_name, const std::string &server_ip);
    
    /**
     * \brief Destructor.
     */
    ~GprsDevice() = default;
    
    /**
     * \brief Configure the GPRS device.
     */
    void Configure() const;
    
    /**
     * \brief 
     * \param data
     */
    void Send(const std::string &data) const;
    
   private: 
    std::string server_ip_; //!<
    std::string dev_name_; //!<
};

}  // namespace delator

#endif  // GPRS_DEVICE_H_
