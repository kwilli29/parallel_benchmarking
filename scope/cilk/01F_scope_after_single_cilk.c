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

/* Benchmark: 01F: Scope time after single function; CilkScope (Cilk)
 * Launch a bunch and measure when all done 
 */

#define NCILK __cilkrts_get_nworkers()

void spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

void hello(){
	printf("* %d hello\n", __cilkrts_get_worker_number());
	return; 
}
void hi(){
	printf("* %d hi\n", __cilkrts_get_worker_number());
	return;
}
void greetings(){
	printf("* %d greetings\n",__cilkrts_get_worker_number());
	return;
}
void welcome(){
	printf("* %d welcome\n", __cilkrts_get_worker_number());
	return;

}
void byebye(){
	printf("* %d byebye\n", __cilkrts_get_worker_number());
	return;
}

int main(int argc, char *argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start);

	cilk_scope{
		spawn_function();
    }

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01F\n");

	return 0;
}


