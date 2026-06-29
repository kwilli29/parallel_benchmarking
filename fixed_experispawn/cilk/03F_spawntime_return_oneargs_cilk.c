#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>
#include <sys/time.h>

/* Benchmark: 03F: Spawn time return from function ; One+Arg Spawn (Cilk) 
 * 
 */
static const int ITERATION = 100000;
struct timespec spawn_function_long(double x){

    double z = 0;
    double i = 0.0;

    //double x = 15.0;
	static const int nn = 87;

    double a =0.0;
	for (int j = 0; j < ITERATION; j++){
        z*=acos((double)j);

        for (long m = 1; m < nn; ++m){
            a = (double)((double)m*1.0);
            x = sin((double)x*1.0) / (double)(a*1.0 + (j * i + i + j)*1.0 / a);
        }

        z += x + z; //
        z= tanh((double)z);

        i += 1.0;
	}

    // printf("**%d\t", __cilkrts_get_worker_number()); // print thread id

    struct timespec t_start;
	clock_gettime(CLOCK_MONOTONIC, &t_start);

	return t_start; //
}
struct timespec spawn_function(int x){           // Simple Function to Spawn

	// int x = 100; 
    int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

    struct timespec t_start;
	clock_gettime(CLOCK_MONOTONIC, &t_start);
    

	return t_start; //  end_time; 
}

int main(int argc, char *argv[]){

    int NCILK = __cilkrts_get_nworkers();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            NCILK = __cilkrts_get_nworkers();
        } else {
            NCILK = atoi(argv[1]);
            if(NCILK < 1){
                NCILK = __cilkrts_get_nworkers();
            }
        }
    }
	printf("* # Spawns: %d\n", NCILK);
    int iter = 50;
    
    double x = 15.0;

	struct timespec t_start, t_res, t_end;

	// Use for loop, timestamp before spawn to right at start of spawn_function

	t_start = cilk_spawn spawn_function_long(x); 
    clock_gettime(CLOCK_MONOTONIC, &t_end);

    cilk_sync;
    
	//printf("****\n");	
    timespec_sub(&t_res, t_start, t_end); // t_end happens before t_start
    if(t_res.tv_nsec < 0 && t_res.tv_sec >= 0){ t_res.tv_nsec *= -1; printf("-");}
    printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("03F\n");
	
	return 0;
}