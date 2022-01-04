#pragma once

#include <otf2/OTF2_Definitions.h>
#include <string>

std::string getFileModeString(OTF2_FileMode FileMode);
std::string getCompressionString(OTF2_Compression Compression);
std::string getFlushTypeString(OTF2_FlushType FlushType);
std::string getHintString(OTF2_Hint Hint);
std::string getBooleanString(OTF2_Boolean Boolean);
std::string getFileTypeString(OTF2_FileType FileType);
std::string getFileSubstrateString(OTF2_FileSubstrate FileSubstrate);
std::string getMappingTypeString(OTF2_MappingType MappingType);
std::string getTypeString(OTF2_Type Type);
std::string getParadigmString(OTF2_Paradigm Paradigm);
std::string getParadigmClassString(OTF2_ParadigmClass ParadigmClass);
std::string getParadigmPropertyString(OTF2_ParadigmProperty ParadigmProperty);
std::string getThumbnailTypeString(OTF2_ThumbnailType ThumbnailType);

std::string getSystemTreeDomainString(OTF2_SystemTreeDomain SystemTreeDomain);
std::string getLocationGroupTypeString(OTF2_LocationGroupType LocationGroupType);
std::string getLocationTypeString(OTF2_LocationType LocationType);
std::string getRegionRoleString(OTF2_RegionRole RegionRole);
std::string getRegionFlagString(OTF2_RegionFlag RegionFlag);
std::string getGroupTypeString(OTF2_GroupType GroupType);
std::string getGroupFlagString(OTF2_GroupFlag GroupFlag);
std::string getBaseString(OTF2_Base Base);
std::string getMetricOccurrenceString(OTF2_MetricOccurrence MetricOccurrence);
std::string getMetricTypeString(OTF2_MetricType MetricType);
std::string getMetricValuePropertyString(OTF2_MetricValueProperty MetricValueProperty);
std::string getMetricTimingString(OTF2_MetricTiming MetricTiming);
std::string getMetricModeString(OTF2_MetricMode MetricMode);
std::string getMetricScopeString(OTF2_MetricScope MetricScope);
std::string getRecorderKindString(OTF2_RecorderKind RecorderKind);
std::string getParameterTypeString(OTF2_ParameterType ParameterType);
std::string getCartPeriodicityString(OTF2_CartPeriodicity CartPeriodicity);
std::string getInterruptGeneratorModeString(OTF2_InterruptGeneratorMode InterruptGeneratorMode);
std::string getIoParadigmClassString(OTF2_IoParadigmClass IoParadigmClass);
std::string getIoParadigmFlagString(OTF2_IoParadigmFlag IoParadigmFlag);
std::string getIoParadigmPropertyString(OTF2_IoParadigmProperty IoParadigmProperty);
std::string getIoHandleFlagString(OTF2_IoHandleFlag IoHandleFlag);
std::string getIoAccessModeString(OTF2_IoAccessMode IoAccessMode);
std::string getIoStatusFlagString(OTF2_IoStatusFlag IoStatusFlag);