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

// loop spawn 1000 children & return, each child incr. counter
// for all of vary sz & params, measure times for for all

int main(int argc, char *argv[]) {
	int n = 1000000;

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

	printf("while global counter race_condition: (%d) = %ld\n", n, counter);
	ctimer_print(t, "while global counter race_condition");

	printf("\n");

	//// ////
	
	// Serial while counter

	counter=0;

	ctimer_start(&t);

   cnt = 0;
	while(cnt < n){ // while
		thread_routine();
		cnt++;
	}

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("while global counter serial: (%d) = %ld\n", n, counter);
	ctimer_print(t, "while global counter serial");

	printf("\n");

	return 0;
}

