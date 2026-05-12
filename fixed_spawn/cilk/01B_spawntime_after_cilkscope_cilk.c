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

/* Benchmark: 01B: Spawn time after ; CilkScope Set # of Spawns (Cilk)
 * Launch a bunch and measure when all done -
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

	// use cilk scope to spawn threads in a parallel region

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

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); // 100

   }
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01B\n");

	return 0;
}