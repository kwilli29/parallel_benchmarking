#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <sys/time.h>
#include <limits.h>
#include "ctimer.h"

/* 01C Reduce Max benchmark : (OpenCilk)
* Benchmark
*/

void zero(void *view) { *(long *)view = LONG_MIN; }
void maximum(void *left, void *right) {  // L >= R, L=L ;; L < R, L=R

	*(long *)left = *(long *)left >= *(long *)right ? *(long *)left : *(long *) right;

} // Maximum

// extern long f(int index);

long f( int index){
	return index;
}

void compute_max(long cilk_reducer(zero, maximum) *max)
{
    cilk_for (int i = 9999999; i >= 0; i--)
        *max = *max >= f(i) ? *max : f(i); // dereferenced pointer converts to current view
}

long provide_reducer()
{
	long cilk_reducer(zero, maximum) max = LONG_MIN; // must be initialized

	compute_max(__builtin_addressof(max));

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
