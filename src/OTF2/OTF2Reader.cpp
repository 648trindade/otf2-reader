#include "OTF2Reader.h"
#include "OTF2Callbacks.h"

#include <iostream>
#include <limits>
#include <stdexcept>

OTF2Reader::OTF2Reader()
{
}

OTF2Reader::OTF2Reader(const std::string& otf2_filename)
{
    this->Open(otf2_filename);
}

OTF2Reader::~OTF2Reader()
{
    if (this->reader)
        this->Close();
}

void OTF2Reader::Open(const std::string& otf2_filename)
{
    this->reader = OTF2_Reader_Open(otf2_filename.c_str());
    if (this->reader == nullptr)
        throw std::runtime_error("Error opening OTF2 file: " + otf2_filename);
    
    OTF2_Reader_GetNumberOfLocations(this->reader, &this->num_locations);

    /* Define definition callbacks. */
    this->def_callbacks = OTF2_GlobalDefReaderCallbacks_New();
    OTF2_GlobalDefReaderCallbacks_SetLocationCallback(this->def_callbacks, otf2_global_def_location);
    OTF2_GlobalDefReaderCallbacks_SetStringCallback(this->def_callbacks, otf2_global_def_string);
    OTF2_GlobalDefReaderCallbacks_SetRegionCallback(this->def_callbacks, otf2_global_def_region);
    OTF2_GlobalDefReaderCallbacks_SetClockPropertiesCallback(this->def_callbacks, otf2_global_def_clock_properties);
    OTF2_GlobalDefReaderCallbacks_SetLocationGroupCallback(this->def_callbacks, otf2_global_def_location_group);
    OTF2_GlobalDefReaderCallbacks_SetLocationCallback(this->def_callbacks, otf2_global_def_location);
    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodeCallback(this->def_callbacks, otf2_global_def_system_tree_node);
    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodePropertyCallback(
        this->def_callbacks, otf2_global_def_system_tree_node_property);
    OTF2_GlobalDefReaderCallbacks_SetSystemTreeNodeDomainCallback(
        this->def_callbacks, otf2_global_def_system_tree_node_domain);

    OTF2_GlobalDefReader* glob_def_reader = OTF2_Reader_GetGlobalDefReader(this->reader);
    OTF2_Reader_RegisterGlobalDefCallbacks(this->reader, glob_def_reader, this->def_callbacks, this);

    size_t definitions_read = 0;
    OTF2_Reader_ReadGlobalDefinitions(this->reader, glob_def_reader, OTF2_UNDEFINED_UINT64, &definitions_read);

    /* Read definitions */
    for (OTF2_LocationRef& location : this->locations)
    {
        OTF2_DefReader* def_reader = OTF2_Reader_GetDefReader(this->reader, location);
        size_t definitions_read = 0;
        OTF2_Reader_ReadAllLocalDefinitions(this->reader, def_reader, &definitions_read);
        OTF2_Reader_CloseDefReader(this->reader, def_reader);
    }

    /* Create event readers */
    for (OTF2_LocationRef& location : this->locations)
    {
        OTF2_Reader_GetEvtReader(this->reader, location);
    }

    /* Define event callbacks. */
    this->evt_callbacks = OTF2_GlobalEvtReaderCallbacks_New();
    OTF2_GlobalEvtReaderCallbacks_SetEnterCallback(this->evt_callbacks, otf2_enter);
    OTF2_GlobalEvtReaderCallbacks_SetLeaveCallback(this->evt_callbacks, otf2_leave);

    /* Get global event reader. */
    OTF2_GlobalEvtReader* glob_evt_reader = OTF2_Reader_GetGlobalEvtReader(this->reader);

    /* Register the above defined callbacks to the global event reader. */
    OTF2_Reader_RegisterGlobalEvtCallbacks(this->reader, glob_evt_reader, this->evt_callbacks, this);
}

void OTF2Reader::Close()
{
    if (this->reader)
    {
        this->num_locations = 0;
        this->locations.clear();
        this->names.clear();
        this->region_names.clear();
        this->group.clear();
        OTF2_Reader_Close(this->reader);
        this->reader = nullptr;
    }
}

void OTF2Reader::AddRegion(OTF2_RegionRef region, OTF2_StringRef name)
{
    this->region_names[region] = name;
}

std::string OTF2Reader::GetRegionName(OTF2_RegionRef region) const
{
    return this->GetName(this->region_names.at(region));
}

OTF2_StringRef OTF2Reader::GetRegionNameRef(OTF2_RegionRef region) const
{
    return this->region_names.at(region);
}

void OTF2Reader::AddLocation(OTF2_LocationRef location, OTF2_StringRef name)
{
    this->locations.push_back(location);
    this->location_names[location] = name;
}

int OTF2Reader::GetNumberOfLocations() const
{
    return this->locations.size();
}

OTF2_LocationRef OTF2Reader::GetLocation(int index) const
{
    return this->locations[index];
}

std::string OTF2Reader::GetLocationName(OTF2_LocationRef location) const
{
    return this->names[this->location_names.at(location)];
}


OTF2_StringRef OTF2Reader::GetLocationNameRef(OTF2_LocationRef location) const
{
    return this->location_names.at(location);
}

void OTF2Reader::AddName(const char* name)
{
    this->names.push_back(name);
}

std::string OTF2Reader::GetName(OTF2_StringRef index) const
{
    return this->names[index];
}

size_t OTF2Reader::GetNumberOfNames() const
{
    return this->names.size();
}

void OTF2Reader::SetGlobalOffset(size_t _global_offset)
{
    this->global_offset = _global_offset;
}

size_t OTF2Reader::GetGlobalOffset() const
{
    return this->global_offset;
}

size_t OTF2Reader::GetTimeInNanoSeconds(size_t global_time) const
{
    return global_time - this->global_offset;
}

double OTF2Reader::GetTimeInSeconds(size_t global_time) const
{
    return double(global_time - this->global_offset) / 1e9;
}

TreeLocationGroup& OTF2Reader::GetLocationGroup()
{
    return this->group;
}

void OTF2Reader::SetLocationGroupId(OTF2_LocationGroupRef id)
{
    this->group.set_id(id);
}

void OTF2Reader::ReadAllEvents()
{
    /* Read until events are all read. */
    OTF2_GlobalEvtReader* glob_evt_reader = OTF2_Reader_GetGlobalEvtReader(this->reader);
    const size_t events_to_read = std::numeric_limits<size_t>::max();
    size_t events_read = events_to_read;
    std::cout << "Reading Global Events" << std::endl;
    while (events_read == events_to_read)
    {
        OTF2_Reader_ReadGlobalEvents(this->reader, glob_evt_reader, events_to_read, &events_read);
        std::cout << "\tevents read: " << events_read << std::endl;
    }
}