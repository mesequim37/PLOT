#include "tools.h"

//Implicit


double g(double x, double t);

int main(){
	double h = 0.01, k=0.00005; //k es deltaT y h es deltaX
	double lambda = k/h*h;
	double *x,*t,*b,*frontera;
	int i,j;
	int tmax=1;
	int n,m=10;
	double eps = 0.001;
	int MaxIt = 10;
	
	
	b = (double *) malloc(n * sizeof(double));
	frontera = (double *) malloc(n+1 * sizeof(double));
	
	
	//Vector de posición x
	x = (double *) malloc( n * sizeof(double) );

	x[0] = 0;
	x[n] = 1;
	for( i = 1; i < n; i++ ) {
      	x[i] = x[i-1] + h ;
	}

	//Vector de tiempo t
	t = (double *) malloc(m * sizeof(double));
	
	t[0] = 0;
	t[m] = tmax;
	for( i = 1; i < m; i++ ) {
      	t[i] = t[i-1] + k ; 
	}
	
	//Generando la matriz de coeficientes 
	double **matrix = Matgen(m,n);
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			if (i==j){
				matrix[i][j]=(1+2*lambda);
				}
			else if (j=i+1){
				matrix[i][j]=-lambda;
				}
			else if(j=i-1){
				matrix[i][j]=lambda;
				}
			}
	}
		
	double **m_result = Matgen(m+1,n+1); //Declarando la matriz de resultados
	
	// Obteniendo el vector frontera
	for (i=0; i<n+1; i++){
		frontera[i] = exp(x[i]);
	}
	
	for (j=0; j<n+1; j++){
		m_result[0][j]=frontera[j]; 
	}
	
	for (i=0; i<n; i++){
		b[i] = frontera[i] + k*g(x[i],t[i]); //no sirve aqui xd
	}
	
	
	// AQUI faltan pasos para obtener los resultados del metodo
	
	// Obteniendo el implicito
	int JacobiMethod(int n, double **matrix, double *b, int *xi, double eps, int MaxIt){
	
	}
}

double g(double x, double t){
		return cos(M_PI*t)*sin(2*M_PI*x);
	}
	