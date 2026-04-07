#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "ctimer.h"

/* 01A Reduce Sum benchmark : (Serial)
* Benchmark
*/

long f( int index){
	return index;
}

void compute_sum(long *sum)
{
    for (int i = 0; i < 10000000; ++i)
        *sum += f(i); // dereferenced pointer converts to current view
}

long provide_reducer()
{
	long sum = 0L; // must be initialized

	compute_sum(&sum);

	return sum;

}

int main(int argc, char*argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	long reducersum = provide_reducer();    
	printf("*sum: %ld\n",reducersum);

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}

// +, *, GCD/LCM, inter./union,functino composition, mat mul, min/max (R, ordered set)
