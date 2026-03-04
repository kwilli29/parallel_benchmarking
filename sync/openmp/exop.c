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

/* Benchmark: 01D: Spawn time after ; ParallelFor-Loop Spawns (OpenMP)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

struct timespec val;

void spawn_function(int n, struct timespec t){           // Simple Spawn Function
	struct timespec v;

	timespec_sub(&v, t, val);
	printf("%ld.%09ld\n", (long)v.tv_sec, v.tv_nsec);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	printf("Spawn %d\n", n);

	return; 
}


int main2(){ // int argc, char *argv[]){

	int DEPTH = 271;

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	#pragma omp parallel for schedule (static, 1) // grainsize
	for(int i = 0; i < DEPTH; i++){
		spawn_function(i, t_start); 
	} 

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	return 0;
}

int main(int argc, char *argv[]) {

	struct timespec t_start, t_res;

	int t_end[5] = {0,0,0,0,0};

	struct timespec t_end1[5];
	struct timespec t_end2[5]; 
	clock_gettime(CLOCK_MONOTONIC, &t_start);

	val = t_start;

	#pragma omp parallel num_threads(4)
	#pragma omp sections
	{
		#pragma omp section
		{
			clock_gettime(CLOCK_MONOTONIC, &t_end1[0]);

			#pragma omp task
			spawn_function(0, t_end1[0]);
		}

		#pragma omp section
		{
			clock_gettime(CLOCK_MONOTONIC, &t_end1[1]);

			#pragma omp task
			spawn_function(1, t_end1[1]);
		}
		
		#pragma omp section
		{
			clock_gettime(CLOCK_MONOTONIC, &t_end1[2]);

	 		#pragma omp task
			spawn_function(2, t_end1[2]);
		}

		#pragma omp section
		{
			clock_gettime(CLOCK_MONOTONIC, &t_end1[3]);
 		
			#pragma omp task
			spawn_function(3, t_end1[3]);
		}

		#pragma omp section
		{
			clock_gettime(CLOCK_MONOTONIC, &t_end1[4]);
 	
			#pragma omp task
			spawn_function(4, t_end1[4]);
		}
 	} // End of parallel region

	printf("sync\n");
 
	#pragma omp parallel num_threads(4)
	#pragma omp single
	{
		clock_gettime(CLOCK_MONOTONIC, &t_end2[0]);
		#pragma omp task 
		spawn_function(0, t_end2[0]);

		clock_gettime(CLOCK_MONOTONIC, &t_end2[1]);
		#pragma omp task 
		spawn_function(1, t_end2[1]);

		clock_gettime(CLOCK_MONOTONIC, &t_end2[2]); 
		#pragma omp task
		spawn_function(2, t_end2[2]);;

		clock_gettime(CLOCK_MONOTONIC, &t_end2[3]); 
		#pragma omp task
		spawn_function(3, t_end2[3]);

		clock_gettime(CLOCK_MONOTONIC, &t_end2[4]); 
		#pragma omp task
		spawn_function(4, t_end2[4]);

	}

	for(int i=0; i < 5; i++){

		timespec_sub(&t_res, t_end1[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	
	}

	printf("sync for\n");

	for(int i=0; i < 5; i++){

		timespec_sub(&t_res, t_end2[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	
	}

	printf("\n");
	return(0);
}
