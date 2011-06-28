#include <stdio.h>
#include "Matriz.h"

int main(void) {
	Matriz a = CriaMatriz(10, 2);
	
	unsigned int x, y;
	for(x = 0; x < 10; x++) {
		for(y = 0; y < 2; y++)
			AtribuiMatriz(a, (x*10)+y, x, y);
	}	
	
	for(x = 0; x < 10; x++) {
		for(y = 0; y < 2; y++)
			printf("%5d ", a.array[x][y]);
		printf("\n");
	}
	
	return 0;
}