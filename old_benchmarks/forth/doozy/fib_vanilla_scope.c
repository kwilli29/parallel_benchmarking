#include <stdio.h>
#include <stdlib.h>

#include <cilk/cilk.h>


// Finds fib(36). Fib fcn DOES use cilk_scope

long fib(long n) {
  if (n < 2)
    return n;
  long x, y;
  cilk_scope {
    x = cilk_spawn fib(n-1);
    y = fib(n-2);
  }
  return x + y;
}

int main(int argc, char *argv[]) {
  long n = 36;

  long result = fib(n);

  return 0;
}
