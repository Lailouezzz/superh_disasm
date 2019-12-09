cmake_minimum_required(VERSION 3.0)

# setup project
project(SHD VERSION 0.0.1)
message("version : ${SHD_VERSION_MAJOR}.${SHD_VERSION_MINOR}.${SHD_VERSION_PATCH}")

# Release in defaut
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
message("build type : ${CMAKE_BUILD_TYPE}")

# C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# search BOOST
find_package(Boost 1.60.0)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  message("Boost include : ${Boost_INCLUDE_DIRS}")
else()
  message(FATAL_ERROR "Boost >= 1.60.0 not found")
endif()

# check spirit x3
if(EXISTS "${Boost_INCLUDE_DIRS}/boost/spirit/home/x3.hpp")
  message("found spirit.x3 : ${Boost_INCLUDE_DIRS}/boost/spirit/home/x3.hpp")
else()
  message(FATAL_ERROR "spirit.x3 not found")
endif()

# setup variables
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message("source dir : ${SRC_DIR}")
message("include dir : ${INCLUDE_DIR}")
message("bin dir : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# generate version.hpp
configure_file(${SRC_DIR}/version.hpp.in ${INCLUDE_DIR}/version.hpp)

# list headers and sources file
include_directories(${INCLUDE_DIR})
file(GLOB_RECURSE SRCS ${SRC_DIR}/*.cpp)
file(GLOB_RECURSE HDRS ${INCLUDE_DIR}/*.hpp)

# final executable
add_executable(SuperH_disasm ${SRCS} ${HDRS})
