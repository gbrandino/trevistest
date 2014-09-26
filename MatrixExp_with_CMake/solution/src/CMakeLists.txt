# configure a header file to pass some of the CMake settings
# to the source code, any test that effects config.h.in or config.h must be done before the next line
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )


set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# build executables

add_executable(MatrixExp MatrixExp.cpp FillMatrix.cpp FillMatrix_c11.cpp PrintMatrix.cpp TraceExp.f90 ExpEigenVal.f90 )


# search for libraries (using cmake search modules )
find_package (LAPACK REQUIRED)

if (LAPACK_FOUND)
   include_directories(${LAPACK_INCLUDE_DIRS})
   target_link_libraries (MatrixExp ${LAPACK_LIBRARIES})
endif (LAPACK_FOUND)

find_package (BLAS REQUIRED)
if (BLAS_FOUND)
   include_directories(${BLAS_INCLUDE_DIRS})
   target_link_libraries (MatrixExp ${BLAS_LIBRARIES})
endif (BLAS_FOUND)


