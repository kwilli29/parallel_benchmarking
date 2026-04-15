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

/* 
 * Benchmark: 05B: Schedule = Dynamic ; ParallelFor (OpenMP)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

#define NITER 272

void spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;
	x = x + y + z;
	y = y + x + z;
	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

 	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	#pragma omp parallel for schedule(dynamic, 1) // grainsize
	for(int i = 0; i < NITER-1; i++){
		spawn_function(); 
		// how to time the end of the *last thread * to complete
	}
 
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("05B\n");

	return 0;
}
