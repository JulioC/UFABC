#include <stdio.h>
#include <stdlib.h>

int max_ite(int *v, unsigned int n);

int max_rec(int *v, unsigned int n);

int soma_ite(int *v, unsigned int n);

int soma_ite(int *v, unsigned int n);

int main(void) {
	int x[6] = {1, 56, 5, 95, 0, 34};
	int *y = NULL;
	int n;
	
	y = (int *)malloc(sizeof(int) * 10);
	for(n = 0; n < 10; n++) {
		y[n] = n*10 + 1;
	}

	printf("max_ite(x) = %d\n", max_ite(x, 6));
	printf("max_rec(x) = %d\n", max_rec(x, 6));
	printf("soma_ite(x) = %d\n", soma_ite(x, 6));
	printf("soma_rec(x) = %d\n", soma_rec(x, 6));
	
	printf("max_ite(y) = %d\n", max_ite(y, 10));
	printf("max_rec(y) = %d\n", max_rec(y, 10));
	printf("soma_ite(y) = %d\n", soma_ite(y, 10));
	printf("soma_rec(y) = %d\n", soma_rec(y, 10));
	
	return 0;
}

int max_ite(int *v, unsigned int n) {
	unsigned int x;
	int max = v[0];
	
	for(x = 0; x < n; x++) {
		if(v[x] > max) {
			max = v[x];
		}
	}
	
	return max;
}

// Here be dragons
int max_rec(int *v, unsigned int n) {
	int x = n == 1 ? v[0] : max_rec(v+1, n-1);

	return v[0] > x ? v[0] : x;
}

int soma_ite(int *v, unsigned int n) {
	unsigned int x;
	int soma = 0;	
	
	for(x = 0; x < n; x++) {
		soma += v[x];
	}
	
	return soma;
}

// Here be dragons
int soma_rec(int *v, unsigned int n) {
	return v[0] + (n == 1 ? 0 : soma_rec(v+1, n-1));
}