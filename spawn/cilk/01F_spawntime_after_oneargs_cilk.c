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
 * Benchmark: 01F: Spawn time after ; One Spawns w/ Fcn args (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));


void spawn_function(int x, int y){           // Simple Spawn Function
	int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp
	
	cilk_spawn spawn_function(100, 5000); 
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	cilk_sync;

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01C\n");

	return 0;
}
/* 
wsp_t start = wsp_getworkspan();

wsp_t end = wsp_getworkspan();
wsp_t elapsed = wsp_sub(end, start);
wsp_dump(elapsed, "");
*/
