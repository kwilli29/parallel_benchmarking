#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: 03G: Time b/w thread complete and return ; ThSy Time (Cilk) 
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

#define NCILK __cilkrts_get_nworkers()

struct timespec spawn_function(){           // Simple Function to Spawn

	struct timespec t_start; // 

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	clock_gettime(CLOCK_MONOTONIC, &t_start);

	return t_start; //  to get REALLY granular, could measure time to return timeval from fcn and sub from end
}

int main(int argc, char *argv[]){

	struct timespec t_res,t_start, t_end;

	t_start = cilk_spawn spawn_function(); // Take time stamp before each spawn

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	cilk_sync;

	/**/

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	// printf("04D\n");
	
	// cilk_rts_getworker_number;

	return 0;
}


