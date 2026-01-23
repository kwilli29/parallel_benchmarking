#include <stdio.h>
#include <stdlib.h>

#include <cilk/cilk.h>


// Finds just fib(36). Fib fcn does NOT use cilk_scope

long fib(long n) {
  if (n < 2)
    return n;
  
  long x, y;
  x = cilk_spawn fib(n-1);
  y = fib(n-2);
  
  return x + y;
}

int main(int argc, char *argv[]) {
  long n = 36;

  long result = fib(n);

  return 0;
}
