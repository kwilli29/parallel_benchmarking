#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>
#include "../../include/numthreads.h"

/* Benchmark: 04C: Spawn time before thread function begins ; For-Loop Spawns (Serial) 
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

struct timespec spawn_function(){           // Simple Function to Spawn

	struct timespec t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; //  end_time; 
}

int main(int argc, char *argv[]){

	int N = 100;

	struct timespec t_start, t_res; 
	struct timespec t_end[N];

	clock_gettime(CLOCK_MONOTONIC, &t_start); //


	for(int i=0; i < N; i++){ 	
		t_end[i] = spawn_function();

	} 

	printf("****\n");	
	for(int i = 0; i < N; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	// printf("04C\n");
	
	return 0;
}
