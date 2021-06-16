CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(OTF2Reader CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_MODULE_PATH "${Adaptive_SOURCE_DIR}/cmake")
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

add_subdirectory("src/OTF2")

ADD_EXECUTABLE(
    ${PROJECT_NAME}
    "src/main.cpp"
)
# set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
target_link_libraries(
    ${PROJECT_NAME}
    Threads::Threads
    Boost::program_options
    OTF2Wrapper
)

#get_target_property(MAIN_CFLAGS ${PROJECT_NAME} COMPILE_FLAGS)
#MESSAGE("C++ Flags: ${MAIN_CFLAGS}")

add_subdirectory(tests)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION "bin"
)