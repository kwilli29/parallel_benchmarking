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

void spawn_function(){           // Simple Function to Spawn

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

    int NSERIAL = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            NSERIAL = number_threads();
        } else {
            NSERIAL = atoi(argv[1]);
            if (NSERIAL > 301){
                NSERIAL = number_threads();
            }
        }
    }

	struct timespec t_start, t_res;
	struct timespec t_end[NSERIAL];

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	for(int i=0; i < NSERIAL; i++){
		
		clock_gettime(CLOCK_MONOTONIC, &t_end[i]); spawn_function();

	}

	printf("****\n");
	for(int i = 0; i < NSERIAL; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	//printf("02C\n");

	return 0;
}