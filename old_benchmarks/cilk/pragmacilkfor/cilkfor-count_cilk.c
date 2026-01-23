#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "../ctimer.h"
#include <sys/time.h>

/* Benchmark: PRAGMA
 *
 * cilkfor-count cilk
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
	int gs = 1;

	if (argc > 1){
   	n = atol(argv[1]);}
	if(argc > 2){
		gs = atoi(argv[2]);
	}

	printf("GRAIN SIZE: %d\n", gs);

	long result = 0;

	//ctimer_start(&t);
	struct timeval start_time,end_time;
	gettimeofday(&start_time, NULL);

	#pragma grainsize = gs
	cilk_for(int i=0; i < n; i++){
	 	result = thread_routine1(i);
	}

	gettimeofday(&end_time, NULL);
	double realTime = (end_time.tv_sec+ (double)end_time.tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);
	
	//ctimer_stop(&t);
	//ctimer_measure(&t);

	printf("\nPragma: %d\n", gs);
	printf("\nN cilkfor-count_cilk :%ld\n", n);
	printf("Results cilkfor-count_cilk : (%ld) = %ld\n", n, result);
	//ctimer_print(t, "Overall Time cilkfor-count_cilk :");
	printf("\nOverall Time cilkfor-count_cilk = %lf", realTime);
	printf("\n");

	cilk_sync;


	return 0;
}
