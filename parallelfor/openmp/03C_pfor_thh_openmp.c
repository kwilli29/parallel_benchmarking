#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <omp.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

#include "../../include/numthreads.h"

/* 
 * Benchmark: 03C: Parallel For 2; (OpenMP)
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

    int NITER = number_threads(); 
    int NUMTH = 2;

 	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

    #pragma omp parallel for num_threads(NUMTH)
	for(int i = 0; i < NITER-1; i++){
		spawn_function();
	} 

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("03C\n");

	return 0;
}
