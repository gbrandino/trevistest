cmake_minimum_required (VERSION 2.6)
project ( hello )
# The version number.
set ( HELLO_VERSION_MAJOR 1 )
set ( HELLO_VERSION_MINOR 0 )


# add the binary tree to the search path for include files
include_directories("${PROJECT_BINARY_DIR}")

add_definitions(-DHAVE_CONFIG_H)
add_subdirectory (src)


