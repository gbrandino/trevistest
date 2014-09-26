MatrixExp_with_CMake
========================

Using the provide code in src folder, modify the sample file 
 - CMakeLists.txt 
 - src/CMakeLists.txt

to be able to execute the complete workflow 
   - cmake .
   - ccmake . 
   - make 
   - make test
   - run


Note:
 - The code is written in both c++ and fortran 90, so cmake should look know it 
         - use enable_language (Fortran)
 - It relies upon blas dgemm and lapack dsyev routine, so blas and lapack should be searched using the built-in modules
         - use   
              - find_package (libname  REQUIRED)
              - include_directories
              - target_link_libraries

 - The code works with both c-style random number generators and c+11 new random generators.
         - try adding the following code to BUILD_DIR/CMakelists.txt
           ::
 
           option (USE_CXX11 
           "C++11 compatibiity, mostly for the random generator class" ON)
           if (USE_CXX11)
           set (CMAKE_CXX_FLAGS "-std=c++11")
           endif (USE_CXX11)

   This will add a switchable field, that can be modified using ccmake

 - activate testing  ( use "enable_testing()" ) 
 - add a test 
    ::
    add_test (MatrixExpId3 ${PROJECT_BINARY_DIR}/bin/MatrixExp 3 17 Id)

    set_tests_properties ( MatrixExpId3 
    PROPERTIES PASS_REGULAR_EXPRESSION "Difference between the two methods 0.00000000000000")


 - have the executables built in the "bin" folder
      - use EXECUTABLE_OUTPUT_PATH









