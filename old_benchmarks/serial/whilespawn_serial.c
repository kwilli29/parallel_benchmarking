#include <stdio.h>
#include <stdlib.h>
#include "ctimer.h"

/* Benchmark: while loop calls fcn to incrememnt a gloabl counter.
 */

long counter = 0;

void thread_routine(){ // 

	counter++;

	return;
}


int main(int argc, char *argv[]) {
	int n = 1000000;

	int cnt =0;

	ctimer_t t;
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

