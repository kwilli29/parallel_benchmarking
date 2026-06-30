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
/* Benchmark: 03E: Spawn time return; One Spawns (Pthreads)
 * Launch a bunch and measure when all done 
 */
static const int ITERATION = 100000;
void* spawn_function_long(void* t_start){

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

    //clock_gettime(CLOCK_MONOTONIC, (struct timespec *)t_start);
    gettimeofday((struct timeval *)t_start, NULL);

	return (void*)t_start;
}
void* spawn_function(void* t_start){           // Simple Math for Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;

    //clock_gettime(CLOCK_MONOTONIC, (struct timespec *)t_start);
    gettimeofday((struct timeval *)t_start, NULL);

	return (void*)t_start; 
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

	// struct timespec t_start, t_end, t_res;
    struct timeval t_start, t_end;
    double result=0.0;

	/****/ 

	pthread_create( &Thread, NULL, spawn_function_long, (void*)&t_start);

	// struct timespec* temp = (struct timespec *)&t_start;
    struct timeval* temp = (struct timeval *)&t_start;
	                                   
	pthread_join( Thread, (void*)&temp); // join

    // clock_gettime(CLOCK_MONOTONIC, &t_end);
    // timespec_sub(&t_res, t_end, t_start);
    // if(t_res.tv_nsec < 0 && t_res.tv_sec >= 0){ t_res.tv_nsec *= -1; printf("-");}
    // printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

    gettimeofday(&t_end, NULL);     
    result = (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000);
    printf("%09f\n", result);

	return 0;
}