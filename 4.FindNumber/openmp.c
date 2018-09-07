#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
	int A[100];
	int i;
	int boolean = 0;
	int number = 500;
	srand(1234);
	
	for (i = 0; i < 100; i++) {
		A[i] = rand() % 1000;
	}

	#pragma omp parallel for
	for (i = 0; i < 100; i++) {
		boolean = (A[i] >= number) ? 1 : 0;
		printf("A[%d]: %d,\tA[%d] >= 500: %d\n", i, A[i], i, boolean);
	}
}
