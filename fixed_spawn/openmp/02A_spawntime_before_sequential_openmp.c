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
/* Benchmark: 02A: Spawn time before ; Sequential Spawns (OpenMP)
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

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	// use sections to guarantee order of timestamp then spawn
	// sections go in order

 #pragma omp parallel
 #pragma omp sections
 {

	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[0]); 
	spawn_function(); // Take time stamp before each spawn
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[1]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[2]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[3]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[4]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[5]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[6]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[7]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[8]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[9]); 
	spawn_function(); // 10

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[10]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[11]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[12]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[13]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[14]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[15]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[16]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[17]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[18]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[19]); 
	spawn_function(); // 20

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[20]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[21]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[22]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[23]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[24]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[25]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[26]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[27]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[28]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[29]); 
	spawn_function(); // 30

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[30]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[31]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[32]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[33]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[34]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[35]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[36]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[37]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[38]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[39]); 
	spawn_function(); // 40

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[40]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[41]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[42]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[43]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[44]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[45]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[46]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[47]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[48]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[49]); 
	spawn_function(); // 50

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[50]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[51]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[52]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[53]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[54]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[55]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[56]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[57]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[58]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[59]); 
	spawn_function(); // 60

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[60]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[61]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[62]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[63]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[64]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[65]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[66]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[67]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[68]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[69]); 
	spawn_function(); // 70

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[70]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[71]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[72]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[73]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[74]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[75]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[76]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[77]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[78]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[79]); 
	spawn_function(); // 80

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[80]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[81]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[82]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[83]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[84]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[85]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[86]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[87]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[88]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[89]); 
	spawn_function(); // 90

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[90]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[91]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[92]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[93]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[94]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[95]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[96]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[97]); 
	spawn_function();

	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[98]); 
	spawn_function();
	} 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_end[99]); 
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