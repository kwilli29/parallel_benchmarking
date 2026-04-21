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
 * Benchmark: 02G: Spawn time after ; No sync checkpoints (OpenMP)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

void spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

void timer_fcn(){
	struct timeval t_start, t_end;
	gettimeofday(&t_start, NULL); // 
	gettimeofday(&t_end, NULL);	

	while( ( (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000)  ) < 3.0 ){	
		// spin wait
		gettimeofday(&t_end, NULL);
	}

	return; 

}
int main(int argc, char *argv[]){

 	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // 

	// each checkpoint is a little different
	// or they're all same and diff ones are in like 02B,etc.
	// Time per checkpoint?

	#pragma omp parallel
	#pragma omp single
	{
		#pragma omp task
		spawn_function();

		#pragma omp task
		spawn_function();

		#pragma omp task
		spawn_function();
	
	timer_fcn(); // all threads complete before end time

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("02A\n");
	}
	return 0;
}
