/**
 * \brief
 */
#ifndef MICROPHONE_DEVICE_H_
#define MICROPHONE_DEVICE_H_

#include <string>

namespace delator {

/**
 * \brief This class represents a Microphone device.
 */
class MicrophoneDevice {
   public:
    /**
     * \brief Constructor.
     * \param dev_name
     */
    MicrophoneDevice(const std::string &dev_name);
    
    /**
     * \brief Destructor.
     */
    ~MicrophoneDevice() = default;
    
    /**
     * \brief
     */
    void Configure() const;
    
    /**
     * \brief
     * \param period
     */
    void CaptureAudioInput(const uint32_t period) const;
    
   private:
    std::string dev_name_; //!<
};

}  // namespace delator

#endif  // MICROPHONE_DEVICE_H_
