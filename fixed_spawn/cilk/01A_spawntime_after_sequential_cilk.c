#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Benchmark: 01A: Spawn time after ; Set # of Sequential Spawns (Cilk)
 * Launch a bunch and measure when all done 
 */

void spawn_function(){           // Simple Spawn Function -- can be changed
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	// sequentially spawn functions

		cilk_spawn spawn_function(); //if(NCILK-1 <= 0) { goto end; } // one solution to make it more 'dynamic'
		cilk_spawn spawn_function(); //if(NCILK-2 <= 0) { goto end; }
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 10
		cilk_spawn spawn_function(); //if(NCILK-10 <= 0) { goto end; }
		
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 20
		cilk_spawn spawn_function(); //if(NCILK-20 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 30
		cilk_spawn spawn_function(); //if(NCILK-30 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 40
		cilk_spawn spawn_function(); //if(NCILK-40 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 50
		cilk_spawn spawn_function(); //if(NCILK-50 <= 0) { goto end; } 

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 60
		cilk_spawn spawn_function(); //if(NCILK-60 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 70
		cilk_spawn spawn_function(); //if(NCILK-70 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 80
		cilk_spawn spawn_function(); //if(NCILK-80 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-90 <= 0) { goto end; }// 90

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 100
		cilk_spawn spawn_function(); //if(NCILK-100 <= 0) { goto end; }

// end: // unused label 

	cilk_sync; 
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	//printf("01A\n");

	return 0;
}
