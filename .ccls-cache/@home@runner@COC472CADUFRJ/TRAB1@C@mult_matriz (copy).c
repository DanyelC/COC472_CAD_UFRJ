#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randomNumber() {
    return (double)rand() / (double)RAND_MAX;
}

double *zeroVector(int N) {
    double *vector = (double *)malloc(N * sizeof(double));
    for (int i = 0; i <= N; i++)
        vector[i] = 0;

    return vector;
}

double *multiplySquareByLinear_ij(double **A, double *x, int N) {
    double *b = zeroVector(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i] += A[i][j] * x[j];
        }
    }

    return b;
}

double *multiplySquareByLinear_ji(double **A, double *x, int N) {
    double *b = zeroVector(N);

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            b[i] += A[i][j] * x[j];
        }
    }

    return b;
}

int printB(double *b, int N) {
    for (int i = 0; i < N; i++) {
        printf("%f ", b[i]);
    }
    return 1;
}

int main(int argc, char *argv[]) {
  system("clear");
  FILE *file = fopen("resultados.csv", "a");
  fprintf(file, "N, GB, t1, t2\n");
  for(int i=1;i<argc;++i){
    //printf("argv %s\n",argv[i]);
  double ramgb = strtof(argv[i], NULL);
    //printf("ramgb %f\n",strtof(argv[i], NULL));
  int N = matrix_lenght(ramgb);  
    //n/=20; // apenas por limitação do replit
    //n = (int) floor(n); // apenas por limitação do replit

  fprintf(file, "%d, %f, ", N, ramgb);

  srand(time(NULL));

  double **A = (double **)malloc(N * sizeof(double *));
  double *x = (double *)malloc(N * sizeof(double));
  double *b;
  double *b2;

    // Populate A and b with random numbers
  for (int i = 0; i < N; i++) {
    A[i] = (double *)malloc(N * sizeof(double));
    for (int j = 0; j < N; j++) {
      A[i][j] = randomNumber();
    }
    x[i] = randomNumber();
  };

  // Multiply matrices

  clock_t start, finish;

  start = clock();
  b = multiplySquareByLinear_ij(A, x, N);
  b2 = multiplySquareByLinear_ji(A, x, N);
  finish = clock();

  // Free A
  for (int i = 0; i < N; i++) {
    free(A[i]);
  }
  free(x);
  free(b);
  ree(b2);
  printf("%d,%.6f", N, ((double)(finish - start)) / CLOCKS_PER_SEC);
  }
  return 0;
}