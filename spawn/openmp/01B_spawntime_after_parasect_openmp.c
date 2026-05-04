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

/* Benchmark: 01B: Spawn time after ; Parallel Region Spawns (OpenMP)
 * Launch a bunch and measure when all done
 */

void spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){

	int OMP_THREADS = number_threads()-1;

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start);


	// omp parallel region will call spawn_function in parallel OMP_THREAD # of times

  #pragma omp parallel num_threads(OMP_THREADS) 
  {
 
		spawn_function(); // Take time stamp before each spawn

  }

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	return 0;
}
