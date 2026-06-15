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

/* Benchmark: 04D: Spawn time before thread function begins ; CilkFor Spawns (Cilk) 
 * Launch a bunch and measure when all done
 */
static const int ITERATION = 100000;
struct timespec spawn_function_long(){

    struct timespec t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_end);

    double z = 0;
    double i = 0.0;

    double x = 15.0;
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

	return t_end; // 
}
struct timespec spawn_function(){           // Simple Function to Spawn

	struct timespec t_end; 
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; //  end_time; 
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

	struct timespec t_start[iter]; struct timespec t_res;
	struct timespec t_end[iter];

	// parallel for timestamp before spawn to beginning of spawned function

	#pragma cilk grainsize 1
	cilk_for(int i=0; i < iter; i++){ 	
		clock_gettime(CLOCK_MONOTONIC, &t_start[i]); t_end[i] = cilk_spawn spawn_function_long();

	}

	// printf("****\n");
	for(int i = 0; i < iter; i++){
		
		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	}

	// printf("04D\n");
	
	return 0;
}