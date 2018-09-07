#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100
#define T 4

int main() {
	int A[100];
	int i;
	int sum = 0;
	srand(1234);
	
	for (i = 0; i < N; i++) { A[i] = rand() % 1000; }

	#pragma omp parallel private(i) shared(sum) num_threads(T)
	{	
		int chunkSize = N / T;
		int tid = omp_get_thread_num();
		int start = tid * chunkSize;
		int end = (tid + 1) * chunkSize;
		int psum = 0;
	
		for (i = start; i < end; i++) {
			psum += A[i];				
		}

		#pragma omp critical
		sum += psum;	
	}

	printf("Sum: %d\n", sum);
}
