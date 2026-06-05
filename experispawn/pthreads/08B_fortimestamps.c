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

/* Benchmark: 08B For Timestamps (Pthreads)
 * Launch a bunch and measure when all done 
 */ 

void* spawn_function(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*) NULL; 
}

int main(int argc, char *argv[]){

	int PTH = number_threads();
    
    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            PTH = number_threads();
        } else {
            PTH = atoi(argv[1]);
        }
    }
	printf("* # Spawns: %d\n", PTH);

	pthread_t Threads[ PTH ];

    struct timespec t3;// , t5;//, t_start;
    struct timespec t_res;
    struct timespec t1[PTH]; struct timespec t2[PTH]; struct timespec t4[PTH];

    //////////////////////////////////////////////////////

    // !!!! An alternative way to do this is to have the outer for loop 
    // run in a shell script that executes this program w/ an input argument !!!!

    for(int i=1; i < PTH; i++){      //    for i=1,spawn_max

        clock_gettime(CLOCK_MONOTONIC, &t1[0]);     // measure clock - t1[0]
        for(int j=1; j < i; j++){                   // for j 1,i
            clock_gettime(CLOCK_MONOTONIC, &t1[j]); // measure clock -- t1
        }
        clock_gettime(CLOCK_MONOTONIC, &t2[0]);     // measure clock - t2[0]
        for(int j=1; j < i; j++){                   // for j 1,i
            clock_gettime(CLOCK_MONOTONIC, &t2[j]); // measure clock -- t2
            pthread_create( &Threads[ j-1 ], NULL, spawn_function, NULL);   // spawn
        }
        clock_gettime(CLOCK_MONOTONIC, &t3);        // measure clock - t3

        clock_gettime(CLOCK_MONOTONIC, &t4[0]);     // measure clock
        for(int j=1; j < i; j++){                   // for j 1,i2
            clock_gettime(CLOCK_MONOTONIC, &t4[j]); // measure clock
            pthread_join( Threads[ j-1 ], NULL);    // join
        }

        printf("**** OUTPUTS --> %d****:\n", i);
        for(int k=1; k<i;k++){
            timespec_sub(&t_res, t1[k], t1[0]);
            printf("t1[0]-t1[%d],%ld.%09ld\n", k, (long)t_res.tv_sec, t_res.tv_nsec); // t1[0]-t1[j]
        }
        for(int k=1; k<i;k++){
            timespec_sub(&t_res, t2[k], t2[0]);
            printf("t2[0]-t2[%d],%ld.%09ld\n", k, (long)t_res.tv_sec, t_res.tv_nsec); // t2[0]-t2[j]
        }

        timespec_sub(&t_res, t3, t2[0]);
        printf("t2[0]-t3,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t2[0]-t2[j]
        
        printf("**** **** **** **** ****\n");

        printf("**** SYNC ****:\n");

         for(int k=1; k<i;k++){
            timespec_sub(&t_res, t4[k], t4[0]);
            printf("t4[0]-t4[%d],%ld.%09ld\n", k, (long)t_res.tv_sec, t_res.tv_nsec); // t2[0]-t2[j]
        }

    }

    //////////////////////////////////////////////////////
		
	return 0;
}