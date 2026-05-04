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

/* Benchmark: 03G: Time b/w thread complete and return ; ThSy Time (OpenMP) 
 */

struct timespec spawn_function(){           // Simple Function to Spawn

	struct timespec t_start; // 

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	clock_gettime(CLOCK_MONOTONIC, &t_start);

	return t_start; //  to get REALLY granular, could measure time to return timeval from fcn and sub from end
}

int main(int argc, char *argv[]){

	struct timespec t_res,t_start, t_end;

	#pragma omp parallel
	#pragma omp single
	{
		#pragma omp task
		t_start = spawn_function(); // Take time stamp before each spawn
	// sync;
	}
	clock_gettime(CLOCK_MONOTONIC, &t_end);
	/**/

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	// printf("03G\n");
	
	return 0;
}