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
 * Benchmark: 04A: Sync time just the single sync command ; Compare sync with time for function (Cilk)
 * Try timing just the sync command after 1 thread / a few threads
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

void * spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void *)NULL; 
}

int main(int argc, char *argv[]){

	pthread_t Threads0, Threads1;

 	struct timespec t_start, t_res, t_end;
	struct timeval tstart, tend;

	
	pthread_create( &Threads0, NULL, spawn_function, NULL);

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp
	pthread_join(Threads0, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("++++:\n%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start);
	pthread_create( &Threads1, NULL, spawn_function, NULL);
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
	pthread_join(Threads1, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("----:\n%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);


	// printf("04A\n");

	return 0;
}
