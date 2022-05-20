#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>


double matrix_lenght(double ramgb){
//(n^2 + 2 n) * 64 bits =
  //printf("%f\n", ramgb);
  double max = ramgb*pow(10,9)*8; // em bits
  double c = -1*max/64;
  // definindo a eq do segundo grau para encontrar o tamanho máximo dos arrays
  
  double a, b, delta, x1, x2;
  a = 1.0;
  b = 2.0;
  

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
}

void check_array(int n, double b [n], double b2[n] ){
  for(int i=0; i<n; i++) {
      if (b[i]!=b2[i]){
        printf("Erro no cálculo!");
        return;
      }
    }
  printf("Mesmo resultados!\n");
  }

double multiply_matrix_v1(int n, double A [n][n], double x [n], double b [n]){
  printf("Executando a versão 1:\n");
  clock_t time;
  time = clock();
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[i] += A[i][j] * x[j];
    }
  }
  time = clock() - time;
  double time_taken = ((double)time) / CLOCKS_PER_SEC;  // in seconds
  printf("Tempo gasto: %f segundos.\n", time_taken);
  return time_taken;
}


double multiply_matrix_v2(int n, double A [n][n], double x [n], double b [n]){
  printf("Executando a versão 2:\n");
  clock_t time;
  time = clock();
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[j] += A[j][i] * x[i];
    }
  }
  time = clock() - time;
  double time_taken = ((double)time) / CLOCKS_PER_SEC;  // in seconds
  printf("Tempo gasto: %f segundos.\n", time_taken);
  return time_taken;
}

// gcc -o mult mult_matriz.c -lm
//FAZER GRAFICO!!!!!!!!!!!!!!!!


int main(int argc, char *argv[]){
  system("clear");
  FILE *file = fopen("resultados.csv", "a");
  fprintf(file, "N, GB, t1, t2\n");
  for(int i=1;i<argc;++i){
    //printf("argv %s\n",argv[i]);
    double ramgb = strtof(argv[i], NULL);
    //printf("ramgb %f\n",strtof(argv[i], NULL));
    int n = matrix_lenght(ramgb);  
    //n/=20; // apenas por limitação do replit
    //n = (int) floor(n); // apenas por limitação do replit
    for(int i=1;i<11;++i){

      fprintf(file, "%d, %f, ", n, ramgb);
      printf("Recebido: %f\n", ramgb);
      //printf("Quantidade de memória da máquina: ");
      //scanf("%lf", &ramgb);  
      printf("Iniciando os teste com RAM = %fGB\n",ramgb);
      
    
      //n = 4;
      
      double A[n][n];
      double x[n];
      fill_array_matrix(n, A, x);
      double b[n];
      double b2[n];
      // preenchendo com 0
      memset(b, 0, sizeof b);
      memset(b2, 0, sizeof b2);
      
      double t1 = multiply_matrix_v1(n, A, x, b);
      double t2 = multiply_matrix_v2(n, A, x, b2);
      check_array(n, b, b2);
  

      fprintf(file, "%f, ", t1);
      fprintf(file, "%f", t2);
      fprintf(file, "\n");
      printf("\n\n");
    }
  }
  fclose(file);
  return 0;
}