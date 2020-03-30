// Compile:  g++ -O3 -o lpread.exe lpread.cpp
// Execute:  ./lpread.exe problem-00003-00003-00000a.txt


#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define DEBUG true

int main(int argc, char** argv)
{
  if (argc != 2) {
    printf("Usage : %s problem-00003-00003-00000a.txt\n", argv[0]);
    return -1;
  }
  
  FILE* fp = NULL;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("Cannot open %s\n", argv[1]);
    return -1;
  }

  int m = 0;
  int n = 0;
  fscanf(fp, "%d", &m);
  fscanf(fp, "%d", &n);
  printf("m = %d, n = %d\n", m, n);

  double* b = new double[m];
  double* c = new double[n];
  double* A = new double[m*n];

  for (int i=0; i<m; ++i) {
    fscanf(fp, "%*[^0-9+-]%lf", &b[i]);
  }

  for (int j=0; j<n; ++j) {
    fscanf(fp, "%*[^0-9+-]%lf", &c[j]);
  }

  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      fscanf(fp, "%*[^0-9+-]%lf", &A[i*n+j]);
    }
  }

  fclose(fp);
  #if DEBUG
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

  delete[] b;
  delete[] c;
  delete[] A;
  return 0;
}
