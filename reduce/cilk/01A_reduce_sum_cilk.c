#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <sys/time.h>

/* 01A Reduce Sum benchmark : (OpenCilk)
* Benchmark
*
*/

// Global Array

int N = 36;

// Array of Reducers or Array of Reducer Pointers

void zero(void *view) { *(float *)view = 0; }
void add(void *left, void *right) { *(float *)left += *(float *)right; } // Addition

float cilk_reducer(zero, add)* ; // Defined Reducer

float* global_array;


float fib(int n){

    count_per_arg[n] += 1.0;

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

   global_array  = calloc(N+1, sizeof(float));
   count_per_arg = calloc((N+1),sizeof(float cilk_reducer(zero,add))); 
    

	#pragma grainsize = 1
	cilk_for(int k=0; k <= N; k++){
	 	global_array[k] = fib(k);
	}

    free(global_array);
    free(count_per_arg);

	return 0;
}

// +, *, GCD/LCM, inter./union,functino composition, mat mul, min/max (R, ordered set)
