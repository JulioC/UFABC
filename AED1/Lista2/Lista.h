#ifndef LISTA_H_
#define LISTA_H_

#define LISTA_NULO -1

typedef struct {
	int valor;
	int prox;
} ItemLista;

typedef struct {
	ItemLista *itens;
	int dispo;
	int prim;
} Lista;

// Cria uma lista vazia, para até n elementos
Lista CriaLista(int n);

// Retorna 1 se a lista está vazia
int Vazia(Lista l);

// Insere um elemento no início da lista
void InsereInicio(Lista *l, int v);

// Insere um elemento no fim da lista
void InsereFim(Lista *l, int v);

// Remove o primeiro elemento da lista
int RemoveInicio(Lista *l);

// Remove o ultimo elemento da lista
int RemoveFim(Lista *l);

// Busca um elemento na lista
int Busca(Lista l, int v	);

// Imprime os elementos das lista
void Imprime(Lista l);

// Obtem o comprimento da lista
int Comprimento(Lista l);

// Libera o espaço da lista
void Libera(Lista *l);

#endif