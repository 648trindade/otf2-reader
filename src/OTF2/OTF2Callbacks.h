#pragma once

#include <otf2/otf2.h>

OTF2_CallbackCode otf2_enter(
    OTF2_LocationRef locationID,
    OTF2_TimeStamp time,
    void* userData,
    OTF2_AttributeList* attributes,
    OTF2_RegionRef regionID);

OTF2_CallbackCode otf2_leave(
    OTF2_LocationRef locationID,
    OTF2_TimeStamp time,
    void* userData,
    OTF2_AttributeList* attributes,
    OTF2_RegionRef regionID);

OTF2_CallbackCode otf2_unknown(
    OTF2_LocationRef locationID, OTF2_TimeStamp time, void* userData, OTF2_AttributeList* attributes);

OTF2_CallbackCode otf2_global_def_clock_properties(
    void* userData, uint64_t timerResolution, uint64_t globalOffset, uint64_t traceLength);

OTF2_CallbackCode otf2_global_def_string(void* userData, OTF2_StringRef self, const char* string);

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
    uint32_t endLineNumber);

OTF2_CallbackCode otf2_global_def_location_group(
    void* userData,
    OTF2_LocationGroupRef self,
    OTF2_StringRef name,
    OTF2_LocationGroupType locationGroupType,
    OTF2_SystemTreeNodeRef systemTreeParent);

OTF2_CallbackCode otf2_global_def_location_group_hostfile(
    void* userData,
    OTF2_LocationGroupRef self,
    OTF2_StringRef name,
    OTF2_LocationGroupType locationGroupType,
    OTF2_SystemTreeNodeRef systemTreeParent);

OTF2_CallbackCode otf2_global_def_location_group_flat(
    void* userData,
    OTF2_LocationGroupRef self,
    OTF2_StringRef name,
    OTF2_LocationGroupType locationGroupType,
    OTF2_SystemTreeNodeRef systemTreeParen);

OTF2_CallbackCode otf2_global_def_location(
    void* userData,
    OTF2_LocationRef self,
    OTF2_StringRef name,
    OTF2_LocationType locationType,
    uint64_t numberOfEvents,
    OTF2_LocationGroupRef locationGroup);

OTF2_CallbackCode otf2_global_def_system_tree_node(
    void* userData,
    OTF2_SystemTreeNodeRef self,
    OTF2_StringRef name,
    OTF2_StringRef className,
    OTF2_SystemTreeNodeRef parent);

OTF2_CallbackCode otf2_global_def_system_tree_node_hostfile(
    void* userData,
    OTF2_SystemTreeNodeRef self,
    OTF2_StringRef name,
    OTF2_StringRef className,
    OTF2_SystemTreeNodeRef parent);

OTF2_CallbackCode otf2_global_def_system_tree_node_property(
    void* userData,
    unsigned int systemTreeNode,
    unsigned int ignore,
    unsigned char name,
    union OTF2_AttributeValue_union value);

OTF2_CallbackCode otf2_global_def_system_tree_node_domain(
    void* userData, OTF2_SystemTreeNodeRef systemTreeNode, OTF2_SystemTreeDomain systemTreeDomain);