#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "ctimer.h"
#include <sys/time.h>

/* Benchmark: cilkfor-print_cilk
 * Main thread uses cilk_for to spawn threads in parallel 
 * and invoke function to print value of i
 */

void threadroutine(long id){

	printf("\nSpawning thread: %ld\n", id); // print "Thread id" / which iteration i it is in cilk_for

	return;
}

int main(int argc, char *argv[]) {

	long n = 1000;
	long result = 0;
	int gs = 1;

	if (argc > 1){
		n = atol(argv[1]); } // optional argument for # of threads in cilk_for
	if(argc > 2){
		gs = atoi(argv[2]);  // optional grain size
	}

	printf("GRAIN SIZE: %d\n", gs);

	// ctimer_t s; ctimer_t t; ctimer_start(&t);
	struct timeval start_time,end_time;

	gettimeofday(&start_time, NULL);

	#pragma grainsize = gs
	cilk_for(int i=0; i < n; i++){
		threadroutine(i);           // call function that prints value of i
	}

	gettimeofday(&end_time, NULL);
	double realTime = (end_time.tv_sec+ (double)end_time.tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);
	//ctimer_stop(&t); ctimer_measure(&t);

	printf("/nPragma: %d\n", gs);
	printf("\nN cilkfor-print_cilk :%ld\n", n);
	printf("\nResults cilkfor-print_cilk : (%ld) = %ld\n", n, result); // Overall time
	printf("\nOverall Time cilkfor-print_cilk  = %lf", realTime);
	//ctimer_print(t, "Overall Time for_cilk :");
	printf("\n\n\n\n");

	cilk_sync;

	return 0;
}
