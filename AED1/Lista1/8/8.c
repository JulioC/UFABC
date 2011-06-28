#include <stdio.h>
#include <stdlib.h>

double func_rec(unsigned int n);

double func_iter(unsigned int n);

int main(void) {
	printf("func_iter(%d) = %f\n", 2, func_iter(2));
	printf("func_iter(%d) = %f\n", 4, func_iter(4));
	printf("func_iter(%d) = %f\n", 100, func_iter(100));
	
	printf("func_rec(%d) = %f\n", 2, func_rec(2));
	printf("func_rec(%d) = %f\n", 4, func_rec(4));
	printf("func_rec(%d) = %f\n", 100, func_rec(100));
	
	return 0;
}

double func_rec(unsigned int n) {
	if(n == 1) return 1;
	
	double soma = func_rec(n-1);
	
	if(n % 2) {
		soma += 1.0/n;
	} 
	else {
		soma -= 1.0/n;
	}
	
	return soma;
}

double func_iter(unsigned int n) {
	unsigned int x;
	double soma = 0.0;	
	
	for(x = n; x > 0; x--) {
		if(x % 2) {
			soma += 1.0/x;
		} 
		else {
			soma -= 1.0/x;
		}
	}
	
	return soma;
}