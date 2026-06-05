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

/* Benchmark: 04F: Spawn time beforefunc ; One Spawns (OpenMP)
 * Launch a bunch and measure when all done 
 */

struct timespec spawn_function(int x){           // Simple Function to Spawn

	struct timespec t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; 
}

int main(int argc, char *argv[]){

	int x = 100;

	struct timespec t_start, t_res;
	struct timespec t_end;

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	#pragma omp parallel
	#pragma omp single
	{
		#pragma omp task
		t_end = spawn_function(x);
	}


	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	

	return 0;
}