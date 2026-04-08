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

#define NCILK __cilkrts_get_nworkers()

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

	struct timespec t_start[NCILK-1]; struct timespec t_res;
	struct timespec t_end[NCILK-1];

	// parallel for timestamp before spawn to beginning of spawned function

	#pragma cilk grainsize 1
	cilk_for(int i=0; i < NCILK-1; i++){ 	
		clock_gettime(CLOCK_MONOTONIC, &t_start[i]); t_end[i] = cilk_spawn spawn_function();

	}

	// printf("****\n");
	for(int i = 0; i < NCILK-1; i++){
		
		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	}

	// printf("04D\n");
	

	return 0;
}


