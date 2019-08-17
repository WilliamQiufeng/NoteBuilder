cmake_minimum_required(VERSION 3.14)
project(anvil)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.57.0 COMPONENTS regex REQUIRED)

if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})

endif ()
include_directories(. anvil/header)
include_directories(/usr/local/opt/zlib/include)
file(GLOB_RECURSE INCLUDING ${PROJECT_SOURCE_DIR}/anvil/header/*.hpp ${PROJECT_SOURCE_DIR}/anvil/definition/*.cpp)
message(${INCLUDING})
add_library(anvil STATIC ${INCLUDING})
link_directories(/usr/local/lib)
link_directories(/usr/lib)

if (Boost_FOUND)

    link_libraries(${Boost_LIBRARIES})

endif ()