/* 
 * matrixavg
 *
 * Get the average of the values in a matrix
 *
 * Input:
 * The number of rows and columns in the matrix, followed by n*n values
 *
 * Output:
 * Average value
 */

#include <stdio.h>

int calc(int nodec, int *paths);

int main(int argc, char *argv[]) {
  int aux, dim, dimq, i;
  long int sum = 0;
  
  scanf("%d", &dim);
  if(dim <= 0) {
    fprintf(stderr, "%s: Invalid matrix dimensions (%d)", argv[0], dim);
    return 1;
  }
  
  dimq = dim*dim;
  
  for(i = 0; i < dimq ; i++) {
    scanf("%d", &aux);
    sum += aux;
  }
  
  printf("%d", (sum/dimq));
  
  return 0;
}