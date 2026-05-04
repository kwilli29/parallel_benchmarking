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

/* Benchmark: 04G: Spawn time beforefunc ; Taskloop For-Loop Spawns (OpenMP)
 * Launch a bunch and measure when all done 
 */

struct timespec spawn_function(){           // Simple Function to Spawn

	struct timespec t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; 
}

int main(int argc, char *argv[]){

	int OMP_THREADS = number_threads()-1;

	struct timespec t_start[OMP_THREADS]; struct timespec t_res;
	struct timespec t_end[OMP_THREADS];
	
	#pragma omp parallel
	#pragma omp single
	#pragma omp taskloop simd grainsize(1)
	for(int i = 0; i < OMP_THREADS; i++){
		clock_gettime(CLOCK_MONOTONIC, &t_start[i]);
		t_end[i] = spawn_function(); 
	}

	// printf("****\n");
	for(int i = 0; i < OMP_THREADS; i++){

		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	return 0;
}


