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
#include "../../../include/numthreads.h"

// Overhead Calc

void spawn_function(){           // Simple Spawn Function -- can be changed
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}
struct timespec spawn_function1(){           // Simple Spawn Function

	struct timespec t_end; 						  
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;

	return t_end; // return individual timestamps 
}

int main(int argc, char *argv[]){

    int NSERIAL = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            NSERIAL = number_threads();
        } else {
            NSERIAL = atoi(argv[1]);
            if (NSERIAL > 301){
                NSERIAL = number_threads();
            }
        }
    } printf("# Spawns: %d\n\n", NSERIAL);

    struct timespec t_start, t_end, t_res;

    /****************  01A ****************/ 
    printf("01A\n");

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-1 >= 0) {  spawn_function(); } // 1
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp  : %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-1 >= 0) {} // 1
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("correct ifnosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-2 >= 0) {} 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("incorrect ifnosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);


    /****************  02A ****************/
    struct timespec t_end1[NSERIAL];

    printf("02A\n");
	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-1 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end1[0]);  spawn_function(); } // 1 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-1 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end1[0]); } // 1 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-1 >= 0) {} // 1 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnotimenosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-2 >= 0) {}
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("incorrect ifnotimenosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);


    /****************  04A ****************/
    struct timespec t_start1[NSERIAL];

    printf("04A\n");

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-1 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start1[0]); t_end1[0] =  spawn_function1(); } // 1 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
    


	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-1 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start1[0]); } // 1 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnosp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-1 >= 0) {} // 1 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("correct ifnotimenosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(NSERIAL-2 >= 0) {}
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("incorrect noscopeifnosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);


    return 0;
}