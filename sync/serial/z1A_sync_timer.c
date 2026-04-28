#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* 
 * Benchmark: 01A: Sync time just the sync command ; Timer No Sync (Serial)
 * Try timing just the sync command after 1 thread / a few threads
 */

float TIMER1 = 2.0;
float TIMER2 = 4.0;

#define NCILK __cilkrts_get_nworkers()

void spawn_function1(){           // Simple Spawn Function

	struct timeval t_start, t_end;
	gettimeofday(&t_start, NULL); // 
	gettimeofday(&t_end, NULL);	

	while( ( (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000)  ) < TIMER1 ){	
		// spin wait
		gettimeofday(&t_end, NULL);
	}

	printf("*done w/ timer1: %lf\n", (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000));

	return; 
}
void spawn_function2(){           // Simple Spawn Function

	struct timeval t_start, t_end;
	gettimeofday(&t_start, NULL); //
	gettimeofday(&t_end, NULL);	

	while( ( (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000)  ) < TIMER2 ){	
		// spin wait
		gettimeofday(&t_end, NULL);
	}

	printf("*done w/ timer2: %lf\n", (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000));

	return; 
}


int main(int argc, char *argv[]){

 	struct timespec t_start, t_res, t_end;

	spawn_function1();
	spawn_function2();

	printf("*done w/ spawns\n");

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp
	printf("*start no sync\n");
	printf("*done no sync\n");
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01A\n");

	return 0;
}
