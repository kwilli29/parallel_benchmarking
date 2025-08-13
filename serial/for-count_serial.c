#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "ctimer.h"

/* Serial Benchmark: for-count serial
 * Use a regular for loop to call a function
 * where each function is in a while loop and increments counters.
 *
 * "x" is passed into the function in order to potentially 
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

	while(iter < NITER){
		result = 0;

		ctimer_start(&t);

		for(int i=0; i < n; i++){
	 		result = thread_routine1(i);
		}

		ctimer_stop(&t);
		ctimer_measure(&t);

		printf("forcnt serial th_routine #%d: (%ld) = %ld\n", iter, n, result);
		ctimer_print(t, "forcnt serial th_routine");

		printf("\n");

		iter++;

	}

	return 0;
}
