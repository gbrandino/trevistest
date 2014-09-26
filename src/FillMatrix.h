#ifndef FILL_MATRIX_H
#define FILL_MATRIX_H
#include <cmath>
#include <cstdlib>
#include <time.h>
#define TWO_PI 6.2831853071795864769252866
 
double generateGaussianNoise(const double &variance);
void FillMatrix(double *A,int n);
#endif
