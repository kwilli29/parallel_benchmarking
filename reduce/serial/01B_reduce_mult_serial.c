#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "ctimer.h"

/* 01B Reduce Multiply benchmark : (Serial)
* Benchmark
*/


long f( int index){
	return index;
}

void compute_mult(long *multaccum)
{
    for (int i = 1; i < 20; ++i)
        *multaccum *= f(i); // dereferenced pointer converts to current view
}

long provide_reducer()
{
	long multaccum = 1L; // must be initialized

	compute_mult(&multaccum);

	return multaccum;

}

int main(int argc, char*argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	long reducermult = provide_reducer();
	printf("*mult: %ld\n",reducermult);    

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}

// +, *, GCD/LCM, inter./union,functino composition, mat mul, min/max (R, ordered set)
