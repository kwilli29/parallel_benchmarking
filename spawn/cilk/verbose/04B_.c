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

/* Benchmark: 04B: Spawn time beforefunc ; Sequential Spawns (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

#define NCILK __cilkrts_get_nworkers()

struct timespec t_start;

struct timespec spawn_function(){           // Simple Spawn Function

	struct timespec t_end; 						  
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	
	
	return t_end; 
}
struct timespec spawn_function1(struct timespec t_end, int x){           // Simple Spawn Function
	//printf("%d\t", x);

	// struct timespec t_end, t_res; 						  
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	//timespec_sub(&t_res, t_end, t_start);
	//printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	return t_end; 
}
struct timespec spawn_function2(struct timespec t_start, int x){           // Simple Spawn Function
	//printf("%d\t", x);
	struct timespec t_end, t_res; 						  
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	//timespec_sub(&t_res, t_end, t_start);
	//printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	return t_end; 
}
int main(int argc, char *argv[]){

	int D = 10;	
	
	struct timespec t_res;
	struct timespec t_end[10]; // [NCILK-1];
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	cilk_scope{
		{ // I can't imagine this is remotely recommended even
		t_end[0] = cilk_spawn spawn_function1(t_end[0],0); // Take time stamp before each spawn
		}
		{
		t_end[1] = cilk_spawn spawn_function1(t_end[1],1);
		}
		{
		t_end[2] = cilk_spawn spawn_function1(t_end[2],2);	
		}
		{
		t_end[3] = cilk_spawn spawn_function1(t_end[3],3);
		}
		{
		t_end[4] = cilk_spawn spawn_function1(t_end[4],4);
		}
		{ 
		t_end[5] = cilk_spawn spawn_function1(t_end[5],5); // Take time stamp before each spawn
		}
		{
		t_end[6] = cilk_spawn spawn_function1(t_end[6],6);
		}
		{
		t_end[7] = cilk_spawn spawn_function1(t_end[7],7);	
		}
		{
		t_end[8] = cilk_spawn spawn_function1(t_end[8],8);
		}
		{
		t_end[9] = cilk_spawn spawn_function1(t_end[9],9);
		}
		/*
		t_end[4] = cilk_spawn spawn_function();
		t_end[5] = cilk_spawn spawn_function();
		t_end[6] = cilk_spawn spawn_function();
		t_end[7] = cilk_spawn spawn_function();

		t_end[8] = cilk_spawn spawn_function();
		t_end[9] = cilk_spawn spawn_function(); // 10

		t_end[10] = cilk_spawn spawn_function();
		t_end[11] = cilk_spawn spawn_function();
		t_end[12] = cilk_spawn spawn_function();
		t_end[13] = cilk_spawn spawn_function();

		t_end[14] = cilk_spawn spawn_function();
		t_end[15] = cilk_spawn spawn_function();
		t_end[16] = cilk_spawn spawn_function();
		t_end[17] = cilk_spawn spawn_function();

		t_end[18] = cilk_spawn spawn_function();
		t_end[19] = cilk_spawn spawn_function(); // 20

		t_end[20] = cilk_spawn spawn_function();
		t_end[21] = cilk_spawn spawn_function();
		t_end[22] = cilk_spawn spawn_function();
		t_end[23] = cilk_spawn spawn_function();

		t_end[24] = cilk_spawn spawn_function();
		t_end[25] = cilk_spawn spawn_function();
		t_end[26] = cilk_spawn spawn_function();
		t_end[27] = cilk_spawn spawn_function();

		t_end[28] = cilk_spawn spawn_function();
		t_end[29] = cilk_spawn spawn_function(); // 30
		*/
		// cilk_spawn spawn_function();
		// cilk_spawn spawn_function();

   }

	//cilk_sync; // */

	printf("****\n");	
	for(int i = 0; i < D;i++){ // NCILK-1; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	// printf("04A\n");
	
	return 0;
}


