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
#include <sys/time.h>
#include "../../include/numthreads.h"
/* Benchmark: 04C: Spawn time before function ; For-Loop Spawns (Pthreads)
 * Launch a bunch and measure when all done 
 */
static const int ITERATION = 100000;
void* spawn_function_long(void* t_end){

    //clock_gettime(CLOCK_MONOTONIC, (struct timespec *)t_end);
    gettimeofday((struct timeval *)t_end, NULL);

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

	return (void*)t_end;
}
void* spawn_function(void* t_end){           // Simple Math for Spawn Function

    //clock_gettime(CLOCK_MONOTONIC, (struct timespec *)t_end);
    gettimeofday((struct timeval *)t_end, NULL);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*)t_end; 
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
	pthread_t Threads[ iters ];

	// struct timespec t_start[iters]; struct timespec t_res;
	// struct timespec t_end[iters];

    struct timeval t_start[iters]; double result=0.0;
	struct timeval t_end[iters];

	/****/ 

	for( int i = 0; i < iters; i++ ) {                                     // # seq. for only
		// clock_gettime(CLOCK_MONOTONIC, &t_start[i]);
        gettimeofday(&t_start[i], NULL);
		pthread_create( &Threads[ i ], NULL, spawn_function_long, (void*)&t_end[i]);
	}

	// struct timespec* temp = (struct timespec *)&t_end[0];
    struct timeval* temp = (struct timeval *)&t_end[0];
	
	for( int i = 0; i < iters; i++ ) {                                     // join
		pthread_join( Threads[ i ], (void*)&temp);
		// if(i < 5){ printf("\n%p\n", &t_end); printf("%ld\n", t_end[i].tv_nsec); }
		if (i < PTH-1){ temp = &t_end[i+1]; }
	}

	for(int i = 0; i < iters; i++){

		// timespec_sub(&t_res, t_end[i], t_start[i]);
		// printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

        result = (t_end[i].tv_sec+ (double)t_end[i].tv_usec/1000000) - (t_start[i].tv_sec+(double)t_start[i].tv_usec/1000000);
        printf("%09f\n", result);	

	}

	return 0;
}