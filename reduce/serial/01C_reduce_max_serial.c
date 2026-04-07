#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>
#include "ctimer.h"

/* 01C Reduce Max benchmark : (Serial)
* Benchmark
*/


long f( int index){
	return index;
}

void compute_max(long *max)
{
    for (int i = 9999999; i >= 0; i--)
        *max = *max >= f(i) ? *max : f(i); // dereferenced pointer converts to current view
}

long provide_reducer()
{
	long max = LONG_MIN; // must be initialized

	compute_max(&max);

	return max;

}

int main(int argc, char*argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	long reducermax = provide_reducer();
	printf("*max: %ld\n", reducermax);    

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}

// +, *, GCD/LCM, inter./union,functino composition, mat mul, min/max (R, ordered set)
