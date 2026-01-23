#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "ctimer.h"

/* Benchmark: Use cilk_for to accumulate a sum in parallel.
 * Implement a reducer to solve the race condition 'sum' causes
 */

void zero(void *view) { *(long *)view = 0; }
void add(void *left, void *right){ *(long *)left += *(long *)right; }
// long cilk_reducer(zero, add) sum;

int main(int argc, char *argv[]) {
	int n = 1000;
	if (argc > 1){
   	n = atoi(argv[1]);}

	long cilk_reducer(zero, add) sum = 0L; // sum must be initialized, sum = reducer

	// __builtin_addressof(sum) = long cilk_reducer(zero, add) *sum // address of reducer

	ctimer_t t;
	ctimer_start(&t);

	cilk_for (int i = 0; i <= n; i++){ // accumalte sum of values o to i-1
		sum += i; 
	}

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("\nN reducersum_cilk :%d\n", n); 	
	printf("Results reducersum_cilk : (%d) = %ld\n", n, sum);
	ctimer_print(t, "Overall Time reducersum_cilk :");

	printf("\n");

	//// //// 

	return 0;
}

