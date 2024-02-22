# This below code is only compatible with CMake v3.25 and +
cmake_minimum_required(VERSION 3.25)

# A simple function to get a variable from a string CONTENT based
# on a REGEX. The result is returned in the last argument.
# ----------------------------------------------------------
# Yes ! You can now return result from a CMake function !!!
# ----------------------------------------------------------
function(get_version_from_file CONTENT REGEX RESULT)
    # Match the regular expression, matches are stored in VERSION variable
    string(REGEX MATCH ${REGEX} VERSION ${CONTENT})
    if (VERSION)
        # Individual regex matches are stored in CACHE variable CMAKE_MATCH_N
        # See: https://cmake.org/cmake/help/latest/command/string.html#regex-specification
        set(${RESULT} ${CMAKE_MATCH_1})
    else()
        # We must raised a fatal error here, in case the input file (version.h.in
        # in this example) is ill-formed or not matching with the regex.
        # We must retrieve the version successfully !
        message(FATAL_ERROR "Could not get version with regex ${REGEX}")
    endif()
    # New in CMake 3.25, we can now use return(PROPAGATE xx) to return a value
    # from a function which is a huge improvment on CMake !
    return(PROPAGATE ${RESULT})
endfunction()

# First, we read the VERSION file and store in into FILE_CONTENT variable
file(READ VERSION FILE_CONTENT)

# We get all three major / minor and patch variables from the file_content
get_version_from_file(${FILE_CONTENT} "MAJOR = ([0-9]+)" MAJOR_VERSION)
get_version_from_file(${FILE_CONTENT} "MINOR = ([0-9]+)" MINOR_VERSION)
get_version_from_file(${FILE_CONTENT} "PATCH = ([0-9]+)" PATCH_VERSION)

# We set the SOFTWARE_VERSION variable in the form X.X.X
set(SOFTWARE_VERSION "${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")

# Status message so displayed by default on a CMake command
message(STATUS "Software version read from VERSION file: ${SOFTWARE_VERSION}")


# Create a small project to get the version within a compiled C++ application
project(version LANGUAGES CXX)

# configure_file function takes a version.h.in input file with @VARIABLE@ that
# will be replaced by exact name CMake variable.
# Ex: set(ABC my_abc_value)
# in a file version.h.in, the string @ABC@ will be replaced by my_abc_value
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
    ${CMAKE_BINARY_DIR}/version.hpp
    @ONLY
)

# Create a pgm C++ program
add_executable(pgm ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# The main.cpp file needs to know the path where to find the generated version.hpp
target_include_directories(pgm PRIVATE ${CMAKE_BINARY_DIR})
