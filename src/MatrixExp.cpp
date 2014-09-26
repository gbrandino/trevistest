/* Sample code to be used with CMake.

   The idea is to have a random (symmetric) n-by-n matrix A  generated either with std random engine or the old rand from cstdlib.
   Then use blas-dgemm and lapack-dsyev to verify that 
   Tr [exp(A)]= \sum_i exp(\lambda_i)
   where \lambda_i are eigenvalues of A.

   We expand exp(A) in series 
   exp(A)=\sum_k=0^\infty \frac{1}{k!}A^k and use dgemm to recursively calcualte the sum up to a certain N.
   We use instead lapack to calculate \lambda_i

   Both n (matrix size) and N (the order of the expasion) are command line paramenters. 
 
   Created by G.P. Brandino for the course 
   "P1.1 Scientific programming environment"
   for the Master in High Performance Computing @SISSA/ICTP */

#include <iostream>
#include <cstdio>
#if __cplusplus > 199711L
#define tag " Using fancy c++11 random generator class"
#define c11 1
#include "FillMatrix_c11.h"
#else
#define tag " Using old cstdlib rand() function and Box-Muller transform" 
#define c11 0
#include "FillMatrix.h"
#endif
#include "PrintMatrix.h"
#ifdef HAVE_CONFIG_H
    #include "config.h"
#else
    #define MatrixExp_VERSION_MAJOR "HandCompiled"
    #define MatrixExp_VERSION_MINOR "HandCompiled"
#endif


extern "C" { double  traceexp_(double* A, int* n, int* N); }
extern "C" { double  expeigenval_(double* A, int* n); } 

main (int argc, char* argv[])
{
  if (argc<3 or argc>4 )
     {
     std::cout << std::endl;
     std::cout << " " << MatrixExp_VERSION_MAJOR << "." << MatrixExp_VERSION_MINOR << std::endl;
     std::cout << " The tricky matrix exponential. An elementary check \n \n";  
     std::cout << " usage: " << argv[0] << " {matrix size} {order of the expansion} {optional: if set to whatever number/string, will set the matrix to identity (for testing)}\n";
     return 0; 
     }
  int n,N;
  n=atoi(argv[1]);
  N=atoi(argv[2]);
  std::cout << std::endl;
  std::cout << " " <<  MatrixExp_VERSION_MAJOR << "." << MatrixExp_VERSION_MINOR << std::endl;
  std::cout << " The tricky matrix exponential. An elementary check \n \n";
  std::cout << tag << std::endl;
  std::cout << " Matrix size ---> " << n << std::endl;
  std::cout << " order of the Taylor expasion of exp(A) ---> "<< N << std::endl << std::endl;
 
  double* A;
  A=new double[n*n]; 
  double temp;
#if c11 > 0 //c++11-style random number generation for gaussian random numbers
  FillMatrix_c11(A,n);
#else //using Box-Muller transform
  FillMatrix(A,n); 
#endif
  if (argc==4)
     {
     std::cout << " Testing using identity matrix " << std::endl;
     for (int i=0; i<n; i++)
         {
         for (int j=0; j<n; j++) 
             {
             if (i==j) A[i*n+j]=1.0;
             else A[i*n+j]=0.0;
             }
         }
     }

  // printing input matrix
  PrintMatrix(A,n);

  //Calculating Tr(exp(A)) using our dgemm fortran wrapper
  double ans1;
  ans1 = traceexp_(A,&n,&N);
  std::cout << std::fixed << std::setprecision(14); 
  std::cout << " Tr(exp(A)) = " << ans1 << std::endl << std::endl;

  //Calculating exp(\sum_i \lambda_i) using our dsyev fortran wrapper
  double ans2;
  ans2 = expeigenval_(A,&n);
  std::cout << " Sum_i exp( lambda_i ) = " << ans2 << std::endl << std::endl;
  std::cout << " Difference between the two methods " << ans1-ans2 << std::endl << std::endl;
 
  delete [] A;
  return 0;
}
