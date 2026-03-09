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
 * Benchmark: 02G: Spawn time after ; No sync checkpoints (Pthreads)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

void* spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*)NULL; 
}

void timer_fcn(){
	struct timeval t_start, t_end;
	gettimeofday(&t_start, NULL); // struct timespec *tp
	gettimeofday(&t_end, NULL);	

	while( ( (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000)  ) < 3.0 ){	
		// spin wait
		gettimeofday(&t_end, NULL);
	}

	return; 

}
int main(int argc, char *argv[]){

	pthread_t Threads1, Threads2, Threads3;
	int            ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

 	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	// each checkpoint is a little different
	// or they're all same and diff ones are in like 02B,etc.
	// Time per checkpoint?
	
	pthread_create( &Threads1, &attr, spawn_function, NULL);
	// no checkpoints

	pthread_create( &Threads2, &attr, spawn_function, NULL);


	pthread_create( &Threads3, &attr, spawn_function, NULL);

	
	timer_fcn(); // all threads complete before end time

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// destroy attr
	pthread_attr_destroy(&attr);

	// printf("02G\n");

	return 0;
}
