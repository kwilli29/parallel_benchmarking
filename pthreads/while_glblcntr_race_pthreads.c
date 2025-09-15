#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "ctimer.h"

/* Benchmark: while loop spawns pthreads to incrememnt a global counter.
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
   	n = atoi(argv[1]);}

	ctimer_t t;

	// create threads
	pthread_t thread1[n];

	ctimer_start(&t);

	int cnt=0;
	while(cnt < n){ // while

		if (pthread_create(&thread1[cnt], NULL, (void *)thread_routine, NULL) != 0){
			perror("pthread_create"); exit(1); }

		if (pthread_join(thread1[cnt], NULL) != 0){
			perror("pthread_join");exit(1); }

		cnt++;
	}

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("N :%d\n", n);
	printf("Results while_glblcntr_race_pthreads: (%d) = %ld\n", n, counter);
	ctimer_print(t, "Overall Time while_glblcntr_race_pthreads :");

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

