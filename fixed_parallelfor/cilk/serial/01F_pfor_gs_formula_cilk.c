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
 * Benchmark: 01F: Grainsize = Formula Result; CilkFor (Cilk)
 * Launch a bunch and measure when all done
 */

#define NCILK __cilkrts_get_nworkers()
// #define FORMULA min(2048, (NCILK-1/(8*NCILK)))

void spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){

 	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // 

	//#pragma cilk grainsize FORMULA 
	cilk_for(int i = 0; i < NCILK-1; i++){
		spawn_function();
	} 

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01F\n");

	return 0;
}

