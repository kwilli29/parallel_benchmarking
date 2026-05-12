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
/* Benchmark: 04A: Spawn time beforefunc ; Sequential Spawns (OpenMP)
 * Launch a bunch and measure when all done 
 */

struct timespec spawn_function(){           // Simple Function to Spawn

	struct timespec t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; 
}

int main(int argc, char *argv[]){

	int OMP_THREADS = 100;

	struct timespec t_start[OMP_THREADS]; struct timespec t_res;
	struct timespec t_end[OMP_THREADS];

	// time before spawn to beginning of function
	// thread /spawn/ sequentially

	#pragma omp parallel
	#pragma omp single
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[0]);
	#pragma omp task
	t_end[0] = spawn_function(); // Take time stamp before each spawn
	
	clock_gettime(CLOCK_MONOTONIC, &t_start[1]);
	#pragma omp task
	t_end[1] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[2]);
	#pragma omp task
	t_end[2] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[3]);
	#pragma omp task
	t_end[3] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[4]);
	#pragma omp task
	t_end[4] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[5]);
	#pragma omp task
	t_end[5] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[6]);
	#pragma omp task
	t_end[6] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[7]);
	#pragma omp task
	t_end[7] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[8]);
	#pragma omp task
	t_end[8] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[9]);
	#pragma omp task
	t_end[9] = spawn_function(); // 10


	clock_gettime(CLOCK_MONOTONIC, &t_start[10]);
	#pragma omp task
	t_end[10] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[11]);
	#pragma omp task
	t_end[11] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[12]);
	#pragma omp task
	t_end[12] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[13]);
	#pragma omp task
	t_end[13] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[14]);
	#pragma omp task
	t_end[14] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[15]);
	#pragma omp task
	t_end[15] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[16]);
	#pragma omp task
	t_end[16] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[17]);
	#pragma omp task
	t_end[17] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[18]);
	#pragma omp task
	t_end[18] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[19]);
	#pragma omp task
	t_end[19] = spawn_function(); // 20


	clock_gettime(CLOCK_MONOTONIC, &t_start[20]);
	#pragma omp task
	t_end[20] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[21]);
	#pragma omp task
	t_end[21] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[22]);
	#pragma omp task
	t_end[22] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[23]);
	#pragma omp task
	t_end[23] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[24]);
	#pragma omp task
	t_end[24] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[25]);
	#pragma omp task
	t_end[25] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[26]);
	#pragma omp task
	t_end[26] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[27]);
	#pragma omp task
	t_end[27] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[28]);
	#pragma omp task
	t_end[28] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[29]);
	#pragma omp task
	t_end[29] = spawn_function(); // 30


	clock_gettime(CLOCK_MONOTONIC, &t_start[30]);
	#pragma omp task
	t_end[30] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[31]);
	#pragma omp task
	t_end[31] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[32]);
	#pragma omp task
	t_end[32] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[33]);
	#pragma omp task
	t_end[33] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[34]);
	#pragma omp task
	t_end[34] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[35]);
	#pragma omp task
	t_end[35] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[36]);
	#pragma omp task
	t_end[36] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[37]);
	#pragma omp task
	t_end[37] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[38]);
	#pragma omp task
	t_end[38] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[39]);
	#pragma omp task
	t_end[39] = spawn_function(); // 40


	clock_gettime(CLOCK_MONOTONIC, &t_start[40]);
	#pragma omp task
	t_end[40] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[41]);
	#pragma omp task
	t_end[41] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[42]);
	#pragma omp task
	t_end[42] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[43]);
	#pragma omp task
	t_end[43] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[44]);
	#pragma omp task
	t_end[44] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[45]);
	#pragma omp task
	t_end[45] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[46]);
	#pragma omp task
	t_end[46] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[47]);
	#pragma omp task
	t_end[47] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[48]);
	#pragma omp task
	t_end[48] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[49]);
	#pragma omp task
	t_end[49] = spawn_function(); // 50


	clock_gettime(CLOCK_MONOTONIC, &t_start[50]);
	#pragma omp task
	t_end[50] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[51]);
	#pragma omp task
	t_end[51] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[52]);
	#pragma omp task
	t_end[52] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[53]);
	#pragma omp task
	t_end[53] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[54]);
	#pragma omp task
	t_end[54] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[55]);
	#pragma omp task
	t_end[55] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[56]);
	#pragma omp task
	t_end[56] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[57]);
	#pragma omp task
	t_end[57] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[58]);
	#pragma omp task
	t_end[58] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[59]);
	#pragma omp task
	t_end[59] = spawn_function(); // 60


	clock_gettime(CLOCK_MONOTONIC, &t_start[60]);
	#pragma omp task
	t_end[60] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[61]);
	#pragma omp task
	t_end[61] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[62]);
	#pragma omp task
	t_end[62] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[63]);
	#pragma omp task
	t_end[63] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[64]);
	#pragma omp task
	t_end[64] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[65]);
	#pragma omp task
	t_end[65] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[66]);
	#pragma omp task
	t_end[66] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[67]);
	#pragma omp task
	t_end[67] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[68]);
	#pragma omp task
	t_end[68] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[69]);
	#pragma omp task
	t_end[69] = spawn_function(); // 70


	clock_gettime(CLOCK_MONOTONIC, &t_start[70]);
	#pragma omp task
	t_end[70] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[71]);
	#pragma omp task
	t_end[71] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[72]);
	#pragma omp task
	t_end[72] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[73]);
	#pragma omp task
	t_end[73] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[74]);
	#pragma omp task
	t_end[74] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[75]);
	#pragma omp task
	t_end[75] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[76]);
	#pragma omp task
	t_end[76] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[77]);
	#pragma omp task
	t_end[77] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[78]);
	#pragma omp task
	t_end[78] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[79]);
	#pragma omp task
	t_end[79] = spawn_function(); // 80


	clock_gettime(CLOCK_MONOTONIC, &t_start[80]);
	#pragma omp task
	t_end[80] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[81]);
	#pragma omp task
	t_end[81] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[82]);
	#pragma omp task
	t_end[82] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[83]);
	#pragma omp task
	t_end[83] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[84]);
	#pragma omp task
	t_end[84] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[85]);
	#pragma omp task
	t_end[85] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[86]);
	#pragma omp task
	t_end[86] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[87]);
	#pragma omp task
	t_end[87] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[88]);
	#pragma omp task
	t_end[88] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[89]);
	#pragma omp task
	t_end[89] = spawn_function(); // 90


	clock_gettime(CLOCK_MONOTONIC, &t_start[90]);
	#pragma omp task
	t_end[90] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[91]);
	#pragma omp task
	t_end[91] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[92]);
	#pragma omp task
	t_end[92] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[93]);
	#pragma omp task
	t_end[93] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[94]);
	#pragma omp task
	t_end[94] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[95]);
	#pragma omp task
	t_end[95] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[96]);
	#pragma omp task
	t_end[96] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[97]);
	#pragma omp task
	t_end[97] = spawn_function();

 
	clock_gettime(CLOCK_MONOTONIC, &t_start[98]);
	#pragma omp task
	t_end[98] = spawn_function();
 
	clock_gettime(CLOCK_MONOTONIC, &t_start[99]);
	#pragma omp task
	t_end[99] = spawn_function(); // 100

	}

	// printf("****\n");
	for(int i = 0; i < OMP_THREADS; i++){

		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	return 0;
}