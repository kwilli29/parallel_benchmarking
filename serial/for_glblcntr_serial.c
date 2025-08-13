#include <stdio.h>
#include <stdlib.h>
#include "ctimer.h"

/* Serial Benchmark: for loop calls fcn to incrememnt a gloabl counter.
 */

long counter = 0;

void thread_routine(){ //
 
	counter++;

	return;
}

int main(int argc, char *argv[]) {
	int n = 1000000;

	ctimer_t t;
	ctimer_start(&t);

	for(int i=0; i < n; i++){ // serial for
		thread_routine();
	}

	ctimer_stop(&t);
	ctimer_measure(&t);
	
	printf("for global counter serial: (%d) = %ld\n", n, counter);
	ctimer_print(t, "for global counter serial");

	printf("\n");

	return 0;
}
