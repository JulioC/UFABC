#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Chamadas.h"

struct t_Chamada {
  char *tel;
  float val;
  Chamada *prox;
};

#ifdef RECURSIVE

void ChEspera(Chamada **ch, const char *tel, float val) {
  // Só inserimos se a prioridade for menor ou igual ao inicio
  if(NULL != *ch) {
    if((*ch)->val >= val) {
      ChEspera(&((*ch)->prox), tel, val);
      return;
    }
  }
  
  // Aloca a chamada atual
  Chamada *temp = (Chamada *)malloc(sizeof(Chamada));
  if(NULL == temp) { return; }
  
  // Aloca espaço para a string do telefone
  temp->tel = (char *)malloc(sizeof(Chamada) * (strlen(tel) + 1));
  if(NULL == temp->tel) { return; }
  
  // Preenche a estrutura temporária com os valores
  strcpy(temp->tel, tel);
  temp->val = val;
  temp->prox = *ch;
  
  *ch = temp;
}

#else

void ChEspera(Chamada **ch, const char *tel, float val) {
  Chamada **cur = ch;
  while(NULL != *cur && (*cur)->val >= val) {
    cur = &((*cur)->prox);
  }
 
  // Aloca a chamada atual
  Chamada *temp = (Chamada *)malloc(sizeof(Chamada));
  if(NULL == temp) { return; }
  
  // Aloca espaço para a string do telefone
  temp->tel = (char *)malloc(sizeof(Chamada) * (strlen(tel) + 1));
  if(NULL == temp->tel) { return; }
  
  // Preenche a estrutura temporária com os valores
  strcpy(temp->tel, tel);
  temp->val = val;
  temp->prox = *cur;
  
  *cur = temp;
}

#endif

int ChRetoma(Chamada **ch, char *tel) {
  // Retorna 0 se não houver chamadas em espera
  if(NULL == *ch) { return 0; }
  
  // Altera o valor do ponteiro passado por argumento
  Chamada *temp = (*ch); 
  *ch = temp->prox;
  
  // Copia o valor do telefone
  strcpy(tel, temp->tel);
  
  // Libera o espaço usado pela chamada
  free(temp);
  
  return strlen(tel);
}