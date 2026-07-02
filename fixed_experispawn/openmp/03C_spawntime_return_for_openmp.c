#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <assert.h>
#include <math.h>
#include <sys/time.h>
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
/* Benchmark: 03C: Spawn time beforefunc ; For-Loop Spawns (OpenMP)
 * Launch a bunch and measure when all done 
 */
static const int ITERATION = 100000;
struct timespec spawn_function_long(){
// struct timeval spawn_function_long(){
// double spawn_function_long(){

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

    // printf("**%d\t", __cilkrts_get_worker_number()); // print thread id

    // double t_start = 0.0;
    // t_start = omp_get_wtime();

    struct timespec t_start;
	clock_gettime(CLOCK_MONOTONIC, &t_start);

    // struct timeval t_start;
    // gettimeofday(&t_start, NULL);

	return t_start;
}
struct timespec spawn_function(){           // Simple Function to Spawn
// struct timeval spawn_function(){ 
// double spawn_function(){ 

    int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

    // double t_start = 0.0;
    // t_start = omp_get_wtime();

    struct timespec t_start;
	clock_gettime(CLOCK_MONOTONIC, &t_start);

    // struct timeval t_start;
    // gettimeofday(&t_start, NULL);

	return t_start; 
}

int main(int argc, char *argv[]){

	int OMP_THREADS = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            OMP_THREADS = number_threads();
        } else {
            OMP_THREADS = atoi(argv[1]);
             if (OMP_THREADS < 1){
                OMP_THREADS = number_threads();;
            }
        }
    }    
    printf("* # Spawns: %d\n", OMP_THREADS);
    int iters=50;

    // double t_start[iters]; double t_end[iters]; 

	struct timespec t_start[iters]; struct timespec t_res;
	struct timespec t_end[iters];

    // struct timeval t_start[iters]; struct timeval t_end[iters]; 
    // double result=0.0;

	#pragma omp parallel num_threads(OMP_THREADS) 
	{
		#pragma omp single
		{
			for(int i = 0; i < iters; i++){
				
				#pragma omp task	
				t_start[i] = spawn_function_long(); 
                
                // t_end[i] = omp_get_wtime();
                clock_gettime(CLOCK_MONOTONIC, &t_end[i]);
                // gettimeofday(&t_end[i], NULL);
			} 
		}
	}
	// printf("****\n");
	for(int i = 0; i < iters; i++){

        // printf("%f\n", t_end[i] - t_start[i]);

		timespec_sub(&t_res, t_end[i], t_start[i]);
		if(t_res.tv_nsec < 0 && t_res.tv_sec >= 0){ t_res.tv_nsec *= -1; printf("-");}
		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

        // result = (t_end[i].tv_sec+ (double)t_end[i].tv_usec/1000000) - (t_start[i].tv_sec+(double)t_start[i].tv_usec/1000000);
        // printf("%09f\n", result);        
	
	}

	return 0;
}
