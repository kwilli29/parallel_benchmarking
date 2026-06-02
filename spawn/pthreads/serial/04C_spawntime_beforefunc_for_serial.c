#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>
#include "../../include numthreads.h"

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

	struct timespec t_start[NSERIAL]; struct timespec t_res; 
	struct timespec t_end[NSERIAL];

	for(int i=0; i < NSERIAL; i++){ 	
		clock_gettime(CLOCK_MONOTONIC, &t_start[i]); t_end[i] = spawn_function();

	} 

	printf("****\n");	
	for(int i = 0; i < NSERIAL; i++){
		
		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	// printf("04C\n");
	
	return 0;
}