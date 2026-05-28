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
#include "../../include/numthreads.h"
/* Benchmark: 04A: Spawn time before function ; Sequential Spawns (Pthreads)
 * Launch a bunch and measure when all done 
 */

void* spawn_function(void *t_end){           // Simple Math for Spawn Function

	clock_gettime(CLOCK_MONOTONIC, (struct timespec *)t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void *)t_end; 
}

int main(int argc, char *argv[]){

	int PTH = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            PTH = number_threads();
        } else {
            PTH = atoi(argv[1]);
            if (PTH > 301){
                PTH = number_threads();;
            }
        }
    }
	printf("* # Spawns: %d\n", PTH);

	pthread_t Threads[ PTH ];

	struct timespec t_start[PTH]; struct timespec t_res;
	struct timespec t_end[PTH];

	// all threads spawn & join
	/****/

	if( PTH-1 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[0]); pthread_create( &Threads[ 0 ], NULL, spawn_function, (void *)&t_end[0]); }
	if( PTH-2 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[1]); pthread_create( &Threads[ 1 ], NULL, spawn_function, (void *)&t_end[1]); }
	if( PTH-3 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[2]); pthread_create( &Threads[ 2 ], NULL, spawn_function, (void *)&t_end[2]); }
	if( PTH-4 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[3]); pthread_create( &Threads[ 3 ], NULL, spawn_function, (void *)&t_end[3]); }
	if( PTH-5 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[4]); pthread_create( &Threads[ 4 ], NULL, spawn_function, (void *)&t_end[4]); }
	if( PTH-6 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[5]); pthread_create( &Threads[ 5 ], NULL, spawn_function, (void *)&t_end[5]); }
	if( PTH-7 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[6]); pthread_create( &Threads[ 6 ], NULL, spawn_function, (void *)&t_end[6]); }
	if( PTH-8 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[7]); pthread_create( &Threads[ 7 ], NULL, spawn_function, (void *)&t_end[7]); }
	if( PTH-9 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[8]); pthread_create( &Threads[ 8 ], NULL, spawn_function, (void *)&t_end[8]); }
	if( PTH-10 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[9]); pthread_create( &Threads[ 9 ], NULL, spawn_function, (void *)&t_end[9]); } // 10

	if( PTH-11 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[10]); pthread_create( &Threads[ 10 ], NULL, spawn_function, (void *)&t_end[10]); }
	if( PTH-12 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[11]); pthread_create( &Threads[ 11 ], NULL, spawn_function, (void *)&t_end[11]); }
	if( PTH-13 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[12]); pthread_create( &Threads[ 12 ], NULL, spawn_function, (void *)&t_end[12]); }
	if( PTH-14 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[13]); pthread_create( &Threads[ 13 ], NULL, spawn_function, (void *)&t_end[13]); }
	if( PTH-15 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[14]); pthread_create( &Threads[ 14 ], NULL, spawn_function, (void *)&t_end[14]); }
	if( PTH-16 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[15]); pthread_create( &Threads[ 15 ], NULL, spawn_function, (void *)&t_end[15]); }
	if( PTH-17 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[16]); pthread_create( &Threads[ 16 ], NULL, spawn_function, (void *)&t_end[16]); }
	if( PTH-18 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[17]); pthread_create( &Threads[ 17 ], NULL, spawn_function, (void *)&t_end[17]); }
	if( PTH-19 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[18]); pthread_create( &Threads[ 18 ], NULL, spawn_function, (void *)&t_end[18]); }
	if( PTH-20 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[19]); pthread_create( &Threads[ 19 ], NULL, spawn_function, (void *)&t_end[19]); } // 20

	if( PTH-21 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[20]); pthread_create( &Threads[ 20 ], NULL, spawn_function, (void *)&t_end[20]); }
	if( PTH-22 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[21]); pthread_create( &Threads[ 21 ], NULL, spawn_function, (void *)&t_end[21]); }
	if( PTH-23 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[22]); pthread_create( &Threads[ 22 ], NULL, spawn_function, (void *)&t_end[22]); }
	if( PTH-24 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[23]); pthread_create( &Threads[ 23 ], NULL, spawn_function, (void *)&t_end[23]); }
	if( PTH-25 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[24]); pthread_create( &Threads[ 24 ], NULL, spawn_function, (void *)&t_end[24]); }
	if( PTH-26 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[25]); pthread_create( &Threads[ 25 ], NULL, spawn_function, (void *)&t_end[25]); }
	if( PTH-27 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[26]); pthread_create( &Threads[ 26 ], NULL, spawn_function, (void *)&t_end[26]); }
	if( PTH-28 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[27]); pthread_create( &Threads[ 27 ], NULL, spawn_function, (void *)&t_end[27]); }
	if( PTH-29 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[28]); pthread_create( &Threads[ 28 ], NULL, spawn_function, (void *)&t_end[28]); }
	if( PTH-30 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[29]); pthread_create( &Threads[ 29 ], NULL, spawn_function, (void *)&t_end[29]); } // 30

	if( PTH-31 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[30]); pthread_create( &Threads[ 30 ], NULL, spawn_function, (void *)&t_end[30]); }
	if( PTH-32 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[31]); pthread_create( &Threads[ 31 ], NULL, spawn_function, (void *)&t_end[31]); }
	if( PTH-33 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[32]); pthread_create( &Threads[ 32 ], NULL, spawn_function, (void *)&t_end[32]); }
	if( PTH-34 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[33]); pthread_create( &Threads[ 33 ], NULL, spawn_function, (void *)&t_end[33]); }
	if( PTH-35 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[34]); pthread_create( &Threads[ 34 ], NULL, spawn_function, (void *)&t_end[34]); }
	if( PTH-36 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[35]); pthread_create( &Threads[ 35 ], NULL, spawn_function, (void *)&t_end[35]); }
	if( PTH-37 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[36]); pthread_create( &Threads[ 36 ], NULL, spawn_function, (void *)&t_end[36]); }
	if( PTH-38 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[37]); pthread_create( &Threads[ 37 ], NULL, spawn_function, (void *)&t_end[37]); }
	if( PTH-39 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[38]); pthread_create( &Threads[ 38 ], NULL, spawn_function, (void *)&t_end[38]); }
	if( PTH-40 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[39]); pthread_create( &Threads[ 39 ], NULL, spawn_function, (void *)&t_end[39]); } // 40

	if( PTH-41 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[40]); pthread_create( &Threads[ 40 ], NULL, spawn_function, (void *)&t_end[40]); }
	if( PTH-42 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[41]); pthread_create( &Threads[ 41 ], NULL, spawn_function, (void *)&t_end[41]); }
	if( PTH-43 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[42]); pthread_create( &Threads[ 42 ], NULL, spawn_function, (void *)&t_end[42]); }
	if( PTH-44 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[43]); pthread_create( &Threads[ 43 ], NULL, spawn_function, (void *)&t_end[43]); }
	if( PTH-45 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[44]); pthread_create( &Threads[ 44 ], NULL, spawn_function, (void *)&t_end[44]); }
	if( PTH-46 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[45]); pthread_create( &Threads[ 45 ], NULL, spawn_function, (void *)&t_end[45]); }
	if( PTH-47 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[46]); pthread_create( &Threads[ 46 ], NULL, spawn_function, (void *)&t_end[46]); }
	if( PTH-48 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[47]); pthread_create( &Threads[ 47 ], NULL, spawn_function, (void *)&t_end[47]); }
	if( PTH-49 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[48]); pthread_create( &Threads[ 48 ], NULL, spawn_function, (void *)&t_end[48]); }
	if( PTH-50 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[49]); pthread_create( &Threads[ 49 ], NULL, spawn_function, (void *)&t_end[49]); } // 50

	if( PTH-51 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[50]); pthread_create( &Threads[ 50 ], NULL, spawn_function, (void *)&t_end[50]); }
	if( PTH-52 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[51]); pthread_create( &Threads[ 51 ], NULL, spawn_function, (void *)&t_end[51]); }
	if( PTH-53 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[52]); pthread_create( &Threads[ 52 ], NULL, spawn_function, (void *)&t_end[52]); }
	if( PTH-54 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[53]); pthread_create( &Threads[ 53 ], NULL, spawn_function, (void *)&t_end[53]); }
	if( PTH-55 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[54]); pthread_create( &Threads[ 54 ], NULL, spawn_function, (void *)&t_end[54]); }
	if( PTH-56 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[55]); pthread_create( &Threads[ 55 ], NULL, spawn_function, (void *)&t_end[55]); }
	if( PTH-57 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[56]); pthread_create( &Threads[ 56 ], NULL, spawn_function, (void *)&t_end[56]); }
	if( PTH-58 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[57]); pthread_create( &Threads[ 57 ], NULL, spawn_function, (void *)&t_end[57]); }
	if( PTH-59 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[58]); pthread_create( &Threads[ 58 ], NULL, spawn_function, (void *)&t_end[58]); }
	if( PTH-60 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[59]); pthread_create( &Threads[ 59 ], NULL, spawn_function, (void *)&t_end[59]); } // 60

	if( PTH-61 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[60]); pthread_create( &Threads[ 60 ], NULL, spawn_function, (void *)&t_end[60]); }
	if( PTH-62 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[61]); pthread_create( &Threads[ 61 ], NULL, spawn_function, (void *)&t_end[61]); }
	if( PTH-63 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[62]); pthread_create( &Threads[ 62 ], NULL, spawn_function, (void *)&t_end[62]); }
	if( PTH-64 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[63]); pthread_create( &Threads[ 63 ], NULL, spawn_function, (void *)&t_end[63]); }
	if( PTH-65 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[64]); pthread_create( &Threads[ 64 ], NULL, spawn_function, (void *)&t_end[64]); }
	if( PTH-66 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[65]); pthread_create( &Threads[ 65 ], NULL, spawn_function, (void *)&t_end[65]); }
	if( PTH-67 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[66]); pthread_create( &Threads[ 66 ], NULL, spawn_function, (void *)&t_end[66]); }
	if( PTH-68 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[67]); pthread_create( &Threads[ 67 ], NULL, spawn_function, (void *)&t_end[67]); }
	if( PTH-69 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[68]); pthread_create( &Threads[ 68 ], NULL, spawn_function, (void *)&t_end[68]); }
	if( PTH-70 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[69]); pthread_create( &Threads[ 69 ], NULL, spawn_function, (void *)&t_end[69]); } // 70

	if( PTH-71 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[70]); pthread_create( &Threads[ 70 ], NULL, spawn_function, (void *)&t_end[70]); }
	if( PTH-72 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[71]); pthread_create( &Threads[ 71 ], NULL, spawn_function, (void *)&t_end[71]); }
	if( PTH-73 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[72]); pthread_create( &Threads[ 72 ], NULL, spawn_function, (void *)&t_end[72]); }
	if( PTH-74 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[73]); pthread_create( &Threads[ 73 ], NULL, spawn_function, (void *)&t_end[73]); }
	if( PTH-75 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[74]); pthread_create( &Threads[ 74 ], NULL, spawn_function, (void *)&t_end[74]); }
	if( PTH-76 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[75]); pthread_create( &Threads[ 75 ], NULL, spawn_function, (void *)&t_end[75]); }
	if( PTH-77 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[76]); pthread_create( &Threads[ 76 ], NULL, spawn_function, (void *)&t_end[76]); }
	if( PTH-78 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[77]); pthread_create( &Threads[ 77 ], NULL, spawn_function, (void *)&t_end[77]); }
	if( PTH-79 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[78]); pthread_create( &Threads[ 78 ], NULL, spawn_function, (void *)&t_end[78]); }
	if( PTH-80 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[79]); pthread_create( &Threads[ 79 ], NULL, spawn_function, (void *)&t_end[79]); } // 80

	if( PTH-81 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[80]); pthread_create( &Threads[ 80 ], NULL, spawn_function, (void *)&t_end[80]); }
	if( PTH-82 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[81]); pthread_create( &Threads[ 81 ], NULL, spawn_function, (void *)&t_end[81]); }
	if( PTH-83 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[82]); pthread_create( &Threads[ 82 ], NULL, spawn_function, (void *)&t_end[82]); }
	if( PTH-84 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[83]); pthread_create( &Threads[ 83 ], NULL, spawn_function, (void *)&t_end[83]); }
	if( PTH-85 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[84]); pthread_create( &Threads[ 84 ], NULL, spawn_function, (void *)&t_end[84]); }
	if( PTH-86 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[85]); pthread_create( &Threads[ 85 ], NULL, spawn_function, (void *)&t_end[85]); }
	if( PTH-87 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[86]); pthread_create( &Threads[ 86 ], NULL, spawn_function, (void *)&t_end[86]); }
	if( PTH-88 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[87]); pthread_create( &Threads[ 87 ], NULL, spawn_function, (void *)&t_end[87]); }
	if( PTH-89 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[88]); pthread_create( &Threads[ 88 ], NULL, spawn_function, (void *)&t_end[88]); }
	if( PTH-90 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[89]); pthread_create( &Threads[ 89 ], NULL, spawn_function, (void *)&t_end[89]); } // 90

	if( PTH-91 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[90]); pthread_create( &Threads[ 90 ], NULL, spawn_function, (void *)&t_end[90]); }
	if( PTH-92 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[91]); pthread_create( &Threads[ 91 ], NULL, spawn_function, (void *)&t_end[91]); }
	if( PTH-93 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[92]); pthread_create( &Threads[ 92 ], NULL, spawn_function, (void *)&t_end[92]); }
	if( PTH-94 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[93]); pthread_create( &Threads[ 93 ], NULL, spawn_function, (void *)&t_end[93]); }
	if( PTH-95 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[94]); pthread_create( &Threads[ 94 ], NULL, spawn_function, (void *)&t_end[94]); }
	if( PTH-96 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[95]); pthread_create( &Threads[ 95 ], NULL, spawn_function, (void *)&t_end[95]); }
	if( PTH-97 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[96]); pthread_create( &Threads[ 96 ], NULL, spawn_function, (void *)&t_end[96]); }
	if( PTH-98 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[97]); pthread_create( &Threads[ 97 ], NULL, spawn_function, (void *)&t_end[97]); }
	if( PTH-99 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[98]); pthread_create( &Threads[ 98 ], NULL, spawn_function, (void *)&t_end[98]); }
	if( PTH-100 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[99]); pthread_create( &Threads[ 99 ], NULL, spawn_function, (void *)&t_end[99]); } // 100

	if( PTH-101 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[100]); pthread_create( &Threads[ 100 ], NULL, spawn_function, (void *)&t_end[100]); }
	if( PTH-102 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[101]); pthread_create( &Threads[ 101 ], NULL, spawn_function, (void *)&t_end[101]); }
	if( PTH-103 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[102]); pthread_create( &Threads[ 102 ], NULL, spawn_function, (void *)&t_end[102]); }
	if( PTH-104 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[103]); pthread_create( &Threads[ 103 ], NULL, spawn_function, (void *)&t_end[103]); }
	if( PTH-105 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[104]); pthread_create( &Threads[ 104 ], NULL, spawn_function, (void *)&t_end[104]); }
	if( PTH-106 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[105]); pthread_create( &Threads[ 105 ], NULL, spawn_function, (void *)&t_end[105]); }
	if( PTH-107 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[106]); pthread_create( &Threads[ 106 ], NULL, spawn_function, (void *)&t_end[106]); }
	if( PTH-108 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[107]); pthread_create( &Threads[ 107 ], NULL, spawn_function, (void *)&t_end[107]); }
	if( PTH-109 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[108]); pthread_create( &Threads[ 108 ], NULL, spawn_function, (void *)&t_end[108]); }
	if( PTH-110 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[109]); pthread_create( &Threads[ 109 ], NULL, spawn_function, (void *)&t_end[109]); } // 110

	if( PTH-111 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[110]); pthread_create( &Threads[ 110 ], NULL, spawn_function, (void *)&t_end[110]); }
	if( PTH-112 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[111]); pthread_create( &Threads[ 111 ], NULL, spawn_function, (void *)&t_end[111]); }
	if( PTH-113 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[112]); pthread_create( &Threads[ 112 ], NULL, spawn_function, (void *)&t_end[112]); }
	if( PTH-114 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[113]); pthread_create( &Threads[ 113 ], NULL, spawn_function, (void *)&t_end[113]); }
	if( PTH-115 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[114]); pthread_create( &Threads[ 114 ], NULL, spawn_function, (void *)&t_end[114]); }
	if( PTH-116 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[115]); pthread_create( &Threads[ 115 ], NULL, spawn_function, (void *)&t_end[115]); }
	if( PTH-117 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[116]); pthread_create( &Threads[ 116 ], NULL, spawn_function, (void *)&t_end[116]); }
	if( PTH-118 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[117]); pthread_create( &Threads[ 117 ], NULL, spawn_function, (void *)&t_end[117]); }
	if( PTH-119 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[118]); pthread_create( &Threads[ 118 ], NULL, spawn_function, (void *)&t_end[118]); }
	if( PTH-120 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[119]); pthread_create( &Threads[ 119 ], NULL, spawn_function, (void *)&t_end[119]); } // 120

	if( PTH-121 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[120]); pthread_create( &Threads[ 120 ], NULL, spawn_function, (void *)&t_end[120]); }
	if( PTH-122 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[121]); pthread_create( &Threads[ 121 ], NULL, spawn_function, (void *)&t_end[121]); }
	if( PTH-123 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[122]); pthread_create( &Threads[ 122 ], NULL, spawn_function, (void *)&t_end[122]); }
	if( PTH-124 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[123]); pthread_create( &Threads[ 123 ], NULL, spawn_function, (void *)&t_end[123]); }
	if( PTH-125 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[124]); pthread_create( &Threads[ 124 ], NULL, spawn_function, (void *)&t_end[124]); }
	if( PTH-126 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[125]); pthread_create( &Threads[ 125 ], NULL, spawn_function, (void *)&t_end[125]); }
	if( PTH-127 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[126]); pthread_create( &Threads[ 126 ], NULL, spawn_function, (void *)&t_end[126]); }
	if( PTH-128 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[127]); pthread_create( &Threads[ 127 ], NULL, spawn_function, (void *)&t_end[127]); }
	if( PTH-129 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[128]); pthread_create( &Threads[ 128 ], NULL, spawn_function, (void *)&t_end[128]); }
	if( PTH-130 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[129]); pthread_create( &Threads[ 129 ], NULL, spawn_function, (void *)&t_end[129]); } // 130

	if( PTH-131 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[130]); pthread_create( &Threads[ 130 ], NULL, spawn_function, (void *)&t_end[130]); }
	if( PTH-132 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[131]); pthread_create( &Threads[ 131 ], NULL, spawn_function, (void *)&t_end[131]); }
	if( PTH-133 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[132]); pthread_create( &Threads[ 132 ], NULL, spawn_function, (void *)&t_end[132]); }
	if( PTH-134 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[133]); pthread_create( &Threads[ 133 ], NULL, spawn_function, (void *)&t_end[133]); }
	if( PTH-135 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[134]); pthread_create( &Threads[ 134 ], NULL, spawn_function, (void *)&t_end[134]); }
	if( PTH-136 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[135]); pthread_create( &Threads[ 135 ], NULL, spawn_function, (void *)&t_end[135]); }
	if( PTH-137 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[136]); pthread_create( &Threads[ 136 ], NULL, spawn_function, (void *)&t_end[136]); }
	if( PTH-138 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[137]); pthread_create( &Threads[ 137 ], NULL, spawn_function, (void *)&t_end[137]); }
	if( PTH-139 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[138]); pthread_create( &Threads[ 138 ], NULL, spawn_function, (void *)&t_end[138]); }
	if( PTH-140 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[139]); pthread_create( &Threads[ 139 ], NULL, spawn_function, (void *)&t_end[139]); } // 140

	if( PTH-141 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[140]); pthread_create( &Threads[ 140 ], NULL, spawn_function, (void *)&t_end[140]); }
	if( PTH-142 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[141]); pthread_create( &Threads[ 141 ], NULL, spawn_function, (void *)&t_end[141]); }
	if( PTH-143 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[142]); pthread_create( &Threads[ 142 ], NULL, spawn_function, (void *)&t_end[142]); }
	if( PTH-144 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[143]); pthread_create( &Threads[ 143 ], NULL, spawn_function, (void *)&t_end[143]); }
	if( PTH-145 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[144]); pthread_create( &Threads[ 144 ], NULL, spawn_function, (void *)&t_end[144]); }
	if( PTH-146 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[145]); pthread_create( &Threads[ 145 ], NULL, spawn_function, (void *)&t_end[145]); }
	if( PTH-147 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[146]); pthread_create( &Threads[ 146 ], NULL, spawn_function, (void *)&t_end[146]); }
	if( PTH-148 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[147]); pthread_create( &Threads[ 147 ], NULL, spawn_function, (void *)&t_end[147]); }
	if( PTH-149 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[148]); pthread_create( &Threads[ 148 ], NULL, spawn_function, (void *)&t_end[148]); }
	if( PTH-150 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[149]); pthread_create( &Threads[ 149 ], NULL, spawn_function, (void *)&t_end[149]); } // 150

	if( PTH-151 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[150]); pthread_create( &Threads[ 150 ], NULL, spawn_function, (void *)&t_end[150]); }
	if( PTH-152 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[151]); pthread_create( &Threads[ 151 ], NULL, spawn_function, (void *)&t_end[151]); }
	if( PTH-153 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[152]); pthread_create( &Threads[ 152 ], NULL, spawn_function, (void *)&t_end[152]); }
	if( PTH-154 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[153]); pthread_create( &Threads[ 153 ], NULL, spawn_function, (void *)&t_end[153]); }
	if( PTH-155 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[154]); pthread_create( &Threads[ 154 ], NULL, spawn_function, (void *)&t_end[154]); }
	if( PTH-156 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[155]); pthread_create( &Threads[ 155 ], NULL, spawn_function, (void *)&t_end[155]); }
	if( PTH-157 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[156]); pthread_create( &Threads[ 156 ], NULL, spawn_function, (void *)&t_end[156]); }
	if( PTH-158 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[157]); pthread_create( &Threads[ 157 ], NULL, spawn_function, (void *)&t_end[157]); }
	if( PTH-159 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[158]); pthread_create( &Threads[ 158 ], NULL, spawn_function, (void *)&t_end[158]); }
	if( PTH-160 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[159]); pthread_create( &Threads[ 159 ], NULL, spawn_function, (void *)&t_end[159]); } // 160

	if( PTH-161 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[160]); pthread_create( &Threads[ 160 ], NULL, spawn_function, (void *)&t_end[160]); }
	if( PTH-162 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[161]); pthread_create( &Threads[ 161 ], NULL, spawn_function, (void *)&t_end[161]); }
	if( PTH-163 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[162]); pthread_create( &Threads[ 162 ], NULL, spawn_function, (void *)&t_end[162]); }
	if( PTH-164 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[163]); pthread_create( &Threads[ 163 ], NULL, spawn_function, (void *)&t_end[163]); }
	if( PTH-165 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[164]); pthread_create( &Threads[ 164 ], NULL, spawn_function, (void *)&t_end[164]); }
	if( PTH-166 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[165]); pthread_create( &Threads[ 165 ], NULL, spawn_function, (void *)&t_end[165]); }
	if( PTH-167 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[166]); pthread_create( &Threads[ 166 ], NULL, spawn_function, (void *)&t_end[166]); }
	if( PTH-168 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[167]); pthread_create( &Threads[ 167 ], NULL, spawn_function, (void *)&t_end[167]); }
	if( PTH-169 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[168]); pthread_create( &Threads[ 168 ], NULL, spawn_function, (void *)&t_end[168]); }
	if( PTH-170 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[169]); pthread_create( &Threads[ 169 ], NULL, spawn_function, (void *)&t_end[169]); } // 170

	if( PTH-171 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[170]); pthread_create( &Threads[ 170 ], NULL, spawn_function, (void *)&t_end[170]); }
	if( PTH-172 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[171]); pthread_create( &Threads[ 171 ], NULL, spawn_function, (void *)&t_end[171]); }
	if( PTH-173 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[172]); pthread_create( &Threads[ 172 ], NULL, spawn_function, (void *)&t_end[172]); }
	if( PTH-174 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[173]); pthread_create( &Threads[ 173 ], NULL, spawn_function, (void *)&t_end[173]); }
	if( PTH-175 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[174]); pthread_create( &Threads[ 174 ], NULL, spawn_function, (void *)&t_end[174]); }
	if( PTH-176 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[175]); pthread_create( &Threads[ 175 ], NULL, spawn_function, (void *)&t_end[175]); }
	if( PTH-177 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[176]); pthread_create( &Threads[ 176 ], NULL, spawn_function, (void *)&t_end[176]); }
	if( PTH-178 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[177]); pthread_create( &Threads[ 177 ], NULL, spawn_function, (void *)&t_end[177]); }
	if( PTH-179 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[178]); pthread_create( &Threads[ 178 ], NULL, spawn_function, (void *)&t_end[178]); }
	if( PTH-180 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[179]); pthread_create( &Threads[ 179 ], NULL, spawn_function, (void *)&t_end[179]); } // 180

	if( PTH-181 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[180]); pthread_create( &Threads[ 180 ], NULL, spawn_function, (void *)&t_end[180]); }
	if( PTH-182 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[181]); pthread_create( &Threads[ 181 ], NULL, spawn_function, (void *)&t_end[181]); }
	if( PTH-183 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[182]); pthread_create( &Threads[ 182 ], NULL, spawn_function, (void *)&t_end[182]); }
	if( PTH-184 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[183]); pthread_create( &Threads[ 183 ], NULL, spawn_function, (void *)&t_end[183]); }
	if( PTH-185 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[184]); pthread_create( &Threads[ 184 ], NULL, spawn_function, (void *)&t_end[184]); }
	if( PTH-186 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[185]); pthread_create( &Threads[ 185 ], NULL, spawn_function, (void *)&t_end[185]); }
	if( PTH-187 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[186]); pthread_create( &Threads[ 186 ], NULL, spawn_function, (void *)&t_end[186]); }
	if( PTH-188 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[187]); pthread_create( &Threads[ 187 ], NULL, spawn_function, (void *)&t_end[187]); }
	if( PTH-189 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[188]); pthread_create( &Threads[ 188 ], NULL, spawn_function, (void *)&t_end[188]); }
	if( PTH-190 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[189]); pthread_create( &Threads[ 189 ], NULL, spawn_function, (void *)&t_end[189]); } // 190

	if( PTH-191 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[190]); pthread_create( &Threads[ 190 ], NULL, spawn_function, (void *)&t_end[190]); }
	if( PTH-192 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[191]); pthread_create( &Threads[ 191 ], NULL, spawn_function, (void *)&t_end[191]); }
	if( PTH-193 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[192]); pthread_create( &Threads[ 192 ], NULL, spawn_function, (void *)&t_end[192]); }
	if( PTH-194 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[193]); pthread_create( &Threads[ 193 ], NULL, spawn_function, (void *)&t_end[193]); }
	if( PTH-195 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[194]); pthread_create( &Threads[ 194 ], NULL, spawn_function, (void *)&t_end[194]); }
	if( PTH-196 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[195]); pthread_create( &Threads[ 195 ], NULL, spawn_function, (void *)&t_end[195]); }
	if( PTH-197 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[196]); pthread_create( &Threads[ 196 ], NULL, spawn_function, (void *)&t_end[196]); }
	if( PTH-198 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[197]); pthread_create( &Threads[ 197 ], NULL, spawn_function, (void *)&t_end[197]); }
	if( PTH-199 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[198]); pthread_create( &Threads[ 198 ], NULL, spawn_function, (void *)&t_end[198]); }
	if( PTH-200 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[199]); pthread_create( &Threads[ 199 ], NULL, spawn_function, (void *)&t_end[199]); } // 200

	if( PTH-201 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[200]); pthread_create( &Threads[ 200 ], NULL, spawn_function, (void *)&t_end[200]); }
	if( PTH-202 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[201]); pthread_create( &Threads[ 201 ], NULL, spawn_function, (void *)&t_end[201]); }
	if( PTH-203 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[202]); pthread_create( &Threads[ 202 ], NULL, spawn_function, (void *)&t_end[202]); }
	if( PTH-204 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[203]); pthread_create( &Threads[ 203 ], NULL, spawn_function, (void *)&t_end[203]); }
	if( PTH-205 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[204]); pthread_create( &Threads[ 204 ], NULL, spawn_function, (void *)&t_end[204]); }
	if( PTH-206 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[205]); pthread_create( &Threads[ 205 ], NULL, spawn_function, (void *)&t_end[205]); }
	if( PTH-207 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[206]); pthread_create( &Threads[ 206 ], NULL, spawn_function, (void *)&t_end[206]); }
	if( PTH-208 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[207]); pthread_create( &Threads[ 207 ], NULL, spawn_function, (void *)&t_end[207]); }
	if( PTH-209 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[208]); pthread_create( &Threads[ 208 ], NULL, spawn_function, (void *)&t_end[208]); }
	if( PTH-210 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[209]); pthread_create( &Threads[ 209 ], NULL, spawn_function, (void *)&t_end[209]); } // 210

	if( PTH-211 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[210]); pthread_create( &Threads[ 210 ], NULL, spawn_function, (void *)&t_end[210]); }
	if( PTH-212 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[211]); pthread_create( &Threads[ 211 ], NULL, spawn_function, (void *)&t_end[211]); }
	if( PTH-213 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[212]); pthread_create( &Threads[ 212 ], NULL, spawn_function, (void *)&t_end[212]); }
	if( PTH-214 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[213]); pthread_create( &Threads[ 213 ], NULL, spawn_function, (void *)&t_end[213]); }
	if( PTH-215 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[214]); pthread_create( &Threads[ 214 ], NULL, spawn_function, (void *)&t_end[214]); }
	if( PTH-216 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[215]); pthread_create( &Threads[ 215 ], NULL, spawn_function, (void *)&t_end[215]); }
	if( PTH-217 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[216]); pthread_create( &Threads[ 216 ], NULL, spawn_function, (void *)&t_end[216]); }
	if( PTH-218 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[217]); pthread_create( &Threads[ 217 ], NULL, spawn_function, (void *)&t_end[217]); }
	if( PTH-219 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[218]); pthread_create( &Threads[ 218 ], NULL, spawn_function, (void *)&t_end[218]); }
	if( PTH-220 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[219]); pthread_create( &Threads[ 219 ], NULL, spawn_function, (void *)&t_end[219]); } // 220

	if( PTH-221 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[220]); pthread_create( &Threads[ 220 ], NULL, spawn_function, (void *)&t_end[220]); }
	if( PTH-222 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[221]); pthread_create( &Threads[ 221 ], NULL, spawn_function, (void *)&t_end[221]); }
	if( PTH-223 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[222]); pthread_create( &Threads[ 222 ], NULL, spawn_function, (void *)&t_end[222]); }
	if( PTH-224 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[223]); pthread_create( &Threads[ 223 ], NULL, spawn_function, (void *)&t_end[223]); }
	if( PTH-225 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[224]); pthread_create( &Threads[ 224 ], NULL, spawn_function, (void *)&t_end[224]); }
	if( PTH-226 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[225]); pthread_create( &Threads[ 225 ], NULL, spawn_function, (void *)&t_end[225]); }
	if( PTH-227 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[226]); pthread_create( &Threads[ 226 ], NULL, spawn_function, (void *)&t_end[226]); }
	if( PTH-228 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[227]); pthread_create( &Threads[ 227 ], NULL, spawn_function, (void *)&t_end[227]); }
	if( PTH-229 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[228]); pthread_create( &Threads[ 228 ], NULL, spawn_function, (void *)&t_end[228]); }
	if( PTH-230 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[229]); pthread_create( &Threads[ 229 ], NULL, spawn_function, (void *)&t_end[229]); } // 230

	if( PTH-231 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[230]); pthread_create( &Threads[ 230 ], NULL, spawn_function, (void *)&t_end[230]); }
	if( PTH-232 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[231]); pthread_create( &Threads[ 231 ], NULL, spawn_function, (void *)&t_end[231]); }
	if( PTH-233 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[232]); pthread_create( &Threads[ 232 ], NULL, spawn_function, (void *)&t_end[232]); }
	if( PTH-234 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[233]); pthread_create( &Threads[ 233 ], NULL, spawn_function, (void *)&t_end[233]); }
	if( PTH-235 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[234]); pthread_create( &Threads[ 234 ], NULL, spawn_function, (void *)&t_end[234]); }
	if( PTH-236 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[235]); pthread_create( &Threads[ 235 ], NULL, spawn_function, (void *)&t_end[235]); }
	if( PTH-237 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[236]); pthread_create( &Threads[ 236 ], NULL, spawn_function, (void *)&t_end[236]); }
	if( PTH-238 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[237]); pthread_create( &Threads[ 237 ], NULL, spawn_function, (void *)&t_end[237]); }
	if( PTH-239 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[238]); pthread_create( &Threads[ 238 ], NULL, spawn_function, (void *)&t_end[238]); }
	if( PTH-240 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[239]); pthread_create( &Threads[ 239 ], NULL, spawn_function, (void *)&t_end[239]); } // 240

	if( PTH-241 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[240]); pthread_create( &Threads[ 240 ], NULL, spawn_function, (void *)&t_end[240]); }
	if( PTH-242 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[241]); pthread_create( &Threads[ 241 ], NULL, spawn_function, (void *)&t_end[241]); }
	if( PTH-243 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[242]); pthread_create( &Threads[ 242 ], NULL, spawn_function, (void *)&t_end[242]); }
	if( PTH-244 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[243]); pthread_create( &Threads[ 243 ], NULL, spawn_function, (void *)&t_end[243]); }
	if( PTH-245 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[244]); pthread_create( &Threads[ 244 ], NULL, spawn_function, (void *)&t_end[244]); }
	if( PTH-246 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[245]); pthread_create( &Threads[ 245 ], NULL, spawn_function, (void *)&t_end[245]); }
	if( PTH-247 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[246]); pthread_create( &Threads[ 246 ], NULL, spawn_function, (void *)&t_end[246]); }
	if( PTH-248 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[247]); pthread_create( &Threads[ 247 ], NULL, spawn_function, (void *)&t_end[247]); }
	if( PTH-249 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[248]); pthread_create( &Threads[ 248 ], NULL, spawn_function, (void *)&t_end[248]); }
	if( PTH-250 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[249]); pthread_create( &Threads[ 249 ], NULL, spawn_function, (void *)&t_end[249]); } // 250

	if( PTH-251 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[250]); pthread_create( &Threads[ 250 ], NULL, spawn_function, (void *)&t_end[250]); }
	if( PTH-252 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[251]); pthread_create( &Threads[ 251 ], NULL, spawn_function, (void *)&t_end[251]); }
	if( PTH-253 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[252]); pthread_create( &Threads[ 252 ], NULL, spawn_function, (void *)&t_end[252]); }
	if( PTH-254 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[253]); pthread_create( &Threads[ 253 ], NULL, spawn_function, (void *)&t_end[253]); }
	if( PTH-255 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[254]); pthread_create( &Threads[ 254 ], NULL, spawn_function, (void *)&t_end[254]); }
	if( PTH-256 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[255]); pthread_create( &Threads[ 255 ], NULL, spawn_function, (void *)&t_end[255]); }
	if( PTH-257 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[256]); pthread_create( &Threads[ 256 ], NULL, spawn_function, (void *)&t_end[256]); }
	if( PTH-258 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[257]); pthread_create( &Threads[ 257 ], NULL, spawn_function, (void *)&t_end[257]); }
	if( PTH-259 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[258]); pthread_create( &Threads[ 258 ], NULL, spawn_function, (void *)&t_end[258]); }
	if( PTH-260 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[259]); pthread_create( &Threads[ 259 ], NULL, spawn_function, (void *)&t_end[259]); } // 260

	if( PTH-261 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[260]); pthread_create( &Threads[ 260 ], NULL, spawn_function, (void *)&t_end[260]); }
	if( PTH-262 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[261]); pthread_create( &Threads[ 261 ], NULL, spawn_function, (void *)&t_end[261]); }
	if( PTH-263 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[262]); pthread_create( &Threads[ 262 ], NULL, spawn_function, (void *)&t_end[262]); }
	if( PTH-264 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[263]); pthread_create( &Threads[ 263 ], NULL, spawn_function, (void *)&t_end[263]); }
	if( PTH-265 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[264]); pthread_create( &Threads[ 264 ], NULL, spawn_function, (void *)&t_end[264]); }
	if( PTH-266 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[265]); pthread_create( &Threads[ 265 ], NULL, spawn_function, (void *)&t_end[265]); }
	if( PTH-267 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[266]); pthread_create( &Threads[ 266 ], NULL, spawn_function, (void *)&t_end[266]); }
	if( PTH-268 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[267]); pthread_create( &Threads[ 267 ], NULL, spawn_function, (void *)&t_end[267]); }
	if( PTH-269 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[268]); pthread_create( &Threads[ 268 ], NULL, spawn_function, (void *)&t_end[268]); }
	if( PTH-269 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[269]); pthread_create( &Threads[ 269 ], NULL, spawn_function, (void *)&t_end[269]); } // 270

    if( PTH-271 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[270]); pthread_create( &Threads[ 270 ], NULL, spawn_function, (void *)&t_end[270]); }
	if( PTH-272 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[271]); pthread_create( &Threads[ 271 ], NULL, spawn_function, (void *)&t_end[271]); }
	if( PTH-273 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[272]); pthread_create( &Threads[ 272 ], NULL, spawn_function, (void *)&t_end[272]); }
	if( PTH-274 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[273]); pthread_create( &Threads[ 273 ], NULL, spawn_function, (void *)&t_end[273]); }
	if( PTH-275 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[274]); pthread_create( &Threads[ 274 ], NULL, spawn_function, (void *)&t_end[274]); }
	if( PTH-276 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[275]); pthread_create( &Threads[ 275 ], NULL, spawn_function, (void *)&t_end[275]); }
	if( PTH-277 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[276]); pthread_create( &Threads[ 276 ], NULL, spawn_function, (void *)&t_end[276]); }
	if( PTH-278 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[277]); pthread_create( &Threads[ 277 ], NULL, spawn_function, (void *)&t_end[277]); }
	if( PTH-279 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[278]); pthread_create( &Threads[ 278 ], NULL, spawn_function, (void *)&t_end[278]); }
	if( PTH-279 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[279]); pthread_create( &Threads[ 279 ], NULL, spawn_function, (void *)&t_end[279]); } // 280

    if( PTH-281 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[280]); pthread_create( &Threads[ 280 ], NULL, spawn_function, (void *)&t_end[280]); }
	if( PTH-282 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[281]); pthread_create( &Threads[ 281 ], NULL, spawn_function, (void *)&t_end[281]); }
	if( PTH-283 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[282]); pthread_create( &Threads[ 282 ], NULL, spawn_function, (void *)&t_end[282]); }
	if( PTH-284 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[283]); pthread_create( &Threads[ 283 ], NULL, spawn_function, (void *)&t_end[283]); }
	if( PTH-285 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[284]); pthread_create( &Threads[ 284 ], NULL, spawn_function, (void *)&t_end[284]); }
	if( PTH-286 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[285]); pthread_create( &Threads[ 285 ], NULL, spawn_function, (void *)&t_end[285]); }
	if( PTH-287 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[286]); pthread_create( &Threads[ 286 ], NULL, spawn_function, (void *)&t_end[286]); }
	if( PTH-288 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[287]); pthread_create( &Threads[ 287 ], NULL, spawn_function, (void *)&t_end[287]); }
	if( PTH-289 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[288]); pthread_create( &Threads[ 288 ], NULL, spawn_function, (void *)&t_end[288]); }
	if( PTH-289 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[289]); pthread_create( &Threads[ 289 ], NULL, spawn_function, (void *)&t_end[289]); } // 290
	
	if( PTH-291 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[290]); pthread_create( &Threads[ 290 ], NULL, spawn_function, (void *)&t_end[290]); }
	if( PTH-292 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[291]); pthread_create( &Threads[ 291 ], NULL, spawn_function, (void *)&t_end[291]); }
	if( PTH-293 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[292]); pthread_create( &Threads[ 292 ], NULL, spawn_function, (void *)&t_end[292]); }
	if( PTH-294 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[293]); pthread_create( &Threads[ 293 ], NULL, spawn_function, (void *)&t_end[293]); }
	if( PTH-295 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[294]); pthread_create( &Threads[ 294 ], NULL, spawn_function, (void *)&t_end[294]); }
	if( PTH-296 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[295]); pthread_create( &Threads[ 295 ], NULL, spawn_function, (void *)&t_end[295]); }
	if( PTH-297 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[296]); pthread_create( &Threads[ 296 ], NULL, spawn_function, (void *)&t_end[296]); }
	if( PTH-298 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[297]); pthread_create( &Threads[ 297 ], NULL, spawn_function, (void *)&t_end[297]); }
	if( PTH-299 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[298]); pthread_create( &Threads[ 298 ], NULL, spawn_function, (void *)&t_end[298]); }
	if( PTH-299 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[299]); pthread_create( &Threads[ 299 ], NULL, spawn_function, (void *)&t_end[299]); } // 300

	if( PTH-300 >= 0 ){ clock_gettime(CLOCK_MONOTONIC, &t_start[300]); pthread_create( &Threads[ 300 ], NULL, spawn_function, (void *)&t_end[300]); } // 301

	/****/
	struct timespec* temp = (struct timespec *)&t_end[0];

	pthread_join( Threads[ 0 ], (void *)&temp); temp = &t_end[1]; if(PTH-1 <= 0){ goto end; }
	pthread_join( Threads[ 1 ], (void *)&temp); temp = &t_end[2]; if(PTH-2 <= 0){ goto end; }
	pthread_join( Threads[ 2 ], (void *)&temp); temp = &t_end[3]; if(PTH-3 <= 0){ goto end; }
	pthread_join( Threads[ 3 ], (void *)&temp); temp = &t_end[4]; if(PTH-4 <= 0){ goto end; }
	pthread_join( Threads[ 4 ], (void *)&temp); temp = &t_end[5]; if(PTH-5 <= 0){ goto end; }
	pthread_join( Threads[ 5 ], (void *)&temp); temp = &t_end[6]; if(PTH-6 <= 0){ goto end; }
	pthread_join( Threads[ 6 ], (void *)&temp); temp = &t_end[7]; if(PTH-7 <= 0){ goto end; }
	pthread_join( Threads[ 7 ], (void *)&temp); temp = &t_end[8]; if(PTH-8 <= 0){ goto end; }
	pthread_join( Threads[ 8 ], (void *)&temp); temp = &t_end[9]; if(PTH-9 <= 0){ goto end; }
	pthread_join( Threads[ 9 ], (void *)&temp); temp = &t_end[10]; if(PTH-10 <= 0){ goto end; } // 10

	pthread_join( Threads[ 10 ], (void *)&temp); temp = &t_end[11]; if(PTH-11 <= 0){ goto end; }
	pthread_join( Threads[ 11 ], (void *)&temp); temp = &t_end[12]; if(PTH-12 <= 0){ goto end; }
	pthread_join( Threads[ 12 ], (void *)&temp); temp = &t_end[13]; if(PTH-13 <= 0){ goto end; }
	pthread_join( Threads[ 13 ], (void *)&temp); temp = &t_end[14]; if(PTH-14 <= 0){ goto end; }
	pthread_join( Threads[ 14 ], (void *)&temp); temp = &t_end[15]; if(PTH-15 <= 0){ goto end; }
	pthread_join( Threads[ 15 ], (void *)&temp); temp = &t_end[16]; if(PTH-16 <= 0){ goto end; }
	pthread_join( Threads[ 16 ], (void *)&temp); temp = &t_end[17]; if(PTH-17 <= 0){ goto end; }
	pthread_join( Threads[ 17 ], (void *)&temp); temp = &t_end[18]; if(PTH-18 <= 0){ goto end; }
	pthread_join( Threads[ 18 ], (void *)&temp); temp = &t_end[19]; if(PTH-19 <= 0){ goto end; }
	pthread_join( Threads[ 19 ], (void *)&temp); temp = &t_end[20]; if(PTH-20 <= 0){ goto end; } // 20

	pthread_join( Threads[ 20 ], (void *)&temp); temp = &t_end[21]; if(PTH-21 <= 0){ goto end; }
	pthread_join( Threads[ 21 ], (void *)&temp); temp = &t_end[22]; if(PTH-22 <= 0){ goto end; }
	pthread_join( Threads[ 22 ], (void *)&temp); temp = &t_end[23]; if(PTH-23 <= 0){ goto end; }
	pthread_join( Threads[ 23 ], (void *)&temp); temp = &t_end[24]; if(PTH-24 <= 0){ goto end; }
	pthread_join( Threads[ 24 ], (void *)&temp); temp = &t_end[25]; if(PTH-25 <= 0){ goto end; }
	pthread_join( Threads[ 25 ], (void *)&temp); temp = &t_end[26]; if(PTH-26 <= 0){ goto end; }
	pthread_join( Threads[ 26 ], (void *)&temp); temp = &t_end[27]; if(PTH-27 <= 0){ goto end; }
	pthread_join( Threads[ 27 ], (void *)&temp); temp = &t_end[28]; if(PTH-28 <= 0){ goto end; }
	pthread_join( Threads[ 28 ], (void *)&temp); temp = &t_end[29]; if(PTH-29 <= 0){ goto end; }
	pthread_join( Threads[ 29 ], (void *)&temp); temp = &t_end[30]; if(PTH-30 <= 0){ goto end; } // 30

	pthread_join( Threads[ 30 ], (void *)&temp); temp = &t_end[31]; if(PTH-31 <= 0){ goto end; }
	pthread_join( Threads[ 31 ], (void *)&temp); temp = &t_end[32]; if(PTH-32 <= 0){ goto end; }
	pthread_join( Threads[ 32 ], (void *)&temp); temp = &t_end[33]; if(PTH-33 <= 0){ goto end; }
	pthread_join( Threads[ 33 ], (void *)&temp); temp = &t_end[34]; if(PTH-34 <= 0){ goto end; }
	pthread_join( Threads[ 34 ], (void *)&temp); temp = &t_end[35]; if(PTH-35 <= 0){ goto end; }
	pthread_join( Threads[ 35 ], (void *)&temp); temp = &t_end[36]; if(PTH-36 <= 0){ goto end; }
	pthread_join( Threads[ 36 ], (void *)&temp); temp = &t_end[37]; if(PTH-37 <= 0){ goto end; }
	pthread_join( Threads[ 37 ], (void *)&temp); temp = &t_end[38]; if(PTH-38 <= 0){ goto end; }
	pthread_join( Threads[ 38 ], (void *)&temp); temp = &t_end[39]; if(PTH-39 <= 0){ goto end; }
	pthread_join( Threads[ 39 ], (void *)&temp); temp = &t_end[40]; if(PTH-40 <= 0){ goto end; } // 40

	pthread_join( Threads[ 40 ], (void *)&temp); temp = &t_end[41]; if(PTH-41 <= 0){ goto end; }
	pthread_join( Threads[ 41 ], (void *)&temp); temp = &t_end[42]; if(PTH-42 <= 0){ goto end; }
	pthread_join( Threads[ 42 ], (void *)&temp); temp = &t_end[43]; if(PTH-43 <= 0){ goto end; }
	pthread_join( Threads[ 43 ], (void *)&temp); temp = &t_end[44]; if(PTH-44 <= 0){ goto end; }
	pthread_join( Threads[ 44 ], (void *)&temp); temp = &t_end[45]; if(PTH-45 <= 0){ goto end; }
	pthread_join( Threads[ 45 ], (void *)&temp); temp = &t_end[46]; if(PTH-46 <= 0){ goto end; }
	pthread_join( Threads[ 46 ], (void *)&temp); temp = &t_end[47]; if(PTH-47 <= 0){ goto end; }
	pthread_join( Threads[ 47 ], (void *)&temp); temp = &t_end[48]; if(PTH-48 <= 0){ goto end; }
	pthread_join( Threads[ 48 ], (void *)&temp); temp = &t_end[49]; if(PTH-49 <= 0){ goto end; }
	pthread_join( Threads[ 49 ], (void *)&temp); temp = &t_end[50]; if(PTH-50 <= 0){ goto end; } // 50

	pthread_join( Threads[ 50 ], (void *)&temp); temp = &t_end[51]; if(PTH-51 <= 0){ goto end; }
	pthread_join( Threads[ 51 ], (void *)&temp); temp = &t_end[52]; if(PTH-52 <= 0){ goto end; }
	pthread_join( Threads[ 52 ], (void *)&temp); temp = &t_end[53]; if(PTH-53 <= 0){ goto end; }
	pthread_join( Threads[ 53 ], (void *)&temp); temp = &t_end[54]; if(PTH-54 <= 0){ goto end; }
	pthread_join( Threads[ 54 ], (void *)&temp); temp = &t_end[55]; if(PTH-55 <= 0){ goto end; }
	pthread_join( Threads[ 55 ], (void *)&temp); temp = &t_end[56]; if(PTH-56 <= 0){ goto end; }
	pthread_join( Threads[ 56 ], (void *)&temp); temp = &t_end[57]; if(PTH-57 <= 0){ goto end; }
	pthread_join( Threads[ 57 ], (void *)&temp); temp = &t_end[58]; if(PTH-58 <= 0){ goto end; }
	pthread_join( Threads[ 58 ], (void *)&temp); temp = &t_end[59]; if(PTH-59 <= 0){ goto end; }
	pthread_join( Threads[ 59 ], (void *)&temp); temp = &t_end[60]; if(PTH-60 <= 0){ goto end; } // 60

	pthread_join( Threads[ 60 ], (void *)&temp); temp = &t_end[61]; if(PTH-61 <= 0){ goto end; }
	pthread_join( Threads[ 61 ], (void *)&temp); temp = &t_end[62]; if(PTH-62 <= 0){ goto end; }
	pthread_join( Threads[ 62 ], (void *)&temp); temp = &t_end[63]; if(PTH-63 <= 0){ goto end; }
	pthread_join( Threads[ 63 ], (void *)&temp); temp = &t_end[64]; if(PTH-64 <= 0){ goto end; }
	pthread_join( Threads[ 64 ], (void *)&temp); temp = &t_end[65]; if(PTH-65 <= 0){ goto end; }
	pthread_join( Threads[ 65 ], (void *)&temp); temp = &t_end[66]; if(PTH-66 <= 0){ goto end; }
	pthread_join( Threads[ 66 ], (void *)&temp); temp = &t_end[67]; if(PTH-67 <= 0){ goto end; }
	pthread_join( Threads[ 67 ], (void *)&temp); temp = &t_end[68]; if(PTH-68 <= 0){ goto end; }
	pthread_join( Threads[ 68 ], (void *)&temp); temp = &t_end[69]; if(PTH-69 <= 0){ goto end; }
	pthread_join( Threads[ 69 ], (void *)&temp); temp = &t_end[70]; if(PTH-70 <= 0){ goto end; } // 70

	pthread_join( Threads[ 70 ], (void *)&temp); temp = &t_end[71]; if(PTH-71 <= 0){ goto end; }
	pthread_join( Threads[ 71 ], (void *)&temp); temp = &t_end[72]; if(PTH-72 <= 0){ goto end; }
	pthread_join( Threads[ 72 ], (void *)&temp); temp = &t_end[73]; if(PTH-73 <= 0){ goto end; }
	pthread_join( Threads[ 73 ], (void *)&temp); temp = &t_end[74]; if(PTH-74 <= 0){ goto end; }
	pthread_join( Threads[ 74 ], (void *)&temp); temp = &t_end[75]; if(PTH-75 <= 0){ goto end; }
	pthread_join( Threads[ 75 ], (void *)&temp); temp = &t_end[76]; if(PTH-76 <= 0){ goto end; }
	pthread_join( Threads[ 76 ], (void *)&temp); temp = &t_end[77]; if(PTH-77 <= 0){ goto end; }
	pthread_join( Threads[ 77 ], (void *)&temp); temp = &t_end[78]; if(PTH-78 <= 0){ goto end; }
	pthread_join( Threads[ 78 ], (void *)&temp); temp = &t_end[79]; if(PTH-79 <= 0){ goto end; }
	pthread_join( Threads[ 79 ], (void *)&temp); temp = &t_end[80]; if(PTH-80 <= 0){ goto end; } // 80

	pthread_join( Threads[ 80 ], (void *)&temp); temp = &t_end[81]; if(PTH-81 <= 0){ goto end; }
	pthread_join( Threads[ 81 ], (void *)&temp); temp = &t_end[82]; if(PTH-82 <= 0){ goto end; }
	pthread_join( Threads[ 82 ], (void *)&temp); temp = &t_end[83]; if(PTH-83 <= 0){ goto end; }
	pthread_join( Threads[ 83 ], (void *)&temp); temp = &t_end[84]; if(PTH-84 <= 0){ goto end; }
	pthread_join( Threads[ 84 ], (void *)&temp); temp = &t_end[85]; if(PTH-85 <= 0){ goto end; }
	pthread_join( Threads[ 85 ], (void *)&temp); temp = &t_end[86]; if(PTH-86 <= 0){ goto end; }
	pthread_join( Threads[ 86 ], (void *)&temp); temp = &t_end[87]; if(PTH-87 <= 0){ goto end; }
	pthread_join( Threads[ 87 ], (void *)&temp); temp = &t_end[88]; if(PTH-88 <= 0){ goto end; }
	pthread_join( Threads[ 88 ], (void *)&temp); temp = &t_end[89]; if(PTH-89 <= 0){ goto end; }
	pthread_join( Threads[ 89 ], (void *)&temp); temp = &t_end[90]; if(PTH-90 <= 0){ goto end; } // 90

	pthread_join( Threads[ 90 ], (void *)&temp); temp = &t_end[91]; if(PTH-91 <= 0){ goto end; }
	pthread_join( Threads[ 91 ], (void *)&temp); temp = &t_end[92]; if(PTH-92 <= 0){ goto end; }
	pthread_join( Threads[ 92 ], (void *)&temp); temp = &t_end[93]; if(PTH-93 <= 0){ goto end; }
	pthread_join( Threads[ 93 ], (void *)&temp); temp = &t_end[94]; if(PTH-94 <= 0){ goto end; }
	pthread_join( Threads[ 94 ], (void *)&temp); temp = &t_end[95]; if(PTH-95 <= 0){ goto end; }
	pthread_join( Threads[ 95 ], (void *)&temp); temp = &t_end[96]; if(PTH-96 <= 0){ goto end; }
	pthread_join( Threads[ 96 ], (void *)&temp); temp = &t_end[97]; if(PTH-97 <= 0){ goto end; }
	pthread_join( Threads[ 97 ], (void *)&temp); temp = &t_end[98]; if(PTH-98 <= 0){ goto end; }
	pthread_join( Threads[ 98 ], (void *)&temp); temp = &t_end[99]; if(PTH-99 <= 0){ goto end; }
	pthread_join( Threads[ 99 ], (void *)&temp); temp = &t_end[100]; if(PTH-100 <= 0){ goto end; } // 100

	pthread_join( Threads[ 100 ], (void *)&temp); temp = &t_end[101]; if(PTH-101 <= 0){ goto end; }
	pthread_join( Threads[ 101 ], (void *)&temp); temp = &t_end[102]; if(PTH-102 <= 0){ goto end; }
	pthread_join( Threads[ 102 ], (void *)&temp); temp = &t_end[103]; if(PTH-103 <= 0){ goto end; }
	pthread_join( Threads[ 103 ], (void *)&temp); temp = &t_end[104]; if(PTH-104 <= 0){ goto end; }
	pthread_join( Threads[ 104 ], (void *)&temp); temp = &t_end[105]; if(PTH-105 <= 0){ goto end; }
	pthread_join( Threads[ 105 ], (void *)&temp); temp = &t_end[106]; if(PTH-106 <= 0){ goto end; }
	pthread_join( Threads[ 106 ], (void *)&temp); temp = &t_end[107]; if(PTH-107 <= 0){ goto end; }
	pthread_join( Threads[ 107 ], (void *)&temp); temp = &t_end[108]; if(PTH-108 <= 0){ goto end; }
	pthread_join( Threads[ 108 ], (void *)&temp); temp = &t_end[109]; if(PTH-109 <= 0){ goto end; }
	pthread_join( Threads[ 109 ], (void *)&temp); temp = &t_end[110]; if(PTH-110 <= 0){ goto end; } // 110

	pthread_join( Threads[ 110 ], (void *)&temp); temp = &t_end[111]; if(PTH-111 <= 0){ goto end; }
	pthread_join( Threads[ 111 ], (void *)&temp); temp = &t_end[112]; if(PTH-112 <= 0){ goto end; }
	pthread_join( Threads[ 112 ], (void *)&temp); temp = &t_end[113]; if(PTH-113 <= 0){ goto end; }
	pthread_join( Threads[ 113 ], (void *)&temp); temp = &t_end[114]; if(PTH-114 <= 0){ goto end; }
	pthread_join( Threads[ 114 ], (void *)&temp); temp = &t_end[115]; if(PTH-115 <= 0){ goto end; }
	pthread_join( Threads[ 115 ], (void *)&temp); temp = &t_end[116]; if(PTH-116 <= 0){ goto end; }
	pthread_join( Threads[ 116 ], (void *)&temp); temp = &t_end[117]; if(PTH-117 <= 0){ goto end; }
	pthread_join( Threads[ 117 ], (void *)&temp); temp = &t_end[118]; if(PTH-118 <= 0){ goto end; }
	pthread_join( Threads[ 118 ], (void *)&temp); temp = &t_end[119]; if(PTH-119 <= 0){ goto end; }
	pthread_join( Threads[ 119 ], (void *)&temp); temp = &t_end[120]; if(PTH-120 <= 0){ goto end; } // 120

	pthread_join( Threads[ 120 ], (void *)&temp); temp = &t_end[121]; if(PTH-121 <= 0){ goto end; }
	pthread_join( Threads[ 121 ], (void *)&temp); temp = &t_end[122]; if(PTH-122 <= 0){ goto end; }
	pthread_join( Threads[ 122 ], (void *)&temp); temp = &t_end[123]; if(PTH-123 <= 0){ goto end; }
	pthread_join( Threads[ 123 ], (void *)&temp); temp = &t_end[124]; if(PTH-124 <= 0){ goto end; }
	pthread_join( Threads[ 124 ], (void *)&temp); temp = &t_end[125]; if(PTH-125 <= 0){ goto end; }
	pthread_join( Threads[ 125 ], (void *)&temp); temp = &t_end[126]; if(PTH-126 <= 0){ goto end; }
	pthread_join( Threads[ 126 ], (void *)&temp); temp = &t_end[127]; if(PTH-127 <= 0){ goto end; }
	pthread_join( Threads[ 127 ], (void *)&temp); temp = &t_end[128]; if(PTH-128 <= 0){ goto end; }
	pthread_join( Threads[ 128 ], (void *)&temp); temp = &t_end[129]; if(PTH-129 <= 0){ goto end; }
	pthread_join( Threads[ 129 ], (void *)&temp); temp = &t_end[130]; if(PTH-130 <= 0){ goto end; } // 130

	pthread_join( Threads[ 130 ], (void *)&temp); temp = &t_end[131]; if(PTH-131 <= 0){ goto end; }
	pthread_join( Threads[ 131 ], (void *)&temp); temp = &t_end[132]; if(PTH-132 <= 0){ goto end; }
	pthread_join( Threads[ 132 ], (void *)&temp); temp = &t_end[133]; if(PTH-133 <= 0){ goto end; }
	pthread_join( Threads[ 133 ], (void *)&temp); temp = &t_end[134]; if(PTH-134 <= 0){ goto end; }
	pthread_join( Threads[ 134 ], (void *)&temp); temp = &t_end[135]; if(PTH-135 <= 0){ goto end; }
	pthread_join( Threads[ 135 ], (void *)&temp); temp = &t_end[136]; if(PTH-136 <= 0){ goto end; }
	pthread_join( Threads[ 136 ], (void *)&temp); temp = &t_end[137]; if(PTH-137 <= 0){ goto end; }
	pthread_join( Threads[ 137 ], (void *)&temp); temp = &t_end[138]; if(PTH-138 <= 0){ goto end; }
	pthread_join( Threads[ 138 ], (void *)&temp); temp = &t_end[139]; if(PTH-139 <= 0){ goto end; }
	pthread_join( Threads[ 139 ], (void *)&temp); temp = &t_end[140]; if(PTH-140 <= 0){ goto end; } // 140

	pthread_join( Threads[ 140 ], (void *)&temp); temp = &t_end[141]; if(PTH-141 <= 0){ goto end; }
	pthread_join( Threads[ 141 ], (void *)&temp); temp = &t_end[142]; if(PTH-142 <= 0){ goto end; }
	pthread_join( Threads[ 142 ], (void *)&temp); temp = &t_end[143]; if(PTH-143 <= 0){ goto end; }
	pthread_join( Threads[ 143 ], (void *)&temp); temp = &t_end[144]; if(PTH-144 <= 0){ goto end; }
	pthread_join( Threads[ 144 ], (void *)&temp); temp = &t_end[145]; if(PTH-145 <= 0){ goto end; }
	pthread_join( Threads[ 145 ], (void *)&temp); temp = &t_end[146]; if(PTH-146 <= 0){ goto end; }
	pthread_join( Threads[ 146 ], (void *)&temp); temp = &t_end[147]; if(PTH-147 <= 0){ goto end; }
	pthread_join( Threads[ 147 ], (void *)&temp); temp = &t_end[148]; if(PTH-148 <= 0){ goto end; }
	pthread_join( Threads[ 148 ], (void *)&temp); temp = &t_end[149]; if(PTH-149 <= 0){ goto end; }
	pthread_join( Threads[ 149 ], (void *)&temp); temp = &t_end[150]; if(PTH-150 <= 0){ goto end; } // 150

	pthread_join( Threads[ 150 ], (void *)&temp); temp = &t_end[151]; if(PTH-151 <= 0){ goto end; }
	pthread_join( Threads[ 151 ], (void *)&temp); temp = &t_end[152]; if(PTH-152 <= 0){ goto end; }
	pthread_join( Threads[ 152 ], (void *)&temp); temp = &t_end[153]; if(PTH-153 <= 0){ goto end; }
	pthread_join( Threads[ 153 ], (void *)&temp); temp = &t_end[154]; if(PTH-154 <= 0){ goto end; }
	pthread_join( Threads[ 154 ], (void *)&temp); temp = &t_end[155]; if(PTH-155 <= 0){ goto end; }
	pthread_join( Threads[ 155 ], (void *)&temp); temp = &t_end[156]; if(PTH-156 <= 0){ goto end; }
	pthread_join( Threads[ 156 ], (void *)&temp); temp = &t_end[157]; if(PTH-157 <= 0){ goto end; }
	pthread_join( Threads[ 157 ], (void *)&temp); temp = &t_end[158]; if(PTH-158 <= 0){ goto end; }
	pthread_join( Threads[ 158 ], (void *)&temp); temp = &t_end[159]; if(PTH-159 <= 0){ goto end; }
	pthread_join( Threads[ 159 ], (void *)&temp); temp = &t_end[160]; if(PTH-160 <= 0){ goto end; } // 160

	pthread_join( Threads[ 160 ], (void *)&temp); temp = &t_end[161]; if(PTH-161 <= 0){ goto end; }
	pthread_join( Threads[ 161 ], (void *)&temp); temp = &t_end[162]; if(PTH-162 <= 0){ goto end; }
	pthread_join( Threads[ 162 ], (void *)&temp); temp = &t_end[163]; if(PTH-163 <= 0){ goto end; }
	pthread_join( Threads[ 163 ], (void *)&temp); temp = &t_end[164]; if(PTH-164 <= 0){ goto end; }
	pthread_join( Threads[ 164 ], (void *)&temp); temp = &t_end[165]; if(PTH-165 <= 0){ goto end; }
	pthread_join( Threads[ 165 ], (void *)&temp); temp = &t_end[166]; if(PTH-166 <= 0){ goto end; }
	pthread_join( Threads[ 166 ], (void *)&temp); temp = &t_end[167]; if(PTH-167 <= 0){ goto end; }
	pthread_join( Threads[ 167 ], (void *)&temp); temp = &t_end[168]; if(PTH-168 <= 0){ goto end; }
	pthread_join( Threads[ 168 ], (void *)&temp); temp = &t_end[169]; if(PTH-169 <= 0){ goto end; }
	pthread_join( Threads[ 169 ], (void *)&temp); temp = &t_end[170]; if(PTH-170 <= 0){ goto end; } // 170

	pthread_join( Threads[ 170 ], (void *)&temp); temp = &t_end[171]; if(PTH-171 <= 0){ goto end; }
	pthread_join( Threads[ 171 ], (void *)&temp); temp = &t_end[172]; if(PTH-172 <= 0){ goto end; }
	pthread_join( Threads[ 172 ], (void *)&temp); temp = &t_end[173]; if(PTH-173 <= 0){ goto end; }
	pthread_join( Threads[ 173 ], (void *)&temp); temp = &t_end[174]; if(PTH-174 <= 0){ goto end; }
	pthread_join( Threads[ 174 ], (void *)&temp); temp = &t_end[175]; if(PTH-175 <= 0){ goto end; }
	pthread_join( Threads[ 175 ], (void *)&temp); temp = &t_end[176]; if(PTH-176 <= 0){ goto end; }
	pthread_join( Threads[ 176 ], (void *)&temp); temp = &t_end[177]; if(PTH-177 <= 0){ goto end; }
	pthread_join( Threads[ 177 ], (void *)&temp); temp = &t_end[178]; if(PTH-178 <= 0){ goto end; }
	pthread_join( Threads[ 178 ], (void *)&temp); temp = &t_end[179]; if(PTH-179 <= 0){ goto end; }
	pthread_join( Threads[ 179 ], (void *)&temp); temp = &t_end[180]; if(PTH-180 <= 0){ goto end; } // 180

	pthread_join( Threads[ 180 ], (void *)&temp); temp = &t_end[181]; if(PTH-181 <= 0){ goto end; }
	pthread_join( Threads[ 181 ], (void *)&temp); temp = &t_end[182]; if(PTH-182 <= 0){ goto end; }
	pthread_join( Threads[ 182 ], (void *)&temp); temp = &t_end[183]; if(PTH-183 <= 0){ goto end; }
	pthread_join( Threads[ 183 ], (void *)&temp); temp = &t_end[184]; if(PTH-184 <= 0){ goto end; }
	pthread_join( Threads[ 184 ], (void *)&temp); temp = &t_end[185]; if(PTH-185 <= 0){ goto end; }
	pthread_join( Threads[ 185 ], (void *)&temp); temp = &t_end[186]; if(PTH-186 <= 0){ goto end; }
	pthread_join( Threads[ 186 ], (void *)&temp); temp = &t_end[187]; if(PTH-187 <= 0){ goto end; }
	pthread_join( Threads[ 187 ], (void *)&temp); temp = &t_end[188]; if(PTH-188 <= 0){ goto end; }
	pthread_join( Threads[ 188 ], (void *)&temp); temp = &t_end[189]; if(PTH-189 <= 0){ goto end; }
	pthread_join( Threads[ 189 ], (void *)&temp); temp = &t_end[190]; if(PTH-190 <= 0){ goto end; } // 190

	pthread_join( Threads[ 190 ], (void *)&temp); temp = &t_end[191]; if(PTH-191 <= 0){ goto end; }
	pthread_join( Threads[ 191 ], (void *)&temp); temp = &t_end[192]; if(PTH-192 <= 0){ goto end; }
	pthread_join( Threads[ 192 ], (void *)&temp); temp = &t_end[193]; if(PTH-193 <= 0){ goto end; }
	pthread_join( Threads[ 193 ], (void *)&temp); temp = &t_end[194]; if(PTH-194 <= 0){ goto end; }
	pthread_join( Threads[ 194 ], (void *)&temp); temp = &t_end[195]; if(PTH-195 <= 0){ goto end; }
	pthread_join( Threads[ 195 ], (void *)&temp); temp = &t_end[196]; if(PTH-196 <= 0){ goto end; }
	pthread_join( Threads[ 196 ], (void *)&temp); temp = &t_end[197]; if(PTH-197 <= 0){ goto end; }
	pthread_join( Threads[ 197 ], (void *)&temp); temp = &t_end[198]; if(PTH-198 <= 0){ goto end; }
	pthread_join( Threads[ 198 ], (void *)&temp); temp = &t_end[199]; if(PTH-199 <= 0){ goto end; }
	pthread_join( Threads[ 199 ], (void *)&temp); temp = &t_end[200]; if(PTH-200 <= 0){ goto end; } // 200

	pthread_join( Threads[ 200 ], (void *)&temp); temp = &t_end[201]; if(PTH-201 <= 0){ goto end; }
	pthread_join( Threads[ 201 ], (void *)&temp); temp = &t_end[202]; if(PTH-202 <= 0){ goto end; }
	pthread_join( Threads[ 202 ], (void *)&temp); temp = &t_end[203]; if(PTH-203 <= 0){ goto end; }
	pthread_join( Threads[ 203 ], (void *)&temp); temp = &t_end[204]; if(PTH-204 <= 0){ goto end; }
	pthread_join( Threads[ 204 ], (void *)&temp); temp = &t_end[205]; if(PTH-205 <= 0){ goto end; }
	pthread_join( Threads[ 205 ], (void *)&temp); temp = &t_end[206]; if(PTH-206 <= 0){ goto end; }
	pthread_join( Threads[ 206 ], (void *)&temp); temp = &t_end[207]; if(PTH-207 <= 0){ goto end; }
	pthread_join( Threads[ 207 ], (void *)&temp); temp = &t_end[208]; if(PTH-208 <= 0){ goto end; }
	pthread_join( Threads[ 208 ], (void *)&temp); temp = &t_end[209]; if(PTH-209 <= 0){ goto end; }
	pthread_join( Threads[ 209 ], (void *)&temp); temp = &t_end[210]; if(PTH-210 <= 0){ goto end; } // 210

	pthread_join( Threads[ 210 ], (void *)&temp); temp = &t_end[211]; if(PTH-211 <= 0){ goto end; }
	pthread_join( Threads[ 211 ], (void *)&temp); temp = &t_end[212]; if(PTH-212 <= 0){ goto end; }
	pthread_join( Threads[ 212 ], (void *)&temp); temp = &t_end[213]; if(PTH-213 <= 0){ goto end; }
	pthread_join( Threads[ 213 ], (void *)&temp); temp = &t_end[214]; if(PTH-214 <= 0){ goto end; }
	pthread_join( Threads[ 214 ], (void *)&temp); temp = &t_end[215]; if(PTH-215 <= 0){ goto end; }
	pthread_join( Threads[ 215 ], (void *)&temp); temp = &t_end[216]; if(PTH-216 <= 0){ goto end; }
	pthread_join( Threads[ 216 ], (void *)&temp); temp = &t_end[217]; if(PTH-217 <= 0){ goto end; }
	pthread_join( Threads[ 217 ], (void *)&temp); temp = &t_end[218]; if(PTH-218 <= 0){ goto end; }
	pthread_join( Threads[ 218 ], (void *)&temp); temp = &t_end[219]; if(PTH-219 <= 0){ goto end; }
	pthread_join( Threads[ 219 ], (void *)&temp); temp = &t_end[220]; if(PTH-220 <= 0){ goto end; } // 220

	pthread_join( Threads[ 220 ], (void *)&temp); temp = &t_end[221]; if(PTH-221 <= 0){ goto end; }
	pthread_join( Threads[ 221 ], (void *)&temp); temp = &t_end[222]; if(PTH-222 <= 0){ goto end; }
	pthread_join( Threads[ 222 ], (void *)&temp); temp = &t_end[223]; if(PTH-223 <= 0){ goto end; }
	pthread_join( Threads[ 223 ], (void *)&temp); temp = &t_end[224]; if(PTH-224 <= 0){ goto end; }
	pthread_join( Threads[ 224 ], (void *)&temp); temp = &t_end[225]; if(PTH-225 <= 0){ goto end; }
	pthread_join( Threads[ 225 ], (void *)&temp); temp = &t_end[226]; if(PTH-226 <= 0){ goto end; }
	pthread_join( Threads[ 226 ], (void *)&temp); temp = &t_end[227]; if(PTH-227 <= 0){ goto end; }
	pthread_join( Threads[ 227 ], (void *)&temp); temp = &t_end[228]; if(PTH-228 <= 0){ goto end; }
	pthread_join( Threads[ 228 ], (void *)&temp); temp = &t_end[229]; if(PTH-229 <= 0){ goto end; }
	pthread_join( Threads[ 229 ], (void *)&temp); temp = &t_end[230]; if(PTH-230 <= 0){ goto end; } // 230

	pthread_join( Threads[ 230 ], (void *)&temp); temp = &t_end[231]; if(PTH-231 <= 0){ goto end; }
	pthread_join( Threads[ 231 ], (void *)&temp); temp = &t_end[232]; if(PTH-232 <= 0){ goto end; }
	pthread_join( Threads[ 232 ], (void *)&temp); temp = &t_end[233]; if(PTH-233 <= 0){ goto end; }
	pthread_join( Threads[ 233 ], (void *)&temp); temp = &t_end[234]; if(PTH-234 <= 0){ goto end; }
	pthread_join( Threads[ 234 ], (void *)&temp); temp = &t_end[235]; if(PTH-235 <= 0){ goto end; }
	pthread_join( Threads[ 235 ], (void *)&temp); temp = &t_end[236]; if(PTH-236 <= 0){ goto end; }
	pthread_join( Threads[ 236 ], (void *)&temp); temp = &t_end[237]; if(PTH-237 <= 0){ goto end; }
	pthread_join( Threads[ 237 ], (void *)&temp); temp = &t_end[238]; if(PTH-238 <= 0){ goto end; }
	pthread_join( Threads[ 238 ], (void *)&temp); temp = &t_end[239]; if(PTH-239 <= 0){ goto end; }
	pthread_join( Threads[ 239 ], (void *)&temp); temp = &t_end[240]; if(PTH-240 <= 0){ goto end; } // 240

	pthread_join( Threads[ 240 ], (void *)&temp); temp = &t_end[241]; if(PTH-241 <= 0){ goto end; }
	pthread_join( Threads[ 241 ], (void *)&temp); temp = &t_end[242]; if(PTH-242 <= 0){ goto end; }
	pthread_join( Threads[ 242 ], (void *)&temp); temp = &t_end[243]; if(PTH-243 <= 0){ goto end; }
	pthread_join( Threads[ 243 ], (void *)&temp); temp = &t_end[244]; if(PTH-244 <= 0){ goto end; }
	pthread_join( Threads[ 244 ], (void *)&temp); temp = &t_end[245]; if(PTH-245 <= 0){ goto end; }
	pthread_join( Threads[ 245 ], (void *)&temp); temp = &t_end[246]; if(PTH-246 <= 0){ goto end; }
	pthread_join( Threads[ 246 ], (void *)&temp); temp = &t_end[247]; if(PTH-247 <= 0){ goto end; }
	pthread_join( Threads[ 247 ], (void *)&temp); temp = &t_end[248]; if(PTH-248 <= 0){ goto end; }
	pthread_join( Threads[ 248 ], (void *)&temp); temp = &t_end[249]; if(PTH-249 <= 0){ goto end; }
	pthread_join( Threads[ 249 ], (void *)&temp); temp = &t_end[250]; if(PTH-250 <= 0){ goto end; } // 250

	pthread_join( Threads[ 250 ], (void *)&temp); temp = &t_end[251]; if(PTH-251 <= 0){ goto end; }
	pthread_join( Threads[ 251 ], (void *)&temp); temp = &t_end[252]; if(PTH-252 <= 0){ goto end; }
	pthread_join( Threads[ 252 ], (void *)&temp); temp = &t_end[253]; if(PTH-253 <= 0){ goto end; }
	pthread_join( Threads[ 253 ], (void *)&temp); temp = &t_end[254]; if(PTH-254 <= 0){ goto end; }
	pthread_join( Threads[ 254 ], (void *)&temp); temp = &t_end[255]; if(PTH-255 <= 0){ goto end; }
	pthread_join( Threads[ 255 ], (void *)&temp); temp = &t_end[256]; if(PTH-256 <= 0){ goto end; }
	pthread_join( Threads[ 256 ], (void *)&temp); temp = &t_end[257]; if(PTH-257 <= 0){ goto end; }
	pthread_join( Threads[ 257 ], (void *)&temp); temp = &t_end[258]; if(PTH-258 <= 0){ goto end; }
	pthread_join( Threads[ 258 ], (void *)&temp); temp = &t_end[259]; if(PTH-259 <= 0){ goto end; }
	pthread_join( Threads[ 259 ], (void *)&temp); temp = &t_end[260]; if(PTH-260 <= 0){ goto end; } // 260

	pthread_join( Threads[ 260 ], (void *)&temp); temp = &t_end[261]; if(PTH-261 <= 0){ goto end; }
	pthread_join( Threads[ 261 ], (void *)&temp); temp = &t_end[262]; if(PTH-262 <= 0){ goto end; }
	pthread_join( Threads[ 262 ], (void *)&temp); temp = &t_end[263]; if(PTH-263 <= 0){ goto end; }
	pthread_join( Threads[ 263 ], (void *)&temp); temp = &t_end[264]; if(PTH-264 <= 0){ goto end; }
	pthread_join( Threads[ 264 ], (void *)&temp); temp = &t_end[265]; if(PTH-265 <= 0){ goto end; }
	pthread_join( Threads[ 265 ], (void *)&temp); temp = &t_end[266]; if(PTH-266 <= 0){ goto end; }
	pthread_join( Threads[ 266 ], (void *)&temp); temp = &t_end[267]; if(PTH-267 <= 0){ goto end; }
	pthread_join( Threads[ 267 ], (void *)&temp); temp = &t_end[268]; if(PTH-268 <= 0){ goto end; }
	pthread_join( Threads[ 268 ], (void *)&temp); temp = &t_end[269]; if(PTH-269 <= 0){ goto end; }
	pthread_join( Threads[ 269 ], (void *)&temp); temp = &t_end[270]; if(PTH-270 <= 0){ goto end; } // 270

	pthread_join( Threads[ 270 ], (void *)&temp); temp = &t_end[271]; if(PTH-271 <= 0){ goto end; }
	pthread_join( Threads[ 271 ], (void *)&temp); temp = &t_end[272]; if(PTH-272 <= 0){ goto end; }
	pthread_join( Threads[ 272 ], (void *)&temp); temp = &t_end[273]; if(PTH-273 <= 0){ goto end; }
	pthread_join( Threads[ 273 ], (void *)&temp); temp = &t_end[274]; if(PTH-274 <= 0){ goto end; }
	pthread_join( Threads[ 274 ], (void *)&temp); temp = &t_end[275]; if(PTH-275 <= 0){ goto end; }
	pthread_join( Threads[ 275 ], (void *)&temp); temp = &t_end[276]; if(PTH-276 <= 0){ goto end; }
	pthread_join( Threads[ 276 ], (void *)&temp); temp = &t_end[277]; if(PTH-277 <= 0){ goto end; }
	pthread_join( Threads[ 277 ], (void *)&temp); temp = &t_end[278]; if(PTH-278 <= 0){ goto end; }
	pthread_join( Threads[ 278 ], (void *)&temp); temp = &t_end[279]; if(PTH-279 <= 0){ goto end; }
	pthread_join( Threads[ 279 ], (void *)&temp); temp = &t_end[270]; if(PTH-270 <= 0){ goto end; } // 280

    pthread_join( Threads[ 280 ], (void *)&temp); temp = &t_end[281]; if(PTH-281 <= 0){ goto end; }
	pthread_join( Threads[ 281 ], (void *)&temp); temp = &t_end[282]; if(PTH-282 <= 0){ goto end; }
	pthread_join( Threads[ 282 ], (void *)&temp); temp = &t_end[283]; if(PTH-283 <= 0){ goto end; }
	pthread_join( Threads[ 283 ], (void *)&temp); temp = &t_end[284]; if(PTH-284 <= 0){ goto end; }
	pthread_join( Threads[ 284 ], (void *)&temp); temp = &t_end[285]; if(PTH-285 <= 0){ goto end; }
	pthread_join( Threads[ 285 ], (void *)&temp); temp = &t_end[286]; if(PTH-286 <= 0){ goto end; }
	pthread_join( Threads[ 286 ], (void *)&temp); temp = &t_end[287]; if(PTH-287 <= 0){ goto end; }
	pthread_join( Threads[ 287 ], (void *)&temp); temp = &t_end[288]; if(PTH-288 <= 0){ goto end; }
	pthread_join( Threads[ 288 ], (void *)&temp); temp = &t_end[289]; if(PTH-289 <= 0){ goto end; }
	pthread_join( Threads[ 289 ], (void *)&temp); temp = &t_end[280]; if(PTH-280 <= 0){ goto end; } // 290

    pthread_join( Threads[ 290 ], (void *)&temp); temp = &t_end[291]; if(PTH-291 <= 0){ goto end; }
	pthread_join( Threads[ 291 ], (void *)&temp); temp = &t_end[292]; if(PTH-292 <= 0){ goto end; }
	pthread_join( Threads[ 292 ], (void *)&temp); temp = &t_end[293]; if(PTH-293 <= 0){ goto end; }
	pthread_join( Threads[ 293 ], (void *)&temp); temp = &t_end[294]; if(PTH-294 <= 0){ goto end; }
	pthread_join( Threads[ 294 ], (void *)&temp); temp = &t_end[295]; if(PTH-295 <= 0){ goto end; }
	pthread_join( Threads[ 295 ], (void *)&temp); temp = &t_end[296]; if(PTH-296 <= 0){ goto end; }
	pthread_join( Threads[ 296 ], (void *)&temp); temp = &t_end[297]; if(PTH-297 <= 0){ goto end; }
	pthread_join( Threads[ 297 ], (void *)&temp); temp = &t_end[298]; if(PTH-298 <= 0){ goto end; }
	pthread_join( Threads[ 298 ], (void *)&temp); temp = &t_end[299]; if(PTH-299 <= 0){ goto end; }
	pthread_join( Threads[ 299 ], (void *)&temp); temp = &t_end[290]; if(PTH-290 <= 0){ goto end; } // 300

    pthread_join( Threads[ 300 ], (void *)&temp); temp = &t_end[300]; if(PTH-300 <= 0){ goto end; } // 301

end:

	/****/

	for(int i = 0; i < PTH; i++){

		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	}
			
	return 0;
}