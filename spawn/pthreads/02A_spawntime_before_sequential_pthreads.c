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
/* Benchmark: 02A Spawn time before ; Sequential Spawns (Pthreads)
 * Launch a bunch and measure when all done 
 */

pthread_barrier_t sync_barrier; /* to sync */

void* spawn_function(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	// pthread_barrier_wait 
	pthread_barrier_wait(&sync_barrier);

	return (void*) NULL; 
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

	int ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

	pthread_t Threads[ PTH ];

	// pthread_barrier_init
	pthread_barrier_init(&sync_barrier, NULL, PTH+1);

	struct timespec t_start, t_res;
	struct timespec t_end[PTH];
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 
    
	if(PTH-1 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[0] ); pthread_create( &Threads[ 0 ], &attr, spawn_function, NULL); }
	if(PTH-2 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[1] ); pthread_create( &Threads[ 1 ], &attr, spawn_function, NULL); }
	if(PTH-3 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[2] ); pthread_create( &Threads[ 2 ], &attr, spawn_function, NULL); }
	if(PTH-4 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[3] ); pthread_create( &Threads[ 3 ], &attr, spawn_function, NULL); }
	if(PTH-5 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[4] ); pthread_create( &Threads[ 4 ], &attr, spawn_function, NULL); }
	if(PTH-6 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[5] ); pthread_create( &Threads[ 5 ], &attr, spawn_function, NULL); }
	if(PTH-7 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[6] ); pthread_create( &Threads[ 6 ], &attr, spawn_function, NULL); }
	if(PTH-8 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[7] ); pthread_create( &Threads[ 7 ], &attr, spawn_function, NULL); }
	if(PTH-9 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[8] ); pthread_create( &Threads[ 8 ], &attr, spawn_function, NULL); } 
	if(PTH-10 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[9] ); pthread_create( &Threads[ 9 ], &attr, spawn_function, NULL); } // 10

	if(PTH-11 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[10] ); pthread_create( &Threads[ 10 ], &attr, spawn_function, NULL); }
	if(PTH-12 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[11] ); pthread_create( &Threads[ 11 ], &attr, spawn_function, NULL); }
	if(PTH-13 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[12] ); pthread_create( &Threads[ 12 ], &attr, spawn_function, NULL); }
	if(PTH-14 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[13] ); pthread_create( &Threads[ 13 ], &attr, spawn_function, NULL); }
	if(PTH-15 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[14] ); pthread_create( &Threads[ 14 ], &attr, spawn_function, NULL); }
	if(PTH-16 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[15] ); pthread_create( &Threads[ 15 ], &attr, spawn_function, NULL); }
	if(PTH-17 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[16] ); pthread_create( &Threads[ 16 ], &attr, spawn_function, NULL); }
	if(PTH-18 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[17] ); pthread_create( &Threads[ 17 ], &attr, spawn_function, NULL); }
	if(PTH-19 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[18] ); pthread_create( &Threads[ 18 ], &attr, spawn_function, NULL); }
	if(PTH-20 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[19] ); pthread_create( &Threads[ 19 ], &attr, spawn_function, NULL); } // 20

	if(PTH-21 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[20] ); pthread_create( &Threads[ 20 ], &attr, spawn_function, NULL); }
	if(PTH-22 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[21] ); pthread_create( &Threads[ 21 ], &attr, spawn_function, NULL); }
	if(PTH-23 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[22] ); pthread_create( &Threads[ 22 ], &attr, spawn_function, NULL); }
	if(PTH-24 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[23] ); pthread_create( &Threads[ 23 ], &attr, spawn_function, NULL); }
	if(PTH-25 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[24] ); pthread_create( &Threads[ 24 ], &attr, spawn_function, NULL); }
	if(PTH-26 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[25] ); pthread_create( &Threads[ 25 ], &attr, spawn_function, NULL); }
	if(PTH-27 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[26] ); pthread_create( &Threads[ 26 ], &attr, spawn_function, NULL); }
	if(PTH-28 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[27] ); pthread_create( &Threads[ 27 ], &attr, spawn_function, NULL); }
	if(PTH-29 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[28] ); pthread_create( &Threads[ 28 ], &attr, spawn_function, NULL); }
	if(PTH-30 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[29] ); pthread_create( &Threads[ 29 ], &attr, spawn_function, NULL); } // 30

	if(PTH-31 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[30] ); pthread_create( &Threads[ 30 ], &attr, spawn_function, NULL); }
	if(PTH-32 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[31] ); pthread_create( &Threads[ 31 ], &attr, spawn_function, NULL); }
	if(PTH-33 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[32] ); pthread_create( &Threads[ 32 ], &attr, spawn_function, NULL); }
	if(PTH-34 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[33] ); pthread_create( &Threads[ 33 ], &attr, spawn_function, NULL); }
	if(PTH-35 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[34] ); pthread_create( &Threads[ 34 ], &attr, spawn_function, NULL); }
	if(PTH-36 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[35] ); pthread_create( &Threads[ 35 ], &attr, spawn_function, NULL); }
	if(PTH-37 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[36] ); pthread_create( &Threads[ 36 ], &attr, spawn_function, NULL); }
	if(PTH-38 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[37] ); pthread_create( &Threads[ 37 ], &attr, spawn_function, NULL); }
	if(PTH-39 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[38] ); pthread_create( &Threads[ 38 ], &attr, spawn_function, NULL); }
	if(PTH-40 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[39] ); pthread_create( &Threads[ 39 ], &attr, spawn_function, NULL); } // 40

	if(PTH-41 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[40] ); pthread_create( &Threads[ 40 ], &attr, spawn_function, NULL); }
	if(PTH-42 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[41] ); pthread_create( &Threads[ 41 ], &attr, spawn_function, NULL); }
	if(PTH-43 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[42] ); pthread_create( &Threads[ 42 ], &attr, spawn_function, NULL); }
	if(PTH-44 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[43] ); pthread_create( &Threads[ 43 ], &attr, spawn_function, NULL); }
	if(PTH-45 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[44] ); pthread_create( &Threads[ 44 ], &attr, spawn_function, NULL); }
	if(PTH-46 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[45] ); pthread_create( &Threads[ 45 ], &attr, spawn_function, NULL); }
	if(PTH-47 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[46] ); pthread_create( &Threads[ 46 ], &attr, spawn_function, NULL); }
	if(PTH-48 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[47] ); pthread_create( &Threads[ 47 ], &attr, spawn_function, NULL); }
	if(PTH-49 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[48] ); pthread_create( &Threads[ 48 ], &attr, spawn_function, NULL); }
	if(PTH-50 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[49] ); pthread_create( &Threads[ 49 ], &attr, spawn_function, NULL); } // 50

	if(PTH-51 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[50] ); pthread_create( &Threads[ 50 ], &attr, spawn_function, NULL); }
	if(PTH-52 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[51] ); pthread_create( &Threads[ 51 ], &attr, spawn_function, NULL); }
	if(PTH-53 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[52] ); pthread_create( &Threads[ 52 ], &attr, spawn_function, NULL); }
	if(PTH-54 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[53] ); pthread_create( &Threads[ 53 ], &attr, spawn_function, NULL); }
	if(PTH-55 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[54] ); pthread_create( &Threads[ 54 ], &attr, spawn_function, NULL); }
	if(PTH-56 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[55] ); pthread_create( &Threads[ 55 ], &attr, spawn_function, NULL); }
	if(PTH-57 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[56] ); pthread_create( &Threads[ 56 ], &attr, spawn_function, NULL); }
	if(PTH-58 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[57] ); pthread_create( &Threads[ 57 ], &attr, spawn_function, NULL); }
	if(PTH-59 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[58] ); pthread_create( &Threads[ 58 ], &attr, spawn_function, NULL); }
	if(PTH-60 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[59] ); pthread_create( &Threads[ 59 ], &attr, spawn_function, NULL); } // 60

	if(PTH-61 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[60] ); pthread_create( &Threads[ 60 ], &attr, spawn_function, NULL); }
	if(PTH-62 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[61] ); pthread_create( &Threads[ 61 ], &attr, spawn_function, NULL); }
	if(PTH-63 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[62] ); pthread_create( &Threads[ 62 ], &attr, spawn_function, NULL); }
	if(PTH-64 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[63] ); pthread_create( &Threads[ 63 ], &attr, spawn_function, NULL); }
	if(PTH-65 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[64] ); pthread_create( &Threads[ 64 ], &attr, spawn_function, NULL); }
	if(PTH-66 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[65] ); pthread_create( &Threads[ 65 ], &attr, spawn_function, NULL); }
	if(PTH-67 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[66] ); pthread_create( &Threads[ 66 ], &attr, spawn_function, NULL); }
	if(PTH-68 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[67] ); pthread_create( &Threads[ 67 ], &attr, spawn_function, NULL); }
	if(PTH-69 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[68] ); pthread_create( &Threads[ 68 ], &attr, spawn_function, NULL); }
	if(PTH-70 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[69] ); pthread_create( &Threads[ 69 ], &attr, spawn_function, NULL); } // 70

	if(PTH-71 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[70] ); pthread_create( &Threads[ 70 ], &attr, spawn_function, NULL); }
	if(PTH-72 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[71] ); pthread_create( &Threads[ 71 ], &attr, spawn_function, NULL); }
	if(PTH-73 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[72] ); pthread_create( &Threads[ 72 ], &attr, spawn_function, NULL); }
	if(PTH-74 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[73] ); pthread_create( &Threads[ 73 ], &attr, spawn_function, NULL); }
	if(PTH-75 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[74] ); pthread_create( &Threads[ 74 ], &attr, spawn_function, NULL); }
	if(PTH-76 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[75] ); pthread_create( &Threads[ 75 ], &attr, spawn_function, NULL); }
	if(PTH-77 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[76] ); pthread_create( &Threads[ 76 ], &attr, spawn_function, NULL); }
	if(PTH-78 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[77] ); pthread_create( &Threads[ 77 ], &attr, spawn_function, NULL); }
	if(PTH-79 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[78] ); pthread_create( &Threads[ 78 ], &attr, spawn_function, NULL); }
	if(PTH-80 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[79] ); pthread_create( &Threads[ 79 ], &attr, spawn_function, NULL); } // 80

	if(PTH-81 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[80] ); pthread_create( &Threads[ 80 ], &attr, spawn_function, NULL); }
	if(PTH-82 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[81] ); pthread_create( &Threads[ 81 ], &attr, spawn_function, NULL); }
	if(PTH-83 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[82] ); pthread_create( &Threads[ 82 ], &attr, spawn_function, NULL); }
	if(PTH-84 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[83] ); pthread_create( &Threads[ 83 ], &attr, spawn_function, NULL); }
	if(PTH-85 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[84] ); pthread_create( &Threads[ 84 ], &attr, spawn_function, NULL); }
	if(PTH-86 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[85] ); pthread_create( &Threads[ 85 ], &attr, spawn_function, NULL); }
	if(PTH-87 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[86] ); pthread_create( &Threads[ 86 ], &attr, spawn_function, NULL); }
	if(PTH-88 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[87] ); pthread_create( &Threads[ 87 ], &attr, spawn_function, NULL); }
	if(PTH-89 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[88] ); pthread_create( &Threads[ 88 ], &attr, spawn_function, NULL); }
	if(PTH-90 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[89] ); pthread_create( &Threads[ 89 ], &attr, spawn_function, NULL); } // 90

	if(PTH-91 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[90] ); pthread_create( &Threads[ 90 ], &attr, spawn_function, NULL); }
	if(PTH-92 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[91] ); pthread_create( &Threads[ 91 ], &attr, spawn_function, NULL); }
	if(PTH-93 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[92] ); pthread_create( &Threads[ 92 ], &attr, spawn_function, NULL); }
	if(PTH-94 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[93] ); pthread_create( &Threads[ 93 ], &attr, spawn_function, NULL); }
	if(PTH-95 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[94] ); pthread_create( &Threads[ 94 ], &attr, spawn_function, NULL); }
	if(PTH-96 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[95] ); pthread_create( &Threads[ 95 ], &attr, spawn_function, NULL); }
	if(PTH-97 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[96] ); pthread_create( &Threads[ 96 ], &attr, spawn_function, NULL); }
	if(PTH-98 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[97] ); pthread_create( &Threads[ 97 ], &attr, spawn_function, NULL); }
	if(PTH-99 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[98] ); pthread_create( &Threads[ 98 ], &attr, spawn_function, NULL); }
	if(PTH-100 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[99] ); pthread_create( &Threads[ 99 ], &attr, spawn_function, NULL); } // 100

	if(PTH-101 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[100] ); pthread_create( &Threads[ 100 ], &attr, spawn_function, NULL); }
	if(PTH-102 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[101] ); pthread_create( &Threads[ 101 ], &attr, spawn_function, NULL); }
	if(PTH-103 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[102] ); pthread_create( &Threads[ 102 ], &attr, spawn_function, NULL); }
	if(PTH-104 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[103] ); pthread_create( &Threads[ 103 ], &attr, spawn_function, NULL); }
	if(PTH-105 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[104] ); pthread_create( &Threads[ 104 ], &attr, spawn_function, NULL); }
	if(PTH-106 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[105] ); pthread_create( &Threads[ 105 ], &attr, spawn_function, NULL); }
	if(PTH-107 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[106] ); pthread_create( &Threads[ 106 ], &attr, spawn_function, NULL); }
	if(PTH-108 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[107] ); pthread_create( &Threads[ 107 ], &attr, spawn_function, NULL); }
	if(PTH-109 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[108] ); pthread_create( &Threads[ 108 ], &attr, spawn_function, NULL); }
	if(PTH-110 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[109] ); pthread_create( &Threads[ 109 ], &attr, spawn_function, NULL); } // 110

	if(PTH-111 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[110] ); pthread_create( &Threads[ 110 ], &attr, spawn_function, NULL); }
	if(PTH-112 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[111] ); pthread_create( &Threads[ 111 ], &attr, spawn_function, NULL); }
	if(PTH-113 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[112] ); pthread_create( &Threads[ 112 ], &attr, spawn_function, NULL); }
	if(PTH-114 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[113] ); pthread_create( &Threads[ 113 ], &attr, spawn_function, NULL); }
	if(PTH-115 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[114] ); pthread_create( &Threads[ 114 ], &attr, spawn_function, NULL); }
	if(PTH-116 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[115] ); pthread_create( &Threads[ 115 ], &attr, spawn_function, NULL); }
	if(PTH-117 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[116] ); pthread_create( &Threads[ 116 ], &attr, spawn_function, NULL); }
	if(PTH-118 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[117] ); pthread_create( &Threads[ 117 ], &attr, spawn_function, NULL); }
	if(PTH-119 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[118] ); pthread_create( &Threads[ 118 ], &attr, spawn_function, NULL); }
	if(PTH-120 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[119] ); pthread_create( &Threads[ 119 ], &attr, spawn_function, NULL); } // 120

	if(PTH-121 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[120] ); pthread_create( &Threads[ 120 ], &attr, spawn_function, NULL); }
	if(PTH-122 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[121] ); pthread_create( &Threads[ 121 ], &attr, spawn_function, NULL); }
	if(PTH-123 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[122] ); pthread_create( &Threads[ 122 ], &attr, spawn_function, NULL); }
	if(PTH-124 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[123] ); pthread_create( &Threads[ 123 ], &attr, spawn_function, NULL); }
	if(PTH-125 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[124] ); pthread_create( &Threads[ 124 ], &attr, spawn_function, NULL); }
	if(PTH-126 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[125] ); pthread_create( &Threads[ 125 ], &attr, spawn_function, NULL); }
	if(PTH-127 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[126] ); pthread_create( &Threads[ 126 ], &attr, spawn_function, NULL); }
	if(PTH-128 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[127] ); pthread_create( &Threads[ 127 ], &attr, spawn_function, NULL); }
	if(PTH-129 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[128] ); pthread_create( &Threads[ 128 ], &attr, spawn_function, NULL); }
	if(PTH-130 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[129] ); pthread_create( &Threads[ 129 ], &attr, spawn_function, NULL); } // 130

	if(PTH-131 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[130] ); pthread_create( &Threads[ 130 ], &attr, spawn_function, NULL); }
	if(PTH-132 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[131] ); pthread_create( &Threads[ 131 ], &attr, spawn_function, NULL); }
	if(PTH-133 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[132] ); pthread_create( &Threads[ 132 ], &attr, spawn_function, NULL); }
	if(PTH-134 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[133] ); pthread_create( &Threads[ 133 ], &attr, spawn_function, NULL); }
	if(PTH-135 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[134] ); pthread_create( &Threads[ 134 ], &attr, spawn_function, NULL); }
	if(PTH-136 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[135] ); pthread_create( &Threads[ 135 ], &attr, spawn_function, NULL); }
	if(PTH-137 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[136] ); pthread_create( &Threads[ 136 ], &attr, spawn_function, NULL); }
	if(PTH-138 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[137] ); pthread_create( &Threads[ 137 ], &attr, spawn_function, NULL); }
	if(PTH-139 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[138] ); pthread_create( &Threads[ 138 ], &attr, spawn_function, NULL); }
	if(PTH-140 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[139] ); pthread_create( &Threads[ 139 ], &attr, spawn_function, NULL); } // 140

	if(PTH-141 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[140] ); pthread_create( &Threads[ 140 ], &attr, spawn_function, NULL); }
	if(PTH-142 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[141] ); pthread_create( &Threads[ 141 ], &attr, spawn_function, NULL); }
	if(PTH-143 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[142] ); pthread_create( &Threads[ 142 ], &attr, spawn_function, NULL); }
	if(PTH-144 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[143] ); pthread_create( &Threads[ 143 ], &attr, spawn_function, NULL); }
	if(PTH-145 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[144] ); pthread_create( &Threads[ 144 ], &attr, spawn_function, NULL); }
	if(PTH-146 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[145] ); pthread_create( &Threads[ 145 ], &attr, spawn_function, NULL); }
	if(PTH-147 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[146] ); pthread_create( &Threads[ 146 ], &attr, spawn_function, NULL); }
	if(PTH-148 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[147] ); pthread_create( &Threads[ 147 ], &attr, spawn_function, NULL); }
	if(PTH-149 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[148] ); pthread_create( &Threads[ 148 ], &attr, spawn_function, NULL); }
	if(PTH-150 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[149] ); pthread_create( &Threads[ 149 ], &attr, spawn_function, NULL); } // 150

	if(PTH-151 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[150] ); pthread_create( &Threads[ 150 ], &attr, spawn_function, NULL); }
	if(PTH-152 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[151] ); pthread_create( &Threads[ 151 ], &attr, spawn_function, NULL); }
	if(PTH-153 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[152] ); pthread_create( &Threads[ 152 ], &attr, spawn_function, NULL); }
	if(PTH-154 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[153] ); pthread_create( &Threads[ 153 ], &attr, spawn_function, NULL); }
	if(PTH-155 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[154] ); pthread_create( &Threads[ 154 ], &attr, spawn_function, NULL); }
	if(PTH-156 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[155] ); pthread_create( &Threads[ 155 ], &attr, spawn_function, NULL); }
	if(PTH-157 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[156] ); pthread_create( &Threads[ 156 ], &attr, spawn_function, NULL); }
	if(PTH-158 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[157] ); pthread_create( &Threads[ 157 ], &attr, spawn_function, NULL); }
	if(PTH-159 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[158] ); pthread_create( &Threads[ 158 ], &attr, spawn_function, NULL); }
	if(PTH-160 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[159] ); pthread_create( &Threads[ 159 ], &attr, spawn_function, NULL); } // 160

	if(PTH-161 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[160] ); pthread_create( &Threads[ 160 ], &attr, spawn_function, NULL); }
	if(PTH-162 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[161] ); pthread_create( &Threads[ 161 ], &attr, spawn_function, NULL); }
	if(PTH-163 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[162] ); pthread_create( &Threads[ 162 ], &attr, spawn_function, NULL); }
	if(PTH-164 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[163] ); pthread_create( &Threads[ 163 ], &attr, spawn_function, NULL); }
	if(PTH-165 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[164] ); pthread_create( &Threads[ 164 ], &attr, spawn_function, NULL); }
	if(PTH-166 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[165] ); pthread_create( &Threads[ 165 ], &attr, spawn_function, NULL); }
	if(PTH-167 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[166] ); pthread_create( &Threads[ 166 ], &attr, spawn_function, NULL); }
	if(PTH-168 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[167] ); pthread_create( &Threads[ 167 ], &attr, spawn_function, NULL); }
	if(PTH-169 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[168] ); pthread_create( &Threads[ 168 ], &attr, spawn_function, NULL); }
	if(PTH-170 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[169] ); pthread_create( &Threads[ 169 ], &attr, spawn_function, NULL); } // 170

	if(PTH-171 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[170] ); pthread_create( &Threads[ 170 ], &attr, spawn_function, NULL); }
	if(PTH-172 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[171] ); pthread_create( &Threads[ 171 ], &attr, spawn_function, NULL); }
	if(PTH-173 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[172] ); pthread_create( &Threads[ 172 ], &attr, spawn_function, NULL); }
	if(PTH-174 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[173] ); pthread_create( &Threads[ 173 ], &attr, spawn_function, NULL); }
	if(PTH-175 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[174] ); pthread_create( &Threads[ 174 ], &attr, spawn_function, NULL); }
	if(PTH-176 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[175] ); pthread_create( &Threads[ 175 ], &attr, spawn_function, NULL); }
	if(PTH-177 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[176] ); pthread_create( &Threads[ 176 ], &attr, spawn_function, NULL); }
	if(PTH-178 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[177] ); pthread_create( &Threads[ 177 ], &attr, spawn_function, NULL); }
	if(PTH-179 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[178] ); pthread_create( &Threads[ 178 ], &attr, spawn_function, NULL); }
	if(PTH-180 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[179] ); pthread_create( &Threads[ 179 ], &attr, spawn_function, NULL); } // 180

	if(PTH-181 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[180] ); pthread_create( &Threads[ 180 ], &attr, spawn_function, NULL); }
	if(PTH-182 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[181] ); pthread_create( &Threads[ 181 ], &attr, spawn_function, NULL); }
	if(PTH-183 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[182] ); pthread_create( &Threads[ 182 ], &attr, spawn_function, NULL); }
	if(PTH-184 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[183] ); pthread_create( &Threads[ 183 ], &attr, spawn_function, NULL); }
	if(PTH-185 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[184] ); pthread_create( &Threads[ 184 ], &attr, spawn_function, NULL); }
	if(PTH-186 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[185] ); pthread_create( &Threads[ 185 ], &attr, spawn_function, NULL); }
	if(PTH-187 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[186] ); pthread_create( &Threads[ 186 ], &attr, spawn_function, NULL); }
	if(PTH-188 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[187] ); pthread_create( &Threads[ 187 ], &attr, spawn_function, NULL); }
	if(PTH-189 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[188] ); pthread_create( &Threads[ 188 ], &attr, spawn_function, NULL); }
	if(PTH-190 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[189] ); pthread_create( &Threads[ 189 ], &attr, spawn_function, NULL); } // 190

	if(PTH-191 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[190] ); pthread_create( &Threads[ 190 ], &attr, spawn_function, NULL); }
	if(PTH-192 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[191] ); pthread_create( &Threads[ 191 ], &attr, spawn_function, NULL); }
	if(PTH-193 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[192] ); pthread_create( &Threads[ 192 ], &attr, spawn_function, NULL); }
	if(PTH-194 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[193] ); pthread_create( &Threads[ 193 ], &attr, spawn_function, NULL); }
	if(PTH-195 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[194] ); pthread_create( &Threads[ 194 ], &attr, spawn_function, NULL); }
	if(PTH-196 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[195] ); pthread_create( &Threads[ 195 ], &attr, spawn_function, NULL); }
	if(PTH-197 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[196] ); pthread_create( &Threads[ 196 ], &attr, spawn_function, NULL); }
	if(PTH-198 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[197] ); pthread_create( &Threads[ 197 ], &attr, spawn_function, NULL); }
	if(PTH-199 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[198] ); pthread_create( &Threads[ 198 ], &attr, spawn_function, NULL); }
	if(PTH-200 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[199] ); pthread_create( &Threads[ 199 ], &attr, spawn_function, NULL); } // 200

	if(PTH-201 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[200] ); pthread_create( &Threads[ 200 ], &attr, spawn_function, NULL); }
	if(PTH-202 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[201] ); pthread_create( &Threads[ 201 ], &attr, spawn_function, NULL); }
	if(PTH-203 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[202] ); pthread_create( &Threads[ 202 ], &attr, spawn_function, NULL); }
	if(PTH-204 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[203] ); pthread_create( &Threads[ 203 ], &attr, spawn_function, NULL); }
	if(PTH-205 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[204] ); pthread_create( &Threads[ 204 ], &attr, spawn_function, NULL); }
	if(PTH-206 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[205] ); pthread_create( &Threads[ 205 ], &attr, spawn_function, NULL); }
	if(PTH-207 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[206] ); pthread_create( &Threads[ 206 ], &attr, spawn_function, NULL); }
	if(PTH-208 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[207] ); pthread_create( &Threads[ 207 ], &attr, spawn_function, NULL); }
	if(PTH-209 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[208] ); pthread_create( &Threads[ 208 ], &attr, spawn_function, NULL); }
	if(PTH-210 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[209] ); pthread_create( &Threads[ 209 ], &attr, spawn_function, NULL); } // 210

	if(PTH-211 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[210] ); pthread_create( &Threads[ 210 ], &attr, spawn_function, NULL); }
	if(PTH-212 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[211] ); pthread_create( &Threads[ 211 ], &attr, spawn_function, NULL); }
	if(PTH-213 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[212] ); pthread_create( &Threads[ 212 ], &attr, spawn_function, NULL); }
	if(PTH-214 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[213] ); pthread_create( &Threads[ 213 ], &attr, spawn_function, NULL); }
	if(PTH-215 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[214] ); pthread_create( &Threads[ 214 ], &attr, spawn_function, NULL); }
	if(PTH-216 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[215] ); pthread_create( &Threads[ 215 ], &attr, spawn_function, NULL); }
	if(PTH-217 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[216] ); pthread_create( &Threads[ 216 ], &attr, spawn_function, NULL); }
	if(PTH-218 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[217] ); pthread_create( &Threads[ 217 ], &attr, spawn_function, NULL); }
	if(PTH-219 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[218] ); pthread_create( &Threads[ 218 ], &attr, spawn_function, NULL); }
	if(PTH-220 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[219] ); pthread_create( &Threads[ 219 ], &attr, spawn_function, NULL); } // 220

	if(PTH-221 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[220] ); pthread_create( &Threads[ 220 ], &attr, spawn_function, NULL); }
	if(PTH-222 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[221] ); pthread_create( &Threads[ 221 ], &attr, spawn_function, NULL); }
	if(PTH-223 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[222] ); pthread_create( &Threads[ 222 ], &attr, spawn_function, NULL); }
	if(PTH-224 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[223] ); pthread_create( &Threads[ 223 ], &attr, spawn_function, NULL); }
	if(PTH-225 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[224] ); pthread_create( &Threads[ 224 ], &attr, spawn_function, NULL); }
	if(PTH-226 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[225] ); pthread_create( &Threads[ 225 ], &attr, spawn_function, NULL); }
	if(PTH-227 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[226] ); pthread_create( &Threads[ 226 ], &attr, spawn_function, NULL); }
	if(PTH-228 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[227] ); pthread_create( &Threads[ 227 ], &attr, spawn_function, NULL); }
	if(PTH-229 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[228] ); pthread_create( &Threads[ 228 ], &attr, spawn_function, NULL); }
	if(PTH-230 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[229] ); pthread_create( &Threads[ 229 ], &attr, spawn_function, NULL); } // 230

	if(PTH-231 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[230] ); pthread_create( &Threads[ 230 ], &attr, spawn_function, NULL); }
	if(PTH-232 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[231] ); pthread_create( &Threads[ 231 ], &attr, spawn_function, NULL); }
	if(PTH-233 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[232] ); pthread_create( &Threads[ 232 ], &attr, spawn_function, NULL); }
	if(PTH-234 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[233] ); pthread_create( &Threads[ 233 ], &attr, spawn_function, NULL); }
	if(PTH-235 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[234] ); pthread_create( &Threads[ 234 ], &attr, spawn_function, NULL); }
	if(PTH-236 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[235] ); pthread_create( &Threads[ 235 ], &attr, spawn_function, NULL); }
	if(PTH-237 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[236] ); pthread_create( &Threads[ 236 ], &attr, spawn_function, NULL); }
	if(PTH-238 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[237] ); pthread_create( &Threads[ 237 ], &attr, spawn_function, NULL); }
	if(PTH-239 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[238] ); pthread_create( &Threads[ 238 ], &attr, spawn_function, NULL); }
	if(PTH-240 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[239] ); pthread_create( &Threads[ 239 ], &attr, spawn_function, NULL); } // 240

	if(PTH-241 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[240] ); pthread_create( &Threads[ 240 ], &attr, spawn_function, NULL); }
	if(PTH-242 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[241] ); pthread_create( &Threads[ 241 ], &attr, spawn_function, NULL); }
	if(PTH-243 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[242] ); pthread_create( &Threads[ 242 ], &attr, spawn_function, NULL); }
	if(PTH-244 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[243] ); pthread_create( &Threads[ 243 ], &attr, spawn_function, NULL); }
	if(PTH-245 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[244] ); pthread_create( &Threads[ 244 ], &attr, spawn_function, NULL); }
	if(PTH-246 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[245] ); pthread_create( &Threads[ 245 ], &attr, spawn_function, NULL); }
	if(PTH-247 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[246] ); pthread_create( &Threads[ 246 ], &attr, spawn_function, NULL); }
	if(PTH-248 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[247] ); pthread_create( &Threads[ 247 ], &attr, spawn_function, NULL); }
	if(PTH-249 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[248] ); pthread_create( &Threads[ 248 ], &attr, spawn_function, NULL); }
	if(PTH-250 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[249] ); pthread_create( &Threads[ 249 ], &attr, spawn_function, NULL); } // 250

	if(PTH-251 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[250] ); pthread_create( &Threads[ 250 ], &attr, spawn_function, NULL); }
	if(PTH-252 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[251] ); pthread_create( &Threads[ 251 ], &attr, spawn_function, NULL); }
	if(PTH-253 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[252] ); pthread_create( &Threads[ 252 ], &attr, spawn_function, NULL); }
	if(PTH-254 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[253] ); pthread_create( &Threads[ 253 ], &attr, spawn_function, NULL); }
	if(PTH-255 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[254] ); pthread_create( &Threads[ 254 ], &attr, spawn_function, NULL); }
	if(PTH-256 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[255] ); pthread_create( &Threads[ 255 ], &attr, spawn_function, NULL); }
	if(PTH-257 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[256] ); pthread_create( &Threads[ 256 ], &attr, spawn_function, NULL); }
	if(PTH-258 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[257] ); pthread_create( &Threads[ 257 ], &attr, spawn_function, NULL); }
	if(PTH-259 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[258] ); pthread_create( &Threads[ 258 ], &attr, spawn_function, NULL); }
	if(PTH-260 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[259] ); pthread_create( &Threads[ 259 ], &attr, spawn_function, NULL); } // 260

	if(PTH-261 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[260] ); pthread_create( &Threads[ 260 ], &attr, spawn_function, NULL); }
	if(PTH-262 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[261] ); pthread_create( &Threads[ 261 ], &attr, spawn_function, NULL); }
	if(PTH-263 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[262] ); pthread_create( &Threads[ 262 ], &attr, spawn_function, NULL); }
	if(PTH-264 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[263] ); pthread_create( &Threads[ 263 ], &attr, spawn_function, NULL); }
	if(PTH-265 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[264] ); pthread_create( &Threads[ 264 ], &attr, spawn_function, NULL); }
	if(PTH-266 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[265] ); pthread_create( &Threads[ 265 ], &attr, spawn_function, NULL); }
	if(PTH-267 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[266] ); pthread_create( &Threads[ 266 ], &attr, spawn_function, NULL); }
	if(PTH-268 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[267] ); pthread_create( &Threads[ 267 ], &attr, spawn_function, NULL); }
	if(PTH-269 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[268] ); pthread_create( &Threads[ 268 ], &attr, spawn_function, NULL); }
	if(PTH-270 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[269] ); pthread_create( &Threads[ 269 ], &attr, spawn_function, NULL); } // 270

	if(PTH-271 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[270] ); pthread_create( &Threads[ 270 ], &attr, spawn_function, NULL); }
	if(PTH-272 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[271] ); pthread_create( &Threads[ 271 ], &attr, spawn_function, NULL); }
	if(PTH-273 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[272] ); pthread_create( &Threads[ 272 ], &attr, spawn_function, NULL); }
	if(PTH-274 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[273] ); pthread_create( &Threads[ 273 ], &attr, spawn_function, NULL); }
	if(PTH-275 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[274] ); pthread_create( &Threads[ 274 ], &attr, spawn_function, NULL); }
	if(PTH-276 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[275] ); pthread_create( &Threads[ 275 ], &attr, spawn_function, NULL); }
	if(PTH-277 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[276] ); pthread_create( &Threads[ 276 ], &attr, spawn_function, NULL); }
	if(PTH-278 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[277] ); pthread_create( &Threads[ 277 ], &attr, spawn_function, NULL); }
	if(PTH-279 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[278] ); pthread_create( &Threads[ 278 ], &attr, spawn_function, NULL); }
	if(PTH-280 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[279] ); pthread_create( &Threads[ 279 ], &attr, spawn_function, NULL); } // 270

	if(PTH-281 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[280] ); pthread_create( &Threads[ 280 ], &attr, spawn_function, NULL); }
	if(PTH-282 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[281] ); pthread_create( &Threads[ 281 ], &attr, spawn_function, NULL); }
	if(PTH-283 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[282] ); pthread_create( &Threads[ 282 ], &attr, spawn_function, NULL); }
	if(PTH-284 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[283] ); pthread_create( &Threads[ 283 ], &attr, spawn_function, NULL); }
	if(PTH-285 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[284] ); pthread_create( &Threads[ 284 ], &attr, spawn_function, NULL); }
	if(PTH-286 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[285] ); pthread_create( &Threads[ 285 ], &attr, spawn_function, NULL); }
	if(PTH-287 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[286] ); pthread_create( &Threads[ 286 ], &attr, spawn_function, NULL); }
	if(PTH-288 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[287] ); pthread_create( &Threads[ 287 ], &attr, spawn_function, NULL); }
	if(PTH-289 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[288] ); pthread_create( &Threads[ 288 ], &attr, spawn_function, NULL); }
	if(PTH-290 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[289] ); pthread_create( &Threads[ 289 ], &attr, spawn_function, NULL); } // 280

	if(PTH-291 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[290] ); pthread_create( &Threads[ 290 ], &attr, spawn_function, NULL); }
	if(PTH-292 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[291] ); pthread_create( &Threads[ 291 ], &attr, spawn_function, NULL); }
	if(PTH-293 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[292] ); pthread_create( &Threads[ 292 ], &attr, spawn_function, NULL); }
	if(PTH-294 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[293] ); pthread_create( &Threads[ 293 ], &attr, spawn_function, NULL); }
	if(PTH-295 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[294] ); pthread_create( &Threads[ 294 ], &attr, spawn_function, NULL); }
	if(PTH-296 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[295] ); pthread_create( &Threads[ 295 ], &attr, spawn_function, NULL); }
	if(PTH-297 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[296] ); pthread_create( &Threads[ 296 ], &attr, spawn_function, NULL); }
	if(PTH-298 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[297] ); pthread_create( &Threads[ 297 ], &attr, spawn_function, NULL); }
	if(PTH-299 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[298] ); pthread_create( &Threads[ 298 ], &attr, spawn_function, NULL); }
	if(PTH-300 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[299] ); pthread_create( &Threads[ 299 ], &attr, spawn_function, NULL); } // 300

	if(PTH-301 >= 0){ clock_gettime(CLOCK_MONOTONIC, &t_end[300] ); pthread_create( &Threads[ 300 ], &attr, spawn_function, NULL); } // 301


// end:

	// each thread waits until all threads have hit the barrier, then they all return
	pthread_barrier_wait(&sync_barrier);

	// pthread_destroy_barrier
	pthread_barrier_destroy(&sync_barrier);

	// destroy attr
	pthread_attr_destroy(&attr);


	printf("****\n");
	for(int i = 0; i < PTH; i++){

		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	}

	// printf(02C"\n");
		
	return 0;
}