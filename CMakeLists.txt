cmake_minimum_required(VERSION 3.10)
project(FileLoaderTest)

# Add Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(FileLoaderTest test/FileLoaderTest.cpp src/FileLoader.cpp)
target_include_directories(FileLoaderTest PUBLIC include)
target_link_libraries(FileLoaderTest gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(FileLoaderTest)
