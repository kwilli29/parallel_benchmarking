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

/* Test (OpenMP)
 * Overhead of the parallel for directive
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

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

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	#pragma omp parallel
	{

	  for(int j=1; j <= innerreps; j++){

		#pragma omp parallel for schedule (static, 1) // schedule, grainsize
		for(int i=1; i <= omp_get_num_threads(); i++){
			delay(delaylength);
		}

	  }

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
!$OMP DO
		do i=1,omp_get_num_threads()
			call delay(delaylength)
		enddo
!$OMP END DO
	end do
!$OMP END PARALLEL 
*/
