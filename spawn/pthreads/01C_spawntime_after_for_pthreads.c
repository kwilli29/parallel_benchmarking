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

	// pthread_barrier_wait 
	pthread_barrier_wait(&sync_barrier);

	return (void*) NULL; 
}

int main(int argc, char *argv[]){

	int DEPTH = 271;

	int ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

	pthread_t Threads[ DEPTH ];

	// pthread_barrier_init 
	pthread_barrier_init(&sync_barrier, NULL, DEPTH+1);

	struct timespec t_start, t_res, t_end;

	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	for( int i = 0; i < DEPTH; i++ ) {                                     // # seq. for only
		pthread_create( &Threads[ i ], &attr, spawn_function, NULL);
	}

	// does main thread need a barrier here for the "sync" ???? !!!!
	pthread_barrier_wait(&sync_barrier);

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	// pthread_destroy_barrier 
	pthread_barrier_destroy(&sync_barrier); // sync all threads before getting endtime

	// destroy attr
	pthread_attr_destroy(&attr);
	
	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
		
	return 0;
}

