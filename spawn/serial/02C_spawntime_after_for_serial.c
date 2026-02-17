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

/* Benchmark: 02C: Spawn time before ; For-Loop Spawns (Serial)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

void spawn_function(){           // Simple Function to Spawn

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

	int N = 272;

	struct timespec t_start, t_res;
	struct timespec t_end[N-1];

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	for(int i=0; i < N-1; i++){
		
		clock_gettime(CLOCK_MONOTONIC, &t_end[i]); spawn_function();

	}

	for(int i = 0; i < N-1; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	//printf("02C\n");

	return 0;
}



