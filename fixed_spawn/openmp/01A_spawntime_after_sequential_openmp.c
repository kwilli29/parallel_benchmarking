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

/* Benchmark: 01A: Spawn time after ; Sequential Spawns (OpenMP)
 * Launch a bunch and measure when all done
 * This is NOT how OpenMP is meant to be used
 */

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

	#pragma omp parallel
	#pragma omp single   // one threads 'allocates' tasks to other threads
	{

	// 
	#pragma omp task
		spawn_function(); // Take time stamp before each spawn
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function(); // 10

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function(); // 20

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function(); // 30

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function(); // 40

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function(); // 50

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function(); // 60

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function(); // 70

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function(); // 80

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function(); // 90

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function();

	// 
	#pragma omp task
		spawn_function();
	// 
	#pragma omp task
		spawn_function(); // 100

	}	

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	return 0;
}