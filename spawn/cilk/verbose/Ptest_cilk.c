#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <pthread.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Benchmark: 08A:  ; Recursive Spawns (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

#define NCILK __cilkrts_get_nworkers()

#define M 10000

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* recursive_spawn(void * COUNTER){

	// lock
	//COUNTER = 
	*(int *)COUNTER += 1; // passed in var
	// unlock

	if(*(int *)COUNTER == (int)M){ 
		// signal the main thread
		pthread_cond_signal(&cond);
	} else {
		// create -- test attach/detach & sys/proc scope
		cilk_spawn recursive_spawn((void*)COUNTER);
		// pthread_create(&Threads[*(int *)COUNTER], NULL, recursive_spawn, (void *) COUNTER);
		// exit
		//pthread_exit(NULL);
		return (void*)NULL;
	}
	
	return (void*)NULL;	

}

int main(int argc, char *argv[]){

	struct timespec t_start, t_res, t_end;

	pthread_mutex_init(&count_mutex, NULL);
	pthread_cond_init(&cond, NULL);

	int COUNTER = 0;

	/****/ 

	clock_gettime(CLOCK_MONOTONIC, &t_start);
	
	// create recursive thread -- test attach/detach & sys/proc scope
	// pthread_create(&Threads[COUNTER], NULL, recursive_spawn, (void *)&COUNTER);
	cilk_spawn recursive_spawn((void*)&COUNTER);


	// wait on condition variable
  pthread_mutex_lock(&count_mutex);
  while(COUNTER < M) {
	//printf("counter: %d\n", COUNTER);
    pthread_cond_wait(&cond, &count_mutex);
	//printf("counter2: %d\n", COUNTER);
  }
  pthread_mutex_unlock(&count_mutex);

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// divde time by M

	double divTime = ( (long)t_res.tv_sec + ( (double)t_res.tv_nsec/1000000000) ) / (M+0.0);

	printf("%.12lf\n", (double)divTime);	

	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&cond);

	return 0;
}
