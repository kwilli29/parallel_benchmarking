#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <sys/time.h>

// Doozy Fib W/O Reducers . Find fib(0) to fib(36) w/ cilk_for and track counter arrays

// Global Array

int N = 36;

int* global_array;

int* count_per_arg;

int fib(int n){

    count_per_arg[n] += 1;

    if (n < 2){
        return n;
    } 

    int x, y; // local variables

    x = cilk_spawn fib((n - 1));   // incr. global count array per arg. for # of calls
    y = fib((n - 2));              // atomic add

    cilk_sync; 


    return x + y;
}


int main(int argc, char*argv[]){

   global_array = calloc(N+1, sizeof(int));
   count_per_arg = calloc(N+1, sizeof(int));

	#pragma grainsize = 1
	cilk_for(int k=0; k <= N; k++){
	 	global_array[k] = fib(k);
	}

    free(global_array);
    free(count_per_arg);

	return 0;
}
