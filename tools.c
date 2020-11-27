#include "tools.h"

double **Matgen(int fil, int col){
	int i;
	double **arr=NULL;
	
	arr = (double * *)malloc(fil * sizeof(double));
	for (i=0; i<fil; i++){
		arr[i] = (double *) malloc(col*sizeof(double) );
		if(arr[i] == NULL){
			perror("ERROR. There is not enough memory");
			exit(EXIT_FAILURE);
		}
	}
	
	return arr;
}



int JacobiMethod(int n, double **A, double *b, int *xi, double eps, int MaxIt){
	
	int i, j, k = 0;
	double *xk=NULL;  //Nuevo Vector a formar 
	xk = (double *) malloc(n * sizeof(double));
	if (xk==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	
	double err;

	while (k < MaxIt, k++){
		for (i = 0; i < n; i++){
			
			double sum, diff;
			
			sum = b[i];
			for (j = 0; j < n; j++){
				sum = sum - A[i][j]*xi[j];
			}
			
			sum = sum + A[i][i]*xi[i];
			xk[i] = sum/A[i][i];
			
			diff = xk[i] - xi[i];
			err = err + diff*diff;
		}
		
		if (err < eps){
			break;
			
		} else{
			xi[i] = xk[i];
			
		}
		
	}
	
	return k;
}

double *Mat_Vec_Mult(int n, double **mat, double *arr){
	
	int i, k;
	double *resu=NULL;
	resu = (double *) malloc(n * sizeof(double));
	if (resu==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<n;i++){
		
		double sum = 0;
		
		for(k=0;k<n;k++){
			sum+=mat[i][k]*arr[k];	
		}
		
		resu[i]=sum;
	}
	
	return resu;

}
