
cmake_minimum_required (VERSION 3.7)

project ( Weather )

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall --std=c++11")
set (BOOST_ROOT $ENV{BOOST_ROOT})

file (GLOB HEADERS "include/*.hpp" )

set(BUILD_CPR_TESTS OFF)
add_subdirectory(cpr)

# set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Typically you don't care so much for a third party library's tests to be
# run from your own project's code.
set(JSON_BuildTests OFF CACHE INTERNAL "")

# Don't use include(nlohmann_json/CMakeLists.txt) since that carries with it
# unintended consequences that will break the build.  It's generally
# discouraged (although not necessarily well documented as such) to use
# include(...) for pulling in other CMake projects anyways.
add_subdirectory(json)
set (NLOHMANN_JSON_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/json/single_include")
# add_library(weather ...)
# target_link_libraries(weather PRIVATE nlohmann_json::nlohmann_json)


# include_directories(${CPR_INCLUDE_DIRS})
# target_link_libraries(weather ${CPR_LIBRARIES})

add_executable( weather
                src/main.cpp
                ${HEADERS}
                )

target_link_libraries( weather 
                       PUBLIC
                       pthread
                       boost_thread
                       boost_system
                       boost_filesystem
                       boost_program_options
                       "${CPR_LIBRARIES}"
                      )

target_include_directories( weather 
                            PUBLIC
                            "${CPR_INCLUDE_DIRS}"
                            "${NLOHMANN_JSON_INCLUDE_DIR}"
                            "${CMAKE_CURRENT_SOURCE_DIR}/include"
                            )
