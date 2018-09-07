#include <stdio.h>
#include <stdlib.h>

int main() {
	int A[100];
	int i;
	srand(1234);
	
	for (i = 0; i < 100; i++) {
		A[i] = rand() % 1000;
		printf("A[%d]: %d,\tA[%d]x10: %d\n", i, A[i], i, A[i] * 10);
	}	
}
