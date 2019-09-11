cmake_minimum_required(VERSION 2.8)

project(libanvil C CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.57.0 COMPONENTS regex REQUIRED)
boost_find()
zlib_find()

file(GLOB_RECURSE SOURCES include/*.hpp src/*.cpp)
add_library(anvil STATIC ${SOURCES})

link_boost(anvil)
link_zlib(anvil)