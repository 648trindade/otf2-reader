list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(OTF2 REQUIRED)

if (NOT OTF2_FOUND)
    message(FATAL_ERROR "Please download and install OTF2 2.2.\n"
    "Available from: https://www.vi-hps.org/cms/upload/packages/otf2/otf2-2.2.tar.gz")
endif()

add_library(
    OTF2Wrapper
    STATIC
        OTF2Reader.h
        OTF2Reader.cpp
        OTF2Callbacks.h
        OTF2Callbacks.cpp
        OTF2CallTree.hpp
        OTF2CallTree.cpp
        OTF2EnumToStrings.hpp
        OTF2EnumToStrings.cpp
)

target_link_libraries(OTF2Wrapper otf2::otf2)