#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* 
 * Benchmark: 04F: Spawn time beforefunc ; One Spawns w/ Fcn args (Cilk)
 * Launch a bunch and measure when all done 
 */

static const int ITERATION = 100000;
// struct timespec spawn_function_long(double x){
struct timeval spawn_function_long(double x){

	// struct timespec t_end; 
	// clock_gettime(CLOCK_MONOTONIC, &t_end);

    struct timeval t_end;
    gettimeofday(&t_end,NULL);

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

    // printf("**%d\t", __cilkrts_get_worker_number()); // print thread id

	return t_end; // 
}

// struct timespec spawn_function(int x){           // Simple Function to Spawn
struct timeval spawn_function(int x){

	// struct timespec t_end; 
	// clock_gettime(CLOCK_MONOTONIC, &t_end);

    struct timeval t_end;
    gettimeofday(&t_end,NULL);

	int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; //  end_time; 
}

int main(int argc, char *argv[]){
    int NCILK = __cilkrts_get_nworkers();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            NCILK = __cilkrts_get_nworkers();
        } else {
            NCILK = atoi(argv[1]);
            if(NCILK < 1){
                NCILK = __cilkrts_get_nworkers();
            }
        }
    }
	printf("* # Spawns: %d\n", NCILK);
    int iter = 50;
    
	double x = 15.0;

	// struct timespec t_start, t_res;
	// struct timespec t_end;
	// clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

    struct timeval t_start, t_end;
    double result=0.0;
    gettimeofday(&t_start, NULL);
	
	t_end = cilk_spawn spawn_function_long(x); // spawn with one int argument
	
	cilk_sync;

	// timespec_sub(&t_res, t_end, t_start);
	// printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    result = (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000);
    printf("%09f\n", result);

	// printf("04F\n");

	return 0;
}
