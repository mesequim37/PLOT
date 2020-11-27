#include "tools.h"

//Definimos las funciones de condición inicial, frontera y externa
double Ta(double t);
double Tb(double t);
double T0(double x);
double g(double x, double t);

int main(){
	
	double *x=NULL, *t=NULL;
	int i, j, n=100, tmax=1, m=20000;
	double h = 0.01, k=0.00005;
	x = (double *) malloc( n * sizeof(double) );
	double **T = Matgen(m+1,n);		
	t = (double *) malloc(m * sizeof(double));
	
	//Vector de posición x
	x[0] = 0;
	x[n] = 1;
	for( i = 1; i < n; i++ ) {
      	x[i] = x[i-1] + h ;
	}

	//Vector de tiempo t
	t[0] = 0;
	t[m] = tmax;
	for( i = 1; i < m; i++ ) {
      	t[i] = t[i-1] + k ; 
	}
	
	//Colocamos la condición inicial t=0
	
	for (j=0; j <= n; j++){
		T[0][j] = T0(x[j]);
	}
	
	//Colocamos las condiciones de frontera x=0 y x=1
	
	for (i = 0; i <= m; i++){
		T[i][0] = Ta(t[i]);
	}

	for (i = 0; i <= m; i++){
		T[i][1] = Tb(t[i]);
	}

	//Explicit method solve
	for (i = 0; i < m; i++){
		for (j = 1; j < n-1; j++){
			T[i+1][j] = (1-2*k/(h*h))*T[i][j] + k/(h*h)*T[i][j+1] + k/(h*h)*T[i][j-1] + k*g(x[i],t[j]);
			
		}
		
	}
	for (i=48; i<=n-32; i++){
		printf("%f\n",T[19955][i]);
	}
	
	FILE *expl = fopen("expl.dat", "w");
	for (i = m/5; i <= m; i++){
		for (j=n/5; j<=n; j++){
    		fprintf(expl, "%f %f %f", t[i], x[j],T[i][j]);
    		fprintf(expl, "\n");
		}
	}
	fclose(expl);
	
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
