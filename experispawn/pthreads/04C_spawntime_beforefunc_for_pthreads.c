#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>
#include "../../include/numthreads.h"
/* Benchmark: 04C: Spawn time before function ; For-Loop Spawns (Pthreads)
 * Launch a bunch and measure when all done 
 */

void* spawn_function(void* t_end){           // Simple Math for Spawn Function

	clock_gettime(CLOCK_MONOTONIC, (struct timespec *)t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*)t_end; 
}

int main(int argc, char *argv[]){

	int PTH = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            PTH = number_threads();
        } else {
            PTH = atoi(argv[1]);
            if (PTH < 1){
                PTH = number_threads();;
            }
        }
    }
	printf("* # Spawns: %d\n", PTH);

	pthread_t Threads[ PTH ];

	struct timespec t_start[PTH]; struct timespec t_res;
	struct timespec t_end[PTH];

	/****/ 

	for( int i = 0; i < PTH; i++ ) {                                     // # seq. for only
		clock_gettime(CLOCK_MONOTONIC, &t_start[i]);
		pthread_create( &Threads[ i ], NULL, spawn_function, (void*)&t_end[i]);
	}

	struct timespec* temp = (struct timespec *)&t_end[0];
	
	for( int i = 0; i < PTH; i++ ) {                                     // join
		pthread_join( Threads[ i ], (void*)&temp);

		// if(i < 5){ printf("\n%p\n", &t_end); printf("%ld\n", t_end[i].tv_nsec); }

		if (i < PTH-1){ temp = &t_end[i+1]; }
	}

	for(int i = 0; i < PTH; i++){

		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	}

	return 0;
}