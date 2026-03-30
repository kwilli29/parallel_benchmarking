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
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

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

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 110
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 120
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 130
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 140
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 150
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 160
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 170
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 180
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
	spawn_function(); // 190

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 200
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 210
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 220
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 230
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function(); // 240
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
	spawn_function(); // 250

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function(); // 260

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function();
	spawn_function();
	spawn_function();

	spawn_function();
	spawn_function(); // 270

	spawn_function(); 
	// spawn_function();
	// spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	//printf("01A\n");

	
	/*clock_gettime(CLOCK_MONOTONIC, &t_start);

	int N = 271;

	for(int i=0; i<N; i++){
		spawn_function();

	}
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);*/

	return 0;
}


