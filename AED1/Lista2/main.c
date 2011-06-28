#include <stdio.h>
#include "Lista.h"

int main(void) {
	Lista l = CriaLista(10);
		
	InsereInicio(&l, 1);	
	InsereFim(&l, 116);
	InsereFim(&l, 62);
	InsereInicio(&l, 145);	
	InsereInicio(&l, 5);	
	InsereFim(&l, 662);
	InsereFim(&l, 696);
	InsereFim(&l, 6);
	
	Imprime(l);
	printf("\n");
		
	RemoveInicio(&l);		
	RemoveInicio(&l);	
	RemoveFim(&l);
	
	Imprime(l);
	printf("\n");
	
	InsereInicio(&l, 1);	
	InsereInicio(&l, 5);	
	InsereFim(&l, 662);
	InsereFim(&l, 696);
	
	Imprime(l);
	printf("\n");
	
	printf("Comprimento: %d\n", Comprimento(l));
	printf("Posicao de 62: %d\n", Busca(l, 62));
	
	Libera(&l);
	
	return 0;
}