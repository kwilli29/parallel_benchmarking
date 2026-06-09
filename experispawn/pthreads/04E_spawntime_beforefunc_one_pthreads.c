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

/* Benchmark: 04E: Spawn time before function ; One Spawn (Pthreads)
 * Launch a bunch and measure when all done 
 */

struct timespec t_end;

static const int ITERATION = 100000;
void* spawn_function_long(){

    clock_gettime(CLOCK_MONOTONIC, &t_end);

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

	return (void*)&t_end;
}
void* spawn_function(){           // Simple Math for Spawn Function

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*)&t_end; 
}

int main(int argc, char *argv[]){

	pthread_t Thread;

	struct timespec t_start, t_res;

	/****/ 

	clock_gettime(CLOCK_MONOTONIC, &t_start);
    
	pthread_create( &Thread, NULL, spawn_function_long, NULL);

	struct timespec* temp = &t_end;
	pthread_join(Thread, (void *)&temp);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}