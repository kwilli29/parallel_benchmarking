#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "ctimer.h"

/* Benchmark: for-count cilk
 * Use a regular for loop to spawn a thread routine
 * where each thread waits in a while loop and increments counters.
 *
 * "x" is passed into the thread routine in order to potentially 
 * see if there's any effect with caching, instead of adding up same numbers each time. 
 */

int thread_routine1(int x){ // this thread function is called in for loop

	int a = 0; 

	while(a < 100){ // x is passed in and is the value of i in for loop
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

	while(iter < NITER){ // call the for loop NITER times to see effect 
								// the more the for loop is called
		result = 0;

		ctimer_start(&t);

		for(int i=0; i < n; i++){
			result = cilk_spawn thread_routine1(i); // spawn threads, pass in i
		}
		cilk_sync;

		ctimer_stop(&t);
		ctimer_measure(&t);

		printf("for-count cilk #%d: (%ld) = %ld\n", iter, n, result);
		ctimer_print(t, "for-count cilk");

		printf("\n");

		iter++;

	}

	return 0;
}
