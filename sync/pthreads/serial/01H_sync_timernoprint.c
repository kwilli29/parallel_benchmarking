#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* 
 * Benchmark: 01H: Sync time no sync command ; Timer Sync No Prints (Pthreads)
 * Try timing no sync command after 1 thread / a few threads
 */

float TIMER1 = 2.0;
float TIMER2 = 4.0;

void* spawn_function1(){           // Simple Spawn Function

	struct timeval t_start, t_end;
	gettimeofday(&t_start, NULL); // struct timespec *tp
	gettimeofday(&t_end, NULL);	

	while( ( (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000)  ) < TIMER1 ){	
		// spin wait
		gettimeofday(&t_end, NULL);
	}

	//printf("done w/ timer1: %lf\n", (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000));

	return (void*)NULL; 
}
void* spawn_function2(){           // Simple Spawn Function

	struct timeval t_start, t_end;
	gettimeofday(&t_start, NULL); // struct timespec *tp
	gettimeofday(&t_end, NULL);	

	while( ( (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000)  ) < TIMER2 ){	
		// spin wait
		gettimeofday(&t_end, NULL);
	}

	//printf("done w/ timer2: %lf\n", (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000));

	return (void*)NULL; 
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

	clock_gettime(CLOCK_MONOTONIC, &t_start); //

	pthread_create( &Threads1, &attr, spawn_function1, NULL);
	pthread_create( &Threads2, &attr, spawn_function2, NULL);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01H\n");

	// destroy attr
	pthread_attr_destroy(&attr);

	return 0;
}
