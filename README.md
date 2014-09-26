
Travis-CI
=========

[![Build Status](https://travis-ci.org/gbrandino/trevistest.svg?branch=master)](https://travis-ci.org/gbrandino/trevistest)

The aim of this exercise is to set up a github repo to work with travis-ci
We will be using the solution of the exercise "MatrixExp_with_CMake" for this step.

- go to your github account and create a new PUBLIC repo
- go to trevis-ci.org and from there sign-in in your github account. Allow travis to access your account.
- on your machine, create a git repository, and put inside the CMakeLists.txt and the src/ folder from the solution of the exercise "MatrixExp_with_CMake"
- (for compatibility with travis (which uses gcc-4.6, in CMakeLists.txt modify the std=c++11 in c++0x, or set the USE_CXX11 to be "OFF" as default)
- create a .travis.yml file in the root of your repo
  The file should contain

        language: c
        compiler:
        - gcc
        before_script:
        - cmake .
        - make
        script:
        - ctest


- The build will fail, since no fortran compiler is installed on travis by default. Add the following line just before the "before_script"

        before_install:
        sudo apt-get install gfortran


