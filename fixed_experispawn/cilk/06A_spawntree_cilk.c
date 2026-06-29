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
#include "ctimer.h"
#include <math.h>
#include <sys/time.h>

/* Benchmark: 06A: Spawn Tree ; CilkScope , Recursion (Cilk)
 * Optional argument to specify the depth of the spawn tree. 
 * Main thread calls runbench function
 * 
 * runbench function calls a function to print the depth
 * then calls 2 cilk_spawns which invoke runbench
 */

void runbench(int, int);

/*void spawn_function1(int depcnt){           // Print Depth Function
	printf("Thread depth: %d\n", depcnt);
	return; 
}*/

void spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

void runbench(int depcnt, int DEPTH){

	spawn_function(); // call the Print Depth function

	if(depcnt < DEPTH){

        cilk_scope{
            cilk_spawn runbench(depcnt+1, DEPTH); // cilk_spawn
            runbench(depcnt+1, DEPTH);
        }

        cilk_sync;          // all spawned children must complete before proceeding
	}

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
            if(NCILK < 1){
                NCILK = __cilkrts_get_nworkers();
            }
        }
    }
	printf("* # Spawns: %d\n", NCILK);

	int DEPTH = 10;
	int depcnt = 0;

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	runbench(depcnt, DEPTH); // Main thread

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
  
	// printf("06A\n");
 
	return 0;
}