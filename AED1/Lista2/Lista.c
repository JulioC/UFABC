#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Lista CriaLista(int n) {
	Lista l;
	l.itens = malloc(sizeof(ItemLista) * n);
	if(l.itens == NULL) return l;
	
	int x;
	for(x = 0; x < n; x++) {
		l.itens[x].prox = x+1;
	}
	l.itens[n-1].prox = LISTA_NULO;
	
	l.dispo = 0;
	l.prim = LISTA_NULO;
	
	return l;
}

int Vazia(Lista l) {
	return l.prim == LISTA_NULO;
}

void InsereInicio(Lista *l, int v) {
	if(l->dispo == LISTA_NULO) return;
	
	int pos = l->dispo;
	
	l->dispo = l->itens[pos].prox;
		
	l->itens[pos].valor = v;
	l->itens[pos].prox = l->prim; 
	
	l->prim = pos;
}

void InsereFim(Lista *l, int v) {
	if(l->dispo == LISTA_NULO) return;
	
	int pos = l->dispo;
	
	l->dispo = l->itens[pos].prox;
		
	l->itens[pos].valor = v;
	l->itens[pos].prox = LISTA_NULO; 
	
	if(l->prim == LISTA_NULO) {
		l->prim = pos;
	}
	else {
		int cur = l->prim;
		while(l->itens[cur].prox != LISTA_NULO) {
			cur = l->itens[cur].prox;
		}
		
		l->itens[cur].prox = pos;
	}	
}

int RemoveInicio(Lista *l) {
	if(Vazia(*l)) return;
	
	int pos = l->prim;
	
	l->prim = l->itens[pos].prox;
	
	l->itens[pos].prox = l->dispo;
	l->dispo = pos;
	
	return l->itens[pos].valor;
}

int RemoveFim(Lista *l) {
	if(Vazia(*l)) return;
	
	int pos = l->prim;
	int ant = LISTA_NULO;
	while(l->itens[pos].prox != LISTA_NULO) {
		ant = pos;
		pos = l->itens[pos].prox;
	}
	
	if(ant != LISTA_NULO) {
		l->itens[ant].prox = LISTA_NULO;
	}
	
	l->itens[pos].prox = l->dispo;
	l->dispo = pos;
	
	return l->itens[pos].valor;
}

int Busca(Lista l, int v) {
	int pos = l.prim;
	int n = 0;
	
	while(pos != LISTA_NULO) {
		if(l.itens[pos].valor == v) {
			return n;
		}
		pos = l.itens[pos].prox;
		n++;
	}
	
	return LISTA_NULO;
}

void Imprime(Lista l) {
	int pos = l.prim;
	int n = 0;
	
	while(pos != LISTA_NULO) {
		printf("#%d = %d\n", n, l.itens[pos].valor);
		pos = l.itens[pos].prox;
		n++;
	}
}

int Comprimento(Lista l) {
	int pos = l.prim;
	int n = 0;
	
	while(pos != LISTA_NULO) {
		pos = l.itens[pos].prox;
		n++;
	}
	
	return n;
}

void Libera(Lista *l) {
	free(l->itens);
	l->itens =  NULL;
	l->dispo = 0;
	l->prim = LISTA_NULO;
}