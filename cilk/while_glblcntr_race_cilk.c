#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "ctimer.h"

/* Benchmark: while loop spawns threads to incrememnt a gloabl counter.
 * Counter is a race condition.
 */

long counter = 0;

void thread_routine(){ // race condition

	counter++;

	return;
}

// loop spawn default 1000 (or user specified #) children & return, each child incr. counter
// for all of vary sz & params, measure times for for all

int main(int argc, char *argv[]) {
	int n = 1000;
	if (argc > 1){
   	    n = atoi(argv[1]);
    }

	ctimer_t t;
	ctimer_start(&t);

   int cnt = 0;
	while(cnt < n){ // while
		cilk_spawn thread_routine();	
		cnt++;
	}
	cilk_sync;

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("N while_glblcntr_race_cilk :%d\n", n);
	printf("Results while_glblcntr_race_cilk : (%d) = %ld\n", n, counter);
	ctimer_print(t, "Overall Time while_glblcntr_race_cilk :");

	printf("\n");

	//// ////

	return 0;
}

