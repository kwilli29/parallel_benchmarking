#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Benchmark: Launch Done (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

void spawn_function(){           // Print Depth Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){

	int DEPTH = 273;

	struct timeval start_time,endtime;
	gettimeofday(&start_time, NULL);


	struct timespec t_start, t_res;
	struct timespec t_end[3];
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	//ctimer_t start;
	//struct timespec* ends[3];

	// ctimer_start(&start);
	//ctimer_start(&ends[0]);
	//ctimer_start(&ends[1]);
	//ctimer_start(&ends[2]);
	
	//ctimer_stop(&ends[0]);
	//ctimer_measure(&ends[0]);
	clock_gettime(CLOCK_MONOTONIC, &t_end[0]);
	cilk_spawn spawn_function();

	//ctimer_stop(&ends[1]);
	//ctimer_measure(&ends[1]);
	clock_gettime(CLOCK_MONOTONIC, &t_end[1]);
	cilk_spawn spawn_function();
		
	//ctimer_stop(&ends[2]);
	//ctimer_measure(&ends[2]);
	clock_gettime(CLOCK_MONOTONIC, &t_end[2]);
	cilk_spawn spawn_function();

	cilk_sync; // */

	/*ctimer_stop(&start);
	ctimer_measure(&start);

	ctimer_measure(&ends[0]);
	ctimer_measure(&ends[1]); 
	ctimer_measure(&ends[2]); 

	printf("ctimer test()\n");
	
	ctimer_print(start, "start");
	ctimer_print(ends[0], "ends[0]");
	ctimer_print(ends[1], "ends[1]");
	ctimer_print(ends[2], "ends[2]");*/

	for(int i = 0; i < 3; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld sec\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	gettimeofday(&endtime, NULL);
	double realTime = 0.0;
	realTime = (endtime.tv_sec+ (double)endtime.tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);

	printf("\ngtod: %lf\n\n", realTime);

	return 0;
}
