#include <stdlib.h>
#include "Vetor.h"

Vetor CriaVetor(unsigned int m) {
	Vetor v;
	v.m = m;
	v.array = (int *)malloc(sizeof(int) * m);
	
	unsigned int x;
	for(x = 0; x < m; x++) {
		v.array[x] = 0;
	}
	
	return v;
}

void AtribuiVetor(Vetor v, int n, unsigned int i) {
	v.array[i] = n;
}

void LiberaVetor(Vetor v) {
	free(v.array);
	
	v.m = 0;
	v.array = NULL;
}