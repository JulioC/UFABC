/* 
 * removenode
 *
 * Remove a node (row and column) from a graph matrix
 *
 * Input:
 * The number of rows and columns in the matrix, followed by n*n values
 * The index (zero-based) of the node to be removed
 *
 * Output:
 * The result matrix
 */

#include <stdlib.h>
#include <stdio.h>

int calc(int nodec, int *paths);

int main(int argc, char *argv[]) {
  int dim, dimq, target, i, j;
  int *nodes = NULL;
  
  scanf("%d", &dim);
  if(dim <= 0) {
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
  
  scanf("%d", &target);
  if(!(target >= 0 && target < dim)) {
    fprintf(stderr, "%s: Invalid target node (%d)", argv[0], target);
    return 1;
  }  
  
  for(i = 0; i < dim ; i++) {
    if(i == target) continue;
    
    for(j = 0; j < dim ; j++) {
      if(j == target) continue;
    
      printf("%d ", nodes[j + (i * dim)]);
    }
    
    printf("\n");
  }

  free(nodes);
  
  return 0;
}