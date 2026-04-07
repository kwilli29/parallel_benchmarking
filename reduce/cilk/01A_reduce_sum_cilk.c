#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <sys/time.h>
#include "ctimer.h"

/* 01A Reduce Sum benchmark : (OpenCilk)
* Benchmark
*/

void zero(void *view) { *(long *)view = 0; }
void add(void *left, void *right) { *(long *)left += *(long *)right; } // Addition

// extern long f(int index);

long f( int index){
	return index;
}

void compute_sum(long cilk_reducer(zero, add) *sum)
{
    cilk_for (int i = 0; i < 10000000; ++i)
        *sum += f(i); // dereferenced pointer converts to current view
}

long provide_reducer()
{
	long cilk_reducer(zero, add) sum = 0L; // must be initialized

	compute_sum(__builtin_addressof(sum));

	return sum;

}

int main(int argc, char*argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	long reducersum = provide_reducer();    

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	return 0;
}

// +, *, GCD/LCM, inter./union,functino composition, mat mul, min/max (R, ordered set)

//extern long f(int index);
// The argument is a pointer to a reducer.
/*void compute_sum(long cilk_reducer(zero, add) *sum)
{
    cilk_for (int i = 0; i < 10000000; ++i)
        *sum += f(i); // dereferenced pointer converts to current view
}
long provide_reducer()
{
    long cilk_reducer(zero, add) sum = 0L; // must be initialized
    compute_sum(__builtin_addressof(sum));
    return sum;
}
*/
