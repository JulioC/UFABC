/* 
 * floyd
 *
 * Get the minimal path lenght between every pair of nodes in a adjency matrix 
 *
 * Input:
 * The number of rows and columns in the matrix, followed by n*n values
 *
 * Output:
 * The min path matrix
 */

#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int i, j, dim, dimq;
  int *nodes = NULL;
  int *paths = NULL;
  
  scanf("%d", &dim);
  if(dim < 0) {
    fprintf(stderr, "%s: Invalid matrix dimensions (%d)", argv[0], dim);
    return 1;
  }
  
  dimq = dim * dim;
  
  nodes = (int *)malloc(sizeof(int) * dimq);
  if(nodes == NULL) {
    fprintf(stderr, "%s: Unable to allocate memory", argv[0]);
    return 1;
  }
  
  for(i = 0; i < dimq ; i++) {
    scanf("%d", (nodes + i));
  }
  
  paths = (int *)malloc(sizeof(int) * dimq);
  if(paths == NULL) {
    fprintf(stderr, "%s: Unable to allocate memory", argv[0]);
    return 1;
  }
  
  for(i = 0; i < dim; i++) {
    for(j = 0; j < dim; j++) {
      if(j == i) {
        paths[(i * dim) + j] = 0;
      }
      else if(nodes[(i * dim) + j] == 0) {
        paths[(i * dim) + j] = -1;
      }
      else {
        paths[(i * dim) + j] = nodes[(i * dim) + j];
      }
    }
  }  
  
  // Here sind dracones :-)
  for(k = 0; k < dim; k++) {
    for(i = 0; i < dim; i++) {
      for(j = 0; j < dim; j++) {
        a = paths[(i * dim) + j];
        b = (paths[(i * dim) + k] < 0 || paths[(k * dim) + j] < 0) ? -1 : (paths[(i * dim) + k)] + paths[(k * dim) + j]);
        
        if((a < b && a >= 0) || b < 0) {
          paths[(i * dim) + j] = a;
        }
        else {
          paths[(i * dim) + j] = b;
        }
      }
    }
  }
  
  for(i = 0; i < dimq ; i++) {
    printf("%4d ", paths[i]);
    if(!((i+1) % dim)) {
      printf("\n");
    }
  }
  
  free(paths);
  free(nodes);
  
  return 0;
}