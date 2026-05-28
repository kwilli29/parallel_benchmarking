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

// #define NCILK __cilkrts_get_nworkers()

/* Benchmark: 01A: Spawn time after ; Sequential Spawns (Cilk)
 * Launch a bunch and measure when all done 
 */

void spawn_function(){           // Simple Spawn Function -- can be changed
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

    int NCILK = __cilkrts_get_nworkers();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            NCILK = __cilkrts_get_nworkers();
        } else {
            NCILK = atoi(argv[1]);
            if (NCILK > 301){
                NCILK = __cilkrts_get_nworkers();
            }
        }
    }

	printf("* # Spawns: %d\n", NCILK);

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

	// sequentially spawn functions

		cilk_spawn spawn_function(); if(NCILK-1 <= 0) { goto end; } // 1 // one solution to make it more 'dynamic'
		cilk_spawn spawn_function(); if(NCILK-2 <= 0) { goto end; } // 2
		cilk_spawn spawn_function(); if(NCILK-3 <= 0) { goto end; } // 3
		cilk_spawn spawn_function(); if(NCILK-4 <= 0) { goto end; } // 4

		cilk_spawn spawn_function(); if(NCILK-5 <= 0) { goto end; } // 5
		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); if(NCILK-7 <= 0) { goto end; } // 7
		cilk_spawn spawn_function(); if(NCILK-8 <= 0) { goto end; } // 8

		cilk_spawn spawn_function(); if(NCILK-9 <= 0) { goto end; } // 9
		cilk_spawn spawn_function(); if(NCILK-10 <= 0) { goto end; } // 10
		
		cilk_spawn spawn_function(); if(NCILK-11 <= 0) { goto end; } // 11
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); if(NCILK-15 <= 0) { goto end; } // 15
		cilk_spawn spawn_function(); if(NCILK-16 <= 0) { goto end; } // 16
		cilk_spawn spawn_function(); if(NCILK-17 <= 0) { goto end; } // 17
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-20 <= 0) { goto end; } // 20

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); // if(NCILK-30 <= 0) { goto end; } // 30

		cilk_spawn spawn_function(); if(NCILK-31 <= 0) { goto end; } // 31
		cilk_spawn spawn_function(); if(NCILK-32 <= 0) { goto end; } // 32
		cilk_spawn spawn_function(); if(NCILK-33 <= 0) { goto end; } // 33
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-40 <= 0) { goto end; } // 40

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); if(NCILK-47 <= 0) { goto end; } // 47
		cilk_spawn spawn_function(); if(NCILK-48 <= 0) { goto end; } // 48

		cilk_spawn spawn_function(); if(NCILK-49 <= 0) { goto end; } // 49
		cilk_spawn spawn_function(); // if(NCILK-50 <= 0) { goto end; }  // 50

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); // if(NCILK-60 <= 0) { goto end; } // 60

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); if(NCILK-63 <= 0) { goto end; } // 63
		cilk_spawn spawn_function(); if(NCILK-64 <= 0) { goto end; } // 64

		cilk_spawn spawn_function(); if(NCILK-65 <= 0) { goto end; } // 65
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-70 <= 0) { goto end; } // 70

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-80 <= 0) { goto end; } // 80

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-90 <= 0) { goto end; } // 90

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); 
		cilk_spawn spawn_function(); //if(NCILK-100 <= 0) { goto end; } // 100

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-110 <= 0) { goto end; } // 110

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-120 <= 0) { goto end; } // 120

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); if(NCILK-127 <= 0) { goto end; } // 127
		cilk_spawn spawn_function(); if(NCILK-128 <= 0) { goto end; } // 128

		cilk_spawn spawn_function(); if(NCILK-129 <= 0) { goto end; } // 129
		cilk_spawn spawn_function(); // if(NCILK-130 <= 0) { goto end; } // 130

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-140 <= 0) { goto end; } // 140

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-150 <= 0) { goto end; } // 150

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-160 <= 0) { goto end; } // 160

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-170 <= 0) { goto end; } // 170

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-180 <= 0) { goto end; } // 180

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

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-200 <= 0) { goto end; } // 200

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); 
		cilk_spawn spawn_function(); //if(NCILK-210 <= 0) { goto end; } // 210

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); 
		cilk_spawn spawn_function(); //if(NCILK-220 <= 0) { goto end; } // 220

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); 
		cilk_spawn spawn_function(); //if(NCILK-230 <= 0) { goto end; } // 230

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); 
		cilk_spawn spawn_function(); //if(NCILK-240 <= 0) { goto end; } // 240

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

		cilk_spawn spawn_function(); if(NCILK-255 <= 0) { goto end; } // 255
		cilk_spawn spawn_function(); if(NCILK-256 <= 0) { goto end; } // 256
		cilk_spawn spawn_function(); if(NCILK-257 <= 0) { goto end; } // 257
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
		cilk_spawn spawn_function(); // if(NCILK-270 <= 0) { goto end; } // 270

		cilk_spawn spawn_function(); if(NCILK-271 <= 0) { goto end; } // 271
		cilk_spawn spawn_function(); if(NCILK-272 <= 0) { goto end; } // 272
		cilk_spawn spawn_function(); if(NCILK-273 <= 0) { goto end; } // 273
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-280 <= 0) { goto end; } // 280

        cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function(); //if(NCILK-290 <= 0) { goto end; } // 290

        cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();
		cilk_spawn spawn_function();

		cilk_spawn spawn_function(); if(NCILK-299 <= 0) { goto end; } // 299 
		cilk_spawn spawn_function(); if(NCILK-300 <= 0) { goto end; } // 300

        cilk_spawn spawn_function(); if(NCILK-301 <= 0) { goto end; } // 301

end: // unused label 

	cilk_sync; 
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	//printf("01A\n");

	return 0;
}