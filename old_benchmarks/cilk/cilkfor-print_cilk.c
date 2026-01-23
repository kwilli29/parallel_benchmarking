#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "ctimer.h"

/* Benchmark: cilkfor_cilk
 * Main thread uses cilk_for to spawn threads in parallel 
 * and invoke function to print value of i
 */

void threadroutine(long id){

	printf("\nSpawning thread: %ld\n", id); // print "thread id"

	return;
}

int main(int argc, char *argv[]) {

	long n = 1000;
	long result = 0;

	if (argc > 1){
		n = atol(argv[1]); } // optional argument for # of threads in cilk_for

	ctimer_t s;
	ctimer_t t;

	ctimer_start(&t);

	cilk_for(int i=0; i < n; i++){
		ctimer_start(&s);
		threadroutine(i); // time for spawning in cilk_for
		ctimer_stop(&s);
		
		ctimer_measure(&s);
		ctimer_print(s, "Subtime cilkfor-print_cilk Function :");
	}

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("\nN cilkfor-print_cilk :%ld\n", n);
	printf("\nResults cilkfor-print_cilk : (%ld) = %ld\n", n, result); // overall time
	ctimer_print(t, "Overall Time cilkfor-print_cilk :");


	printf("\n\n\n\n");

	return 0;
}
