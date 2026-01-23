#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <sys/time.h>

// Doozy Fib W/ Reducers . fib(0) to fib(36) w/ cilkfor. Track 2 counters. count_per_arg is an array of reducers

// Global Array

int N = 36;

// Array of Reducers or Array of Reducer Pointers

void zero(void *view) { *(int *)view = 0; }
void add(void *left, void *right) { *(int *)left += *(int *)right; }

int cilk_reducer(zero, add)* count_per_arg;

int* global_array;


int fib(int n){

    count_per_arg[n] += 1;

    if (n < 2){
        return n;
    } 

    int x, y; // local variables
    x = cilk_spawn fib((n - 1));   // incr. global count array per arg. for # of calls
    x = fib((n - 2));              // atomic add

    cilk_sync; 

    return x + y;
}

int main(int argc, char*argv[]){

   global_array  = calloc(N+1, sizeof(int));
   count_per_arg = calloc((N+1),sizeof(int cilk_reducer(zero,add))); 
	// count_per_arg = malloc((N+1)*sizeof(int cilk_reducer(zero,add)));
    
	// for(int k=0; k <= N; k++){ count_per_arg[k] = 0; }

	#pragma grainsize = 1
	cilk_for(int k=0; k <= N; k++){
	 	global_array[k] = fib(k);
	}

    free(global_array);
    free(count_per_arg);

	return 0;
}
