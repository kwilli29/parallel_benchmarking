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

/* 01B Reduce Multiply benchmark : (OpenMP)
* Benchmark
*/

long f( int index){
	return index;
}

void compute_multiply(long *mult)
{
   
	#pragma omp parallel for reduction(*:mult[0])
	for (int i = 1; i < 20; ++i)
	{
   	*mult *= f(i);
	}

}

long provide_reducer()
{
	long mult = 1L; // must be initialized

	compute_multiply(&mult);

	return mult;

}

int main(int argc, char*argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	long reducermult = provide_reducer();
	printf("*mult: %ld\n", reducermult);    

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}

// +, *, GCD/LCM, inter./union,functino composition, mat mul, min/max (R, ordered set)