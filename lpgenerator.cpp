// Compile:  g++ -O3 -o lpgenerator.exe lpgenerator.cpp
// Execute:  ./lpgenerator.exe 3 8 1024


#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG false

double rand10()
{
  // return a random value between 1 to 10
  const double max_value = 10;  
  return (max_value-1)*(((double)rand())/RAND_MAX)+1;
}

double randpm10()
{
  // return a random value between -10 to 10
  const double max_value = 10;
  return max_value*(2*((double)rand())/RAND_MAX-1);
}

int main(int argc, char** argv)
{
  int m = 0;
  int n = 0;
  int seed = 0;
  if (argc != 4) {
    printf("Usage  : %s m n seed\n", argv[0]);
    printf("     m : the number of constraints\n");
    printf("     n : the number of variables\n");
    printf("  seed : the number of seed\n");    
    printf("Example: %s 3 8 1024\n", argv[0]);
    return -1;
  }
      
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  seed = atoi(argv[3]);

  printf("m = %d, n = %d, seed = %d\n", m, n , seed);
  srand(seed);


  double* c;
  double* b;
  double* A;

  c = new double[n];
  b = new double[m];
  A = new double[m*n];

  // feasible solution
  double* x0;
  x0 = new double[n];

  for (int j=0; j<n; ++j) {
    x0[j] = rand10();
  }

  for (int j=0; j<n; ++j) {
    c[j] = randpm10();
  }

  double sum0 = 0;
  for (int j=0; j<n; ++j) {
    A[0*m + j] = rand10();
    sum0 += A[0*m + j]*x0[j];
  }
  b[0] = sum0 + rand10();

  for (int i=1; i<m; ++i) {
    double sum1 = 0;
    for (int j=0; j<n; ++j) {
      A[i*n + j] = randpm10();
      sum1 += A[i*n + j]*x0[j];
    }
    b[i] = sum1 + rand10();
    if (b[i] < 0) {
      b[i] = rand10();
    }
  }
  
  #if DEBUG
  printf("x0 = [");
  for (int j=0; j<n; ++j) {
    printf("%lf, ", x0[j]);
  }
  printf("]\n");
  printf("b = [");
  for (int i=0; i<m; ++i) {
    printf("%lf, ", b[i]);
  }
  printf("]\n");
  printf("c = [");
  for (int j=0; j<n; ++j) {
    printf("%lf, ", c[j]);
  }
  printf("]\n");
  printf("A = [");
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      printf("%lf, ", A[i*n+j]);
    }
    printf("\n");
  }
  printf("]\n");
  #endif

  char filename[1024];
  sprintf(filename, "problem-%05d-%05d-%06d.txt", m, n, seed);
  printf("Writing LP to %s\n", filename);

  FILE* fp;
  if ((fp = fopen(filename, "w")) == NULL) {
    printf("Cannot open %s\n", filename);
    return -1;
  }

  fprintf(fp, "%d\n",m);
  fprintf(fp, "%d\n",n);
  for (int i=0; i<m-1; ++i) {
    fprintf(fp, "%lf,", b[i]);
  }
  fprintf(fp, "%lf\n", b[m-1]);
  for (int j=0; j<n-1; ++j) {
    fprintf(fp, "%lf,", c[j]);
  }
  fprintf(fp, "%lf\n", c[n-1]);
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n-1; ++j) {
      fprintf(fp, "%lf,", A[i*n+j]);
    }
    fprintf(fp, "%lf\n", A[i*n+n-1]);
  }
  fclose(fp);

  delete[] c;
  delete[] b;
  delete[] A;
  delete[] x0;
  
  return 0;
}
  
