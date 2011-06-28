#include <stdio.h>
#include <string.h>

void convert(int num, int base, char *res);

int main(int argc, char **argv) {
	printf("%d", sizeof(long long int));
	
	if(argc < 3) {
		printf("usage: %s <num> <base>", argv[0]);
		return 1;
	}
	
	int num, base;
	num = atoi(argv[1]);
	base = atoi(argv[2]);
	
	char res[128];
	convert(num, base, res);
	
	printf("%s", res);
}

void convert(int num, int base, char *res) {
	int n = 0;
	do {
		res[n] = '0' + (num % base);
		num = num/base;
		n++;
	} while(num);
	res[n] = '\0';

	char aux;
	int len = strlen(res)-1;
	for(n = (len/2); n >= 0; n--) {
		aux = res[n];
		res[n] = res[len-n];	
		res[len-n] = aux;
	}
}
