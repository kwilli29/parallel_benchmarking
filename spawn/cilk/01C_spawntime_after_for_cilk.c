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

/* Benchmark: 01C: Spawn time after ; For-Loop Spawns (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

#define NCILK __cilkrts_get_nworkers()

void spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){

	wsp_t start = wsp_getworkspan();

	//struct timespec t_start, t_res, t_end;
	//clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp
	
	for(int i = 0; i < NCILK-1; i++){
		cilk_spawn spawn_function(); 
	}
 	
	//clock_gettime(CLOCK_MONOTONIC, &t_end);
	//timespec_sub(&t_res, t_end, t_start);
	//printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01C\n");

	wsp_t end = wsp_getworkspan();
	wsp_t elapsed = wsp_sub(end, start);
	wsp_dump(elapsed, "1C FOR CILK");

	return 0;
}
/* 
wsp_t start = wsp_getworkspan();

wsp_t end = wsp_getworkspan();
wsp_t elapsed = wsp_sub(end, start);
wsp_dump(elapsed, "qsort_sample");
*/
