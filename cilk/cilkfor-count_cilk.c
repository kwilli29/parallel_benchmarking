#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "ctimer.h"

/* Benchmark: cilkfor-count cilk
 * Use a cilk_for loop to spawn a thread routine
 * where each thread waits in a while loop and increments counters.
 *
 * "x" is passed into the thread routine in order to potentially 
 * see if there's any effect with caching, instead of adding up same numbers each time. 
 */

int thread_routine1(int x){

	int a = 0; 

	while(a < 100){
		x = x + a;
		a++;
	}

	return x;
}


int main(int argc, char*argv[]){
 	long n = 8;
	if (argc > 1){
   	n = atol(argv[1]);}

	int NITER = 4; int iter = 0;
	long result = 0;
	ctimer_t t;

	while(iter < NITER){ // run the cilkfor count NITER times
		result = 0;

		ctimer_start(&t);

		cilk_for(int i=0; i < n; i++){
	 		result = thread_routine1(i);
		}

		ctimer_stop(&t);
		ctimer_measure(&t);

		printf("cilkfor-count #%d: (%ld) = %ld\n", iter, n, result);
		ctimer_print(t, "cilkfor-count");

		printf("\n");

		cilk_sync;

		iter++;

	}

	return 0;
}
