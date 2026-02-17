#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Test (Cilk)
 * Overhead of the parallel for directive
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

#define NCILK __cilkrts_get_nworkers()

void delay(float delaylength){           // Simple Spawn Function

	int x = 0;

	while(x < delaylength){
		x++;
	} 

	return; 
}


int main(int argc, char *argv[]){

	int innerreps = 100;
	float delaylength = 10000.0;

	int itersperthr = 1024;

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

		for(int i=1; i <= itersperthr*NCILK; i++){
			delay(delaylength);
		}

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	//double div = ((long)t_res.tv_sec + ((double)t_res.tv_nsec/1000000000)) / (innerreps+0.0);

	//printf("divTime: %.9f\n", (float)div);	

	return 0;
}

// 1-indexed for i=1; i <= stop; step
/*
!$OMP PARALLEL
	do j=1,innerreps
!$OMP DO SCHEDULE(schedtype,chunksize)
		do i=1,itersperthr*omp_get_num_threads()
			call delay(delaylength)
		end do
	end do
!$OMP END PARALLEL
*/
