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
#include "../ctimer.h"
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

    int OMP_THREADS = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            OMP_THREADS = number_threads();
        } else {
            OMP_THREADS = atoi(argv[1]);
            if (OMP_THREADS > 301){
                OMP_THREADS = number_threads();
            }
        }
    }

    struct timespec t_start, t_end, t_res;

    /****************  01A ****************/ 
    printf("01A\n");

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel
	#pragma omp single
	{
    if( (OMP_THREADS-1) >= 0 ) {
    #pragma omp task
        spawn_function(); }
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);


    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel
	#pragma omp single
	{
    if( (OMP_THREADS-1) >= 0 ) {}
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("correct ifnosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel
	#pragma omp single
	{
    if( (OMP_THREADS-2) >= 0 ) {}
    } 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("incorrect ifnosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    /****************  01B ****************/
    printf("skip 01B\n\n");

    /****************  02A ****************/
    struct timespec t_end1[OMP_THREADS];

    printf("02A\n");
	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel
    #pragma omp sections
    {
	    #pragma omp section
	    {
	    if(OMP_THREADS-1 >= 0){
	        clock_gettime(CLOCK_MONOTONIC, &t_end1[0]); 
	        spawn_function();
	    }
	    }
    } 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);


    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel
    #pragma omp sections
    {
	    #pragma omp section
	    {
	    if(OMP_THREADS-1 >= 0){
	        clock_gettime(CLOCK_MONOTONIC, &t_end1[0]); 
	    }
	    }
    } 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel
    #pragma omp sections
    {
	    #pragma omp section
	    {
	    if(OMP_THREADS-1 >= 0){
	    }
	    }
    } 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnotimenosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);


    /****************  02B ****************/
    printf("02B\n");

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel num_threads(OMP_THREADS)
    {
        #pragma omp taskgroup
        {
        if(OMP_THREADS-1 >= 0){
            clock_gettime(CLOCK_MONOTONIC, &t_end1[0]); 
            #pragma omp task 
                spawn_function();
        }
        } 
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);


    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel num_threads(OMP_THREADS)
    {
        #pragma omp taskgroup
        {
        if(OMP_THREADS-1 >= 0){
            clock_gettime(CLOCK_MONOTONIC, &t_end1[0]); 
        }
        } 
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnosp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel num_threads(OMP_THREADS)
    {
        #pragma omp taskgroup
        {
        if(OMP_THREADS-1 >= 0){}
        } 
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnotimenosp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    { if(OMP_THREADS-1 >= 0){} } 
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("nopararegifnotimenosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    /****************  04A ****************/
    struct timespec t_start1[OMP_THREADS];

    printf("04A\n");

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
	#pragma omp parallel
	#pragma omp single
	{	
        if(OMP_THREADS-1 >= 0){
            clock_gettime(CLOCK_MONOTONIC, &t_start1[0]); 
            #pragma omp task
            t_end1[0] = spawn_function1();
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
    

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
	#pragma omp parallel
	#pragma omp single
	{	
        if(OMP_THREADS-1 >= 0){
            clock_gettime(CLOCK_MONOTONIC, &t_start1[0]); 
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnosp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
	#pragma omp parallel
	#pragma omp single
	{	
        if(OMP_THREADS-1 >= 0){}
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnotimenosp: %ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    /****************  04B ****************/
    printf("04B\n");

	clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel
    #pragma omp sections
    {
        #pragma omp section
        {
        if(OMP_THREADS-1 >= 0){
            clock_gettime(CLOCK_MONOTONIC, &t_start1[0]); 
            #pragma omp task 
            t_end1[0] = spawn_function1();
        }
        } 
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifsp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel
    #pragma omp sections
    {
        #pragma omp section
        {
        if(OMP_THREADS-1 >= 0){
            clock_gettime(CLOCK_MONOTONIC, &t_start1[0]); 
        }
        } 
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnosp: %ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    #pragma omp parallel
    #pragma omp sections
    {
        #pragma omp section
        {
        if(OMP_THREADS-1 >= 0){}
        } 
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("ifnotimenosp:%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &t_start); //
    if(OMP_THREADS-1 >= 0){}
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	timespec_sub(&t_res, t_end, t_start);
	printf("nopararegifnotimenosp:%ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);

    return 0;
}