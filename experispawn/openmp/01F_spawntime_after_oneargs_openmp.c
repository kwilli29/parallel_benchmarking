#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: 01E: Spawn time after ; One Spawn w/ fcn args (OpenMP)
 * Launch a bunch and measure when all done -
 */

void spawn_function(int x){           // Simple Spawn Function

	int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){

	int x = 100;

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	// I really think this is the most representative way to spawn 1 "thread" in a pool of 200
	// not what openmp is for
	
	// one int arg

	#pragma omp parallel //num_threads(1) 
	#pragma omp single
	{
		#pragma omp task
		spawn_function(x);
	}	
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	return 0;
}