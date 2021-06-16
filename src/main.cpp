#include <iostream>
#include <boost/program_options.hpp>
#include "OTF2/OTF2Reader.h"

// Forward definitions ============================================================================
boost::program_options::variables_map parse_command_line_options(int argc, char* argv[]);

int main(int argc, char* argv[])
{    
    const auto& vm = parse_command_line_options(argc, argv);
    if (vm.empty())
        return 1;

    if (vm.count("file"))
    {
        const std::string& otf2_filename = vm["file"].as<std::string>();
        OTF2Reader reader;
        reader.Open(otf2_filename);
    }

    return 0;
}

boost::program_options::variables_map parse_command_line_options(int argc, char* argv[])
{
    boost::program_options::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("file", boost::program_options::value<std::string>(), "OTF2 file to open")
    ;

    boost::program_options::variables_map vm;
    boost::program_options::store(
        boost::program_options::parse_command_line(argc, argv, desc), vm
    );
    boost::program_options::notify(vm);    

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        vm.clear();
    }

    return vm;
}