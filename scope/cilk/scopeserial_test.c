#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: 02B: Spawn time before ; CilkScope Spawns (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 *
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

#define NCILK 11 // __cilkrts_get_nworkers()

void spawn_function(){           // Simple Function to Spawn

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){


	struct timespec t_start, t_res;
	struct timespec t_end[NCILK-1];
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	cilk_scope{

		clock_gettime(CLOCK_MONOTONIC, &t_end[0]); spawn_function(); // Take time stamp before each spawn
		clock_gettime(CLOCK_MONOTONIC, &t_end[1]); spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[2]); spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[3]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[4]); spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[5]); spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[6]); spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[7]); spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[8]); spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[9]); spawn_function(); // 10

	}

	printf("****\n");
	for(int i = 0; i < NCILK-1; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}
	
	// printf("02B\n");

	return 0;
}

	
// cilk_rts_getworker_number;
