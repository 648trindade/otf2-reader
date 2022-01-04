#include "args.hpp"
#include "json_dump.hpp"

#include "OTF2/OTF2Reader.h"

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
        reader.ReadAllEvents();
        dump_to_JSON(reader, "/tmp/results.json");
    }

    return 0;
}