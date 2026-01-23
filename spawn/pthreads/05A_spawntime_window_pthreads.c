#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>

/* Benchmark: 05A: Spawn counter window ; While-Loop  (Pthreads)
 * Launch a bunch in a time window and measure when all done  
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));


void* spawn_function(){           // Simple Spawn Function

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void*) NULL; 
}

int main(int argc, char *argv[]){

	float TIMER = 2.0;
	int counter = 0;

	int DEPTH = 8000;
	pthread_t Threads[ DEPTH ];

	struct timeval t_start, t_end;
	
	gettimeofday(&t_start, NULL); // struct timespec *tp
	gettimeofday(&t_end, NULL);	
	
	while( ( (t_end.tv_sec+ (double)t_end.tv_usec/1000000) - (t_start.tv_sec+(double)t_start.tv_usec/1000000)  ) < TIMER ){
	
		pthread_create( &Threads[ counter ], NULL, spawn_function, NULL);

		gettimeofday(&t_end, NULL);
		counter+=1;

		pthread_join(Threads[counter-1], NULL);	
	}

	for(int i = 0; i < counter; i++){
		 pthread_join(Threads[i], NULL);
	}

	// no barrier bc # threads not known

	printf("%d\n", counter);
	// printf("05A\n");

	return 0;
}


