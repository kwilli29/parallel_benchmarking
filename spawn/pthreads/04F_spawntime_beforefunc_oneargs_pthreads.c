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

/* Benchmark: 04F: Spawn time before function ; One Spawn w/ fcn arg (Pthreads)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

struct timespec t_end; 

void* spawn_function(void * x){           // Simple Math for Spawn Function

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int y = 5000; int z = 1000000;

	*(int *)x = *(int *)x + y + z;

	y = y + *(int *)x + z;

	z = z + y + *(int *)x;	


	return (void*)NULL; 
}

int main(int argc, char *argv[]){

	int x = 100;

	int ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

	pthread_t Thread;

	struct timespec t_start, t_res;
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	//int status = pthread_create( &Threads[ i ], NULL, spawn_function, NULL);
	pthread_create( &Thread, NULL, spawn_function,(void*)&x);
	

	

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	// destroy attr
	pthread_attr_destroy(&attr);


	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}

