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

/* Benchmark: 08A For Timestamps (Pthreads)
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
            //if (PTH > 301){
                PTH = number_threads();;
            //}
        }
    }
	printf("* # Spawns: %d\n", PTH);

	int ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

	pthread_t Threads[ PTH ];

    struct timespec t1, t3, t5, t6, t7, t_start, t2,t4; // ,t8;
    struct timespec t_res;
    // struct timespec t2[PTH]; struct timespec t4[PTH];

    clock_gettime(CLOCK_MONOTONIC, &t_start);

    //////////////////////////////////////////////////////

    // !!!! An alternative way to do this is to have the outer for loop 
    // run in a shell script that executes this program w/ an input argument !!!!

    for(int i=1; i < PTH; i++){      //    for i=1,spawn_max

        clock_gettime(CLOCK_MONOTONIC, &t1);     // measure clock - t1
        for(int j=1; j < i; j++){                // for j 1,i
            clock_gettime(CLOCK_MONOTONIC, &t2); // measure clock -- t2
        }
        clock_gettime(CLOCK_MONOTONIC, &t3);     // measure clock - t3
        for(int j=1; j < i; j++){                // for j 1,i
            clock_gettime(CLOCK_MONOTONIC, &t4); // measure clock -- t4
            pthread_create( &Threads[ j-1 ], &attr, spawn_function, NULL);   // spawn
        }
        clock_gettime(CLOCK_MONOTONIC, &t5);     // measure clock - t5
    }
    clock_gettime(CLOCK_MONOTONIC, &t6); // measure clock
    // sync
    clock_gettime(CLOCK_MONOTONIC, &t7); // measure clock

    //////////////////////////////////////////////////////
    
    printf("**** OUTPUTS -->****:\n");
    timespec_sub(&t_res, t1, t_start);
    printf("t1,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t1

    timespec_sub(&t_res, t2, t_start);
    printf("t2,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t2

    timespec_sub(&t_res, t2, t1);
    printf("t2-t1,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t2-t1

    timespec_sub(&t_res, t3, t_start);
    printf("t3,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t3

    timespec_sub(&t_res, t4, t_start);
    printf("t4,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t4

    timespec_sub(&t_res, t4, t3);
    printf("t3-t4,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t3-t4

    timespec_sub(&t_res, t5, t_start);
    printf("t5,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t5

    timespec_sub(&t_res, t5, t4);
    printf("t5-t4,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t5-t4

    printf("**** SYNC ****:\n");

    timespec_sub(&t_res, t6, t_start);
    printf("t6,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t6

    timespec_sub(&t_res, t7, t_start);
    printf("t7,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t7

    timespec_sub(&t_res, t7, t6);
    printf("t7-t6,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t7-t6

	// destroy attr
	pthread_attr_destroy(&attr);
		
	return 0;
}