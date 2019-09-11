cmake_minimum_required(VERSION 2.8)

project(midifile C CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CheckIncludeFiles)

include_directories(include)

check_include_files(unistd.h HAVE_UNISTD_H)
check_include_files(humdrum.h HAVE_HUMDRUM_H)
check_include_files(sys/io.h HAVE_SYS_IO_H)

##############################
##
## Operating-system specific settings:
##

if (APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum OS X deployment version")
endif ()

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

    option(STATIC_CRT "Use static CRT libraries" OFF)

    # Rewrite command line flags to use /MT if necessary
    if (STATIC_CRT)
        foreach (flag_var
                CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
                CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
            if (${flag_var} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
            endif (${flag_var} MATCHES "/MD")
        endforeach (flag_var)
    endif ()
endif ()


##############################
##
## Library:
##

set(SRCS
        src/Options.cpp
        src/Binasc.cpp
        src/MidiEvent.cpp
        src/MidiEventList.cpp
        src/MidiFile.cpp
        src/MidiMessage.cpp
        )

set(HDRS
        include/Binasc.h
        include/MidiEvent.h
        include/MidiEventList.h
        include/MidiFile.h
        include/MidiMessage.h
        include/Options.h
        )

add_library(midifile STATIC ${SRCS} ${HDRS})

##############################
##
## Programs:
##

#add_executable(80off tools/80off.cpp)
#add_executable(asciimidi tools/asciimidi.cpp)
#add_executable(binasc tools/binasc.cpp)
#add_executable(createmidifile tools/createmidifile.cpp)
#add_executable(createmidifile2 tools/createmidifile2.cpp)
#add_executable(drumtab tools/drumtab.cpp)
#add_executable(durations tools/durations.cpp)
#add_executable(mid2mat tools/mid2mat.cpp)
#add_executable(mid2mtb tools/mid2mtb.cpp)
#add_executable(mid2svg tools/mid2svg.cpp)
#add_executable(midi2binasc tools/midi2binasc.cpp)
#add_executable(midi2melody tools/midi2melody.cpp)
#add_executable(midi2notes tools/midi2notes.cpp)
#add_executable(midi2skini tools/midi2skini.cpp)
#add_executable(midi2text tools/midi2text.cpp)
#add_executable(midicat tools/midicat.cpp)
#add_executable(midimixup tools/midimixup.cpp)
#add_executable(miditime tools/miditime.cpp)
#add_executable(perfid tools/perfid.cpp)
#add_executable(retick tools/retick.cpp)
#add_executable(shutak tools/shutak.cpp)
#add_executable(smfdur tools/smfdur.cpp)
#add_executable(stretch tools/stretch.cpp)
#add_executable(sysextest tools/sysextest.cpp)
#add_executable(text2midi tools/text2midi.cpp)
#add_executable(textmidi tools/textmidi.cpp)
#add_executable(toascii tools/toascii.cpp)
#add_executable(tobin tools/tobin.cpp)
#add_executable(tobinary tools/tobinary.cpp)
#add_executable(todec tools/todec.cpp)
#add_executable(tohex tools/tohex.cpp)
#add_executable(type0 tools/type0.cpp)
#add_executable(vlv tools/vlv.cpp)
#
#target_link_libraries(80off .)
#target_link_libraries(asciimidi .)
#target_link_libraries(binasc .)
#target_link_libraries(createmidifile .)
#target_link_libraries(createmidifile2 .)
#target_link_libraries(drumtab .)
#target_link_libraries(durations .)
#target_link_libraries(mid2mat .)
#target_link_libraries(mid2mtb .)
#target_link_libraries(mid2svg .)
#target_link_libraries(midi2binasc .)
#target_link_libraries(midi2melody .)
#target_link_libraries(midi2notes .)
#target_link_libraries(midi2skini .)
#target_link_libraries(midi2text .)
#target_link_libraries(midicat .)
#target_link_libraries(midimixup .)
#target_link_libraries(miditime .)
#target_link_libraries(perfid .)
#target_link_libraries(retick .)
#target_link_libraries(shutak .)
#target_link_libraries(smfdur .)
#target_link_libraries(stretch .)
#target_link_libraries(sysextest .)
#target_link_libraries(text2midi .)
#target_link_libraries(textmidi .)
#target_link_libraries(toascii .)
#target_link_libraries(tobin .)
#target_link_libraries(tobinary .)
#target_link_libraries(todec .)
#target_link_libraries(tohex .)
#target_link_libraries(type0 .)
#target_link_libraries(vlv .)
#
#if (HAVE_UNISTD_H AND HAVE_SYS_IO_H)
#    add_executable(midi2beep tools/midi2beep.cpp)
#
#    target_link_libraries(midi2beep .)
#endif ()
#
## The following programs require headers from humextra repository.
## <https://github.com/humdrum-tools/humextra>
#if (HAVE_HUMDRUM_H)
#    add_executable(henonfile tools/henonfile.cpp)
#    add_executable(mid2hum tools/mid2hum.cpp)
#    add_executable(midiexcerpt tools/midiexcerpt.cpp)
#    add_executable(peep2midi tools/peep2midi.cpp)
#
#    target_link_libraries(henonfile .)
#    target_link_libraries(mid2hum .)
#    target_link_libraries(midiexcerpt .)
#    target_link_libraries(peep2midi .)
#endif ()
