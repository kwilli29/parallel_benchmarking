#include <stdio.h>
#include <stdlib.h>
#include "ctimer.h"

/* Serial Benchmark: fibonacci 
 */

int fib_serial(int n){
	if (n < 2){ return n;}

	int res1, res2;
	res1 = fib_serial(n-1);
	res2 = fib_serial(n-2);
	return res1 + res2;
}


int main(int argc, char *argv[]) {
	long n = 10;
	if (argc > 1)
		n = atol(argv[1]);

	long result = 0;

	ctimer_t t;
	
	ctimer_start(&t);
	result = fib_serial(n);
	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("serial fib(%ld) = %ld\n", n, result);
	ctimer_print(t, "fib");

  return 0;
}
