#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Benchmark: 02E: No Scope time after ; Parallel Region  (OpenMP)
 */

#define OMP_THREADS 271 

void spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

void hello(){
	printf("* %d hello\n", omp_get_thread_num());
	return;
}
void hi(){
	printf("* %d hi\n", omp_get_thread_num());
	return;
}
void greetings(){
	printf("* %d greetings\n", omp_get_thread_num());
	return;
}
void welcome(){
	printf("* %d welcome\n", omp_get_thread_num());
	return;

}
void byebye(){
	printf("* %d byebye\n", omp_get_thread_num());
	return;
}

int main(int argc, char *argv[]){

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	#pragma omp parallel
	#pragma omp single
	{

        #pragma omp parallel for
        for(int i=0 ; i < 100; i++){
            hello();
        }
        
        #pragma omp parallel for
        for(int i=0 ; i < 100; i++){
            hi();
        }
        
        #pragma omp parallel for
        for(int i=0 ; i < 100; i++){
            greetings();
        }

        #pragma omp parallel for
        for(int i=0 ; i < 100; i++){
            welcome();
        }

        #pragma omp parallel for
        for(int i=0 ; i < 100; i++){
            byebye();
        }
   }

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("02E\n");

	return 0;
}