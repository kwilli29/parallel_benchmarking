#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "ctimer.h"

/* Benchmark: for loop spawns pthreads to increment a gloabl counter.
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
	int n = 1000;
	if (argc > 1){
   	n = atol(argv[1]);}

	ctimer_t t;
	//ctimer_start(&t);

	// create threads
	pthread_t thread1[n];

	ctimer_start(&t);

	for(int i=0; i < n; i++){

		if (pthread_create(&thread1[i], NULL, (void *)thread_routine, NULL) != 0){
			perror("pthread_create"); exit(1); }

		if (pthread_join(thread1[i], NULL) != 0){
			perror("pthread_join");exit(1); }
	}

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("N :%d\n", n);	
	printf("Results ptfor_glblcntr_race_pthreads : (%d) = %ld\n", n, counter);
	ctimer_print(t, "ptfor_glblcntr_race_pthreads :");

	printf("\n");

	return 0;
}

