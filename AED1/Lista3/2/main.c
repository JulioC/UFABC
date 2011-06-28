#include <stdio.h>
#include "Chamadas.h"

// Comente essa linha para não usar recursividade nas funções
#define RECURSIVE

int main(void) {
	Chamada *ch = NULL;
  int i;
  char buffer[64];
  float val;
  
  do {
    printf("\nSelecione\n");
    printf(" 1 - Adicionar Chamada em Espera\n");
    printf(" 2 - Remover Chamada em Espera\n");
    printf(" 0 - Sair\n");
    printf("Opcao: ");
    scanf("%i%*c", &i);
    printf("\n");

    switch(i) {
      case 1:
        printf("Telefone: ");
        scanf("%s", buffer);
        printf("Custo da ligacao: ");
        scanf("%f", &val);
        
        ChEspera(&ch, buffer, val);
      break;
      case 2:
        if(ChRetoma(&ch, buffer)) {
          printf("Chamada retomada: %s\n", buffer);
        }
        else {
          printf("Nao ha chamadas em espera\n");
        }
      break;
    }  
  } while(i != 0);
	
	return 0;
}