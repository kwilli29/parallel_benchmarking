#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>
#include "../../include/numthreads.h"
/* Benchmark: 01A: Spawn time after ; Sequential Spawns (Pthreads)
 * Launch a bunch and measure when all done
 */


pthread_barrier_t sync_barrier; /* to sync */

void* spawn_function(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	// pthread_barrier_wait
	pthread_barrier_wait(&sync_barrier);

	return (void*) NULL; 
}

int main(int argc, char *argv[]){

	int PTH = 100;

	int            ds, rc;
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

	pthread_create( &Threads[ 0 ], &attr, spawn_function, NULL); // all threads spawn detached,
	pthread_create( &Threads[ 1 ], &attr, spawn_function, NULL); // hit the barrier,
	pthread_create( &Threads[ 2 ], &attr, spawn_function, NULL); // and are immmediately freed w/o joining
	pthread_create( &Threads[ 3 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 4 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 5 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 6 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 7 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 8 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 9 ], &attr, spawn_function, NULL); // 10

	pthread_create( &Threads[ 10 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 11 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 12 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 13 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 14 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 15 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 16 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 17 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 18 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 19 ], &attr, spawn_function, NULL); // 20

	pthread_create( &Threads[ 20 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 21 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 22 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 23 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 24 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 25 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 26 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 27 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 28 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 29 ], &attr, spawn_function, NULL); // 30

	pthread_create( &Threads[ 30 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 31 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 32 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 33 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 34 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 35 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 36 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 37 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 38 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 39 ], &attr, spawn_function, NULL); // 40

	pthread_create( &Threads[ 40 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 41 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 42 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 43 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 44 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 45 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 46 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 47 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 48 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 49 ], &attr, spawn_function, NULL); // 50

	pthread_create( &Threads[ 50 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 51 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 52 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 53 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 54 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 55 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 56 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 57 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 58 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 59 ], &attr, spawn_function, NULL); // 60

	pthread_create( &Threads[ 60 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 61 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 62 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 63 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 64 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 65 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 66 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 67 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 68 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 69 ], &attr, spawn_function, NULL); // 70

	pthread_create( &Threads[ 70 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 71 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 72 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 73 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 74 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 75 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 76 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 77 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 78 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 79 ], &attr, spawn_function, NULL); // 80

	pthread_create( &Threads[ 80 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 81 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 82 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 83 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 84 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 85 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 86 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 87 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 88 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 89 ], &attr, spawn_function, NULL); // 90

	pthread_create( &Threads[ 90 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 91 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 92 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 93 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 94 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 95 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 96 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 97 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 98 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 99 ], &attr, spawn_function, NULL); // 100

	// each thread waits until all threads have hit the barrier, then they all return
	pthread_barrier_wait(&sync_barrier);

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	// pthread_destroy_barrier
	pthread_barrier_destroy(&sync_barrier);

	// destroy attr
	pthread_attr_destroy(&attr);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
		
	return 0;
}