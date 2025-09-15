#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cilk/cilk.h>
#include "ctimer.h"

/* Benchmark: fibonacci with Cilk
 *
 * Taken from OpenCilk's tutorial examples on GitHub
 *
 */

// return sysconf(_SC_NPROCESSORS_ONLN);
// printf("# of Cores: %ld \n", sysconf(_SC_NPROCESSORS_ONLN));

int fib_small(int n) { // no serial fib. calc is offloaded
	if (n < 2)
		return n;

	printf("3. # of Cores: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));

	int x, y;

	cilk_scope {
		printf("4. # of Cores: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));
		x = cilk_spawn fib_small(n-1); // x and y assigned in parallel
		printf("5. # of Cores: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));
		y = fib_small(n-2);
	}

	printf("6. # of Cores: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));
	return x + y;
}

int fib_serial(int n){ // serial fibonacci
    if (n < 2){ return n;}

    int res1, res2;
    res1 = fib_serial(n-1);
    res2 = fib_serial(n-2);
    return res1 + res2;
}
int fib_opt(int n){ // more optimal fib. 
    if (n < 20)
        return fib_serial(n); // serial fib. calc offloaded if n < 20

    int x, y;

	cilk_scope {
   	x = cilk_spawn fib_opt(n-1); // x and y assigned in parallel
   	y = fib_opt(n-2);
	}

    return x + y;
}

int main(int argc, char *argv[]) {
	printf("1. # of Cores: %ld \n", sysconf(_SC_NPROCESSORS_ONLN));

	long n = 10;
	//if (argc > 1)
	//	n = atol(argv[1]);

	long result = 0;

	ctimer_t t;
	ctimer_start(&t);

	printf("2. # of Cores: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));
	result = fib_small(n);

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("\nfib_small N : %ld\n", n);
	printf("\nfib_small Results : (%ld) = %ld\n", n, result);
	ctimer_print(t, "fib_small Overall Time : ");

	printf("7. # of Cores: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));

//// //// 
	ctimer_start(&t);
	result = fib_opt(n);
	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("\nfib_opt N : %ld\n", n);
	printf("fib_opt Results : (%ld) = %ld\n", n, result);
	ctimer_print(t, "fib_opt Overall Time : ");

	return 0;
}
