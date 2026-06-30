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
/* Benchmark: 04E: Spawn time before function ; One Spawn (Pthreads)
 * Launch a bunch and measure when all done 
 */

// struct timespec t_end;
struct timeval t_end; 

static const int ITERATION = 100000;
void* spawn_function_long(){

	// clock_gettime(CLOCK_MONOTONIC, &t_end);
    gettimeofday(&t_end, NULL);

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

	// clock_gettime(CLOCK_MONOTONIC, &t_end);
    gettimeofday(&t_end, NULL);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

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
    
	pthread_t Thread;



	/****/ 

	// struct timespec t_start, t_res;
	// clock_gettime(CLOCK_MONOTONIC, &t_start);

    struct timeval t_start;
    double result=0.0;
    gettimeofday(&t_start, NULL);
    
	pthread_create( &Thread, NULL, spawn_function_long, NULL);

	// struct timespec* temp = &t_end;
    struct timeval* temp = &t_end;
	pthread_join(Thread, (void *)&temp);

	// timespec_sub(&t_res, t_end, t_start);
	// printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
     
    result = (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000);
    printf("%09f\n", result);

	return 0;
}