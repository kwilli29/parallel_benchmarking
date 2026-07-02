#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <math.h>
#include <sys/time.h>
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
/* 06A : SpawnTree (Pthreads)
 *
 */

int DEPTH = 10;

void runbench(int);

void spawn_function1(int depcnt){ // 1 argument
	printf("Thread depth: %d\n", depcnt);
	return; 
}

void* spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*) NULL; 
}

void runbench(int depcnt){ //  

   spawn_function(); // depcnt);

	pthread_t thread1;
	pthread_t thread2;

   if(depcnt < DEPTH){

		if (pthread_create(&thread1, NULL, (void *)runbench, (void*)(size_t)depcnt+1) != 0){
			perror("pthread_create"); exit(1); }

		if (pthread_create(&thread2, NULL, (void *)runbench, (void*)(size_t)depcnt+1) != 0){
			perror("pthread_create"); exit(1); }

		//// //// 
		
		if (pthread_join(thread1, NULL) != 0){
			perror("pthread_join1"); exit(1); }

		if (pthread_join(thread2, NULL) != 0){
			perror("pthread_join2"); exit(1); }
    	}


    return;
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

	int depcnt = 0;

	// struct timespec t_start, t_res, t_end;
	// clock_gettime(CLOCK_MONOTONIC, &t_start); //

    struct timeval t_start, t_end;
    double result=0.0;
    gettimeofday(&t_start, NULL);

	runbench(depcnt); // Main thread

	// clock_gettime(CLOCK_MONOTONIC, &t_end);
	// timespec_sub(&t_res, t_end, t_start);
	// printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    gettimeofday(&t_end, NULL);     
    result = (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000);
    printf("%09f\n", result);	
	
	//printf("D spawntree_pthreads :%d\n", DEPTH);

   return 0;
}