#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>
#include <sys/time.h>
#include "../../include/numthreads.h"

/* Benchmark: 04C: Spawn time before thread function begins ; For-Loop Spawns (Serial) 
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */
static const int ITERATION = 100000;
//struct timespec spawn_function_long(){
struct timeval spawn_function_long(){

	// struct timespec t_end; 						  
	// clock_gettime(CLOCK_MONOTONIC, &t_end);

    struct timeval t_end;
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

	return t_end;
}
//struct timespec spawn_function(){           // Simple Function to Spawn
struct timeval spawn_function(){

	// struct timespec t_end; 						  
	// clock_gettime(CLOCK_MONOTONIC, &t_end);

    struct timeval t_end;
    gettimeofday(&t_end, NULL);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; //  end_time; 
}

int main(int argc, char *argv[]){

	int NSERIAL = number_threads();
    
    // Process Command-Line Arguments
    if(argc > 1){
        if(atoi(argv[1]) == 0){
            NSERIAL = number_threads();
        } else {
            NSERIAL = atoi(argv[1]);
        }
    }printf("*# NSERIAL: %d\n", NSERIAL);
    int iters = 50;

	// struct timespec t_start[iters]; struct timespec t_res; 
	// struct timespec t_end[iters];

    struct timeval t_start[iters]; struct timeval t_end[iters];
    double result=0.0;

	for(int i=0; i < iters; i++){ 	
		// clock_gettime(CLOCK_MONOTONIC, &t_start[i]); 
        gettimeofday(&t_start[i], NULL);
        t_end[i] = spawn_function_long();
	} 

	printf("****\n");	
	for(int i = 0; i < iters; i++){
		
		// timespec_sub(&t_res, t_end[i], t_start[i]);
		// printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
    
        result = (t_end[i].tv_sec+ (double)t_end[i].tv_usec/1000000) - (t_start[i].tv_sec+(double)t_start[i].tv_usec/1000000);
        printf("%09f\n", result);
	
	}

	// printf("04C\n");
	
	return 0;
}