cmake_minimum_required(VERSION 3.14)
project(NoteBuilder)

set(CMAKE_CXX_STANDARD 17)

find_library(anvil REQUIRED)

function(boost_find)
    find_package(Boost 1.57.0 COMPONENTS regex REQUIRED)

    if (Boost_FOUND)
        message(STATUS "Boost_INCLUDE_DIRS:\t${Boost_INCLUDE_DIRS}")
        message(STATUS "Boost_LIBRARIES:\t\t${Boost_LIBRARIES}")
        message(STATUS "Boost_VERSION:\t\t${Boost_VERSION}")
        include_directories(${Boost_INCLUDE_DIRS})

    endif ()
endfunction()

function(link_boost pro)
    if (Boost_FOUND)
        message(${Boost_LIBRARIES})
        target_link_libraries(${pro} ${Boost_LIBRARIES})
    else ()
        message("Boost not found! Required from ${pro}!")
    endif ()
endfunction()

function(zlib_find)
    find_package(zlib REQUIRED)

    if (ZLIB_FOUND)
        message("ZLIB include dirs: \t${ZLIB_INCLUDE_DIRS}")
        message("ZLIB lib:\t\t\t${ZLIB_LIBRARIES}")
        include_directories(${ZLIB_INCLUDE_DIRS})
    endif ()
endfunction()
function(link_zlib pro)
    if (ZLIB_FOUND)
        target_link_directories(${pro} ${ZLIB_LIBRARIES})
    else ()
        message("ZLib not found! Required from ${pro}!")
    endif ()
endfunction()

zlib_find()
boost_find()


add_subdirectory(third_party/midifile)
#add_subdirectory(third_party/libanvil)
add_subdirectory(third_party/libnbtplusplus)


include_directories(src)
include_directories(third_party)
include_directories(third_party/libnbtplusplus/include)


file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.hpp)

message("Source files found are: ${SOURCES}")

add_executable(NoteBuilder ${SOURCES})


target_link_libraries(NoteBuilder nbt++)



