# Read a version from a file

This is an example on how to read a version from a file based on modern CMake (>3.25).

We have a `VERSION` file with the following content:

```
MAJOR = 2
MINOR = 1
PATCH = 4
```

We want to get these information in a C++ header file we can use in our program.

# How to use ?

```
$ mkdir build
$ cd build
$ cmake -GNinja ..
-- Software version read from VERSION file: 2.1.4
-- The CXX compiler identification is GNU 8.1.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/mingw64/bin/c++.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (1.1s)
-- Generating done (0.0s)
-- Build files have been written to: C:/Users/AdrienMartin/Documents/99-Perso/CMake-examples/version-from-file/build
$ ninja
[2/2] Linking CXX executable pgm.exe
$ ./pgm
MAJOR version: 2
MINOR version: 1
PATCH version: 4
Software version: 2.1.4
```