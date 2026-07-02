#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "../../include/numthreads.h"
#include <time.h>
enum {
    _MSEC_PER_SEC = 1000,
    _USEC_PER_SEC = 1000 * 1000,
    _NSEC_PER_SEC = 1000 * 1000 * 1000
};
void timespec_sub( struct timespec * t_diff, struct timespec const  t_end,  struct timespec const  t_start ) {
    /**<[out] time difference */ /**<[in]  end time */ /**<[in]  start time */
    t_diff->tv_nsec = t_end.tv_nsec - t_start.tv_nsec; t_diff->tv_sec  = t_end.tv_sec  - t_start.tv_sec;
    if ((t_diff->tv_sec > 0) && (t_diff->tv_nsec < 0)) {
        t_diff->tv_nsec += _NSEC_PER_SEC; t_diff->tv_sec--;
    } else if ((t_diff->tv_sec < 0) && (t_diff->tv_nsec > 0)) {
        t_diff->tv_nsec -= _NSEC_PER_SEC; t_diff->tv_sec++;
    }
    /* (s > 0 & ns > 0) : do nothing (t_start < t_end) */ /* (s < 0 & ns < 0) : do nothing (t_start > t_end) */
}
/* Benchmark: 04E: Spawn time beforefunc ; Sequential Spawns (Serial)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */
static const int ITERATION = 100000;
struct timespec spawn_function_long(){
// struct timeval spawn_function_long(){

    struct timespec t_end; 						  
	clock_gettime(CLOCK_MONOTONIC, &t_end);

    // struct timeval t_end;
    // gettimeofday(&t_end, NULL);

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
struct timespec spawn_function(){           // Simple Spawn Function
// struct timeval spawn_function(){ 

	struct timespec t_end; 						  
	clock_gettime(CLOCK_MONOTONIC, &t_end);

    // struct timeval t_end;
    // gettimeofday(&t_end, NULL);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; 
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
    
	struct timespec t_start, t_res;
	struct timespec t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); 

    // struct timeval t_start, t_end;
    // double result=0.0;
    // gettimeofday(&t_start, NULL);
    
    t_end = spawn_function_long(); // Take time stamp before each spawn

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
    
    // result = (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000);
    // printf("%09f\n", result);

	// printf("04E\n");
	
	return 0;
}