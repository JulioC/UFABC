#include <stdio.h>

int MDC(int x, int y);

int main(void) {
	printf("MDC(12, 18) = %d\n", MDC(12, 18));
	printf("MDC(12, 18) = %d\n", MDC(11, 121));

	return 0;
}

int MDC(int x, int y) {	
	if(x > y) {
		return MDC(x-y, y);
	}
	if(x < y) {
		return MDC(x, y-x);
	}
		
	return x;
}