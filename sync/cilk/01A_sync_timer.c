#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* 
 * Benchmark: 01A: Sync time just the sync command ; Timer Sync (Cilk)
 * Try timing just the sync command after 1 thread / a few threads
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

float TIMER1 = 4.0;
float TIMER2 = 8.0;

#define NCILK __cilkrts_get_nworkers()

void spawn_function1(){           // Simple Spawn Function

	struct timeval t_start, t_end;
	gettimeofday(&t_start, NULL); // struct timespec *tp
	gettimeofday(&t_end, NULL);	

	while( ( (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000)  ) < TIMER1 ){	
		// spin wait
		gettimeofday(&t_end, NULL);
	}

	printf("done w/ timer1: %lf\n", (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000));

	return; 
}
void spawn_function2(){           // Simple Spawn Function

	struct timeval t_start, t_end;
	gettimeofday(&t_start, NULL); // struct timespec *tp
	gettimeofday(&t_end, NULL);	

	while( ( (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000)  ) < TIMER2 ){	
		// spin wait
		gettimeofday(&t_end, NULL);
	}

	printf("done w/ timer2: %lf\n", (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000));

	return; 
}


int main(int argc, char *argv[]){

 	struct timespec t_start, t_res, t_end;

	cilk_spawn spawn_function1();
	cilk_spawn spawn_function2();

	printf("done w/ spawns\n");

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp
	printf("start sync\n");
	cilk_sync;
	printf("done sync\n");
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);


	// printf("01D\n");

	return 0;
}

/* 
wsp_t start = wsp_getworkspan();

wsp_t end = wsp_getworkspan();
wsp_t elapsed = wsp_sub(end, start);
wsp_dump(elapsed, "");
*/

