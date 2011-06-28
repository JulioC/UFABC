#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Show debug info
#define DEBUG

// Parity: 1 = odd
#define PARITY 1 

int main(int argc, char **argv) {
	// Ensure that we have a word to compute
	if(argc < 2) {
		printf("usage: %s [word]\n", argv[0]);
		return 1;
	}
	
	char *w = argv[1];
	char *r = NULL;
	int l = strlen(w);
	int n, p, t, x, y, z;	
	
#ifdef DEBUG 
	printf("Word length: %d\n", l);
#endif
	
	// Check if the word is valid [made of 1 and 0]
	for(x = 0; x < l; x++) {
		if(w[x] != '0' && w[x] != '1') {
			printf("Invalid character (pos %d)\n", x);
			return 1;	
		}
	}

	// Here be dragons!
	// Compute hamming digits number, which should be 2^n >= n + l +1
	for(n = 0; ; n++) {
		if((1 << n) >= (n + l + 1)) break;
	}
	
#ifdef DEBUG 
	printf("Hamming digits: %d\n", (n));
#endif

	t = n + l;
	
	// Allocate enough space to Hamming code
	r = (char *)malloc(sizeof(char) * (t +1));
	if(r == NULL) {
		printf("Unable to alloc result");
		return 1;
	}
	
	// Write the data bits on their positions
	for(x = y = z = p = 0; x < t; x++) {
		if(z == 0) {
			z = 1 << p++;
			r[x] = 'A'+p-1;
		} else {
			r[x] = w[y++];
		}		
		
		z--;
	}
	r[t] = '\0';
	
#ifdef DEBUG
	printf("Parity Mask: %s\n", r);
#endif
	
	for(p = 0; p < n; p++) {
		y = 1 << n;
		for(x = 0; x < t; x++) {
			// TODO: get number of 1s for parity bit
		}
		// TODO: add parity bits
	}

	//printf("%s", r);
	
	free(r);
	
	return 0;
}