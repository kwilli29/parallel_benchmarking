#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: 03A: Time b/w thread complete and sync complete ; ThSy Time (Cilk) 
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

#define NCILK __cilkrts_get_nworkers()


struct timespec spawn_function(){           // Simple Function to Spawn

	struct timespec t_end; // ADD TIME END

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	return t_end; //  to get REALLY granular, could measure time to return timeval from fcn and sub from end
}

int main(int argc, char *argv[]){

	int N = 30;  // NCILK-1

	struct timespec t_res,t_syncend;
	struct timespec t_end[N];

	t_end[0] = cilk_spawn spawn_function(); // Take time stamp before each spawn
	t_end[1] = cilk_spawn spawn_function();
	t_end[2] = cilk_spawn spawn_function();
	t_end[3] = cilk_spawn spawn_function();

	t_end[4] = cilk_spawn spawn_function();
	t_end[5] = cilk_spawn spawn_function();
	t_end[6] = cilk_spawn spawn_function();
	t_end[7] = cilk_spawn spawn_function();

	t_end[8] = cilk_spawn spawn_function();
	t_end[9] = cilk_spawn spawn_function(); // 10

	t_end[10] = cilk_spawn spawn_function();
	t_end[11] = cilk_spawn spawn_function();
	t_end[12] = cilk_spawn spawn_function();
	t_end[13] = cilk_spawn spawn_function();

	t_end[14] = cilk_spawn spawn_function();
	t_end[15] = cilk_spawn spawn_function();
	t_end[16] = cilk_spawn spawn_function();
	t_end[17] = cilk_spawn spawn_function();

	t_end[18] = cilk_spawn spawn_function();
	t_end[19] = cilk_spawn spawn_function(); // 20

	t_end[20] = cilk_spawn spawn_function();
	t_end[21] = cilk_spawn spawn_function();
	t_end[22] = cilk_spawn spawn_function();
	t_end[23] = cilk_spawn spawn_function();

	t_end[24] = cilk_spawn spawn_function();
	t_end[25] = cilk_spawn spawn_function();
	t_end[26] = cilk_spawn spawn_function();
	t_end[27] = cilk_spawn spawn_function();

	t_end[28] = cilk_spawn spawn_function();
	t_end[29] = cilk_spawn spawn_function(); // 30


	cilk_sync;
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

	printf("*t b/w last fcn complete & sync complete\n");

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	// printf("03A\n");
	
	// cilk_rts_getworker_number;

	return 0;
}


