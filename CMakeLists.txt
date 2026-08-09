cmake_minimum_required(VERSION 3.10)
project(design_patterns_examples VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE PATTERN_HEADERS "${PROJECT_SOURCE_DIR}/include/*.h" "${PROJECT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE PATTERN_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(design_patterns_examples ${PATTERN_SOURCES})
