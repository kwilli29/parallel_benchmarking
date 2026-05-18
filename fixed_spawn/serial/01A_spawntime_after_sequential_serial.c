#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Benchmark: 01A: Spawn time after ; Sequential Spawns (Serial)
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
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 10
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 20
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 30
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 40
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 50
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 60
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 70
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 80
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function(); // 90

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 100
	spawn_function();


	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	//printf("01A\n");

	/*clock_gettime(CLOCK_MONOTONIC, &t_start);

	int N = 100;

	for(int i=0; i<N; i++){
		spawn_function();

	}
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);*/

	return 0;
}
