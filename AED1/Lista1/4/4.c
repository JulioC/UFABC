#include <stdio.h>

void yyy(int v[], unsigned int n, int * min, int * max);

int main(void) {
	// Test arrays
	int case1[] = {3, -92, 0, 213, -242};
	int case2[] = {0};
	int case3[] = {84, 2, 84};
	
	int n, min, max;
	
	printf("Test Case 1: ");
	for(n = 0; n < 5; n++) {
		printf("%d ", case1[n]);
	}
	printf("\n");
	yyy(case1, 5, &min, &max);
	printf("Min: %d Max: %d\n", min, max);
	
	printf("Test Case 2: ");
	for(n = 0; n < 1; n++) {
		printf("%d ", case2[n]);
	}
	printf("\n");
	yyy(case2, 1, &min, &max);
	printf("Min: %d Max: %d\n", min, max);
	
	printf("Test Case 3: ");
	for(n = 0; n < 3; n++) {
		printf("%d ", case3[n]);
	}
	printf("\n");
	yyy(case3, 3, &min, &max);
	printf("Min: %d Max: %d\n", min, max);

	return 0;
}

void yyy(int v[], unsigned int n, int *min, int *max) {
	int x;
	
	*min = *max = v[0];
	
	for(x = 0; x < n; x++) {
		if(v[x] > *max) {
			*max = v[x];
		}
		if(v[x] < *min) {
			*min = v[x];
		}
	}
}