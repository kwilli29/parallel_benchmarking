#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <pthread.h> 
#include "ctimer.h"

/* Benchmark: while loops spawns threads to incrememnt a gloabl counter.
 * Counter is not a race condition.
 */

long counter = 0;

pthread_mutex_t m;

void thread_routine(){ // Locks

	pthread_mutex_lock(&m);
	counter++;
	pthread_mutex_unlock(&m);

	return;
}

// loop spawn 1000 (or user specified #) children & return, each child incr. counter
// for all of vary sz & params, measure times for for all

int main(int argc, char *argv[]) {
	int n = 1000;
	if (argc > 1){
   	    n = atoi(argv[1]);
    }

	if (pthread_mutex_init(&m, NULL) != 0) { perror("Mutex initialization failed"); return 1;}

	ctimer_t t;
	ctimer_start(&t);

   int cnt = 0;
	while(cnt < n){ // while
		thread_routine();	
		cnt++;
	}

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("N while_glblcntr_norace_cilk :%d\n", n);
	printf("Results while_glblcntr_norace_cilk : (%d) = %ld\n", n, counter);
	ctimer_print(t, "Overall Time while_glbl_cntr_norace_cilk :");

	printf("\n");

	cilk_sync;

	pthread_mutex_destroy(&m);

	return 0;
}

