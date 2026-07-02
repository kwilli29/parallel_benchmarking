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
/* Benchmark: 02C: Spawn time before ; For-Loop Para. Sects. Spawns (OpenMP)
 * Launch a bunch and measure when all done 
 */
static const int ITERATION = 100000;
void spawn_function_long(){

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

	return;
}
void spawn_function(){           // Simple Function to Spawn

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
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
    printf("# Spawns: %d\n", OMP_THREADS);
    int iters=50;

double t_start; double t_end[iters];
t_start = omp_get_wtime(); 

	// struct timespec t_start, t_res;
	// struct timespec t_end[iters];
    // clock_gettime(CLOCK_MONOTONIC, &t_start); // 

    // struct timeval t_start; struct timeval t_end[iters]; 
    // double result=0.0;
    // gettimeofday(&t_start, NULL);

	#pragma omp parallel num_threads(OMP_THREADS) 
	{
		#pragma omp single
		{
			for(int i = 0; i < iters; i++){
				t_end[i] = omp_get_wtime();
				// clock_gettime(CLOCK_MONOTONIC, &t_end[i]); 
                // gettimeofday(&t_end[i], NULL);

				#pragma omp task
				spawn_function_long(); 
			} 
		}
	}

	printf("****\n");
	for(int i = 0; i < iters; i++){

        t_end[i] = omp_get_wtime(); 
        printf("%f\n", t_end[i] - t_start);

		// timespec_sub(&t_res, t_end[i], t_start);
		// printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

        // result = (t_end[i].tv_sec+ (double)t_end[i].tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000);
        // printf("%09f\n", result);
	
	}

	return 0;
}