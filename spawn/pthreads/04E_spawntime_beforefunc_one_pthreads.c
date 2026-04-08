#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: 04E: Spawn time before function ; One Spawn (Pthreads)
 * Launch a bunch and measure when all done 
 */

struct timespec t_end;

void* spawn_function(){           // Simple Math for Spawn Function

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*)&t_end; 
}

int main(int argc, char *argv[]){

	pthread_t Thread;

	struct timespec t_start, t_res;
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	//int status = pthread_create( &Threads[ i ], NULL, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_start);
	pthread_create( &Thread, NULL, spawn_function, NULL);

	struct timespec* temp = &t_end;
	
	pthread_join(Thread, (void *)&temp);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}

