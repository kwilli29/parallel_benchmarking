#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "ctimer.h"

/* Benchmark: fibonacci with Cilk
 *
 * Taken from OpenCilk's tutorial examples on GitHub
 *
 */

int fib_small(int n) { // no serial fib. calc is offloaded
  if (n < 2)
    return n;

  int x, y;
  cilk_scope {
    x = cilk_spawn fib_noif(n-1); // x and y assigned in parallel
    y = fib_noif(n-2);
  }
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
  long n = 10;
  if (argc > 1)
    n = atol(argv[1]);

  long result = 0;

  ctimer_t t;
  ctimer_start(&t);

  result = fib_small(n);

  ctimer_stop(&t);
  ctimer_measure(&t);

  printf("\nfib_small(%ld) = %ld\n", n, result);
  ctimer_print(t, "fib_small");

//// //// 
  ctimer_start(&t);
  result = fib_opt(n);
  ctimer_stop(&t);
  ctimer_measure(&t);

  printf("fib_opt(%ld) = %ld\n", n, result);
  ctimer_print(t, "fib_opt");

  return 0;
}
