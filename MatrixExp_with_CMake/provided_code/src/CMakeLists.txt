# configure a header file to pass some of the CMake settings
# to the source code, any test that effects config.h.in or config.h must be done before the next line
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )


# build executables

add_executable(hello  main.c )



