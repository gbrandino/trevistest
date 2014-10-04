


**Extracting and measuring CPU peak performance of different architectures**

In this exercise you will have to fill in a table (provided on your GitHub repository in *rst* format) with values for the theoretical CPU peak performance and your measurements on simple codes with different optimization settings for three different available architectures, respectively.

1 Before starting this exercise session, please read carefully the document CompilerAutoVectorizationGuide.pdf, available on the moodle.

2 Login into each machine using your account credentials (see the [Resources guide!](README.md) in the repo root)

3 Have a look at the CPU models on available platforms and find out the related *theoretical CPU peak performance* :

		a) Argo GPU node 
		b) Argo mhpc queue nodes
		c) ELCID mhpc queue AMD nodes

	  (Suggestion: find out each CPU model through appropriate Linux CLI commands and check its vendor reference webpage.)
 
4 Write a code performing a trivial matrix multiplication and giving as output the number of FLOPS (floating point operations) per second. Remember from linear algebra that the matrix multiplication is defined as :math:`C_{i,j} = \sum_{k=1}^{m} A_{i,k} \cdot B_{k,j}` .
		a) Build and run your code on each of the three platforms and save the output logs produced by both the compiler and the running code.
		b) Record your data obtained on all the three platforms by using Intel compiler with different optimization options: -­O3, ­-O3 ­-no­-vec, ­-O3 [enforcing maximum supported compiler optimization within available instruction set: which is it? go and look for it!]. Again save your logs as in a).

5 Change your code by adding a call to DGEMM BLAS subroutine and linking to INTEL MKL_SEQUENTIAL libraries: please pay attention to use in your call the proper interface according to the programming language you are using (C and/or Fortran); then record the peak performance as above. Again save your logs as in 4) a,b)

6 Fill in the provided table with all your measurements (units GFlops/s) and comment on your results and their provenance. 

7 Produce a Makefile generating binary executables for all available CPU models so that your results could be easily reproduced by lecturers when checking your assignments.

8 Commit all your source files, the Makefile and the filled table in *rst* format alongside a text file containing all your logs.
