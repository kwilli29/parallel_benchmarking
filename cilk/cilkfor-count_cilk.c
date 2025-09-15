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

	while(a < 1000){
		x = x + a;
		a++;
	}

	return x;
}


int main(int argc, char*argv[]){
 	long n = 8;
	if (argc > 1){
   	n = atol(argv[1]);}

	long result = 0;
	ctimer_t t;

    ////

    result = 0;

    ctimer_start(&t);

    cilk_for(int i=0; i < n; i++){
        result = thread_routine1(i);
    }

    ctimer_stop(&t);
    ctimer_measure(&t);

    printf("\nN cilkfor-count_cilk :%ld\n", n);
    printf("Results cilkfor-count_cilk : %d: (%ld) = %ld\n", iter, n, result);
    ctimer_print(t, "Overall Time cilkfor-count_cilk :");

    printf("\n");

    cilk_sync;

	return 0;
}
