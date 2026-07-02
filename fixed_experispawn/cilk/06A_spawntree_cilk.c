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
#include <math.h>
#include <sys/time.h>
#include <time.h>

void timespec_sub( struct timespec * t_diff, struct timespec const  t_end,  struct timespec const  t_start ) {
    /**<[out] time difference */ /**<[in]  end time */ /**<[in]  start time */
    t_diff->tv_nsec = t_end.tv_nsec - t_start.tv_nsec; t_diff->tv_sec  = t_end.tv_sec  - t_start.tv_sec;
    if ((t_diff->tv_sec > 0) && (t_diff->tv_nsec < 0)) {
        t_diff->tv_nsec += _NSEC_PER_SEC; t_diff->tv_sec--;
    } else if ((t_diff->tv_sec < 0) && (t_diff->tv_nsec > 0)) {
        t_diff->tv_nsec -= _NSEC_PER_SEC; t_diff->tv_sec++;
    }
    /* (s > 0 & ns > 0) : do nothing (t_start < t_end) */ /* (s < 0 & ns < 0) : do nothing (t_start > t_end) */
}

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

	// struct timespec t_start, t_res, t_end;
	// clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

    struct timeval t_start, t_end;
    double result=0.0;
    gettimeofday(&t_start, NULL);

	runbench(depcnt, DEPTH); // Main thread

	// clock_gettime(CLOCK_MONOTONIC, &t_end);
	// timespec_sub(&t_res, t_end, t_start);
	// printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    gettimeofday(&t_end, NULL); 
    result = (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000);
    printf("%09f\n", result);
  
	// printf("06A\n");
 
	return 0;
}