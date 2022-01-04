#include "OTF2EnumToStrings.hpp"

#include <stdexcept>

#define CASE_STRING(V) \
    case V:            \
        return #V

std::string getFileModeString(OTF2_FileMode FileMode)
{
    switch (OTF2_FileMode_enum(FileMode))
    {
        CASE_STRING(OTF2_FILEMODE_WRITE);
        CASE_STRING(OTF2_FILEMODE_READ);
        CASE_STRING(OTF2_FILEMODE_MODIFY);
        default: throw std::runtime_error("unknown");
    }
}

std::string getCompressionString(OTF2_Compression Compression)
{
    switch (OTF2_Compression_enum(Compression))
    {
        CASE_STRING(OTF2_COMPRESSION_UNDEFINED);
        CASE_STRING(OTF2_COMPRESSION_NONE);
        CASE_STRING(OTF2_COMPRESSION_ZLIB);
        default: throw std::runtime_error("unknown");
    }
}

std::string getFlushTypeString(OTF2_FlushType FlushType)
{
    switch (OTF2_FlushType_enum(FlushType))
    {
        CASE_STRING(OTF2_NO_FLUSH);
        CASE_STRING(OTF2_FLUSH);
        default: throw std::runtime_error("unknown");
    }
}

std::string getHintString(OTF2_Hint Hint)
{
    switch (OTF2_Hint_enum(Hint))
    {
        CASE_STRING(OTF2_HINT_GLOBAL_READER);
        default: throw std::runtime_error("unknown");
    }
}

std::string getBooleanString(OTF2_Boolean Boolean)
{
    switch (OTF2_Boolean_enum(Boolean))
    {
        CASE_STRING(OTF2_FALSE);
        CASE_STRING(OTF2_TRUE);
        default: throw std::runtime_error("unknown");
    }
}

std::string getFileTypeString(OTF2_FileType FileType)
{
    switch (OTF2_FileType_enum(FileType))
    {
        CASE_STRING(OTF2_FILETYPE_ANCHOR);
        CASE_STRING(OTF2_FILETYPE_GLOBAL_DEFS);
        CASE_STRING(OTF2_FILETYPE_LOCAL_DEFS);
        CASE_STRING(OTF2_FILETYPE_EVENTS);
        CASE_STRING(OTF2_FILETYPE_SNAPSHOTS);
        CASE_STRING(OTF2_FILETYPE_THUMBNAIL);
        CASE_STRING(OTF2_FILETYPE_MARKER);
        CASE_STRING(OTF2_FILETYPE_SIONRANKMAP);
        default: throw std::runtime_error("unknown");
    }
}

std::string getFileSubstrateString(OTF2_FileSubstrate FileSubstrate)
{
    switch (OTF2_FileSubstrate_enum(FileSubstrate))
    {
        CASE_STRING(OTF2_SUBSTRATE_UNDEFINED);
        CASE_STRING(OTF2_SUBSTRATE_POSIX);
        CASE_STRING(OTF2_SUBSTRATE_SION);
        CASE_STRING(OTF2_SUBSTRATE_NONE);
        default: throw std::runtime_error("unknown");
    }
}

std::string getMappingTypeString(OTF2_MappingType MappingType)
{
    switch (OTF2_MappingType_enum(MappingType))
    {
        CASE_STRING(OTF2_MAPPING_STRING);
        CASE_STRING(OTF2_MAPPING_ATTRIBUTE);
        CASE_STRING(OTF2_MAPPING_LOCATION);
        CASE_STRING(OTF2_MAPPING_REGION);
        CASE_STRING(OTF2_MAPPING_GROUP);
        CASE_STRING(OTF2_MAPPING_METRIC);
        CASE_STRING(OTF2_MAPPING_COMM);
        CASE_STRING(OTF2_MAPPING_PARAMETER);
        CASE_STRING(OTF2_MAPPING_RMA_WIN);
        CASE_STRING(OTF2_MAPPING_SOURCE_CODE_LOCATION);
        CASE_STRING(OTF2_MAPPING_CALLING_CONTEXT);
        CASE_STRING(OTF2_MAPPING_INTERRUPT_GENERATOR);
        CASE_STRING(OTF2_MAPPING_IO_FILE);
        CASE_STRING(OTF2_MAPPING_IO_HANDLE);
        CASE_STRING(OTF2_MAPPING_MAX);
        default: throw std::runtime_error("unknown");
    }
}

std::string getTypeString(OTF2_Type Type)
{
    switch (OTF2_Type_enum(Type))
    {
        CASE_STRING(OTF2_TYPE_NONE);
        CASE_STRING(OTF2_TYPE_UINT8);
        CASE_STRING(OTF2_TYPE_UINT16);
        CASE_STRING(OTF2_TYPE_UINT32);
        CASE_STRING(OTF2_TYPE_UINT64);
        CASE_STRING(OTF2_TYPE_INT8);
        CASE_STRING(OTF2_TYPE_INT16);
        CASE_STRING(OTF2_TYPE_INT32);
        CASE_STRING(OTF2_TYPE_INT64);
        CASE_STRING(OTF2_TYPE_FLOAT);
        CASE_STRING(OTF2_TYPE_DOUBLE);
        CASE_STRING(OTF2_TYPE_STRING);
        CASE_STRING(OTF2_TYPE_ATTRIBUTE);
        CASE_STRING(OTF2_TYPE_LOCATION);
        CASE_STRING(OTF2_TYPE_REGION);
        CASE_STRING(OTF2_TYPE_GROUP);
        CASE_STRING(OTF2_TYPE_METRIC);
        CASE_STRING(OTF2_TYPE_COMM);
        CASE_STRING(OTF2_TYPE_PARAMETER);
        CASE_STRING(OTF2_TYPE_RMA_WIN);
        CASE_STRING(OTF2_TYPE_SOURCE_CODE_LOCATION);
        CASE_STRING(OTF2_TYPE_CALLING_CONTEXT);
        CASE_STRING(OTF2_TYPE_INTERRUPT_GENERATOR);
        CASE_STRING(OTF2_TYPE_IO_FILE);
        CASE_STRING(OTF2_TYPE_IO_HANDLE);
        default: throw std::runtime_error("unknown");
    }
}

std::string getParadigmString(OTF2_Paradigm Paradigm)
{
    switch (OTF2_Paradigm_enum(Paradigm))
    {
        CASE_STRING(OTF2_PARADIGM_UNKNOWN);
        CASE_STRING(OTF2_PARADIGM_USER);
        CASE_STRING(OTF2_PARADIGM_COMPILER);
        CASE_STRING(OTF2_PARADIGM_OPENMP);
        CASE_STRING(OTF2_PARADIGM_MPI);
        CASE_STRING(OTF2_PARADIGM_CUDA);
        CASE_STRING(OTF2_PARADIGM_MEASUREMENT_SYSTEM);
        CASE_STRING(OTF2_PARADIGM_PTHREAD);
        CASE_STRING(OTF2_PARADIGM_HMPP);
        CASE_STRING(OTF2_PARADIGM_OMPSS);
        CASE_STRING(OTF2_PARADIGM_HARDWARE);
        CASE_STRING(OTF2_PARADIGM_GASPI);
        CASE_STRING(OTF2_PARADIGM_UPC);
        CASE_STRING(OTF2_PARADIGM_SHMEM);
        CASE_STRING(OTF2_PARADIGM_WINTHREAD);
        CASE_STRING(OTF2_PARADIGM_QTTHREAD);
        CASE_STRING(OTF2_PARADIGM_ACETHREAD);
        CASE_STRING(OTF2_PARADIGM_TBBTHREAD);
        CASE_STRING(OTF2_PARADIGM_OPENACC);
        CASE_STRING(OTF2_PARADIGM_OPENCL);
        CASE_STRING(OTF2_PARADIGM_MTAPI);
        CASE_STRING(OTF2_PARADIGM_SAMPLING);
        CASE_STRING(OTF2_PARADIGM_NONE);
        CASE_STRING(OTF2_PARADIGM_HIP);
        CASE_STRING(OTF2_PARADIGM_KOKKOS);
        default: throw std::runtime_error("unknown");
    }
}

std::string getParadigmClassString(OTF2_ParadigmClass ParadigmClass)
{
    switch (OTF2_ParadigmClass_enum(ParadigmClass))
    {
        CASE_STRING(OTF2_PARADIGM_CLASS_PROCESS);
        CASE_STRING(OTF2_PARADIGM_CLASS_THREAD_FORK_JOIN);
        CASE_STRING(OTF2_PARADIGM_CLASS_THREAD_CREATE_WAIT);
        CASE_STRING(OTF2_PARADIGM_CLASS_ACCELERATOR);
        default: throw std::runtime_error("unknown");
    }
}

std::string getParadigmPropertyString(OTF2_ParadigmProperty ParadigmProperty)
{
    switch (OTF2_ParadigmProperty_enum(ParadigmProperty))
    {
        CASE_STRING(OTF2_PARADIGM_PROPERTY_COMM_NAME_TEMPLATE);
        CASE_STRING(OTF2_PARADIGM_PROPERTY_RMA_WIN_NAME_TEMPLATE);
        CASE_STRING(OTF2_PARADIGM_PROPERTY_RMA_ONLY);
        default: throw std::runtime_error("unknown");
    }
}

std::string getThumbnailTypeString(OTF2_ThumbnailType ThumbnailType)
{
    switch (OTF2_ThumbnailType_enum(ThumbnailType))
    {
        CASE_STRING(OTF2_THUMBNAIL_TYPE_REGION);
        CASE_STRING(OTF2_THUMBNAIL_TYPE_METRIC);
        CASE_STRING(OTF2_THUMBNAIL_TYPE_ATTRIBUTES);
        default: throw std::runtime_error("unknown");
    }
}

std::string getSystemTreeDomainString(OTF2_SystemTreeDomain SystemTreeDomain)
{
    switch (OTF2_SystemTreeDomain_enum(SystemTreeDomain))
    {
        CASE_STRING(OTF2_SYSTEM_TREE_DOMAIN_MACHINE);
        CASE_STRING(OTF2_SYSTEM_TREE_DOMAIN_SHARED_MEMORY);
        CASE_STRING(OTF2_SYSTEM_TREE_DOMAIN_NUMA);
        CASE_STRING(OTF2_SYSTEM_TREE_DOMAIN_SOCKET);
        CASE_STRING(OTF2_SYSTEM_TREE_DOMAIN_CACHE);
        CASE_STRING(OTF2_SYSTEM_TREE_DOMAIN_CORE);
        CASE_STRING(OTF2_SYSTEM_TREE_DOMAIN_PU);
        default: throw std::runtime_error("unknown");
    }
}

std::string getLocationGroupTypeString(OTF2_LocationGroupType LocationGroupType)
{
    switch (OTF2_LocationGroupType_enum(LocationGroupType))
    {
        CASE_STRING(OTF2_LOCATION_GROUP_TYPE_UNKNOWN);
        CASE_STRING(OTF2_LOCATION_GROUP_TYPE_PROCESS);
        default: throw std::runtime_error("unknown");
    }
}

std::string getLocationTypeString(OTF2_LocationType LocationType)
{
    switch (OTF2_LocationType_enum(LocationType))
    {
        CASE_STRING(OTF2_LOCATION_TYPE_UNKNOWN);
        CASE_STRING(OTF2_LOCATION_TYPE_CPU_THREAD);
        CASE_STRING(OTF2_LOCATION_TYPE_GPU);
        CASE_STRING(OTF2_LOCATION_TYPE_METRIC);
        default: throw std::runtime_error("unknown");
    }
}

std::string getRegionRoleString(OTF2_RegionRole RegionRole)
{
    switch (OTF2_RegionRole_enum(RegionRole))
    {
        CASE_STRING(OTF2_REGION_ROLE_UNKNOWN);
        CASE_STRING(OTF2_REGION_ROLE_FUNCTION);
        CASE_STRING(OTF2_REGION_ROLE_WRAPPER);
        CASE_STRING(OTF2_REGION_ROLE_LOOP);
        CASE_STRING(OTF2_REGION_ROLE_CODE);
        CASE_STRING(OTF2_REGION_ROLE_PARALLEL);
        CASE_STRING(OTF2_REGION_ROLE_SECTIONS);
        CASE_STRING(OTF2_REGION_ROLE_SECTION);
        CASE_STRING(OTF2_REGION_ROLE_WORKSHARE);
        CASE_STRING(OTF2_REGION_ROLE_SINGLE);
        CASE_STRING(OTF2_REGION_ROLE_SINGLE_SBLOCK);
        CASE_STRING(OTF2_REGION_ROLE_MASTER);
        CASE_STRING(OTF2_REGION_ROLE_CRITICAL);
        CASE_STRING(OTF2_REGION_ROLE_CRITICAL_SBLOCK);
        CASE_STRING(OTF2_REGION_ROLE_ATOMIC);
        CASE_STRING(OTF2_REGION_ROLE_BARRIER);
        CASE_STRING(OTF2_REGION_ROLE_IMPLICIT_BARRIER);
        CASE_STRING(OTF2_REGION_ROLE_FLUSH);
        CASE_STRING(OTF2_REGION_ROLE_ORDERED);
        CASE_STRING(OTF2_REGION_ROLE_ORDERED_SBLOCK);
        CASE_STRING(OTF2_REGION_ROLE_TASK);
        CASE_STRING(OTF2_REGION_ROLE_TASK_CREATE);
        CASE_STRING(OTF2_REGION_ROLE_TASK_WAIT);
        CASE_STRING(OTF2_REGION_ROLE_COLL_ONE2ALL);
        CASE_STRING(OTF2_REGION_ROLE_COLL_ALL2ONE);
        CASE_STRING(OTF2_REGION_ROLE_COLL_ALL2ALL);
        CASE_STRING(OTF2_REGION_ROLE_COLL_OTHER);
        CASE_STRING(OTF2_REGION_ROLE_FILE_IO);
        CASE_STRING(OTF2_REGION_ROLE_POINT2POINT);
        CASE_STRING(OTF2_REGION_ROLE_RMA);
        CASE_STRING(OTF2_REGION_ROLE_DATA_TRANSFER);
        CASE_STRING(OTF2_REGION_ROLE_ARTIFICIAL);
        CASE_STRING(OTF2_REGION_ROLE_THREAD_CREATE);
        CASE_STRING(OTF2_REGION_ROLE_THREAD_WAIT);
        CASE_STRING(OTF2_REGION_ROLE_TASK_UNTIED);
        CASE_STRING(OTF2_REGION_ROLE_ALLOCATE);
        CASE_STRING(OTF2_REGION_ROLE_DEALLOCATE);
        CASE_STRING(OTF2_REGION_ROLE_REALLOCATE);
        CASE_STRING(OTF2_REGION_ROLE_FILE_IO_METADATA);
        default: throw std::runtime_error("unknown");
    }
}

std::string getRegionFlagString(OTF2_RegionFlag RegionFlag)
{
    switch (OTF2_RegionFlag_enum(RegionFlag))
    {
        CASE_STRING(OTF2_REGION_FLAG_NONE);
        CASE_STRING(OTF2_REGION_FLAG_DYNAMIC);
        CASE_STRING(OTF2_REGION_FLAG_PHASE);
        default: throw std::runtime_error("unknown");
    }
}

std::string getGroupTypeString(OTF2_GroupType GroupType)
{
    switch (OTF2_GroupType_enum(GroupType))
    {
        CASE_STRING(OTF2_GROUP_TYPE_UNKNOWN);
        CASE_STRING(OTF2_GROUP_TYPE_LOCATIONS);
        CASE_STRING(OTF2_GROUP_TYPE_REGIONS);
        CASE_STRING(OTF2_GROUP_TYPE_METRIC);
        CASE_STRING(OTF2_GROUP_TYPE_COMM_LOCATIONS);
        CASE_STRING(OTF2_GROUP_TYPE_COMM_GROUP);
        CASE_STRING(OTF2_GROUP_TYPE_COMM_SELF);
        default: throw std::runtime_error("unknown");
    }
}

std::string getGroupFlagString(OTF2_GroupFlag GroupFlag)
{
    switch (OTF2_GroupFlag_enum(GroupFlag))
    {
        CASE_STRING(OTF2_GROUP_FLAG_NONE);
        CASE_STRING(OTF2_GROUP_FLAG_GLOBAL_MEMBERS);
        default: throw std::runtime_error("unknown");
    }
}

std::string getBaseString(OTF2_Base Base)
{
    switch (OTF2_Base_enum(Base))
    {
        CASE_STRING(OTF2_BASE_BINARY);
        CASE_STRING(OTF2_BASE_DECIMAL);
        default: throw std::runtime_error("unknown");
    }
}

std::string getMetricOccurrenceString(OTF2_MetricOccurrence MetricOccurrence)
{
    switch (OTF2_MetricOccurrence_enum(MetricOccurrence))
    {
        CASE_STRING(OTF2_METRIC_SYNCHRONOUS_STRICT);
        CASE_STRING(OTF2_METRIC_SYNCHRONOUS);
        CASE_STRING(OTF2_METRIC_ASYNCHRONOUS);
        default: throw std::runtime_error("unknown");
    }
}

std::string getMetricTypeString(OTF2_MetricType MetricType)
{
    switch (OTF2_MetricType_enum(MetricType))
    {
        CASE_STRING(OTF2_METRIC_TYPE_OTHER);
        CASE_STRING(OTF2_METRIC_TYPE_PAPI);
        CASE_STRING(OTF2_METRIC_TYPE_RUSAGE);
        CASE_STRING(OTF2_METRIC_TYPE_USER);
        default: throw std::runtime_error("unknown");
    }
}

std::string getMetricValuePropertyString(OTF2_MetricValueProperty MetricValueProperty)
{
    switch (OTF2_MetricValueProperty_enum(MetricValueProperty))
    {
        CASE_STRING(OTF2_METRIC_VALUE_ACCUMULATED);
        CASE_STRING(OTF2_METRIC_VALUE_ABSOLUTE);
        CASE_STRING(OTF2_METRIC_VALUE_RELATIVE);
        CASE_STRING(OTF2_METRIC_VALUE_MASK);
        default: throw std::runtime_error("unknown");
    }
}

std::string getMetricTimingString(OTF2_MetricTiming MetricTiming)
{
    switch (OTF2_MetricTiming_enum(MetricTiming))
    {
        CASE_STRING(OTF2_METRIC_TIMING_START);
        CASE_STRING(OTF2_METRIC_TIMING_POINT);
        CASE_STRING(OTF2_METRIC_TIMING_LAST);
        CASE_STRING(OTF2_METRIC_TIMING_NEXT);
        CASE_STRING(OTF2_METRIC_TIMING_MASK);
        default: throw std::runtime_error("unknown");
    }
}

std::string getMetricModeString(OTF2_MetricMode MetricMode)
{
    switch (OTF2_MetricMode_enum(MetricMode))
    {
        CASE_STRING(OTF2_METRIC_ACCUMULATED_START);
        CASE_STRING(OTF2_METRIC_ACCUMULATED_POINT);
        CASE_STRING(OTF2_METRIC_ACCUMULATED_LAST);
        CASE_STRING(OTF2_METRIC_ACCUMULATED_NEXT);
        CASE_STRING(OTF2_METRIC_ABSOLUTE_POINT);
        CASE_STRING(OTF2_METRIC_ABSOLUTE_LAST);
        CASE_STRING(OTF2_METRIC_ABSOLUTE_NEXT);
        CASE_STRING(OTF2_METRIC_RELATIVE_POINT);
        CASE_STRING(OTF2_METRIC_RELATIVE_LAST);
        CASE_STRING(OTF2_METRIC_RELATIVE_NEXT);
        default: throw std::runtime_error("unknown");
    }
}

std::string getMetricScopeString(OTF2_MetricScope MetricScope)
{
    switch (OTF2_MetricScope_enum(MetricScope))
    {
        CASE_STRING(OTF2_SCOPE_LOCATION);
        CASE_STRING(OTF2_SCOPE_LOCATION_GROUP);
        CASE_STRING(OTF2_SCOPE_SYSTEM_TREE_NODE);
        CASE_STRING(OTF2_SCOPE_GROUP);
        default: throw std::runtime_error("unknown");
    }
}

std::string getRecorderKindString(OTF2_RecorderKind RecorderKind)
{
    switch (OTF2_RecorderKind_enum(RecorderKind))
    {
        CASE_STRING(OTF2_RECORDER_KIND_UNKNOWN);
        CASE_STRING(OTF2_RECORDER_KIND_ABSTRACT);
        CASE_STRING(OTF2_RECORDER_KIND_CPU);
        CASE_STRING(OTF2_RECORDER_KIND_GPU);
        default: throw std::runtime_error("unknown");
    }
}

std::string getParameterTypeString(OTF2_ParameterType ParameterType)
{
    switch (OTF2_ParameterType_enum(ParameterType))
    {
        CASE_STRING(OTF2_PARAMETER_TYPE_STRING);
        CASE_STRING(OTF2_PARAMETER_TYPE_INT64);
        CASE_STRING(OTF2_PARAMETER_TYPE_UINT64);
        default: throw std::runtime_error("unknown");
    }
}

std::string getCartPeriodicityString(OTF2_CartPeriodicity CartPeriodicity)
{
    switch (OTF2_CartPeriodicity_enum(CartPeriodicity))
    {
        CASE_STRING(OTF2_CART_PERIODIC_FALSE);
        CASE_STRING(OTF2_CART_PERIODIC_TRUE);
        default: throw std::runtime_error("unknown");
    }
}

std::string getInterruptGeneratorModeString(OTF2_InterruptGeneratorMode InterruptGeneratorMode)
{
    switch (OTF2_InterruptGeneratorMode_enum(InterruptGeneratorMode))
    {
        CASE_STRING(OTF2_INTERRUPT_GENERATOR_MODE_TIME);
        CASE_STRING(OTF2_INTERRUPT_GENERATOR_MODE_COUNT);
        default: throw std::runtime_error("unknown");
    }
}

std::string getIoParadigmClassString(OTF2_IoParadigmClass IoParadigmClass)
{
    switch (OTF2_IoParadigmClass_enum(IoParadigmClass))
    {
        CASE_STRING(OTF2_IO_PARADIGM_CLASS_SERIAL);
        CASE_STRING(OTF2_IO_PARADIGM_CLASS_PARALLEL);
        default: throw std::runtime_error("unknown");
    }
}

std::string getIoParadigmFlagString(OTF2_IoParadigmFlag IoParadigmFlag)
{
    switch (OTF2_IoParadigmFlag_enum(IoParadigmFlag))
    {
        CASE_STRING(OTF2_IO_PARADIGM_FLAG_NONE);
        CASE_STRING(OTF2_IO_PARADIGM_FLAG_OS);
        default: throw std::runtime_error("unknown");
    }
}

std::string getIoParadigmPropertyString(OTF2_IoParadigmProperty IoParadigmProperty)
{
    switch (OTF2_IoParadigmProperty_enum(IoParadigmProperty))
    {
        CASE_STRING(OTF2_IO_PARADIGM_PROPERTY_VERSION);
        default: throw std::runtime_error("unknown");
    }
}

std::string getIoHandleFlagString(OTF2_IoHandleFlag IoHandleFlag)
{
    switch (OTF2_IoHandleFlag_enum(IoHandleFlag))
    {
        CASE_STRING(OTF2_IO_HANDLE_FLAG_NONE);
        CASE_STRING(OTF2_IO_HANDLE_FLAG_PRE_CREATED);
        CASE_STRING(OTF2_IO_HANDLE_FLAG_ALL_PROXY);
        default: throw std::runtime_error("unknown");
    }
}

std::string getIoAccessModeString(OTF2_IoAccessMode IoAccessMode)
{
    switch (OTF2_IoAccessMode_enum(IoAccessMode))
    {
        CASE_STRING(OTF2_IO_ACCESS_MODE_READ_ONLY);
        CASE_STRING(OTF2_IO_ACCESS_MODE_WRITE_ONLY);
        CASE_STRING(OTF2_IO_ACCESS_MODE_READ_WRITE);
        CASE_STRING(OTF2_IO_ACCESS_MODE_EXECUTE_ONLY);
        CASE_STRING(OTF2_IO_ACCESS_MODE_SEARCH_ONLY);
        default: throw std::runtime_error("unknown");
    }
}

std::string getIoStatusFlagString(OTF2_IoStatusFlag IoStatusFlag)
{
    switch (OTF2_IoStatusFlag_enum(IoStatusFlag))
    {
        CASE_STRING(OTF2_IO_STATUS_FLAG_NONE);
        CASE_STRING(OTF2_IO_STATUS_FLAG_CLOSE_ON_EXEC);
        CASE_STRING(OTF2_IO_STATUS_FLAG_APPEND);
        CASE_STRING(OTF2_IO_STATUS_FLAG_NON_BLOCKING);
        CASE_STRING(OTF2_IO_STATUS_FLAG_ASYNC);
        CASE_STRING(OTF2_IO_STATUS_FLAG_SYNC);
        CASE_STRING(OTF2_IO_STATUS_FLAG_DATA_SYNC);
        CASE_STRING(OTF2_IO_STATUS_FLAG_AVOID_CACHING);
        CASE_STRING(OTF2_IO_STATUS_FLAG_NO_ACCESS_TIME);
        CASE_STRING(OTF2_IO_STATUS_FLAG_DELETE_ON_CLOSE);
        default: throw std::runtime_error("unknown");
    }
}
