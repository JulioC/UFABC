#include <stdio.h>
#include <stdlib.h>

struct Produto_t {
	char nome[64];
	float valor;
	unsigned int quantidade;
};

typedef struct Produto_t Produto;

int main(void) {
	char continua = '\0';
	int numprods = 0;
	Produto *lista = NULL;
	
	do {				
		// Realoca a lista de produtos para um array maior
		Produto *temp = NULL;
		temp = (Produto *)malloc(sizeof(Produto) * (numprods+1));
		if(temp == NULL) continue;
		
		int n;
		for(n = 0; n < numprods; n++) {
			temp[n] = lista[n];
		}
		
		free(lista);
		lista = temp;
		
		// Obtem o novo produto
		Produto *prod = NULL;
		prod = lista + numprods;
		
		printf("Insira o nome do produto\n");
		scanf("%[^\n]%*c", &prod->nome);
		
		printf("Insira o valor do produto\n");
		scanf("%f%*c", &prod->valor);
		
		printf("Insira a quantidade do produto\n");
		scanf("%i%*c", &prod->quantidade);
		
		// Exibe o subtotal do produto (valor*quantidade)
		printf("Subtotal %.2f\n", (prod->valor * prod->quantidade));
		
		numprods++;
		
		printf("Continua? (S/N) ");
		scanf("[A-Ba-z]%*c", &continua);
	} while(continua != 'N' && continua != 'n');
	
	// Calcula o valor total da lista
	int n;
	float total = 0.0;
	for(n = 0; n < numprods; n++) {
		total += lista[n].valor * lista[n].quantidade;
	}
	
	printf("Produtos: %d\n", numprods);
	printf("Valor total: %.2f\n", total);
	
	free(lista);
	
	return 0;
}