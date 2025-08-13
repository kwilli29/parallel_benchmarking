#include <stdio.h>
#include <stdlib.h>
#include "ctimer.h"

/* Serial Benchmark: for
 * Main thread uses for to spawns print function 
 * to print value of i
 */

void threadroutine(long id){

	printf("\nNot spawning thread [serial]: %ld", id);

	return;
}

int main(int argc, char *argv[]) {

	long n = 10;
	long result = 0;

	if (argc > 1){
		n = atol(argv[1]); }

	ctimer_t s;

	ctimer_t t;
	ctimer_start(&t);

	for(int i=0; i < n; i++){
		ctimer_start(&s);
		threadroutine(i);
		ctimer_stop(&s);
		ctimer_measure(&s);
		printf("\nthreadroutine(%d) = %ld\n", i, result);
		ctimer_print(s, "threadroutine");
	}

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("\nfor serial threadroutine overall(%ld) = %ld\n", n, result);
	ctimer_print(t, "for serial threadroutine overall");

	//// //// //// //// 

	return 0;
}
