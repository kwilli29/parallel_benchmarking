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

/* 
 * Benchmark: 02D: Function in Parallel For  ; Serial For (Serial)
 * Launch a bunch and measure when all done -  
 */

#define NCILK 272

void spawn_function(){           // Simple Spawn Function

	printf("**0\t"); // print thread id

	return; 
}

int main(int argc, char *argv[]){

 	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // 
	
	spawn_function(); 

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("\n%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("02D\n");

	return 0;
}
