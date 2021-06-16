find_library(OTF2 NAMES otf2 REQUIRED)

add_library(
    OTF2Wrapper
    OTF2Reader.h
    OTF2Reader.cpp
)

target_link_libraries(OTF2Wrapper ${OTF2})