#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <pthread.h> 
#include "ctimer.h"
#include <sys/time.h>

/* Benchmark: cilk_for spawns threads to incrememnt a gloabl counter.
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
	int gs = 1;

	if (argc > 1){      // argv[1] = # of Threads
   	n = atol(argv[1]);}
	if(argc > 2){       // argv[2] = Grain size
		gs = atoi(argv[2]);
	}

	printf("GRAIN SIZE: %d\n", gs);
	
	if (pthread_mutex_init(&m, NULL) != 0) { perror("Mutex initialization failed"); return 1;}

	// ctimer_t t; ctimer_start(&t);
	struct timeval start_time,end_time;
	gettimeofday(&start_time, NULL);

	#pragma grainsize = gs         // Define grain size
	cilk_for(int i=0; i < n; i++){ // cilk_for call function to increment global counter
		thread_routine();
	}

	gettimeofday(&end_time, NULL);
	double realTime = (end_time.tv_sec+ (double)end_time.tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);

	//ctimer_stop(&t); ctimer_measure(&t);

	printf("/nPragma: %d\n", gs);
	printf("\nN cilkfor_glblcntr_norace_cilk :%d\n", n);
	printf("Results cilkfor_glblcntr_norace_cilk : (%d) = %ld\n", n, counter);
	printf("\nOverall Time cilkfor_glblcntr_norace_cilk = %lf", realTime);
	// ctimer_print(t, "Overall Time cilkfor_glbl_cntr_norace_cilk :");
	printf("\n");

	cilk_sync;
	pthread_mutex_destroy(&m);
	return 0;
}

