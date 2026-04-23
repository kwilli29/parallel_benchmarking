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

/* Benchmark: 02C: Scope time after ; Serial Region (Serial)
 * Launch a bunch and measure when all done 
 */

void spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

void hello(){
	printf("* 0 hello\n");
	return;
}
void hi(){
	printf("* 0 hi\n");
	return;
}
void greetings(){
	printf("* 0 greetings\n");
	return;
}
void welcome(){
	printf("* 0 welcome\n");
	return;

}
void byebye(){
	printf("* 0 byebye\n");
	return;
}

int main(int argc, char *argv[]){

	struct timespec t_start, t_res, t_end;

	clock_gettime(CLOCK_MONOTONIC, &t_start); // 
		for(int i=0 ; i < 100; i++){
			hello();
		}
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
    printf("+\n");
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start);
		for(int i=0 ; i < 100; i++){
			hi();
		}
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
    printf("*\n");
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start);
		for(int i=0 ; i < 100; i++){
			greetings();
		}
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
    printf("#\n");
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start);
		for(int i=0 ; i < 100; i++){
			welcome();
		}	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
    printf("-\n");
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start);
		for(int i=0 ; i < 100; i++){
			byebye();
		}
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
    printf("&\n");
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("02C\n");

	return 0;
}
