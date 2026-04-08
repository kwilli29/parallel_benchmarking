#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* 
 * Benchmark: 04F: Spawn time beforefunc ; One Spawns w/ Fcn args (Cilk)
 * Launch a bunch and measure when all done 
 */

#define NCILK __cilkrts_get_nworkers()

struct timespec spawn_function(int x){           // Simple Function to Spawn

	struct timespec t_end; 
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; //  end_time; 
}

int main(int argc, char *argv[]){

	int x = 100;

	struct timespec t_start, t_res;
	struct timespec t_end;

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp
	
	t_end = cilk_spawn spawn_function(x); // spawn with one int argument
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	cilk_sync;

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("04F\n");

	return 0;
}
