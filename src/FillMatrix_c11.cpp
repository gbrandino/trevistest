#if __cplusplus > 199711L
#include "FillMatrix_c11.h"
void FillMatrix_c11(double *A,int n)
{
  double temp;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0,0.2);
  for (int i=0; i<n; i++)
      {
      for (int j=i; j<n; j++)
          {
          temp=d(gen);
          A[i*n+j]=temp;
          A[j*n+i]=temp;
          }
      }
}
#endif
