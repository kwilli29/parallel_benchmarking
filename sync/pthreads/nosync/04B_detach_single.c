#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* 
 * Benchmark: 04B: Detach time just the single sync command ; Compare sync with time for function (Pthreads)
 * Try timing just the no sync command after 1 thread / a few threads
 */

void * spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void *)NULL; 
}

int main(int argc, char *argv[]){

	pthread_t Threads0, Threads1;
	int            ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

 	struct timespec t_start, t_res, t_end;
	struct timeval tstart, tend;

	pthread_create( &Threads0, &attr, spawn_function, NULL);

	clock_gettime(CLOCK_MONOTONIC, &t_start); // 
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("++++:\n%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start);
	pthread_create( &Threads1, &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("****:\n%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	gettimeofday(&tstart, NULL); //
	gettimeofday(&tend, NULL);	
	while( ( (tend.tv_sec+ (double)tend.tv_usec/1000000) - (tstart.tv_sec+(double)tstart.tv_usec/1000000)  ) < 1.0 ){	
		gettimeofday(&tend, NULL);
	}

	clock_gettime(CLOCK_MONOTONIC, &t_start);
	spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("####:\n%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start); 
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("----:\n%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("04B\n");
	
	// destroy attr
	pthread_attr_destroy(&attr);

	return 0;
}
