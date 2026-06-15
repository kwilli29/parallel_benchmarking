#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>
#include "../../include/numthreads.h"
/* Benchmark: 03C: Spawn time beforefunc ; For-Loop Spawns (OpenMP)
 * Launch a bunch and measure when all done 
 */
static const int ITERATION = 100000;
struct timespec spawn_function_long(){

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

    struct timespec t_start;
	clock_gettime(CLOCK_MONOTONIC, &t_start);

	return t_start;
}
struct timespec spawn_function(){           // Simple Function to Spawn

    int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	struct timespec t_start;
	clock_gettime(CLOCK_MONOTONIC, &t_start);

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
	struct timespec t_start[iters]; struct timespec t_res;
	struct timespec t_end[iters];

	#pragma omp parallel num_threads(OMP_THREADS) 
	{
		#pragma omp single
		{
			for(int i = 0; i < iters; i++){
				
				#pragma omp task	
				t_start[i] = spawn_function_long(); 
                clock_gettime(CLOCK_MONOTONIC, &t_end[i]);
			} 
		}
	}
	// printf("****\n");
	for(int i = 0; i < iters; i++){

		timespec_sub(&t_res, t_end[i], t_start[i]);
		if(t_res.tv_nsec < 0 && t_res.tv_sec >= 0){ t_res.tv_nsec *= -1; printf("-");}
		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	return 0;
}
