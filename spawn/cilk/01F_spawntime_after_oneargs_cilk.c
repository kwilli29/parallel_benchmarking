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
 * Launch a bunch and measure when all done
 */


void spawn_function(int x){           // Simple Spawn Function
	int y=5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){
	
	int x = 100;

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp
	
	cilk_spawn spawn_function(x); // single spawn with one int arg, can adjust 
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	cilk_sync;

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01F\n");

	return 0;
}
