#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "ctimer.h"
#include <sys/time.h>

/* Benchmark: Use cilk_for to accumulate a sum in parallel.
 * Implement a reducer to solve the race condition 'sum' causes
 */

void zero(void *view) { *(long *)view = 0; }
void add(void *left, void *right){ *(long *)left += *(long *)right; }
// long cilk_reducer(zero, add) sum;

int main(int argc, char *argv[]) {
	int n = 1000;
	int gs = 1;

	if (argc > 1){
   	n = atoi(argv[1]);}
	if(argc > 2){
		gs = atoi(argv[2]);
	}

	printf("GRAIN SIZE: %d\n", gs);

	long cilk_reducer(zero, add) sum = 0L; // sum must be initialized, sum = reducer

	// __builtin_addressof(sum) = long cilk_reducer(zero, add) *sum // address of reducer

	// ctimer_t t; ctimer_start(&t);
	
	struct timeval start_time,end_time;
	gettimeofday(&start_time, NULL);

	#pragma grainsize = gs	
	cilk_for (int i = 0; i <= n; i++){ // accumalte sum of values 0 to i-1
		sum += i; 
	}

	gettimeofday(&end_time, NULL);
	double realTime = (end_time.tv_sec+ (double)end_time.tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);

	// ctimer_stop(&t); ctimer_measure(&t);

	printf("/nPragma: %d\n", gs);
	printf("\nN reducersum_cilk :%d\n", n); 	
	printf("Results reducersum_cilk : (%d) = %ld\n", n, sum);
	printf("\nOverall Time reducersum_cilk  = %lf", realTime);	
	// ctimer_print(t, "Overall Time reducersum_cilk :");
	printf("\n");

	cilk_sync;

	//// //// 

	return 0;
}

