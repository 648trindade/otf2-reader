#include "OTF2Callbacks.h"
#include "OTF2Reader.h"
#include "OTF2EnumToStrings.hpp"

#include <iostream>

// Region Enter && Leave ==============================================================================================

OTF2_CallbackCode otf2_enter(
    OTF2_LocationRef locationID,
    OTF2_TimeStamp time,
    void* userData,
    OTF2_AttributeList* attributes,
    OTF2_RegionRef regionID)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
    TreeLocation& location = reader->GetLocationGroup().get_location(locationID);
    TreeRegion* cursor = location.get_cursor();
    TreeRegion* child = &(cursor->add_child(reader->GetRegionNameRef(regionID), time));
    location.set_cursor(child);

#if VERBOSE
    std::cout << "@@ Enter @@ " << reader->GetLocationName(locationID) << " " << reader->GetRegionName(regionID) << " "
              << reader->GetTimeInSeconds(time) << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_leave(
    OTF2_LocationRef locationID,
    OTF2_TimeStamp time,
    void* userData,
    OTF2_AttributeList* attributes,
    OTF2_RegionRef regionID)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
    TreeLocation& location = reader->GetLocationGroup().get_location(locationID);
    TreeRegion* cursor = location.get_cursor();
    cursor->set_end(time);
    TreeRegion* parent = cursor->get_parent();
    location.set_cursor(parent);

#if VERBOSE
    std::cout << "@@ Leave @@ " << reader->GetRegionName(regionID) << " " << reader->GetTimeInSeconds(time)
              << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_unknown(
    OTF2_LocationRef locationID, OTF2_TimeStamp time, void* userData, OTF2_AttributeList* attributes)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
#if VERBOSE
    std::cout << __FUNCTION__ << " " << reader->GetTimeInSeconds(time) << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

// Clock & Names ======================================================================================================

OTF2_CallbackCode otf2_global_def_clock_properties(
    void* userData, uint64_t timerResolution, uint64_t globalOffset, uint64_t traceLength)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
    reader->SetGlobalOffset(globalOffset);
#if VERBOSE
    std::cout << "Global Offset: " << globalOffset << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_global_def_string(void* userData, OTF2_StringRef self, const char* string)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
    reader->AddName(string);
#if VERBOSE
    std::cout << "## String ## " << self << " " << string << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_global_def_region(
    void* userData,
    OTF2_RegionRef self,
    OTF2_StringRef name,
    OTF2_StringRef canonicalName,
    OTF2_StringRef description,
    OTF2_RegionRole regionRole,
    OTF2_Paradigm paradigm,
    OTF2_RegionFlag regionFlags,
    OTF2_StringRef sourceFile,
    uint32_t beginLineNumber,
    uint32_t endLineNumber)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
    reader->AddRegion(self, name);
    std::cout << "## Region ## " << self << std::endl;
    std::cout << "\tName: " << reader->GetRegionName(self) << std::endl;
    std::cout << "\tCanonical Name: " << reader->GetName(canonicalName) << std::endl;
    std::cout << "\tDescription: " << reader->GetName(description) << std::endl;
    std::cout << "\tRegion Role: " << getRegionRoleString(regionRole) << std::endl;
    std::cout << "\tParadigm: " << getParadigmString(paradigm) << std::endl;
    std::cout << "\tRegion Flags: " << getRegionFlagString(regionFlags) << std::endl;
    if (sourceFile <= reader->GetNumberOfNames())
        std::cout << "\tSource File: " << reader->GetName(sourceFile) << std::endl;
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_global_def_location_group(
    void* userData,
    OTF2_LocationGroupRef self,
    OTF2_StringRef name,
    OTF2_LocationGroupType locationGroupType,
    OTF2_SystemTreeNodeRef systemTreeParent)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
#if VERBOSE
    std::cout << "<< Location Group >> " << reader->GetName(name) << std::endl;
#endif
    reader->GetLocationGroup().set_id(self);
    reader->GetLocationGroup().set_name(name);
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_global_def_location_group_hostfile(
    void* userData,
    OTF2_LocationGroupRef self,
    OTF2_StringRef name,
    OTF2_LocationGroupType locationGroupType,
    OTF2_SystemTreeNodeRef systemTreeParent)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
#if VERBOSE
    std::cout << __FUNCTION__ << " " << reader->GetName(name) << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_global_def_location_group_flat(
    void* userData,
    OTF2_LocationGroupRef self,
    OTF2_StringRef name,
    OTF2_LocationGroupType locationGroupType,
    OTF2_SystemTreeNodeRef systemTreeParent)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
#if VERBOSE
    std::cout << "<< Location Group Flat >>  " << reader->GetName(name) << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_global_def_location(
    void* userData,
    OTF2_LocationRef self,
    OTF2_StringRef name,
    OTF2_LocationType locationType,
    uint64_t numberOfEvents,
    OTF2_LocationGroupRef locationGroup)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
    reader->AddLocation(self, name);
    reader->GetLocationGroup().add_child(self, name, reader->GetGlobalOffset());
#if VERBOSE
    std::cout << "<< Location >> " << reader->GetName(name) << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

// System Tree ==============================================================================================

OTF2_CallbackCode otf2_global_def_system_tree_node(
    void* userData,
    OTF2_SystemTreeNodeRef self,
    OTF2_StringRef name,
    OTF2_StringRef className,
    OTF2_SystemTreeNodeRef parent)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
#if VERBOSE
    std::cout << "[[ Tree Node ]] " << reader->GetName(name) << " Class " << reader->GetName(className) << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_global_def_system_tree_node_hostfile(
    void* userData,
    OTF2_SystemTreeNodeRef self,
    OTF2_StringRef name,
    OTF2_StringRef className,
    OTF2_SystemTreeNodeRef parent)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
#if VERBOSE
    std::cout << "[[ Tree Node ]][[ Hostfile ]] " << reader->GetName(name) << " Class " << reader->GetName(className)
              << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_global_def_system_tree_node_property(
    void* userData,
    unsigned int systemTreeRegion,
    unsigned int ignore,
    unsigned char name,
    union OTF2_AttributeValue_union value)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
#if VERBOSE
    std::cout << "[[ Tree Node ]][[ Property ]] " << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}

OTF2_CallbackCode otf2_global_def_system_tree_node_domain(
    void* userData, OTF2_SystemTreeNodeRef systemTreeRegion, OTF2_SystemTreeDomain systemTreeDomain)
{
    OTF2Reader* reader = (OTF2Reader*) userData;
#if VERBOSE
    std::cout << "[[ Tree Node ]][[ Domain ]] " << std::endl;
#endif
    return OTF2_CALLBACK_SUCCESS;
}
