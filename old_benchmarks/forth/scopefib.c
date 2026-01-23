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


// Global Array

int N = 36;

int* global_array;

int* count_per_arg;

int fib(int n){

    //printf("n: %d, depth: %d\n", n, d);

    count_per_arg[n] += 1;

	// spin

    if (n < 2){
        // printf("fib(%d): %d\n", n, n); // verify value correctness
        return n;
    } 

    int x, y; 

    //cilk_scope{
        x = cilk_spawn fib((n - 1)); // incr. global count array per arg. for # of calls
        y = fib((n - 2));            // atomic add
    //} // threads synced here       // Two levels of sync by design 

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

	//#pragma grainsize = gs
	//cilk_for(int k=0; k <= N; k++){
	// 	global_array[k] = fib(k);
        //fib(k, 1);
	//}
	
	cilk_scope{
		global_array[0] = fib(0);
		global_array[1] = fib(1);
		global_array[2] = fib(2);
		global_array[3] = fib(3);
		global_array[4] = fib(4);
		global_array[5] = fib(5);
		global_array[6] = fib(6);
		global_array[7] = fib(7);
		global_array[8] = fib(8);
		global_array[9] = fib(9);
		global_array[10] = fib(10);
		global_array[11] = fib(11);
		global_array[12] = fib(12);
		global_array[13] = fib(13);
		global_array[14] = fib(14);
		global_array[15] = fib(15);
		global_array[16] = fib(16);
		global_array[17] = fib(17);
		global_array[18] = fib(18);
		global_array[19] = fib(19);
		global_array[20] = fib(20);
		global_array[21] = fib(21);
		global_array[22] = fib(22);
		global_array[23] = fib(23);
		global_array[24] = fib(24);
		global_array[25] = fib(25);
		global_array[26] = fib(26);
		global_array[27] = fib(27);
		global_array[28] = fib(28);
		global_array[29] = fib(29);
		global_array[30] = fib(30);
		global_array[31] = fib(31);
		global_array[32] = fib(32);
		global_array[33] = fib(33);
		global_array[34] = fib(34);
		global_array[35] = fib(35);
		global_array[36] = fib(36);
	}// cilk_sync

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
    // depth of tree
    printf("Wall clock: %lf s\n", realTime); // time(s)


    free(global_array);
    free(count_per_arg);

	return 0;
}
