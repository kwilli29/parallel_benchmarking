#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <math.h>
#include <sys/time.h>
#include "../../include/numthreads.h"
#include <time.h>
enum {
    _MSEC_PER_SEC = 1000,
    _USEC_PER_SEC = 1000 * 1000,
    _NSEC_PER_SEC = 1000 * 1000 * 1000
};
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
/* Benchmark: 02C Spawn time before ; For-Loop Spawns (Pthreads)
 * Launch a bunch and measure when all done 
 */

//pthread_barrier_t sync_barrier; /* to sync */
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
	//pthread_barrier_wait(&sync_barrier);

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
    int iters=50;
	int ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

	pthread_t Threads[ iters ];

	// pthread_barrier_init
	//pthread_barrier_init(&sync_barrier, NULL, PTH+1);

	struct timespec t_start, t_res;
	struct timespec t_end[iters];
	clock_gettime(CLOCK_MONOTONIC, &t_start);

    // struct timeval t_start; double result=0.0;
	// struct timeval t_end[iters];
    // gettimeofday(&t_start, NULL);

	/****/ 

	for( int i = 0; i < iters; i++ ) {                                     // # seq. for only
		clock_gettime(CLOCK_MONOTONIC, &t_end[i]);
        // gettimeofday(&t_end[i], NULL);

		pthread_create( &Threads[ i ], &attr, spawn_function_long, NULL);
	}

	// each thread waits until all threads have hit the barrier, then they all return
	//pthread_barrier_wait(&sync_barrier);

	// pthread_destroy_barrier
	//pthread_barrier_destroy(&sync_barrier);

	// destroy attr
	pthread_attr_destroy(&attr);


	printf("****\n");	
	for(int i = 0; i < iters; i++){

		timespec_sub(&t_res, t_end[i], t_start);
		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

        // result = (t_end[i].tv_sec+ (double)t_end[i].tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000);
        // printf("%09f\n", result);
	}

	return 0;
}