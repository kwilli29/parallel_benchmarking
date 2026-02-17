#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

#define NCILK __cilkrts_get_nworkers()

/* Benchmark: 01A: Spawn time after ; Sequential Spawns (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

void spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

	printf("%d\n", NCILK);

	int cntr = NCILK;
	
	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	// cilk_scope{
		cilk_spawn spawn_function(); //if(NCILK-1 <= 0) { goto end; }
		cilk_spawn spawn_function(); //if(NCILK-2 <= 0) { goto end; }
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		// workerNum = __cilkrts_get_worker_number();
		// printf("The current worker number is %d. That's because we are running serially.\n",workerNum);

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 10
		cilk_spawn spawn_function(); //if(NCILK-10 <= 0) { goto end; }
		
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 20
		cilk_spawn spawn_function(); //if(NCILK-20 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 30
		cilk_spawn spawn_function(); //if(NCILK-30 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 40
		cilk_spawn spawn_function(); //if(NCILK-40 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 50
		cilk_spawn spawn_function(); //if(NCILK-50 <= 0) { goto end; } 

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 60
		cilk_spawn spawn_function(); //if(NCILK-60 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 70
		cilk_spawn spawn_function(); //if(NCILK-70 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 80
		cilk_spawn spawn_function(); //if(NCILK-80 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-90 <= 0) { goto end; }// 90

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 100
		cilk_spawn spawn_function(); //if(NCILK-100 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 110
		cilk_spawn spawn_function(); //if(NCILK-110 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 120
		cilk_spawn spawn_function(); //if(NCILK-120 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 130
		cilk_spawn spawn_function(); //if(NCILK-130 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 140
		cilk_spawn spawn_function(); //if(NCILK-140 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 150
		cilk_spawn spawn_function(); //if(NCILK-150 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 160
		cilk_spawn spawn_function(); //if(NCILK-160 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 170
		cilk_spawn spawn_function(); //if(NCILK-170 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 180
		cilk_spawn spawn_function(); //if(NCILK-180 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-190 <= 0) { goto end; }// 190

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 200
		cilk_spawn spawn_function(); //if(NCILK-200 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 210
		cilk_spawn spawn_function(); //if(NCILK-210 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 220
		cilk_spawn spawn_function(); //if(NCILK-220 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 230
		cilk_spawn spawn_function(); //if(NCILK-230 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); // 240
		cilk_spawn spawn_function(); //if(NCILK-240 <= 0) { goto end; }

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); 
		cilk_spawn spawn_function(); //if(NCILK-250 <= 0) { goto end; } // 250

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-260 <= 0) { goto end; } // 260

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-270 <= 0) { goto end; } // 270

		cilk_spawn spawn_function();
		// cilk_spawn spawn_function();
		// cilk_spawn spawn_function();

   //}

end: 

	cilk_sync; // */
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	//printf("01A\n");

	
	/*clock_gettime(CLOCK_MONOTONIC, &t_start);

	for(int i=0; i<NCILK; i++){
		cilk_spawn spawn_function();

	}
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);*/

	return 0;
}


