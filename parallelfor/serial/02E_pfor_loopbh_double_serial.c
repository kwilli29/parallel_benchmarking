#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* 
 * Benchmark: 02E: DoubleFor Function in CilkFor  ; CilkFor (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */


#define COUNT 4 // 273 // 4
static const int ITERATION = 1000000;
long arr[COUNT];

long do_work(long k){
	long x = 15;
	static const int nn = 87;
	for (long i = 1; i < nn; ++i)
		x = x / i + k % i;
	return x;
}

int main(int argc, char *argv[]){

 	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	for(int j=0; j<ITERATION; j++){
		for (int i = 0; i < COUNT; i++)
			arr[i] += do_work( j * i + i + j); // race condition?
	}

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("02E\n");

	return 0;
}
