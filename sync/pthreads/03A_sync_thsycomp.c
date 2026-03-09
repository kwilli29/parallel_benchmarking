#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: 03A: Time b/w thread complete and sync complete ; ThSy Time (Pthreads) 
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));


void* spawn_function(void *t_end){           // Simple Function to Spawn

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	clock_gettime(CLOCK_MONOTONIC, (struct timespec *)t_end);

	return (void *)t_end; //  to get REALLY granular, could measure time to return timeval from fcn and sub from end
}

int main(int argc, char *argv[]){

	int N = 30;  // 

	pthread_t Threads[N];

	struct timespec t_res,t_syncend;
	struct timespec t_end[N];

	pthread_create( &Threads[ 0 ], NULL, spawn_function, (void *)&t_end[0]); // 
	pthread_create( &Threads[ 1 ], NULL, spawn_function, (void *)&t_end[1]); // 
	pthread_create( &Threads[ 2 ], NULL, spawn_function, (void *)&t_end[2]); //
	pthread_create( &Threads[ 3 ], NULL, spawn_function, (void *)&t_end[3]);
	pthread_create( &Threads[ 4 ], NULL, spawn_function, (void *)&t_end[4]);
	pthread_create( &Threads[ 5 ], NULL, spawn_function, (void *)&t_end[5]);
	pthread_create( &Threads[ 6 ], NULL, spawn_function, (void *)&t_end[6]);
	pthread_create( &Threads[ 7 ], NULL, spawn_function, (void *)&t_end[7]);
	pthread_create( &Threads[ 8 ], NULL, spawn_function, (void *)&t_end[8]);
	pthread_create( &Threads[ 9 ], NULL, spawn_function, (void *)&t_end[9]); // 10

	pthread_create( &Threads[ 10 ], NULL, spawn_function, (void *)&t_end[10]);
	pthread_create( &Threads[ 11 ], NULL, spawn_function, (void *)&t_end[11]);
	pthread_create( &Threads[ 12 ], NULL, spawn_function, (void *)&t_end[12]);
	pthread_create( &Threads[ 13 ], NULL, spawn_function, (void *)&t_end[13]);
	pthread_create( &Threads[ 14 ], NULL, spawn_function, (void *)&t_end[14]);
	pthread_create( &Threads[ 15 ], NULL, spawn_function, (void *)&t_end[15]);
	pthread_create( &Threads[ 16 ], NULL, spawn_function, (void *)&t_end[16]);
	pthread_create( &Threads[ 17 ], NULL, spawn_function, (void *)&t_end[17]);
	pthread_create( &Threads[ 18 ], NULL, spawn_function, (void *)&t_end[18]);
	pthread_create( &Threads[ 19 ], NULL, spawn_function, (void *)&t_end[19]); // 20

	pthread_create( &Threads[ 20 ], NULL, spawn_function, (void *)&t_end[20]);
	pthread_create( &Threads[ 21 ], NULL, spawn_function, (void *)&t_end[21]);
	pthread_create( &Threads[ 22 ], NULL, spawn_function, (void *)&t_end[22]);
	pthread_create( &Threads[ 23 ], NULL, spawn_function, (void *)&t_end[23]);
	pthread_create( &Threads[ 24 ], NULL, spawn_function, (void *)&t_end[24]);
	pthread_create( &Threads[ 25 ], NULL, spawn_function, (void *)&t_end[25]);
	pthread_create( &Threads[ 26 ], NULL, spawn_function, (void *)&t_end[26]);
	pthread_create( &Threads[ 27 ], NULL, spawn_function, (void *)&t_end[27]);
	pthread_create( &Threads[ 28 ], NULL, spawn_function, (void *)&t_end[28]);
	pthread_create( &Threads[ 29 ], NULL, spawn_function, (void *)&t_end[29]); // 30

	// JOIN
	struct timespec* temp = (struct timespec *)&t_end[0];

	pthread_join( Threads[ 0 ], (void *)&temp); temp = &t_end[1];
	pthread_join( Threads[ 1 ], (void *)&temp); temp = &t_end[2];
	pthread_join( Threads[ 2 ], (void *)&temp); temp = &t_end[3];
	pthread_join( Threads[ 3 ], (void *)&temp); temp = &t_end[4];
	pthread_join( Threads[ 4 ], (void *)&temp); temp = &t_end[5];
	pthread_join( Threads[ 5 ], (void *)&temp); temp = &t_end[6];
	pthread_join( Threads[ 6 ], (void *)&temp); temp = &t_end[7];
	pthread_join( Threads[ 7 ], (void *)&temp); temp = &t_end[8];
	pthread_join( Threads[ 8 ], (void *)&temp); temp = &t_end[9];
	pthread_join( Threads[ 9 ], (void *)&temp); temp = &t_end[10]; // 10

	pthread_join( Threads[ 10 ], (void *)&temp); temp = &t_end[11];
	pthread_join( Threads[ 11 ], (void *)&temp); temp = &t_end[12];
	pthread_join( Threads[ 12 ], (void *)&temp); temp = &t_end[13];
	pthread_join( Threads[ 13 ], (void *)&temp); temp = &t_end[14];
	pthread_join( Threads[ 14 ], (void *)&temp); temp = &t_end[15];
	pthread_join( Threads[ 15 ], (void *)&temp); temp = &t_end[16];
	pthread_join( Threads[ 16 ], (void *)&temp); temp = &t_end[17];
	pthread_join( Threads[ 17 ], (void *)&temp); temp = &t_end[18];
	pthread_join( Threads[ 18 ], (void *)&temp); temp = &t_end[19];
	pthread_join( Threads[ 19 ], (void *)&temp); temp = &t_end[20]; // 20

	pthread_join( Threads[ 20 ], (void *)&temp); temp = &t_end[21];
	pthread_join( Threads[ 21 ], (void *)&temp); temp = &t_end[22];
	pthread_join( Threads[ 22 ], (void *)&temp); temp = &t_end[23];
	pthread_join( Threads[ 23 ], (void *)&temp); temp = &t_end[24];
	pthread_join( Threads[ 24 ], (void *)&temp); temp = &t_end[25];
	pthread_join( Threads[ 25 ], (void *)&temp); temp = &t_end[26];
	pthread_join( Threads[ 26 ], (void *)&temp); temp = &t_end[27];
	pthread_join( Threads[ 27 ], (void *)&temp); temp = &t_end[28];
	pthread_join( Threads[ 28 ], (void *)&temp); temp = &t_end[29];
	clock_gettime(CLOCK_MONOTONIC, &t_syncend);	


	struct timespec maxtime = t_end[0];
	double t = 0.0; double mt = 0.0;

	for(int j=0; j < N; j++){

		t  = (double)((long)t_end[j].tv_sec + (t_end[j].tv_nsec/1000000000.0) );
		mt = (double)((long)maxtime.tv_sec  + (maxtime.tv_nsec/1000000000.0) );

		if(t > mt){
			maxtime = t_end[j];
		}
		
	}

	// for(int i = 0; i < N; i++){
		
	//	timespec_sub(&t_res, t_syncend, t_end[i]);

	//	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	//}

	timespec_sub(&t_res, t_syncend, maxtime);

	printf("t b/w last fcn complete & sync complete\n");

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	// printf("03A\n");
	
	return 0;
}


