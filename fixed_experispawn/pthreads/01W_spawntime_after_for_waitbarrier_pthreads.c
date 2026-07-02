#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <math.h>
#include "../../include/numthreads.h"
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
/* Benchmark: 01!: Spawn timer after ; For-Loop Spawns Barrier Wait (Pthreads)
 * Launch a bunch and measure when all done 
 */

pthread_barrier_t sync_barrier; /* to sync */ 

static const int ITERATION = 100000;
void* spawn_function_long(){

    double z = 0;
    double i = 0.0;

    double x = 15.0;
	static const int nn = 87;

    double a =0.0;
	for (int j = 0; j < ITERATION; j++){
        z*=acos((double)j);

        for (long m = 1; m < nn; ++m){
            a = (double)((double)m*1.0);
            x = sin((double)x*1.0) / (double)(a*1.0 + (j * i + i + j)*1.0 / a);
        }

        z += x + z; //
        z= tanh((double)z);

        i += 1.0;
	}

	return (void*) NULL; 
}
void* spawn_function(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	// pthread_barrier_wait 
	// pthread_barrier_wait(&sync_barrier);

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
            if (PTH < 1){
                PTH = number_threads();;
            }
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

	// pthread_barrier_init 
	pthread_barrier_init(&sync_barrier, NULL, PTH+1);

	struct timespec t_start, t_res, t_end;

	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	for( int i = 0; i < PTH; i++ ) {                                     // # seq. for only
		pthread_create( &Threads[ i ], &attr, spawn_function_long, NULL);
	}

	// does main thread need a barrier here for the "sync" ???? !!!!
	pthread_barrier_wait(&sync_barrier);

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	// pthread_destroy_barrier 
	pthread_barrier_destroy(&sync_barrier); // sync all threads before getting endtime

	// destroy attr
	pthread_attr_destroy(&attr);
	
	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
		
	return 0;
}