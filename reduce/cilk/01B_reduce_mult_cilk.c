#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <sys/time.h>
#include "ctimer.h"

/* 01B Reduce Multiply benchmark : (OpenCilk)
* Benchmark
*/

void zero(void *view) { *(long *)view = 1; }
void mult(void *left, void *right) { *(long *)left *= *(long *)right; } // Multiplication

// extern long f(int index);

long f( int index){
	return index;
}

void compute_mult(long cilk_reducer(zero, mult) *multaccum)
{
    cilk_for (int i = 1; i < 20; ++i)
        *multaccum *= f(i); // dereferenced pointer converts to current view
}

long provide_reducer()
{
	long cilk_reducer(zero, mult) multaccum = 1L; // must be initialized

	compute_mult(__builtin_addressof(multaccum));

	return multaccum;

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
