/*
 * test.c
 *  
 * Rotinas de testes do tipo BigN, com a utilização de todos 
 * os métodos de manipulação e conversão disponíveis.
 *
 */
 
 #include <stdio.h>
#include "BigN.h"

#define BUFFER_LEN 256

int main(void) {
	char buffer[BUFFER_LEN];
	char *str = "93458020829";
	int arr[] = {5, 7, 2, 7, 2, 0, 2, 5, 2, 0};
	
	BigN a = NULL;
	BigN b = NULL;
	BigN c = NULL;
	BigN sum = NULL;
	BigN mult = NULL;
	
	a = BNFromInt(43456);
	b = BNFromStr(str);
	c = BNFromArr(arr, 7);

	BNToStr(a, buffer, BUFFER_LEN);
	printf("a = %s\n", buffer);
	
	BNToStr(b, buffer, BUFFER_LEN);
	printf("b = %s\n", buffer);
	
	BNToStr(c, buffer, BUFFER_LEN);
	printf("c = %s\n", buffer);
	
	sum = BNSum(b, c);
	mult = BNMult(a, c);
	
	BNToStr(sum, buffer, BUFFER_LEN);
	printf("b + c = %s\n", buffer);
	
	BNToStr(mult, buffer, BUFFER_LEN);
	printf("a * c = %s\n", buffer);
	
	BNDestroy(a);
	BNDestroy(b);
	BNDestroy(c);
	BNDestroy(mult);
	BNDestroy(sum);
	
	return 0;
}	