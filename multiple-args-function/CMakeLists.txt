# cmake versions less than 3.5 is starting to be deprecated.
# all functions used here are from cmake 3.0 and over.
cmake_minimum_required(VERSION 3.5)

project(multi_args)

# Create a very generic multi argument function to illustrate
# how it works.
function(my_multi_args_function)
    # Set the 4 needed variables to handle all possible argument types.
    # First, the PREFIX value, all arguments will be prefixed by that
    set(PREFIX APP)
    # Then, define all function keywords that are single values
    set(SINGLE_VALUES SV)
    # Then, define all function keywords that are optional values
    set(OPTIONAL_VALUES OV)
    # Then, define all function keywords that are multiples values
    set(MULTIPLE_VALUES MV)

    # To understand how arguments are passed via CMake, you can spy
    # the ARGN variable
    message(DEBUG "ARGN: ${ARGN}")

    # Magic cmake function that does all the parsing for you.
    cmake_parse_arguments(
        ${PREFIX}
        "${OPTIONAL_VALUES}"
        "${SINGLE_VALUES}"
        "${MULTIPLE_VALUES}"
        ${ARGN}
    )

    # Display all single/optional and multiple variables after parsing.
    message(STATUS "single value variable: ${APP_SV}")
    message(STATUS "optional value variable: ${APP_OV}")
    message(STATUS "multiple value variable: ${APP_MV}")
endfunction()


# Very similar function but with a better example. We want a function
# that can print an object name and its type. Optionally, if the object
# is red, we want to display it as well.
function(print_object_types)
    set(PREFIX APP)
    set(SINGLE_VALUES MY_COMMON_TYPE)
    set(OPTIONAL_VALUES PRINT_RED_COLOR)
    set(MULTIPLE_VALUES MY_OBJECTS)

    cmake_parse_arguments(
        ${PREFIX}
        "${OPTIONAL_VALUES}"
        "${SINGLE_VALUES}"
        "${MULTIPLE_VALUES}"
        ${ARGN}
    )

    if (APP_PRINT_RED_COLOR)
        set(COLOR_STRING "and is red")
    endif()

    message(DEBUG "APP_MY_OBJECTS: ${APP_MY_OBJECTS}")

    foreach(OBJECT IN LISTS APP_MY_OBJECTS)
        message(STATUS "object ${OBJECT} is a ${APP_MY_COMMON_TYPE} ${COLOR_STRING}")
    endforeach()

endfunction()

# Generic function call
my_multi_args_function(
    MV multiple_value_1 multiple_value_2
    SV single_value
    OV optional_value)

# Example with red vehicules
print_object_types(
    MY_COMMON_TYPE vehicule
    MY_OBJECTS ferrari ducati firetruck
    PRINT_RED_COLOR)

# Example with movies (not optional values)
print_object_types(
    MY_COMMON_TYPE movie
    MY_OBJECTS titanic matrix shining)
