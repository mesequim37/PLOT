#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double **Matgen(int fil, int col);
int JacobiMethod(int n, double **A, double *b, int *xi, double eps, int MaxIt);
double *Mat_Vec_Mult(int n, double **mat, double *arr);

#endif


