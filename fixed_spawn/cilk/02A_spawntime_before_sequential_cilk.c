#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Benchmark: 02A: Spawn time before ; Sequential Spawns (Cilk)
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

    int NCILK = 100;

	struct timespec t_start, t_res;
	struct timespec t_end[NCILK];
	clock_gettime(CLOCK_MONOTONIC, &t_start);

	// sequential spawn, mark times before each spawn

		clock_gettime(CLOCK_MONOTONIC, &t_end[0]); cilk_spawn spawn_function(); // Take time stamp before each spawn
		clock_gettime(CLOCK_MONOTONIC, &t_end[1]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[2]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[3]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[4]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[5]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[6]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[7]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[8]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[9]); cilk_spawn spawn_function(); // 10

		clock_gettime(CLOCK_MONOTONIC, &t_end[10]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[11]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[12]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[13]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[14]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[15]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[16]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[17]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[18]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[19]); cilk_spawn spawn_function(); // 20

		clock_gettime(CLOCK_MONOTONIC, &t_end[20]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[21]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[22]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[23]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[24]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[25]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[26]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[27]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[28]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[29]); cilk_spawn spawn_function(); // 30

		clock_gettime(CLOCK_MONOTONIC, &t_end[30]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[31]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[32]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[33]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[34]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[35]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[36]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[37]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[38]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[39]); cilk_spawn spawn_function(); // 40

		clock_gettime(CLOCK_MONOTONIC, &t_end[40]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[41]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[42]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[43]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[44]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[45]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[46]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[47]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[48]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[49]); cilk_spawn spawn_function(); // 50

		clock_gettime(CLOCK_MONOTONIC, &t_end[50]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[51]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[52]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[53]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[54]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[55]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[56]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[57]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[58]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[59]); cilk_spawn spawn_function(); // 60

		clock_gettime(CLOCK_MONOTONIC, &t_end[60]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[61]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[62]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[63]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[64]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[65]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[66]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[67]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[68]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[69]); cilk_spawn spawn_function(); // 70

		clock_gettime(CLOCK_MONOTONIC, &t_end[70]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[71]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[72]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[73]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[74]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[75]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[76]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[77]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[78]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[79]); cilk_spawn spawn_function(); // 80

		clock_gettime(CLOCK_MONOTONIC, &t_end[80]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[81]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[82]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[83]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[84]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[85]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[86]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[87]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[88]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[89]); cilk_spawn spawn_function(); // 90

		clock_gettime(CLOCK_MONOTONIC, &t_end[90]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[91]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[92]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[93]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[94]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[95]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[96]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[97]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[98]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[99]); cilk_spawn spawn_function(); // 100

	printf("****\n");
	for(int i = 0; i < NCILK; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}
	
	// printf("02A\n");
	
	return 0;
}
