#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

#include "../../include/numthreads.h"

/* 
 * Benchmark: 05A: Schedule = Static ; ParallelFor (OpenMP)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */



void spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;
	x = x + y + z;
	y = y + x + z;
	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){

    int NITER = number_threads();

 	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

	#pragma omp parallel for schedule(static, 1) // grainsize
	for(int i = 0; i < NITER-1; i++){
		spawn_function();
	}
 
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("05A\n");

	return 0;
}
