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

/* Benchmark: 01C: Spawn timer after ; For-Loop Spawns (Pthreads)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

pthread_barrier_t sync_barrier; /* to sync */

void* spawn_function(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	// pthread_barrier_wait ?
	pthread_barrier_wait(&sync_barrier);

	return (void*) NULL; 
}

int main(int argc, char *argv[]){

	int DEPTH = 271;

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	pthread_t Threads[ DEPTH ];

	// pthread_barrier_init ?
	pthread_barrier_init(&sync_barrier, NULL, DEPTH);

	for( int i = 0; i < DEPTH; i++ ) {                                     // # seq. for only
		//int status = pthread_create( &Threads[ i ], NULL, spawn_function, NULL);
		pthread_create( &Threads[ i ], NULL, spawn_function, NULL);
	}

	for(int i = 0; i < DEPTH; i++){
		 pthread_join( Threads[i], NULL);
	}

	// pthread_destroy_barrier ?
	pthread_barrier_destroy(&sync_barrier); // sync all threads before getting endtime
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
		
	return 0;
}

