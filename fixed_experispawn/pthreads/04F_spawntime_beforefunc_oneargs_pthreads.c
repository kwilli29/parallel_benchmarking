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

/* Benchmark: 04F: Spawn time before function ; One Spawn w/ fcn arg (Pthreads)
 * Launch a bunch and measure when all done
 */

static struct timespec t_end; 

static const int ITERATION = 100000;
void* spawn_function_long(void* x){

    clock_gettime(CLOCK_MONOTONIC, &t_end);

    double z = 0;
    double i = 0.0;

    //double x = 15.0;
	static const int nn = 87;

    double a =0.0;
	for (int j = 0; j < ITERATION; j++){
        z*=acos((double)j);

        for (long m = 1; m < nn; ++m){
            a = (double)((double)m*1.0);
            *(double *)x = sin(*(double *)x*1.0) / (double)(a*1.0 + (j * i + i + j)*1.0 / a);
        }

        z += *(double *)x + z; //
        z= tanh((double)z);

        i += 1.0;
	}

	return (void*)&t_end;
}
void* spawn_function(void* x){           // Simple Math for Spawn Function

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int y = 5000; int z = 1000000;

	*(int *)x = *(int *)x + y + z;

	y = y + *(int *)x + z;

	z = z + y + *(int *)x;	

	return (void*)&t_end; 
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
    
	double x = 15.0;
	double* xp= &x;

	pthread_t Thread;

	struct timespec t_start, t_res;

	/****/ 

	clock_gettime(CLOCK_MONOTONIC, &t_start);

	pthread_create( &Thread, NULL, spawn_function_long, xp);

	struct timespec* temp = &t_end;
	pthread_join(Thread, (void *)&temp);
	
	//printf("\n%p\n", &t_end);	
	//printf("%ld\n", t_end.tv_sec);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}