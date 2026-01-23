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

/* Benchmark: 05A: Spawn count in time window ; While-Loop (OpenMP)
 * **this test is not really representative of how openmp is used
 * Launch a bunch in a time window and measure when all done  
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

	float TIMER = 2.0;
	int counter = 0;

	struct timeval t_start, t_end;
	
	gettimeofday(&t_start, NULL); // struct timespec *tp
	gettimeofday(&t_end, NULL);	
	
	while( ( (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000)  ) < TIMER ){

		#pragma omp task
		spawn_function();

		gettimeofday(&t_end, NULL);
		counter+=1;
	}


	printf("%d\n", counter);


	return 0;
}


