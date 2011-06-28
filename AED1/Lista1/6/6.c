#include <stdio.h>
#include "Vetor.h"

int main(void) {
	Vetor v = CriaVetor(10);
	
	unsigned int n;
	for(n = 0; n < v.m; n++) {
		AtribuiVetor(v, (n*10)+1, n);	
	}
	
	for(n = 0; n < v.m; n++) {
		printf("%d ", v.array[n]);
	}
	
	LiberaVetor(v);
	
	return 0;
}