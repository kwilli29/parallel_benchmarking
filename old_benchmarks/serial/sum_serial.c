#include <stdio.h>
#include <stdlib.h>
#include "ctimer.h"

/* Serial Benchmark: Use for to accumulate a sum.
 */

int main(int argc, char *argv[]) {
	int n = 1000000;

	//// //// 
	long summ = 0;

	ctimer_t t;

	ctimer_start(&t);

	for(int i = 0; i <= n; i++){
		summ += i; 
	}

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("serialfor_sum: (%d) = %ld\n", n, summ);
	ctimer_print(t, "serialfor_sum");
	printf("\n");

	return 0;
}

