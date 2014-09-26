#include "FillMatrix.h"

double generateGaussianNoise(const double &variance)
{
        
	bool haveSpare = false;
	double rand1, rand2;
 
	if(haveSpare)
	{
		haveSpare = false;
		return sqrt(variance * rand1) * sin(rand2);
	}
 
	haveSpare = true;
        
	rand1 = rand() / ((double) RAND_MAX);
	if(rand1 < 1e-100) rand1 = 1e-100;
	rand1 = -2 * log(rand1);
	rand2 = (rand() / ((double) RAND_MAX)) * TWO_PI;
 
	return sqrt(variance * rand1) * cos(rand2);
}


void FillMatrix(double *A,int n)
{
  double temp;
  
  srand(time(NULL)); 
  for (int i=0; i<n; i++)
      {
      for (int j=i; j<n; j++)
          {
          temp=generateGaussianNoise(0.2);
          A[i*n+j]=temp;
          A[j*n+i]=temp;
          }
      }
}

