/*
 * BigN.c
 *
 * Implementação dos métodos de manipulação e conversão
 * para o tipo de dado BigN
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BigN.h"

struct BNAlg{
	byte v; // Já que só vamos guardar valores de 0 a 9, usamos o menor tipo de dado possivel
	struct BNAlg *n;
};

BigN BNFromInt(long long int val) {
	int len = 0;
	int n = val;
	BigN num = NULL;
	
	// Obtem o numero de algarismos de val 
	do {
		n = n/10;
		len++;
	} while (n);
	
	// Percorre os algarismos de val, a partir do maior valor
	for(n = len-1; n >= 0; n--) {
		int y;
		long long int p = 1;
		
		// Calcula a e-nesima potencia de 10
		// (por algum motivo, a função pow retorna resultados errados)
		for(y = 0; y < n; y++) {
			p = p*10;
		}
		
		// O algarismo atual é o resto da divisão de val pela n-esima potencia de 10
		int alg = val/p;
		
		// Remove o algarismo atual de val
		val = val - (alg * p);
		
		// Aloca espaço para o algarismo
		BigN tmp = (BigN)malloc(sizeof(struct BNAlg));
		if(tmp == NULL) continue;
		
		// Atribui o valor do algarismo atual
		tmp->v = alg;
		// Liga o algoritmo atual ao ultimo
		tmp->n = num;
		num = tmp;	
	}
	
	return num;
}

BigN BNFromArr(int *arr, int len) {
	int n;
	BigN num = NULL;
	
	// Percorre os elementos da
	for(n = 0; n < len; n++) {
		// Aloca espaço para o algoritmo
		BigN tmp = (BigN)malloc(sizeof(struct BNAlg));
		if(tmp == NULL) continue;
		
		tmp->v = arr[n];
		// Liga o algoritmo atual ao ultimo
		tmp->n = num;
		num = tmp;	
	}
	
	return num;
}

BigN BNFromStr(char* str) {
	BigN num = NULL;

	// Percorre até o fim da string	
	while(*str != '\0') {
		char chr = *str;
		str++;
		
		// Aloca espaço para o algaritmo atual
		BigN tmp = (BigN)malloc(sizeof(struct BNAlg));
		if(tmp == NULL) continue;
	
		// Calcula o valor do algarismo atual
		tmp->v =  chr - '0';
		
		tmp->n = num;			
		num = tmp;
	}
	
	return num;
}

BigN BNSum(BigN n1, BigN n2) {
	BigN arr[2];
	arr[0] = n1;
	arr[1] = n2;
	
	return BNSumArray(arr, 2);
}

BigN BNSumArray(BigN *arr, int len) {
	int aux = 0;
	int n, val;
	
	BigN lst = NULL;
	BigN sum = NULL;
	BigN tmp = NULL;
	BigN *arr2 = NULL;
	
	// Copia a array, assim podemos modifica-la sem problemas
	arr2 = (BigN *)malloc(len * sizeof(BigN));
	for(n = 0; n < len; n++) {
		arr2[n] = arr[n];
	}
	
	while(1) {
		// Obtem o valor da "casa" atual
		val = aux;
		for(n = 0; n < len; n++) {
			if(arr2[n] != NULL) {
				val += arr2[n]->v; 
				arr2[n] = arr2[n]->n;
			}
		}
		
		// Se val é 0, saimos do loop
		if(!val) break;
		
		// Obtem o "resto"
		aux = val / 10;

		// Aloca espaço para o algarismo
		tmp = (BigN)malloc(sizeof(struct BNAlg));
		if(tmp == NULL) continue;
		
		// O valor dp algarismo atual é o resto da divisão de s por 10 
		tmp->v = val % 10;
		tmp->n = NULL;
		
		if(sum == NULL) {
			// Estamos no 1o algarismo..
			sum = tmp;
		} else {
			// Ligamos o algarismo anterior ao atual
			lst->n = tmp;
		}
		lst = tmp;
	}
	
	return sum;
}

BigN BNMult(BigN n1, BigN n2) {
	// Obtem o tamanho do nosso n1 e n2 e obtem o maior
	int n1len = BNLength(n1);
	int n2len = BNLength(n2);
	int len = n1len > n2len ? n1len : n2len;
	
	// Aloca espaço para nossos sub-resultados
	BigN *subs = (BigN *)malloc((len+1) * sizeof(BigN));
	if(subs == NULL) return NULL;
	
	int n = 0;
	int aux, v, x;
	BigN cur = NULL;
	BigN tmp = NULL;
	BigN lst = NULL;
	
	while(n1 != NULL) {
		aux = 0;
		lst = NULL;
		cur = n2;
		
		// Insere nosso primeiro algarismo
		if(n) {
			tmp = (BigN)malloc(sizeof(struct BNAlg));
			if(tmp == NULL) continue;
			
			tmp->v = 0;
			tmp->n = NULL;
			
			subs[n] = tmp;
			lst = tmp;
		}
		else if(cur != NULL){
			v = (n1->v * cur->v) + aux;
			aux = v / 10;

			tmp = (BigN)malloc(sizeof(struct BNAlg));
			if(tmp == NULL) continue;
			
			tmp->v = v % 10;
			tmp->n = NULL;
			
			subs[n] = tmp;			
			lst = tmp;
			
			cur = cur->n;
		}
		
		// TODO: Adicionar função para fazer o "shift"
		
		// Adiciona os zeros da multiplicação
		for(x = 0; x < n-1; x++) {
			tmp = (BigN)malloc(sizeof(struct BNAlg));
			if(tmp == NULL) continue;
			
			tmp->v = 0;
			tmp->n = NULL;
			
			lst->n = tmp;
			lst = tmp;
		}
		
		// Multiplica cada algarismo do numero...
		while(cur != NULL) {
			v = (n1->v * cur->v) + aux;
			aux = v / 10;

			tmp = (BigN)malloc(sizeof(struct BNAlg));
			if(tmp == NULL) continue;
			
			tmp->v = v % 10;
			tmp->n = NULL;
			
			lst->n = tmp;
			lst = tmp;
			
			cur = cur->n;
		}
		
		// Caso tenhamos alguma "sobra" para adicionar..
		while(aux) {
			v = aux % 10;
			aux = aux / 10;
			
			tmp = (BigN)malloc(sizeof(struct BNAlg));
			if(tmp == NULL) continue;
			
			tmp->v = v;
			tmp->n = NULL;
			
			lst->n = tmp;
		}
		
		// Ponteiro para acessar o subtotal atual
		n1 = n1->n;
		n++;
	}
	
	BigN res = BNSumArray(subs, n);
	
	// Libera o espaço alocado
	for(x = 0; x < n; x++) {
		BNDestroy(subs[x]);
	}	
	free(subs);
	
	return res;
}

int BNEquals(BigN n1, BigN n2) {
	while(n1 != NULL || n2 != NULL) {
		// Se um dos numeros tiver menos algarismos que o outro, são diferentes
		if(n1 == NULL || n2 == NULL) return 0;
		
		// Se os algarismos forem diferentes, n1 e n2 são diferentes
		if(n1->v != n2->v) return 0; 
		
		n1 = n1->n;
		n2 = n2->n;
	}
	
	return 1;
}

int BNLength(BigN num) {
	int n = 0;
	// Vai até o fim do BigN computando a posição
	while(num != NULL) {
		num = num->n;
		n++;	
	}
	return n;
}

void BNToStr(BigN num, char *str, int maxlen) {
	int n, len;
	
	// Obtem o maior comprimento que poderemos chegar
	len = BNLength(num);
	len = len > (maxlen-1) ? (maxlen-1) : len;
	
	// Insere os valores na string a partir do fim dela
	for(n = len-1; n >= 0; n--) {
		str[n] = '0' + num->v;
		num = num->n;
	}
	// Coloca o null terminator na string
	str[len] = '\0';
}

void BNPrint(BigN num) {	
	int len = BNLength(num);
	char *str = (char *)malloc((len+1) * sizeof(char));
	
	// Obtem o BigN como string
	BNToStr(num, str, len);
	printf("%s\n", str);
}

void BNDestroy(BigN num) {
	// Percorre todos os algarismos do BigN
	while(num != NULL) {
		BigN tmp = num;
		num = tmp->n;
		free(tmp);
	}
}