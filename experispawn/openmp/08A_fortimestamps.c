#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>
#include "../../include/numthreads.h"
/* Benchmark: 08A: For Timestamps (OpenMP)
 * Launch a bunch and measure when all done 
 */

void spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){

	int OMP_THREADS = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            OMP_THREADS = number_threads();
        } else {
            OMP_THREADS = atoi(argv[1]);
            if (OMP_THREADS < 1){
                OMP_THREADS = number_threads();;
            }
        }
    }
    printf("* # Spawns: %d\n", OMP_THREADS);

    struct timespec t3, t4, t5;//, t_start;
    struct timespec t_res;
    struct timespec t1[OMP_THREADS]; struct timespec t2[OMP_THREADS];

    // clock_gettime(CLOCK_MONOTONIC, &t_start);

    //////////////////////////////////////////////////////

    // !!!! An alternative way to do this is to have the outer for loop 
    // run in a shell script that executes this program w/ an input argument !!!!

    #pragma omp parallel
    #pragma omp single
    {
      for(int i=1; i < OMP_THREADS; i++){      //    for i=1,spawn_max

        clock_gettime(CLOCK_MONOTONIC, &t1[0]);     // measure clock - t1[0]
        for(int j=1; j < i; j++){                // for j 1,i
            clock_gettime(CLOCK_MONOTONIC, &t1[j]); // measure clock -- t1
        }
        clock_gettime(CLOCK_MONOTONIC, &t2[0]);     // measure clock - t2[0]
        for(int j=1; j < i; j++){                // for j 1,i
            clock_gettime(CLOCK_MONOTONIC, &t2[j]); // measure clock -- t2
                #pragma omp task                     // spawn
                spawn_function();
        }
        clock_gettime(CLOCK_MONOTONIC, &t3);     // measure clock - t3

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

      }

        clock_gettime(CLOCK_MONOTONIC, &t4); // measure clock t4
    }   // sync
    clock_gettime(CLOCK_MONOTONIC, &t5); // measure clock t5

    //////////////////////////////////////////////////////
    
    printf("**** SYNC ****:\n");

    timespec_sub(&t_res, t5, t4);
    printf("t5-t4,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t5-t4

    //timespec_sub(&t_res, t8, t_start);
    //printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t8

	return 0;
}