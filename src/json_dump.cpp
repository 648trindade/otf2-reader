#include "json_dump.hpp"
#include "nlohmann/json.hpp"

#include <fstream>

nlohmann::json dump_region(OTF2Reader& reader, TreeRegion& region)
{
    nlohmann::json j_region{};
    j_region["name"] = reader.GetName(region.get_name());
    j_region["start"] = reader.GetTimeInSeconds(region.get_start());
    j_region["end"] = reader.GetTimeInSeconds(region.get_end());
    j_region["duration"] = region.get_duration() / 1e9;

    auto& j_children = j_region["children"];
    j_children = nlohmann::json::array();
    for (int i = 0; i < region.get_number_of_children(); i++)
    {
        j_children.push_back(dump_region(reader, region.get_child(i)));
    }

    return j_region;
}

void dump_to_JSON(OTF2Reader& reader, std::string filename)
{
    nlohmann::json JSON{};
    auto& group = reader.GetLocationGroup();
    auto& j_group = JSON["group"];
    j_group["id"] = size_t(group.get_id());
    j_group["name"] = reader.GetName(group.get_name_ref());

    auto& j_locations = j_group["locations"];  
    for (int i = 0; i < reader.GetNumberOfLocations(); i++)
    {
        OTF2_LocationRef location_id = reader.GetLocation(i);
        TreeLocation& location = group.get_location(location_id);
        
        nlohmann::json j_location{};
        j_location["id"] = size_t(location_id);
        j_location["name"] = reader.GetLocationName(location_id); 

        auto& j_regions = j_location["regions"];
        j_regions = nlohmann::json::array();
        for (int i = 0; i < location.get_number_of_children(); i++)
        {
            j_regions.push_back(dump_region(reader, location.get_child(i)));
        }
        j_locations.push_back(j_location);
    }

    std::ofstream file(filename);
    file << std::setw(4) << JSON;
    file.close();
}