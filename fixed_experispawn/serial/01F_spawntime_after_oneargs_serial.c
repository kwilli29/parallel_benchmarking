#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"
#include "../../include/numthreads.h"
/* Benchmark: 01F: Spawn time after ; One Spawn (Serial)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */
static const int ITERATION = 100000;
void spawn_function_long(double x){

    double z = 0;
    double i = 0.0;

    //double x = 15.0;
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

	return;
}
void spawn_function(int x){           // Simple Spawn Function
	//int x = 100; 
	int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){
	int NSERIAL = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            NSERIAL = number_threads();
        } else {
            NSERIAL = atoi(argv[1]);
        }
    }

    int iters = 50;
    
	double x = 15.0;

	// struct timespec t_start, t_res, t_end;
	// clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

    struct timeval t_start, t_end;
    double result=0.0;
    gettimeofday(&t_start, NULL);
	
	spawn_function_long(x); 
 	
	// clock_gettime(CLOCK_MONOTONIC, &t_end);
	// timespec_sub(&t_res, t_end, t_start);
	// printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    gettimeofday(&t_end, NULL); 
    result = (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000);
    printf("%09f\n", result);

	// printf("01F\n");

	return 0;
}