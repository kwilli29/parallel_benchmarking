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

/* Benchmark: 04C: Spawn time before function ; For-Loop Spawns (Pthreads)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));


void* spawn_function(void* t_end){           // Simple Math for Spawn Function

	clock_gettime(CLOCK_MONOTONIC, (struct timespec *)t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*)t_end; 
}

int main(int argc, char *argv[]){

	int DEPTH = 271;

	pthread_t Threads[ DEPTH ];

	struct timespec t_start[DEPTH]; struct timespec t_res;
	struct timespec t_end[DEPTH];

	/****/ 

	for( int i = 0; i < DEPTH; i++ ) {                                     // # seq. for only
		clock_gettime(CLOCK_MONOTONIC, &t_start[i]);
		pthread_create( &Threads[ i ], NULL, spawn_function, (void*)&t_end[i]);
	}

	struct timespec* temp = (struct timespec *)&t_end[0];
	
	for( int i = 0; i < DEPTH; i++ ) {                                     // join
		pthread_join( Threads[ i ], (void*)&temp);

		// if(i < 5){ printf("\n%p\n", &t_end); printf("%ld\n", t_end[i].tv_nsec); }

		if (i < DEPTH-1){ temp = &t_end[i+1]; }
	}

	for(int i = 0; i < DEPTH; i++){

		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	}

	return 0;
}

