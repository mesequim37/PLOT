
#include "tools.h"

//Definimos las funciones de condición inicial, frontera y fuerza
double Ta(double t);
double Tb(double t);
double T0(double x);
double g(double x, double t);

int main(){
	int i, j, n=100, tmax=1, m=20000;
	double h = 0.01, k=5e-5; 	
	double **A=NULL, **T=NULL;
	double *x = malloc(n*sizeof(float));
	T = (double * *)malloc(n * sizeof(float));
	for (i=0; i<n; i++){
		T[i] = (double *) malloc(m*sizeof(double) );
		if(T[i] == NULL){
			perror("ERROR. There is not enough memory");
			exit(EXIT_FAILURE);

		}

	}
	
	A = (double * *)malloc(n * sizeof(float));
	
	for (i=0; i<n; i++){
		A[i] = (double *) malloc(n*sizeof(double) );
		if(A[i] == NULL){
			perror("ERROR. There is not enough memory");
			exit(EXIT_FAILURE);

		}

	}
	
	double *y = malloc(m*sizeof(float));
	
	//Vector de posición x
	x[0] = 0;
	x[n] = 1;
	for( i = 1; i < n; i++ ) {
      	x[i] = x[i-1] + h ;
      	//printf("%f\n", x[i]);
	}

	
	//Vector de tiempo y
	y[0] = 0;
	y[m] = tmax;
	for( i = 1; i < m; i++ ) {
      	y[i] = y[i-1] + k ; 
	}
	
	//Creamos la matriz tridiagonal del método explícito
	
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			if (i==j){
				A[i][j]=1-2*k/(h*h);
			}
			if (j==i+1){
				A[i][j]=k/(h*h);
			}
			if (j==i-1){
				A[i][j]=k/(h*h);
			}
		}
	}
	
	//Colocamos la condición inicial t=0
	
	for (j=0; j < n; j++){
		T[0][j] = T0(x[j]);
	}
	
	//Colocamos las condiciones de frontera x=0 y x=1
	
	for (i = 0; i < m; i++){
		T[i][0] = Ta(y[i]);
	}
	
	for (i = 0; i < m; i++){
		T[i][1] = Tb(y[i]);
	}
	
	//Explicit method solve
	for (i = 0; i < m; i++){
		for (j = 1; j < n-1; j++){
			T[i+1][j] = (1-2*k/(h*h))*T[i][j] + k/(h*h)*T[i][j+1] + k/(h*h)*T[i][j-1] + k*g(x[i],y[j]);
			
		}
		
	}
	
	
	return 0;
}


double Ta(double t){
	return 0;
}

double Tb(double t){
	return 0;
}

double T0(double x){
	return exp(x);
}

double g(double x, double t){
	return cos(M_PI*t)*sin(2*M_PI*x);
}