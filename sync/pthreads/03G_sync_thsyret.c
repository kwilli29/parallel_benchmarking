#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: 03G: Time b/w thread complete and return ; ThSy Time (Pthreads) 
 */

void * spawn_function(void* t_start){           // Simple Function to Spawn

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	clock_gettime(CLOCK_MONOTONIC, (struct timespec*)t_start);

	return (void*)t_start; //  to get REALLY granular, could measure time to return timeval from fcn and sub from end
}

int main(int argc, char *argv[]){

	pthread_t Threads0;

	struct timespec t_res,t_start, t_end;
	struct timespec* temp = (struct timespec*)&t_start;

	pthread_create( &Threads0, NULL, spawn_function, (void *)&t_start);

	//sync;
	pthread_join(Threads0, (void*)&temp);
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);
	/**/

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	// printf("03G\n");
	
	return 0;
}
