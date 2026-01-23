#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <sys/time.h>

// fib_cilkfor.c – finds fib(1) to fib(36) with a cilkfor

int N = 36;

int fib(int n){

 

    if (n < 2){
        return n;
    } 

    int x, y; // local variables

    x = cilk_spawn fib((n - 1)); // incr. global count array per arg. for # of calls
    y = fib((n - 2));            // atomic add
     								      // Two levels of sync by design 

    return x + y;
}

int main(int argc, char*argv[]){

	#pragma grainsize = 1
	cilk_for(int k=0; k <= N; k++){
	 	fib(k);
	} cilk_sync;


	return 0;
}
