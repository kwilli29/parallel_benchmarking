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

/* Benchmark: 01F: Spawn timer after ; One Spawn w/ fcn args (Pthreads)
 * Launch a bunch and measure when all done
 */

static const int ITERATION = 100000;
void* spawn_function_long(void* xp){

    double z = 0;
    double i = 0.0;

    //double x = 15.0;
    double x = (double)*(double*)xp;
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
void* spawn_function(void * xp){           // Simple Math for Spawn Function
	
	int x = (int)(intptr_t)xp; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

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
                PTH = number_threads();
            }
        }
    }
	printf("* # Spawns: %d\n", PTH);
    int iters=50;
    
	double x = 15.0;
	double* xp = &x;

	int ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1; // detached
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

	pthread_t Thread;

	struct timespec t_start, t_res, t_end;

	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	pthread_create( &Thread, &attr, spawn_function_long, (void *)(double*) xp);

	// sync?

	clock_gettime(CLOCK_MONOTONIC, &t_end);


	// destroy attr
	pthread_attr_destroy(&attr);
	
	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
		
	return 0;
}