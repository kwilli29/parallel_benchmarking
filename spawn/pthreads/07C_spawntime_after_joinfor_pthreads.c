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

/* Benchmark: 07C: Spawn timer after ; For-Loop+Join Spawns (Pthreads)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

void* spawn_function(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*) NULL; 
}

int main(int argc, char *argv[]){

	int DEPTH = 271;

	pthread_t Threads[ DEPTH ];


	struct timespec t_start, t_res, t_end;

	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	for( int i = 0; i < DEPTH; i++ ) {                                     // # seq. for only
		pthread_create( &Threads[ i ], NULL, spawn_function, NULL);
	}

	for( int i = 0; i < DEPTH; i++ ) {                                     // # seq. for only
		pthread_join( &Threads[ i ], NULL);
	}

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
		
	return 0;
}

