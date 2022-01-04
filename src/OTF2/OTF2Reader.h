#pragma once

#include <map>
#include <string>
#include <vector>

#include "OTF2CallTree.hpp"

#include <otf2/otf2.h>

class OTF2Reader
{
public:
    OTF2Reader();
    OTF2Reader(const std::string& otf2_filename);
    ~OTF2Reader();

    void Open(const std::string& otf2_filename);
    void Close();

    void ReadAllEvents();

    void AddName(const char* name);
    std::string GetName(OTF2_StringRef index) const;
    size_t GetNumberOfNames() const;

    void AddLocation(OTF2_LocationRef location, OTF2_StringRef name);
    int GetNumberOfLocations() const;
    OTF2_LocationRef GetLocation(int index) const;
    std::string GetLocationName(OTF2_LocationRef location) const;
    OTF2_StringRef GetLocationNameRef(OTF2_LocationRef location) const;

    void AddRegion(OTF2_RegionRef region, OTF2_StringRef name);
    std::string GetRegionName(OTF2_RegionRef region) const;
    OTF2_StringRef GetRegionNameRef(OTF2_RegionRef region) const;

    void SetGlobalOffset(size_t _global_offset);
    size_t GetGlobalOffset() const;
    size_t GetTimeInNanoSeconds(size_t global_time) const;
    double GetTimeInSeconds(size_t global_time) const;

    TreeLocationGroup& GetLocationGroup();
    void SetLocationGroupId(OTF2_LocationGroupRef id);

private:
    OTF2_Reader* reader;
    OTF2_GlobalDefReaderCallbacks* def_callbacks;
    OTF2_GlobalEvtReaderCallbacks* evt_callbacks;
    size_t num_locations;
    size_t global_offset;
    std::vector<OTF2_LocationRef> locations;
    std::vector<const char*> names;
    std::map<OTF2_RegionRef, OTF2_StringRef> region_names;
    std::map<OTF2_LocationRef, OTF2_StringRef> location_names;
    TreeLocationGroup group;
};