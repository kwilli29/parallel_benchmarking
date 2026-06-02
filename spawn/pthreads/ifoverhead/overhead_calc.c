#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "../ctimer.h"
#include "../../../include/numthreads.h"

pthread_barrier_t sync_barrier; /* to sync */

// Overhead Calc
void* spawn_function(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	// pthread_barrier_wait
	pthread_barrier_wait(&sync_barrier);

	return (void*) NULL; 
}
void* spawn_function1(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	// pthread_barrier_wait
	pthread_barrier_wait(&sync_barrier);

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
            if (PTH > 301){
                PTH = number_threads();
            }
        }
    }

    struct timespec t_start, t_end, t_res;

    int            ds, rc;
	pthread_attr_t attr;
	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }
	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }
	pthread_t Threads[ PTH ];

	pthread_barrier_init(&sync_barrier, NULL, 1); // pthread_barrier_init

    /****************  01A ****************/ 
    printf("01A\n");

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(PTH-1 >= 0){ pthread_create( &Threads[ 0 ], &attr, spawn_function, NULL); }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp  : %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(PTH-1 >= 0){  }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("correct ifnosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(PTH-2 >= 0) {} 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("incorrect ifnosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    /****************  02A ****************/
    struct timespec t_end1[PTH];

    printf("02A\n");
	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(PTH-1 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end1[0] ); pthread_create( &Threads[ 0 ], &attr, spawn_function, NULL); }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(PTH-1 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end1[0] ); }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);


	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(PTH-1 >= 0){  }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnotimenosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// destroy attr
	pthread_attr_destroy(&attr);

    /****************  04A ****************/
    struct timespec t_start1[PTH];
    struct timespec* temp = (struct timespec *)&t_end1[0];
    pthread_t th4[PTH];

    printf("04A\n");

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
	if( PTH-1 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start1[0]); pthread_create( &th4[ 0 ], NULL, spawn_function1, (void *)&t_end1[0]); }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(PTH-1 >= 0){ pthread_join( th4[ 0 ], (void *)&temp); temp = (struct timespec *)&t_end1[0]; }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifjoin: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
	if( PTH-1 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start1[0]); }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnosp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(PTH-1 >= 0){ temp = (struct timespec *)&t_end1[0]; }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnojoin: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
	if( PTH-1 >= 0 ){ }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnotimenospnojoin: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    // pthread_destroy_barrier
	pthread_barrier_destroy(&sync_barrier);

    return 0;
}