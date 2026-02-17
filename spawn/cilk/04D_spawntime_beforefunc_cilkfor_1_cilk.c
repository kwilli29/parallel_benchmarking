#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: 04D: Spawn time before thread function begins ; CilkFor Spawns (Cilk) 
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

#define NCILK __cilkrts_get_nworkers()

struct timespec spawn_function(){           // Simple Function to Spawn

	struct timespec t_end; // ADD TIME END
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; //  end_time; 
}

int main(int argc, char *argv[]){

	struct timespec t_start, t_res;
	struct timespec t_end[NCILK-1];

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	#pragma cilk grainsize 1
	cilk_for(int i=0; i < NCILK-1; i++){ 	
		t_end[i] = cilk_spawn spawn_function();

	}

	for(int i = 0; i < NCILK-1; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	} 

	// printf("04D\n");
	
	// cilk_rts_getworker_number;

	return 0;
}


