#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include "ctimer.h"

/* Benchmark: ptfor-count pthreads
 * Use a cilk_for loop to spawn a thread routine
 * where each thread waits in a while loop and increments counters.
 *
 * "x" is passed into the thread routine in order to potentially 
 * see if there's any effect with caching, instead of adding up same numbers each time. 
 */

int thread_routine(int x){

	int a = 0; 

	while(a < 100){
		x = x + a;
		a++;
	}

	pthread_exit(&x);
	return x;
}


int main(int argc, char*argv[]){
 	long n = 8;
	if (argc > 1){
   	n = atol(argv[1]);}

	// create threads
	pthread_t thread1[n];

	int NITER = 4; int iter = 0;
	long result = 0;
	ctimer_t t;

	//while(iter < NITER){ // run the for count NITER times
		result = 0;

		ctimer_start(&t);

		for(int i=0; i < n; i++){

			if (pthread_create(&thread1[i], NULL, (void *)thread_routine, (void *)(size_t)i) != 0){
				perror("pthread_create"); exit(1); }

	 		//result = thread_routine(i);
		
			if (pthread_join(thread1[i], (void**)result) != 0){
				perror("pthread_join");exit(1); }
		}

		ctimer_stop(&t);
		ctimer_measure(&t);

		printf("N :%ld\n", n);
		printf("Results ptfor-count #%d: (%ld) = %ld\n", iter, n, result);
		ctimer_print(t, "Overall Time ptfor-count :");

		printf("\n");

		iter++;

	// }

	return 0;
}
