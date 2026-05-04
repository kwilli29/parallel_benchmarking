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

/* 01A Reduce Sum benchmark : (OpenMP)
* Benchmark
*/

long f( int index){
	return index;
}

void compute_sum(long *sum)
{   

	#pragma omp parallel for reduction(+:sum[0])
	for (int i = 0; i < 10000000; ++i)
	{
   	*sum += f(i);
	}
}

long provide_reducer()
{
	long sum = 0L; // must be initialized

	compute_sum(&sum);

	return sum;

}

int main(int argc, char*argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

	long reducersum = provide_reducer();
	printf("*sum: %ld\n", reducersum);    

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}

// +, *, GCD/LCM, inter./union,functino composition, mat mul, min/max (R, ordered set)