#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

int DEPTH = 3;

void spawn_function(int depcnt){ // 1 argument
    
	printf("Thread depth: %d\n", depcnt);

	return; 
}

void runbench(int depcnt){ //  int depcnt, int DEPTH){

	ctimer_t t;
   ctimer_start(&t);

   spawn_function(depcnt);

   ctimer_stop(&t);
	ctimer_measure(&t);
	// printf("SF: %lf\n", realTime);
	ctimer_print(t, "pthreadspawn");

	pthread_t thread1;
	pthread_t thread2;

   if(depcnt < DEPTH){

      ctimer_start(&t);
		if (pthread_create(&thread1, NULL, (void *)runbench, (void*)(size_t)depcnt+1) != 0){
			perror("pthread_create"); exit(1); }
      ctimer_stop(&t);
		ctimer_measure(&t);
      // printf("PC1: %lf\n", realTime);
      ctimer_print(t, "pt_create1");

      ctimer_start(&t);
		if (pthread_create(&thread2, NULL, (void *)runbench, (void*)(size_t)depcnt+1) != 0){
			perror("pthread_create"); exit(1); }
      ctimer_stop(&t);
		ctimer_measure(&t);
      // printf("PC2: %lf\n", realTime);
      ctimer_print(t, "pt_create2");

		//// //// 

      ctimer_start(&t);
      if (pthread_join(thread1, NULL) != 0){
			perror("pthread_join1"); exit(1); }
		ctimer_stop(&t);
		ctimer_measure(&t);
      // printf("PJ1: %lf\n", realTime);
      ctimer_print(t,"pt_join1");

      ctimer_start(&t);
      if (pthread_join(thread2, NULL) != 0){
			perror("pthread_join2"); exit(1); }
		ctimer_stop(&t);
		ctimer_measure(&t);
      // printf("PJ2: %lf\n", realTime);
      ctimer_print(t,"pt_join2");
    }
    return;
}

int main(int argc, char *argv[]){

	int depcnt = 0;
	
	//if(argc > 1){
	//	DEPTH = atoi(argv[1]);
	//}

	ctimer_t t;
 
   ctimer_start(&t);
	runbench(depcnt);
   ctimer_stop(&t);
	ctimer_measure(&t);
   // printf("RT: %lf\n", realTime);
   ctimer_print(t, "Overall Time spawntree_pthreads :");

   return 0;
}


