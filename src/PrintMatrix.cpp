#include "PrintMatrix.h"
void PrintMatrix(double *A,int n)
{
   std::cout << std::fixed;
   for (int i=0; i<n; i++)
       { 
       std::cout<<" | ";
       for (int j=0; j<n; j++)
           {
           if (A[i*n+j]<0.0)
              {
              std::cout <<  std::setprecision(5) << A[i*n+j]<<" ";
              }
           else
              {
              std::cout <<  std::setprecision(6) << A[i*n+j]<<" ";
              }
           }
       std::cout<<"|"<<std::endl;
       }
    std::cout<<std::endl;
}
