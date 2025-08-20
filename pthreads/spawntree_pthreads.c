#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

struct spawnargs {   // Structure declaration
  int depcnt;           // Member (int variable)
  int DEPTH;       // Member (char variable)
} typedef spawnargs; // End the structure with a semicolon

void spawn_function(int depcnt){ // 1 argument

    printf("Thread depth: %d\n", depcnt);

    return; 
}

void runbench(struct spawnargs d){ //  int depcnt, int DEPTH){

	ctimer_t t;
   ctimer_start(&t);
   spawn_function(d.depcnt);
   ctimer_stop(&t);
	ctimer_measure(&t);
    
	// printf("SF: %lf\n", realTime);
	ctimer_print(t, "pthreadspawn");

	pthread_t thread1;
	pthread_t thread2;

   if(d.depcnt < d.DEPTH){

		d.depcnt+=1;

      ctimer_start(&t);
		if (pthread_create(&thread1, NULL, (void *)runbench, (void*)&d) != 0){
		perror("pthread_create"); exit(1); }
      ctimer_stop(&t);
		ctimer_measure(&t);
      // printf("PC1: %lf\n", realTime);
      ctimer_print(t, "pt_create1");

      ctimer_start(&t);
		if (pthread_create(&thread2, NULL, (void *)runbench, (void*)&d) != 0){
		perror("pthread_create"); exit(1); }
      ctimer_stop(&t);
		ctimer_measure(&t);
      // printf("PC2: %lf\n", realTime);
      ctimer_print(t, "pt_create2");
      //spawn_function(depcnt+1);

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

	struct spawnargs d;
	d.DEPTH = 3;
	d.depcnt = 0;


	//if(argc > 1){
	//	d.DEPTH = atoi(argv[1]);
	//}

	ctimer_t t;
 
   ctimer_start(&t);
	runbench(d);
   ctimer_stop(&t);
	ctimer_measure(&t);
   // printf("RT: %lf\n", realTime);
   ctimer_print(t, "RT: ");

   return 0;
}


