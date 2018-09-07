#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
	int A[100];
	int i, max = 0;
	srand(1234);
	
	for (i = 0; i < 100; i++) {
		A[i] = rand() % 1000;
	}

	#pragma omp parallel for reduction(max:max)
	for (i = 0; i < 100; i++) {
		max = (A[i] > max) ? A[i] : max;
		printf("A[%d]: %d, max:%d\n", i, A[i], max);
	}

	printf("Max: %d\n", max);	
}
