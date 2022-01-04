CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(OTF2Reader CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

add_subdirectory("src/OTF2")

add_executable(
    ${PROJECT_NAME}
    "src/main.cpp"
    "src/args.hpp"
    "src/args.cpp"
    "src/json_dump.hpp"
    "src/json_dump.cpp"

    "src/nlohmann/json.hpp"
)

target_link_libraries(
    ${PROJECT_NAME}
    Threads::Threads
    Boost::program_options
    OTF2Wrapper
)

add_subdirectory(tests)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION "bin"
)