cmake_minimum_required (VERSION 2.6)
project (MatrixExp )
enable_language (Fortran)
enable_testing()
# The version number.
set (MatrixExp_VERSION_MAJOR 1)
set (MatrixExp_VERSION_MINOR 0)




# add the binary tree to the search path for include files
include_directories("${PROJECT_BINARY_DIR}")


# to compile with -std=c++11 flag 
option (USE_CXX11 
        "C++11 compatibiity, mostly for the random generator class" OFF)
if (USE_CXX11)
   set (CMAKE_CXX_FLAGS "-std=c++11")
endif (USE_CXX11)

add_definitions(-DHAVE_CONFIG_H)
add_subdirectory (src)


# check that using and identiy matrix of size 3x3 3*exp(1)
add_test (MatrixExpId3 ${PROJECT_BINARY_DIR}/bin/MatrixExp 3 17 Id)
 
set_tests_properties ( MatrixExpId3 
  PROPERTIES PASS_REGULAR_EXPRESSION "Difference between the two methods 0.00000000000000")
