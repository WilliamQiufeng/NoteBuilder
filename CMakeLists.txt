cmake_minimum_required(VERSION 3.14)
project(NoteBuilder)

set(CMAKE_CXX_STANDARD 17)

#find_package(Boost 1.57.0 COMPONENTS regex REQUIRED)
#
#if (Boost_FOUND)
#    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
#    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
#    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
#    include_directories(${Boost_INCLUDE_DIRS})
#
#endif ()

include_directories(src)

#include_directories(/usr/local/opt/zlib/include)

#link_directories(/usr/local/lib)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.hpp)

message("Source files found are: ${SOURCES}")

add_executable(NoteBuilder ${SOURCES})

#target_link_libraries(NoteBuilder include)

#target_link_libraries(NoteBuilder /usr/local/opt/zlib/lib/libz.dylib)

#if (Boost_FOUND)
#    message(${Boost_LIBRARIES})
#    target_link_libraries(NoteBuilder ${Boost_LIBRARIES})
#
#endif ()

#target_link_libraries(NoteBuilder /williamye/program/NoteBuilder/libs/libanvil.a)

