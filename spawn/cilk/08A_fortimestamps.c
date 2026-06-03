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

/* Benchmark: 08A: Spawn time after ; (Cilk)
 *
 */

void spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

    int NCILK = __cilkrts_get_nworkers();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            NCILK = __cilkrts_get_nworkers();
        } else {
            NCILK = atoi(argv[1]);
            // if(NCILK > 301){  NCILK = __cilkrts_get_nworkers(); }
        }
    }
	printf("* # Spawns: %d\n", NCILK);

    struct timespec t1, t2, t3, t4, t5, t6, t7, t8, t_start;
    // struct timespec t2[NCILK]; struct timespec t4[NCIlK]; // -- not needed

    clock_gettime(CLOCK_MONOTONIC, &t_start);

    //////////////////////////////////////////////////////

    for(int i=1; i < NCILK; i++){      //    for i=1,spawn_max
        clock_gettime(CLOCK_MONOTONIC, &t1);     // measure clock
        for(int j=1; j < i; j++){                // for j 1,i
            clock_gettime(CLOCK_MONOTONIC, &t2); // measure clock -- 
        }
        clock_gettime(CLOCK_MONOTONIC, &t3);     // measure clock
        for(int j=1; j < i; j++){                // for j 1,i
            clock_gettime(CLOCK_MONOTONIC, &t4); // measure clock -- 
            cilk_spawn spawn_function();         // spawn
        }
        clock_gettime(CLOCK_MONOTONIC, &t5);     // measure clock
    }
    clock_gettime(CLOCK_MONOTONIC, &t6); // measure clock
    cilk_sync; // sync
    clock_gettime(CLOCK_MONOTONIC, &t7); // measure clock

    //////////////////////////////////////////////////////
    
    struct timespec t_res;
		
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

    timespec_sub(&t_res, t6, t_start);
    printf("t6,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t6

    timespec_sub(&t_res, t7, t_start);
    printf("t7,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t7

    timespec_sub(&t_res, t7, t6);
    printf("t7-t6,%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t7-t6

    //timespec_sub(&t_res, t8, t_start);
    //printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec); // t8

    return 0;
}