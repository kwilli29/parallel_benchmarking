#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: Spawn Tree (Cilk)
 * Optional argument to specify the depth of the spawn tree. 
 * Main thread calls runbench function
 * 
 * runbench function calls a function to print the depth
 * then calls 2 cilk_spawns which invoke runbench
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

void spawn_node(int,int,int);
void runbench(int, int);

void spawn_function(int depcnt){           // Print Depth Function
	printf("Thread depth: %d\n", depcnt);
	return; 
}

void spawn_node(int depcnt, int DEPTH, int id){
    ctimer_start(&t);
    cilk_spawn runbench(depcnt+1, DEPTH); // cilk_spawn
    ctimer_stop(&t);
    ctimer_measure(&t);
    ctimer_print(t, "cspawn #%d:", id); // Time cilk_spawn

}

void runbench(int depcnt, int DEPTH){

	ctimer_t t;
	ctimer_start(&t);

	spawn_function(depcnt); // call the Print Depth function

	ctimer_stop(&t);
	ctimer_measure(&t);
	ctimer_print(t, "Print depth function:");

	if(depcnt < DEPTH){

        cilk_scope{
            spawn_node(depcnt, DEPTH, 1); // spawn nodes in parallel
            spawn_node(depcnt, DEPTH, 2);
        }

        ctimer_start(&t);
        cilk_sync;          // all spawned children must complete before proceeding
        ctimer_stop(&t);
        ctimer_measure(&t);
        ctimer_print(t,"csync:"); // Time cilk_sync
	}

	return;
}

int main(int argc, char *argv[]){

	int DEPTH = 3;
	int depcnt = 0;

	if(argc > 1 && (atoi(argv[1]) <= 10) ){ // depth must be < 10 or else it takes too long
	    DEPTH = atoi(argv[1]); // optional depth argument
	}
 
	ctimer_t t;
	ctimer_start(&t);

	runbench(depcnt, DEPTH); // Main thread

	ctimer_stop(&t);
	ctimer_measure(&t);

    printf("D spawntree_cilk :%d\n", DEPTH);
	ctimer_print(t, "Overall Time spawntree_cilk :");
   
	return 0;
}


