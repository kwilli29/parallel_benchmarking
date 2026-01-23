#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Benchmark: 01B: Spawn time after ; CilkScope Spawns (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

void spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}


int main(int argc, char *argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	cilk_scope{
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 10
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 20
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 30
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 40
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 50
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 60
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 70
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 80
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); // 90

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 100
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 110
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 120
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 130
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 140
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 150
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 160
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 170
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 180
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); // 190

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 200
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 210
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 220
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 230
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 240
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); 
		cilk_spawn spawn_function(); // 250

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); // 260

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); // 270

		cilk_spawn spawn_function();
		// cilk_spawn spawn_function();
		// cilk_spawn spawn_function();

   }
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01B\n");

	return 0;
}


