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

/* Benchmark: 01A: Spawn time after ; Sequential Spawns (Cilk)
 * Launch a bunch and measure when all done 
 */

void spawn_function(){           // Simple Spawn Function -- can be changed
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
            if (NCILK > 301){
                NCILK = __cilkrts_get_nworkers();
            }
        }
    }

	printf("* # Spawns: %d\n", NCILK);

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

	// sequentially spawn functions
    if(NCILK-1 >= 0) {  } // 1

    clock_gettime(CLOCK_MONOTONIC, &t_end);

	cilk_sync; 

	timespec_sub(&t_res, t_end, t_start);
    printf("ns: %.12ld\n", t_res.tv_nsec);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	//printf("01H\n");

	return 0;
}