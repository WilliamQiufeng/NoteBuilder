cmake_minimum_required(VERSION 3.14)
project(NoteBuilder)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.57.0 COMPONENTS regex REQUIRED)

if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})

endif ()

add_subdirectory(include)

include_directories(include/anvil/header)

include_directories(/usr/local/opt/zlib/include)

link_directories(/usr/local/lib)

add_executable(NoteBuilder src/cpp/main.cpp)

target_link_libraries(NoteBuilder anvil)

target_link_libraries(NoteBuilder /usr/local/opt/zlib/lib/libz.dylib)


if (Boost_FOUND)
    message(${Boost_LIBRARIES})
    target_link_libraries(NoteBuilder ${Boost_LIBRARIES})

endif ()

#target_link_libraries(NoteBuilder /williamye/program/NoteBuilder/libs/libanvil.a)

