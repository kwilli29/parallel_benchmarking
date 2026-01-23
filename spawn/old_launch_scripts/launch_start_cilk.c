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

/* Benchmark: Launch Start (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 *
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));


struct timeval spawn_function(){           // Simple Function to Spawn

	struct timeval end_time;
	gettimeofday(&end_time, NULL);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return end_time; 
}

// gettimeofday(&end_time, NULL);
// double realTime = (end_time.tv_sec+ (double)end_time.tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);
// printf("\nOverall Time cilkfor-count_cilk = %lf", realTime);

int main(int argc, char *argv[]){

	int DEPTH = 273;

	struct timeval start_time;
	struct timeval endtimes[DEPTH];

	gettimeofday(&start_time, NULL);

	// ctimer_t t; ctimer_start(&t); ctimer_print(t, "launch_start start");

	#pragma grainsize = 1
	cilk_for(int i = 0; i < DEPTH; i++){ 
	
		endtimes[i] = spawn_function(); 

	} 

	// ctimer_stop(&t); // ctimer_measure(&t);

	double realTime = 0.0;

	for(int i=0; i < DEPTH; i++){
		realTime = (endtimes[i].tv_sec+ (double)endtimes[i].tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);
		printf("\n Overall Time lsc (1) = %lf", realTime);

		//realTime = (endtimes[DEPTH-1].tv_sec+ (double)endtimes[DEPTH-1].tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);
		//printf("\n Overall Time lsc (2) = %lf", realTime);

	}
	
	printf("\n\nlaunch_start()\n");
	//ctimer_print(t, "launch_start");
	
	// cilk_rts_getworker_number;

	return 0;
}


