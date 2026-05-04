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

/* Benchmark: 02D: Spawn time before ; ParallelFor-Loop Spawns (OpenMP)
 * Launch a bunch and measure when all done 
 */

void spawn_function(){           // Simple Function to Spawn

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

    int OMP_THREADS = number_threads()-1;

	struct timespec t_start, t_res;
	struct timespec t_end[OMP_THREADS];

	clock_gettime(CLOCK_MONOTONIC, &t_start); // 

	#pragma omp parallel for schedule (static, 1) // grainsize=1
	for(int i = 0; i < OMP_THREADS; i++){	
		clock_gettime(CLOCK_MONOTONIC, &t_end[i]); spawn_function(); 
	} 
	printf("****\n");
	for(int i = 0; i < OMP_THREADS; i++){

		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	return 0;
}


