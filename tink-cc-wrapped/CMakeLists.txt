# tink-cc-wrapped
#  
# This CMake builds the C++ wrappers for use with the Tink C++ library.
#
# See README.md for what this is used for..

cmake_minimum_required(VERSION 3.13)

project(tink-cc-wrapped VERSION 1.0 LANGUAGES CXX)

#
# Basic setup of CMake for C++ that works for tink-cc.
#

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Required fpr rapidjson
cmake_policy(VERSION 3.5)

# Encourage static linking.
set(BUILD_SHARED_LIBS False)
# Try to make the tink_cc_wrapped library include the Tink/Abseil/Proto/etc definitions.
# TODO: They don't work, see if removing them breaks the current setup.
set (CMAKE_SHARED_LINKER_FLAGS "-Wl,--noas-needed")

#
# IMPORTANT: It can be really hard to get a list of dependencies **in the correct order for linking**.
# Finding this spell took a while.  By lookign at the output of `mkdir build; cd build; cmake ..`
# you can get the list of dependencies.
#

set(CMAKE_LINK_DEPENDS_DEBUG_MODE OFF)

#
# Includes
#

include(FetchContent)

# From https://developers.google.com/tink/tink-setup
# For an alternative, see https://github.com/tink-crypto/tink/blob/master/docs/CMAKE-HOWTO.md.

# Import Tink as an in-tree dependency.
FetchContent_Declare(
  tink
  URL       https://github.com/tink-crypto/tink-cc/archive/refs/tags/v2.3.0.zip
  URL_HASH  SHA256=363ce671ab5ce0b24f279d3647185597a25f407c3608db007315f79f151f436b
)
FetchContent_GetProperties(tink)
if(NOT googletest_POPULATED)
  FetchContent_Populate(tink)
    # add_subdirectory(${tink_SOURCE_DIR} ${tink_BINARY_DIR} EXCLUDE_FROM_ALL)
    add_subdirectory(${tink_SOURCE_DIR} ${tink_BINARY_DIR} )
endif()


# -- Set up Tink --

# From https://developers.google.com/tink/tink-setup
# For an alternative, see https://github.com/tink-crypto/tink/blob/master/docs/CMAKE-HOWTO.md.

# Import Tink as an in-tree dependency.
FetchContent_Declare(
  tink
  URL       https://github.com/tink-crypto/tink-cc/archive/refs/tags/v2.3.0.zip
  URL_HASH  SHA256=363ce671ab5ce0b24f279d3647185597a25f407c3608db007315f79f151f436b
)
FetchContent_GetProperties(tink)
#if(NOT googletest_POPULATED)
#  FetchContent_Populate(tink)
#    # add_subdirectory(${tink_SOURCE_DIR} ${tink_BINARY_DIR} EXCLUDE_FROM_ALL)
#    add_subdirectory(${tink_SOURCE_DIR} ${tink_BINARY_DIR} )
#endif()
    
#
# Build the library for the custom wrappers needed to cxx-bridge to call into Tink.
#
# For example, cxx-bridge doesn't support static functions. (See functions comments for details.)
#

file(GLOB SOURCES 
    "src/*.cpp"
    "src/*.h"
)
add_library(tink_cc_wrapped STATIC
    ${SOURCES}
)
target_link_libraries(tink_cc_wrapped PUBLIC
  tink::static
  absl::check
  absl::flags_parse
)
target_include_directories(tink_cc_wrapped PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)


# Avoid some repetitive errors
target_compile_options(tink_cc_wrapped PRIVATE "-Wno-unused-parameter")

# TODO: Some sources suggest this will statically link it. Remove it?
target_link_options(tink_cc_wrapped PRIVATE "-Wl,--noas-needed,--whole-archive")

#
# For debugging the Rust bindings, it can be helpful to have class dumps to see the C++ layout.
#
set(DUMP_SOURCE_FILES
    ${SOURCES}
)

# This flag is not the same on MacOS
if (NOT CMAKE_SYSTEM_NAME STREQUAL "Darwin")
     # For each source file, add the custom compiler flag
     foreach(source_file ${DUMP_SOURCE_FILES})
         # Get just the filename without path
         get_filename_component(filename_only "${source_file}" NAME)
         
         # Add the compiler flag with the proper output filename
         set_source_files_properties(
             ${source_file}
             PROPERTIES
             COMPILE_FLAGS "-fdump-lang-class=${filename_only}_dump.txt"
         )
     endforeach()
endif()
