#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "../cilk/ctimer.h"
#include <sys/time.h>

// Doozy is the main program and is launched as a single thread with a structure much as is seen on many Pathfinder programs. 

// The doozy thread launches a set of child threads via a cilk for-like fashion, 
//      each with an argument from 0 to n-1, where n is the argument to doozy.

// The k’th child will compute fib(k) 
//     **on the k’th node** and 
//     store the result in the k’th entry in a global array that is striped across a set of nodes 
//     (so that the k’th entry is not on the k’th node), 

// After all child threads have completed, the parent thread will then 
//    call a function to traverse the system printing out the contents of the global array 
//    (allowing us to verify correctness), 
//    and then print out some counts from a replicated array that were updated by the child threads

// TODO:
// 1. How to stripe a global array across nodes -- MPI noooo
    // node = processor? / core?
    // Divide 1D array into chunks 
    // maybe fork?? 
    // MPI Scatter ** / MPI Gather
// 2. How to traverse a system
    // like a /search/ + print algorihtm ?? 
// 3. Print out counts from a replicated array 
    // "counts" were updated by the child threads

// So there 2 arrays??

// Global Array

int N = 2;

//int global_array []; // size N
int* global_array;
// dooesn't have to be a static array? 

//int count_per_arg []; // size N
int* count_per_arg;

int fib(int n){

    //printf("n: %d, depth: %d\n", n, d);

    count_per_arg[(n)] += 1;

    if (n < 2){
        // printf("fib(%d): %d\n", n, n); // verify value correctness
        return n;
    } 

    int x, y; // local variables

    cilk_scope{
        x = cilk_spawn fib((n - 1)); // incr. global count array per arg. for # of calls
        y = fib((n - 2));            // atomic add
    } // threads synced here              // Two levels of sync by design 

    // cilk_sync; 

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

    global_array = calloc(N+1, sizeof(int));
    count_per_arg = calloc(N+1, sizeof(int));

	struct timeval start_time,end_time;
	gettimeofday(&start_time, NULL);

	#pragma grainsize = gs
	for(int k=0; k <= N; k++){
	 	global_array[k] = cilk_spawn fib(k);

	}

	gettimeofday(&end_time, NULL);
	double realTime = (end_time.tv_sec+ (double)end_time.tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);
	
    // traverse system for

    printf("FibVals: ");
    for(int i=0;i<=N; i++){
        printf("%d ", global_array[i]);
    
    }printf("\n");

    printf("CountPerArg RepeatFibs: ");
    for(int i=0;i<=N; i++){
        printf("%d ", count_per_arg[i]);
    
    }printf("\n");

    printf("Iterations: %d\n", N);
    printf("Grain Size: %d\n", gs);
    printf("Wall clock: %lf s\n", realTime); // time(s)


    free(global_array);
    free(count_per_arg);

	return 0;
}