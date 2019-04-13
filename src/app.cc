#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include "daemon.h"

boost::program_options::variables_map ParseCliArguments(int argc, char **argv)
{    
    boost::program_options::variables_map vm;
    
    // TODO
    
    return vm;
}

int main(int argc, char **argv)
{
    int ret = 1;
    
    try {
        auto args = ParseCliArguments(argc, argv);
        
        // TODO: pass the correct values to daemon constructor.
        delator::Daemon daemon{"", "", ""};
        ret = daemon.Run();
    } catch (const std::exception &e) {
        // TODO: handle errors properly.
        std::cerr << e.what() << std::endl;
    }
         
    return ret;
}
