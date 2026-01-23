#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

int DEPTH = 10;

void runbench(int);

void spawn_function1(int depcnt){ // 1 argument
	printf("Thread depth: %d\n", depcnt);
	return; 
}

void* spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*) NULL; 
}

void runbench(int depcnt){ //  

   spawn_function(); // depcnt);

	pthread_t thread1;
	pthread_t thread2;

   if(depcnt < DEPTH){

		if (pthread_create(&thread1, NULL, (void *)runbench, (void*)(size_t)depcnt+1) != 0){
			perror("pthread_create"); exit(1); }

		if (pthread_create(&thread2, NULL, (void *)runbench, (void*)(size_t)depcnt+1) != 0){
			perror("pthread_create"); exit(1); }

		//// //// 
		
		if (pthread_join(thread1, NULL) != 0){
			perror("pthread_join1"); exit(1); }

		if (pthread_join(thread2, NULL) != 0){
			perror("pthread_join2"); exit(1); }
    	}


    return;
}

int main(int argc, char *argv[]){

	struct timespec t_start, t_res, t_end;
   clock_gettime(CLOCK_MONOTONIC, &t_start);

	int depcnt = 0;
	
	runbench(depcnt); // Main Thread
		
   clock_gettime(CLOCK_MONOTONIC, &t_end);
	
	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	
	
	//printf("D spawntree_pthreads :%d\n", DEPTH);

   return 0;
}
