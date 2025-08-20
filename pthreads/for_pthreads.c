#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "ctimer.h"

/* Benchmark: for loop, pthreads
 * Main thread uses for loop to spawn threads in parallel 
 * and invoke function to print value of i
 */

void threadroutine(long id){

	printf("\nSpawning thread: %ld\n", id); // print "thread id"

	return;
}

int main(int argc, char *argv[]) {

	long n = 10;
	long result = 0;

	if (argc > 1){
		n = atol(argv[1]); } // optional argument for # of threads in for loop 

	ctimer_t s;
	ctimer_t t;

	//// //// //// ////
	// create threads
	pthread_t thread1[n];

	ctimer_start(&t);

	for(int i=0; i < n; i++){
		ctimer_start(&s);

		if (pthread_create(&thread1[i], NULL, (void *)threadroutine, (void*)(size_t) i) != 0){
			perror("pthread_create"); exit(1); }

		if (pthread_join(thread1[i], NULL) != 0){
			perror("pthread_join");exit(1); }
		
		ctimer_stop(&s); // time for spawning in for


		ctimer_measure(&s);
		ctimer_print(s, "threadroutine");

	}
	//// //// //// //// 

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("\nptfor  overall(%ld) = %ld\n", n, result); // overall time
	ctimer_print(t, "ptfor overall");


	printf("\n\n\n\n");

	return 0;
}
