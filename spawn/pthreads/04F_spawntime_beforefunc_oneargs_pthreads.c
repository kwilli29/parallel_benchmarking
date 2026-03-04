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

static struct timespec t_end; 

void* spawn_function(void* x){           // Simple Math for Spawn Function

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int y = 5000; int z = 1000000;

	*(int *)x = *(int *)x + y + z;

	y = y + *(int *)x + z;

	z = z + y + *(int *)x;	

	return (void*)&t_end; 
}

int main(int argc, char *argv[]){

	int x = 100;
	int* xp= &x;

	pthread_t Thread;

	struct timespec t_start, t_res;
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	//int status = pthread_create( &Threads[ i ], NULL, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_start);
	pthread_create( &Thread, NULL, spawn_function, xp);

	struct timespec* temp = &t_end;
	
	pthread_join(Thread, (void *)&temp);
	
	//printf("\n%p\n", &t_end);	
	//printf("%ld\n", t_end.tv_sec);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}

