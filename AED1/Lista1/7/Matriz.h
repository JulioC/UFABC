#ifndef MATRIZ_H_
#define MATRIZ_H_

typedef struct {
	unsigned int m;
	unsigned int n;
	int **array;
} Matriz;

Matriz CriaMatriz(unsigned int m, unsigned int n);

void AtribuiMatriz(Matriz a, int n, unsigned int i, unsigned int j);

void DestroiMatriz(Matriz v);

#endif