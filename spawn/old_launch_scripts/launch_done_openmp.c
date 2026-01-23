#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>

/* Benchmark: Launch Done (OpenMP)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 *
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));


void spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){

	int DEPTH = 273;

	struct timeval start_time,endtime;
	gettimeofday(&start_time, NULL);

	#pragma omp parallel for schedule (static, 1) // grainsize
	for(int i = 0; i < DEPTH; i++){
		spawn_function(); 
		// gettimeofday(&end_time, NULL); // how to time the end of the *last thread * to complete
	} 

	gettimeofday(&endtime, NULL);

	double realTime = 0.0;

	//for(int i=0; i < DEPTH; i++){
	realTime = (endtime.tv_sec+ (double)endtime.tv_usec/1000000) - (start_time.tv_sec+(double)start_time.tv_usec/1000000);

	printf("\nOverall Time ldo = %lf\n\n", realTime);

	//}	
	return 0;
}


