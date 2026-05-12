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
/* Benchmark: 02A Spawn time before ; Sequential Spawns (Pthreads)
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

	struct timespec t_start, t_res;
	struct timespec t_end[PTH];
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	clock_gettime(CLOCK_MONOTONIC, &t_end[0] ); pthread_create( &Threads[ 0 ], &attr, spawn_function, NULL); // all threads spawn detached,
	clock_gettime(CLOCK_MONOTONIC, &t_end[1] ); pthread_create( &Threads[ 1 ], &attr, spawn_function, NULL); // hit the barrier,
	clock_gettime(CLOCK_MONOTONIC, &t_end[2] ); pthread_create( &Threads[ 2 ], &attr, spawn_function, NULL); // and are immmediately freed w/o joining
	clock_gettime(CLOCK_MONOTONIC, &t_end[3] ); pthread_create( &Threads[ 3 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[4] ); pthread_create( &Threads[ 4 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[5] ); pthread_create( &Threads[ 5 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[6] ); pthread_create( &Threads[ 6 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[7] ); pthread_create( &Threads[ 7 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[8] ); pthread_create( &Threads[ 8 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[9] ); pthread_create( &Threads[ 9 ], &attr, spawn_function, NULL); // 10

	clock_gettime(CLOCK_MONOTONIC, &t_end[10] ); pthread_create( &Threads[ 10 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[11] ); pthread_create( &Threads[ 11 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[12] ); pthread_create( &Threads[ 12 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[13] ); pthread_create( &Threads[ 13 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[14] ); pthread_create( &Threads[ 14 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[15] ); pthread_create( &Threads[ 15 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[16] ); pthread_create( &Threads[ 16 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[17] ); pthread_create( &Threads[ 17 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[18] ); pthread_create( &Threads[ 18 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[19] ); pthread_create( &Threads[ 19 ], &attr, spawn_function, NULL); // 20

	clock_gettime(CLOCK_MONOTONIC, &t_end[20] ); pthread_create( &Threads[ 20 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[21] ); pthread_create( &Threads[ 21 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[22] ); pthread_create( &Threads[ 22 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[23] ); pthread_create( &Threads[ 23 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[24] ); pthread_create( &Threads[ 24 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[25] ); pthread_create( &Threads[ 25 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[26] ); pthread_create( &Threads[ 26 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[27] ); pthread_create( &Threads[ 27 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[28] ); pthread_create( &Threads[ 28 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[29] ); pthread_create( &Threads[ 29 ], &attr, spawn_function, NULL); // 30

	clock_gettime(CLOCK_MONOTONIC, &t_end[30] ); pthread_create( &Threads[ 30 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[31] ); pthread_create( &Threads[ 31 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[32] ); pthread_create( &Threads[ 32 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[33] ); pthread_create( &Threads[ 33 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[34] ); pthread_create( &Threads[ 34 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[35] ); pthread_create( &Threads[ 35 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[36] ); pthread_create( &Threads[ 36 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[37] ); pthread_create( &Threads[ 37 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[38] ); pthread_create( &Threads[ 38 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[39] ); pthread_create( &Threads[ 39 ], &attr, spawn_function, NULL); // 40

	clock_gettime(CLOCK_MONOTONIC, &t_end[40] ); pthread_create( &Threads[ 40 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[41] ); pthread_create( &Threads[ 41 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[42] ); pthread_create( &Threads[ 42 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[43] ); pthread_create( &Threads[ 43 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[44] ); pthread_create( &Threads[ 44 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[45] ); pthread_create( &Threads[ 45 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[46] ); pthread_create( &Threads[ 46 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[47] ); pthread_create( &Threads[ 47 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[48] ); pthread_create( &Threads[ 48 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[49] ); pthread_create( &Threads[ 49 ], &attr, spawn_function, NULL); // 50

	clock_gettime(CLOCK_MONOTONIC, &t_end[50] ); pthread_create( &Threads[ 50 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[51] ); pthread_create( &Threads[ 51 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[52] ); pthread_create( &Threads[ 52 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[53] ); pthread_create( &Threads[ 53 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[54] ); pthread_create( &Threads[ 54 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[55] ); pthread_create( &Threads[ 55 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[56] ); pthread_create( &Threads[ 56 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[57] ); pthread_create( &Threads[ 57 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[58] ); pthread_create( &Threads[ 58 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[59] ); pthread_create( &Threads[ 59 ], &attr, spawn_function, NULL); // 60

	clock_gettime(CLOCK_MONOTONIC, &t_end[60] ); pthread_create( &Threads[ 60 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[61] ); pthread_create( &Threads[ 61 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[62] ); pthread_create( &Threads[ 62 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[63] ); pthread_create( &Threads[ 63 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[64] ); pthread_create( &Threads[ 64 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[65] ); pthread_create( &Threads[ 65 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[66] ); pthread_create( &Threads[ 66 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[67] ); pthread_create( &Threads[ 67 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[68] ); pthread_create( &Threads[ 68 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[69] ); pthread_create( &Threads[ 69 ], &attr, spawn_function, NULL); // 70

	clock_gettime(CLOCK_MONOTONIC, &t_end[70] ); pthread_create( &Threads[ 70 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[71] ); pthread_create( &Threads[ 71 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[72] ); pthread_create( &Threads[ 72 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[73] ); pthread_create( &Threads[ 73 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[74] ); pthread_create( &Threads[ 74 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[75] ); pthread_create( &Threads[ 75 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[76] ); pthread_create( &Threads[ 76 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[77] ); pthread_create( &Threads[ 77 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[78] ); pthread_create( &Threads[ 78 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[79] ); pthread_create( &Threads[ 79 ], &attr, spawn_function, NULL); // 80

	clock_gettime(CLOCK_MONOTONIC, &t_end[80] ); pthread_create( &Threads[ 80 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[81] ); pthread_create( &Threads[ 81 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[82] ); pthread_create( &Threads[ 82 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[83] ); pthread_create( &Threads[ 83 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[84] ); pthread_create( &Threads[ 84 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[85] ); pthread_create( &Threads[ 85 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[86] ); pthread_create( &Threads[ 86 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[87] ); pthread_create( &Threads[ 87 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[88] ); pthread_create( &Threads[ 88 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[89] ); pthread_create( &Threads[ 89 ], &attr, spawn_function, NULL); // 90

	clock_gettime(CLOCK_MONOTONIC, &t_end[90] ); pthread_create( &Threads[ 90 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[91] ); pthread_create( &Threads[ 91 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[92] ); pthread_create( &Threads[ 92 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[93] ); pthread_create( &Threads[ 93 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[94] ); pthread_create( &Threads[ 94 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[95] ); pthread_create( &Threads[ 95 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[96] ); pthread_create( &Threads[ 96 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[97] ); pthread_create( &Threads[ 97 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[98] ); pthread_create( &Threads[ 98 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[99] ); pthread_create( &Threads[ 99 ], &attr, spawn_function, NULL); // 100

	// each thread waits until all threads have hit the barrier, then they all return
	pthread_barrier_wait(&sync_barrier);

	// pthread_destroy_barrier
	pthread_barrier_destroy(&sync_barrier);

	// destroy attr
	pthread_attr_destroy(&attr);


	printf("****\n");
	for(int i = 0; i < PTH; i++){

		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	}

	// printf(02C"\n");
		
	return 0;
}
