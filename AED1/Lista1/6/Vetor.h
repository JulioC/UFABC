#ifndef VETOR_H_
#define VETOR_H_

typedef struct {
	unsigned int m;
	int *array;
} Vetor;

Vetor CriaVetor(unsigned int m);

void AtribuiVetor(Vetor v, int n, unsigned int i);

void DestroiVetor(Vetor v);

#endif