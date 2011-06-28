#include <stdlib.h>
#include "Matriz.h"

Matriz CriaMatriz(unsigned int m, unsigned int n) {
	Matriz a;
	a.m = m;
	a.n = n;
	a.array = (int **)malloc(sizeof(int *) * m);
	
	unsigned int x, y;
	for(x = 0; x < m; x++) {
		a.array[x] = (int *)malloc(sizeof(int) * n);
		
		for(y = 0; y < n; y++) {
			a.array[x][y] = 0;
		}
	}
	
	return a;
}

void AtribuiMatriz(Matriz a, int n, unsigned int i, unsigned int j) {
	a.array[i][j] = n;
}

void LiberaMatriz(Matriz a) {
	unsigned int x; 
	for(x = 0; x < a.m; x++) {
		free(a.array[x]);
		a.array[x] = NULL;
	}
	
	free(a.array);
	
	a.m = 0;
	a.n = 0;
	a.array = NULL;
}