#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "../cilk/ctimer.h"
#include <sys/time.h>

// Global Array

int N = 36;

// Array of Reducers or Array of Reducer Pointers

void zero(void *view) { *(int *)view = 0; }
void add(void *left, void *right) { *(int *)left += *(int *)right; }

int cilk_reducer(zero, add)* count_per_arg;

int* global_array;


int fib(int n){

    // printf("n: %d, depth: %d\n", n, d);

    count_per_arg[n] += 1;

	 //printf("%d: %d \n", n, count_per_arg[n]);

    if (n < 2){
        // printf("fib(%d): %d\n", n, n); // verify value correctness
        return n;
    } 

    int x, y; // local variables
    x = cilk_spawn fib((n - 1));   // incr. global count array per arg. for # of calls
    x = fib((n - 2));              // atomic add

    cilk_sync; 

    //printf("fib(%d): %d\n", n, (x+y)); // verify value correctness

    return x + y;
}

int main(int argc, char*argv[]){

	int gs = 1;

	if (argc > 1){
   	N = atol(argv[1]);}
	if(argc > 2){
		gs = atoi(argv[2]);
	}

    global_array  = calloc(N+1, sizeof(int));
    count_per_arg = malloc((N+1)*sizeof(int cilk_reducer(zero,add)));
    
	// compute_sum(__builtin_addressof(sum)); // long cilk_reducer(zero, add) *sum

	for(int k=0; k <= N; k++){
		count_per_arg[k] = 0;
	}

	struct timeval start_time,end_time;
	gettimeofday(&start_time, NULL);

	#pragma grainsize = gs
	cilk_for(int k=0; k <= N; k++){
	 	global_array[k] = fib(k);
	}

	gettimeofday(&end_time, NULL);
	double realTime = (end_time.tv_sec+ (double)end_time.tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);

	/* PRINT VALUES */
	
    printf("FibVals: ");
    for(int i=0;i<=N; i++){
        printf("%d ", global_array[i]);
    }printf("\n");

    printf("CountPerArg RepeatFibs: ");
	 cilk_scope{
    	for(int i=N;i>=0; i--){
        printf("%d ", count_per_arg[i]);
    	}printf("\n");
	 }

    printf("Iterations: %d\n", N);
    printf("Grain Size: %d\n", gs);
    printf("Wall clock: %lf s\n", realTime); // time(s)

	/***************/

    free(global_array);
    free(count_per_arg);

	return 0;
}
