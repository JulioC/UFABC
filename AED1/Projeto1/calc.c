/*
 * calc.c
 *  
 * Calculadora simples para realizar soma e multiplicação de 
 * dois números com ilimitadas casas decimais.
 *
 */

#include <stdio.h>
#include "BigN.h"

#define BUFFER_LEN 256

int main(void) {
	char c;
	char buffer[BUFFER_LEN];
	BigN v1 = NULL;
	BigN v2 = NULL;
	BigN r = NULL;
	
	printf("Valor 1:\n");
	scanf("%s%*c", buffer);
	v1 = BNFromStr(buffer);
	
	printf("Valor 2:\n");
	scanf("%s%*c", buffer);
	v2 = BNFromStr(buffer);
	
	printf("Operacao: (+ ou *)\n");
	scanf("%c%*c", &c);
	
	switch(c) {
	case '+':
		r = BNSum(v1, v2);
		break;
	case '*':
		r = BNMult(v1, v2);
		break;
	default:
		printf("Operacao invalida\n");
		break;
	}
	
	BNToStr(r, buffer, BUFFER_LEN);
	
	printf("Resultado: %s\n", buffer);
	
	BNDestroy(v1);
	BNDestroy(v2);
	BNDestroy(r);
	
	return 0;
}	