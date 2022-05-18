#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

float matrix_lenght(float rambg){
//(n^2 + 2 n) * 64 bits = 
  double max = rambg*pow(10,9)*8; // em bits
  double c = -1*max/64;
  // definindo a eq do segundo grau para encontrar o tamanho máximo dos arrays
  
  float a, b, delta, x1, x2;
  a = 1;
  b = 2;
  
  //printf("\nf(x) = x² + 2x + %.2f\n", c);
  
  delta = pow(b,2) - 4*a*c;
  if(delta >= 0){
    if(delta == 0){
      x1 = -b / (2 * a);
      printf("Tamanho máximo dos arrays: %d\n",(int) floor(x1));
      return (int) floor(x1);
    }
    x1 = (-b - sqrt(delta)) / (2 * a);
    x2 = (-b + sqrt(delta)) / (2 * a);
    if(x1>x2){
    printf("Tamanho máximo dos arrays: %d\n",(int) floor(x1));
    return (int) floor(x1);
    }
    printf("Tamanho máximo dos arrays: %d\n",(int) floor(x2));
    return (int) floor(x2);
      
  }
  return 0;
}


void fill_array_matrix(int n, double A [n][n], double x [n] ){
  srand(time(NULL));
  for(int i=0; i<n; i++) {
    x[i] = (double)rand()/(double)(RAND_MAX);
    for(int j=0;j<n;j++) {
      A[i][j] = (double)rand()/(double)(RAND_MAX);
    }
  }

    //for(int i=0; i<n; i++) {
    //  for(int j=0;j<n;j++) {
    //    printf("%.2f ", A[i][j]);
    //  }
    //  printf("\n");
    //}
}

void multiply_matrix(int n, double A [n][n], double x [n], double b [n]){
  //
  // TODO
  //
  }

//GRAVAR TEMPO!!!!!!!!!!!!!!!!!

//FAZER GRAFICO!!!!!!!!!!!!!!!!


int main(int argc, char *argv[]){
  double ramgb = atoi(argv[1]);
  //printf("Quantidade de memória da máquina: ");
  //scanf("%lf", &ramgb);  
  printf("Iniciando os teste com RAM = %.2lfGB\n",ramgb);
  int n = matrix_lenght(ramgb);
  n/=20;
  n = (int) floor(n);
  double A[n][n];
  double x[n];
  fill_array_matrix(n, A, x);
  
  //printf("%d\n", resultado);
  return 0;
}