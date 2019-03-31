#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include "daemon.h"

boost::program_options::variables_map ParseCliArguments(int argc, char **argv)
{    
    boost::program_options::options_description desc("Supported options");
    
    desc.add_options()
        ("server-ip", boost::program_options::value<std::string>(), 
         "IP address of remote server")
        ("gps-port", boost::program_options::value<std::string>(), 
         "Port of GPS device")
        ("gprs-port", boost::program_options::value<std::string>(), 
         "Port of GPRS device");

    boost::program_options::variables_map vm;
    auto args = boost::program_options::parse_command_line(argc, argv, desc);
    
    boost::program_options::store(args, vm);
    boost::program_options::notify(vm);

    return vm;
}

int main(int argc, char **argv)
{
    int ret = 1;
    
    try {
        auto args = ParseCliArguments(argc, argv);
        
        delator::Daemon daemon{args["server-ip"].as<std::string>(), 
                               args["gprs-port"].as<std::string>(), 
                               args["gps-port"].as<std::string>()};
        ret = daemon.Run();
    } catch (const std::exception &e) {
        // TODO: handle errors.
        std::cerr << e.what() << std::endl;
    }
         
    return ret;
}
