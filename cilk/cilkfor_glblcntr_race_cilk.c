#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "ctimer.h"

/* Benchmark: cilk_for spawns threads to incrememnt a gloabl counter.
 * Counter is a race condition.
 */

long counter = 0;

void thread_routine(){ // race condition

	counter++;

	return;
}

// loop spawn 1000 (or user specified #) children & return, each child incr. counter
// for all of vary sz & params, measure times for for all


int main(int argc, char *argv[]) {
	int n = 1000;
	if (argc > 1){
   	n = atol(argv[1]);}

	ctimer_t t;
	ctimer_start(&t);

	// pragma grain sz
	cilk_for(int i=0; i < n; i++){ // cilk for
		thread_routine();
	}

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("\nN cilkfor_glblcntr_race_cilk :%d\n", n);	
	printf("Results cilkfor_glblcntr_race_cilk : (%d) = %ld\n", n, counter);
	ctimer_print(t, "Overall Time cilkfor_glblcntr_race_cilk: ");

	printf("\n");

	cilk_sync;

	return 0;
}

