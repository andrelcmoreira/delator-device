/**
 *
 */
#ifndef DAEMON_H_
#define DAEMON_H_

#include <memory>

#include "gps_device.h"
#include "gprs_device.h"
#include "microphone_device.h"
#include "thread_pool.h"

namespace delator {

/**
 * \brief
 */
class Daemon {
   public:
    /**
     * \brief Constructor.
     */
    Daemon(const std::string &server_ip, 
           const std::string &gprs_port, 
           const std::string &gps_port);
    
    /**
     * \brief Destructor.
     */
    ~Daemon() = default;
    
    /**
     * \brief
     * \return 
     */
    int Run() const;
    
   private:
    std::unique_ptr<MicrophoneDevice> microphone_; //!<
    std::unique_ptr<GpsDevice> gps_; //!<
    std::unique_ptr<GprsDevice> gprs_; //!<
    
    std::unique_ptr<ThreadPool> pool_; //!<
};

}  // namespace delator

#endif  // APP_H_
