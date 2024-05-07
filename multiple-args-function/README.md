# Create a multi argument cmake function

Have you ever wonder how cmake does to create function such as
`target_link_libraries(xxx)` ? You can have any number of arguments,
that's handy.

Well you can easily create your own multiple and/or optional argument
function yourself.

Who doesn't like function ?

# How to use ?

```
$ mkdir build
$ cd build
$ cmake --log-level=DEBUG ..
-- The C compiler identification is GNU 9.4.0
-- The CXX compiler identification is GNU 9.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- ARGN: MV;multiple_value_1;multiple_value_2;SV;single_value;OV;optional_value
-- single value variable: single_value
-- optional value variable: TRUE
-- multiple value variable: multiple_value_1;multiple_value_2
-- APP_MY_OBJECTS: ferrari;ducati;firetruck
-- object ferrari is a vehicule and is red
-- object ducati is a vehicule and is red
-- object firetruck is a vehicule and is red
-- APP_MY_OBJECTS: titanic;matrix;shining
-- object titanic is a movie
-- object matrix is a movie
-- object shining is a movie
-- Configuring done (1.9s)
-- Generating done (0.0s)
-- Build files have been written to: xxx
```