#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Test CilkPlus stuff (Cilk)
 * https://github.com/OpenCilk/cheetah/blob/dev/include/cilk/cilk_api.h 
 */

#define NCILK __cilkrts_get_nworkers()
#define NID __cilkrts_get_worker_number()
#define COUNT 4

//static const int COUNT = 4;
static const int ITERATION = 1000000;
long arr[COUNT];

long do_work(long k){

	long x = 15;
	static const int nn = 87;

	for (long i = 1; i < nn; ++i){
		x = x / i + k % i;
	}

	return x;
}

void fcn(){

	cilk_for (int i = 0; i < COUNT; i++){
		printf("gp: %d\n", NID);
		for (int j = 0; j < ITERATION; j++){
			arr[i] += do_work( j * i + i + j);
		}

		printf("%ld\t", arr[i]);
	}

	printf("\n");

	return;
}

int main(int argc, char *argv[]){


	int y[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int n = 16;

	for(int k=0; k<n;k++){
		printf("%d\t", y[k]);
	}

	printf("\n");
	
	#pragma  simd vectorlength(2)
	for(int i = 4; i < n; i++){

		y[i] = y[i-2] + 1;

	}

	for(int k=0; k<n; k++)
		printf("%d\t", y[k]);

	printf("\n");

	fcn();	

	return 0;
}
