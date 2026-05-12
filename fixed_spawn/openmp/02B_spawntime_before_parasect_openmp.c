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
#include "../../include/numthreads.h"
/* Benchmark: 02B: Spawn time before ; Parallel Section Spawns (OpenMP)
 * Launch a bunch and measure when all done
 */

void spawn_function(){           // Simple Function to Spawn

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

	int OMP_THREADS = 100;

	struct timespec t_start, t_res;
	struct timespec t_end[OMP_THREADS];

	clock_gettime(CLOCK_MONOTONIC, &t_start); // 

	// get # of worker threads
	
	// use takgroups to in parallel perform the tasks of time+spawn, and make sure time happens before spawn in each task
	
 #pragma omp parallel num_threads(OMP_THREADS)
 {
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[0]); 
	#pragma omp task
		spawn_function(); // Take time stamp before each spawn
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[1]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[2]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[3]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[4]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[5]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[6]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[7]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[8]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[9]); 
	#pragma omp task
		spawn_function(); // 10

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[10]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[11]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[12]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[13]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[14]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[15]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[16]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[17]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[18]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[19]); 
	#pragma omp task
		spawn_function(); // 20

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[20]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[21]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[22]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[23]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[24]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[25]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[26]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[27]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[28]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[29]); 
	#pragma omp task
		spawn_function(); // 30

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[30]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[31]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[32]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[33]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[34]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[35]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[36]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[37]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[38]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[39]); 
	#pragma omp task
		spawn_function(); // 40

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[40]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[41]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[42]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[43]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[44]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[45]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[46]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[47]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[48]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[49]); 
	#pragma omp task
		spawn_function(); // 50

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[50]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[51]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[52]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[53]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[54]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[55]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[56]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[57]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[58]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[59]); 
	#pragma omp task
		spawn_function(); // 60

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[60]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[61]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[62]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[63]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[64]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[65]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[66]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[67]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[68]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[69]); 
	#pragma omp task
		spawn_function(); // 70

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[70]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[71]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[72]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[73]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[74]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[75]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[76]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[77]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[78]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[79]); 
	#pragma omp task
		spawn_function(); // 80

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[80]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[81]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[82]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[83]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[84]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[85]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[86]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[87]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[88]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[89]); 
	#pragma omp task
		spawn_function(); // 90

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[90]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[91]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[92]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[93]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[94]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[95]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[96]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[97]); 
	#pragma omp task
		spawn_function();

	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[98]); 
	#pragma omp task
		spawn_function();
	} 
	#pragma omp taskgroup
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[99]); 
	#pragma omp task
		spawn_function(); // 100

	} 

 }
	printf("****\n");
	for(int i = 0; i < OMP_THREADS; i++){

		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	return 0;
}