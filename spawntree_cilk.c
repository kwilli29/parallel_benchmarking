#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
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

void spawn_function(int depcnt){ // 1 argument

    printf("Thread depth: %d\n", depcnt);

    return; 
}

void runbench(int depcnt, int DEPTH){

	 ctimer_t t;
    ctimer_start(&t);

    spawn_function(depcnt); // call the print depth function

    ctimer_stop(&t);
	 ctimer_measure(&t);
	 ctimer_print(t, "print depth function");

    if(depcnt < DEPTH){

        ctimer_start(&t);
        cilk_spawn runbench(depcnt+1,DEPTH); // cilk_spawn #1
        ctimer_stop(&t);
		  ctimer_measure(&t);
        ctimer_print(t, "cspawn1");

        ctimer_start(&t);
        cilk_spawn runbench(depcnt+1,DEPTH); // cilk spawn #2
        ctimer_stop(&t);
		  ctimer_measure(&t);
        ctimer_print(t, "cspawn2");

        ctimer_start(&t);
        cilk_sync; // all spawned children must complete before proceeding
        ctimer_stop(&t);
		  ctimer_measure(&t);
        ctimer_print(t,"csync"); // time cilk_sync

    }

    return;
}

int main(int argc, char *argv[]){

    struct timeval start, end;
    int DEPTH = 3;
    int depcnt = 0;

	 if(argc > 1){
		DEPTH = atoi(argv[1]); // optional depth argument
	 }

	 ctimer_t t;
    ctimer_start(&t);

	 runbench(depcnt, DEPTH); // main thread

    ctimer_stop(&t);
	 ctimer_measure(&t);

    ctimer_print(t, "Real Time: ");

    return 0;
}


