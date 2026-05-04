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
#include <limits.h>

/* 01C Reduce Max benchmark : (OpenMP)
* Benchmark
*/

long f( int index){
	return index;
}

void compute_max(long *maxim)
{
   
	#pragma omp parallel for reduction(max:maxim[0])
	for (int i = 9999999; i >= 0; i--)
	{
   	*maxim = *maxim >= f(i) ? *maxim : f(i);
	}

}

long provide_reducer()
{
	long maxim = LONG_MIN; // must be initialized

	compute_max(&maxim);

	return maxim;

}

int main(int argc, char*argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

	long reducermax = provide_reducer();
	printf("*max: %ld\n", reducermax);    

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}

// +, *, GCD/LCM, inter./union,functino composition, mat mul, min/max (R, ordered set)