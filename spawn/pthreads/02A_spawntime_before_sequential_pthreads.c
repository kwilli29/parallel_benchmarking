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

	int DEPTH = 271;

	int ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

	pthread_t Threads[ DEPTH ];

	// pthread_barrier_init
	pthread_barrier_init(&sync_barrier, NULL, DEPTH+1);

	struct timespec t_start, t_res;
	struct timespec t_end[DEPTH];
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	clock_gettime(CLOCK_MONOTONIC, &t_end[0] ); pthread_create( &Threads[ 0 ], &attr, spawn_function, NULL); // all threads spawn detached,
	clock_gettime(CLOCK_MONOTONIC, &t_end[1] ); pthread_create( &Threads[ 1 ], &attr, spawn_function, NULL); // hit the barrier,
	clock_gettime(CLOCK_MONOTONIC, &t_end[2] ); pthread_create( &Threads[ 2 ], &attr, spawn_function, NULL); // and are immmediately freed w/o joining
	clock_gettime(CLOCK_MONOTONIC, &t_end[3] ); pthread_create( &Threads[ 3 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[4] ); pthread_create( &Threads[ 4 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[5] ); pthread_create( &Threads[ 5 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[6] ); pthread_create( &Threads[ 6 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[7] ); pthread_create( &Threads[ 7 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[8] ); pthread_create( &Threads[ 8 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[9] ); pthread_create( &Threads[ 9 ], &attr, spawn_function, NULL); // 10

	clock_gettime(CLOCK_MONOTONIC, &t_end[10] ); pthread_create( &Threads[ 10 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[11] ); pthread_create( &Threads[ 11 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[12] ); pthread_create( &Threads[ 12 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[13] ); pthread_create( &Threads[ 13 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[14] ); pthread_create( &Threads[ 14 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[15] ); pthread_create( &Threads[ 15 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[16] ); pthread_create( &Threads[ 16 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[17] ); pthread_create( &Threads[ 17 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[18] ); pthread_create( &Threads[ 18 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[19] ); pthread_create( &Threads[ 19 ], &attr, spawn_function, NULL); // 20

	clock_gettime(CLOCK_MONOTONIC, &t_end[20] ); pthread_create( &Threads[ 20 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[21] ); pthread_create( &Threads[ 21 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[22] ); pthread_create( &Threads[ 22 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[23] ); pthread_create( &Threads[ 23 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[24] ); pthread_create( &Threads[ 24 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[25] ); pthread_create( &Threads[ 25 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[26] ); pthread_create( &Threads[ 26 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[27] ); pthread_create( &Threads[ 27 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[28] ); pthread_create( &Threads[ 28 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[29] ); pthread_create( &Threads[ 29 ], &attr, spawn_function, NULL); // 30

	clock_gettime(CLOCK_MONOTONIC, &t_end[30] ); pthread_create( &Threads[ 30 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[31] ); pthread_create( &Threads[ 31 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[32] ); pthread_create( &Threads[ 32 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[33] ); pthread_create( &Threads[ 33 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[34] ); pthread_create( &Threads[ 34 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[35] ); pthread_create( &Threads[ 35 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[36] ); pthread_create( &Threads[ 36 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[37] ); pthread_create( &Threads[ 37 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[38] ); pthread_create( &Threads[ 38 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[39] ); pthread_create( &Threads[ 39 ], &attr, spawn_function, NULL); // 40

	clock_gettime(CLOCK_MONOTONIC, &t_end[40] ); pthread_create( &Threads[ 40 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[41] ); pthread_create( &Threads[ 41 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[42] ); pthread_create( &Threads[ 42 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[43] ); pthread_create( &Threads[ 43 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[44] ); pthread_create( &Threads[ 44 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[45] ); pthread_create( &Threads[ 45 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[46] ); pthread_create( &Threads[ 46 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[47] ); pthread_create( &Threads[ 47 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[48] ); pthread_create( &Threads[ 48 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[49] ); pthread_create( &Threads[ 49 ], &attr, spawn_function, NULL); // 50

	clock_gettime(CLOCK_MONOTONIC, &t_end[50] ); pthread_create( &Threads[ 50 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[51] ); pthread_create( &Threads[ 51 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[52] ); pthread_create( &Threads[ 52 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[53] ); pthread_create( &Threads[ 53 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[54] ); pthread_create( &Threads[ 54 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[55] ); pthread_create( &Threads[ 55 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[56] ); pthread_create( &Threads[ 56 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[57] ); pthread_create( &Threads[ 57 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[58] ); pthread_create( &Threads[ 58 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[59] ); pthread_create( &Threads[ 59 ], &attr, spawn_function, NULL); // 60

	clock_gettime(CLOCK_MONOTONIC, &t_end[60] ); pthread_create( &Threads[ 60 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[61] ); pthread_create( &Threads[ 61 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[62] ); pthread_create( &Threads[ 62 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[63] ); pthread_create( &Threads[ 63 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[64] ); pthread_create( &Threads[ 64 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[65] ); pthread_create( &Threads[ 65 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[66] ); pthread_create( &Threads[ 66 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[67] ); pthread_create( &Threads[ 67 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[68] ); pthread_create( &Threads[ 68 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[69] ); pthread_create( &Threads[ 69 ], &attr, spawn_function, NULL); // 70

	clock_gettime(CLOCK_MONOTONIC, &t_end[70] ); pthread_create( &Threads[ 70 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[71] ); pthread_create( &Threads[ 71 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[72] ); pthread_create( &Threads[ 72 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[73] ); pthread_create( &Threads[ 73 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[74] ); pthread_create( &Threads[ 74 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[75] ); pthread_create( &Threads[ 75 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[76] ); pthread_create( &Threads[ 76 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[77] ); pthread_create( &Threads[ 77 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[78] ); pthread_create( &Threads[ 78 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[79] ); pthread_create( &Threads[ 79 ], &attr, spawn_function, NULL); // 80

	clock_gettime(CLOCK_MONOTONIC, &t_end[80] ); pthread_create( &Threads[ 80 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[81] ); pthread_create( &Threads[ 81 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[82] ); pthread_create( &Threads[ 82 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[83] ); pthread_create( &Threads[ 83 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[84] ); pthread_create( &Threads[ 84 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[85] ); pthread_create( &Threads[ 85 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[86] ); pthread_create( &Threads[ 86 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[87] ); pthread_create( &Threads[ 87 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[88] ); pthread_create( &Threads[ 88 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[89] ); pthread_create( &Threads[ 89 ], &attr, spawn_function, NULL); // 90

	clock_gettime(CLOCK_MONOTONIC, &t_end[90] ); pthread_create( &Threads[ 90 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[91] ); pthread_create( &Threads[ 91 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[92] ); pthread_create( &Threads[ 92 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[93] ); pthread_create( &Threads[ 93 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[94] ); pthread_create( &Threads[ 94 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[95] ); pthread_create( &Threads[ 95 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[96] ); pthread_create( &Threads[ 96 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[97] ); pthread_create( &Threads[ 97 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[98] ); pthread_create( &Threads[ 98 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[99] ); pthread_create( &Threads[ 99 ], &attr, spawn_function, NULL); // 100

	clock_gettime(CLOCK_MONOTONIC, &t_end[100] ); pthread_create( &Threads[ 100 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[101] ); pthread_create( &Threads[ 101 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[102] ); pthread_create( &Threads[ 102 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[103] ); pthread_create( &Threads[ 103 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[104] ); pthread_create( &Threads[ 104 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[105] ); pthread_create( &Threads[ 105 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[106] ); pthread_create( &Threads[ 106 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[107] ); pthread_create( &Threads[ 107 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[108] ); pthread_create( &Threads[ 108 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[109] ); pthread_create( &Threads[ 109 ], &attr, spawn_function, NULL); // 110

	clock_gettime(CLOCK_MONOTONIC, &t_end[110] ); pthread_create( &Threads[ 110 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[111] ); pthread_create( &Threads[ 111 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[112] ); pthread_create( &Threads[ 112 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[113] ); pthread_create( &Threads[ 113 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[114] ); pthread_create( &Threads[ 114 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[115] ); pthread_create( &Threads[ 115 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[116] ); pthread_create( &Threads[ 116 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[117] ); pthread_create( &Threads[ 117 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[118] ); pthread_create( &Threads[ 118 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[119] ); pthread_create( &Threads[ 119 ], &attr, spawn_function, NULL); // 120

	clock_gettime(CLOCK_MONOTONIC, &t_end[120] ); pthread_create( &Threads[ 120 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[121] ); pthread_create( &Threads[ 121 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[122] ); pthread_create( &Threads[ 122 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[123] ); pthread_create( &Threads[ 123 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[124] ); pthread_create( &Threads[ 124 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[125] ); pthread_create( &Threads[ 125 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[126] ); pthread_create( &Threads[ 126 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[127] ); pthread_create( &Threads[ 127 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[128] ); pthread_create( &Threads[ 128 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[129] ); pthread_create( &Threads[ 129 ], &attr, spawn_function, NULL); // 130

	clock_gettime(CLOCK_MONOTONIC, &t_end[130] ); pthread_create( &Threads[ 130 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[131] ); pthread_create( &Threads[ 131 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[132] ); pthread_create( &Threads[ 132 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[133] ); pthread_create( &Threads[ 133 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[134] ); pthread_create( &Threads[ 134 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[135] ); pthread_create( &Threads[ 135 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[136] ); pthread_create( &Threads[ 136 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[137] ); pthread_create( &Threads[ 137 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[138] ); pthread_create( &Threads[ 138 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[139] ); pthread_create( &Threads[ 139 ], &attr, spawn_function, NULL); // 140

	clock_gettime(CLOCK_MONOTONIC, &t_end[140] ); pthread_create( &Threads[ 140 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[141] ); pthread_create( &Threads[ 141 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[142] ); pthread_create( &Threads[ 142 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[143] ); pthread_create( &Threads[ 143 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[144] ); pthread_create( &Threads[ 144 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[145] ); pthread_create( &Threads[ 145 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[146] ); pthread_create( &Threads[ 146 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[147] ); pthread_create( &Threads[ 147 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[148] ); pthread_create( &Threads[ 148 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[149] ); pthread_create( &Threads[ 149 ], &attr, spawn_function, NULL); // 150

	clock_gettime(CLOCK_MONOTONIC, &t_end[150] ); pthread_create( &Threads[ 150 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[151] ); pthread_create( &Threads[ 151 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[152] ); pthread_create( &Threads[ 152 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[153] ); pthread_create( &Threads[ 153 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[154] ); pthread_create( &Threads[ 154 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[155] ); pthread_create( &Threads[ 155 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[156] ); pthread_create( &Threads[ 156 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[157] ); pthread_create( &Threads[ 157 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[158] ); pthread_create( &Threads[ 158 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[159] ); pthread_create( &Threads[ 159 ], &attr, spawn_function, NULL); // 160

	clock_gettime(CLOCK_MONOTONIC, &t_end[160] ); pthread_create( &Threads[ 160 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[161] ); pthread_create( &Threads[ 161 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[162] ); pthread_create( &Threads[ 162 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[163] ); pthread_create( &Threads[ 163 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[164] ); pthread_create( &Threads[ 164 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[165] ); pthread_create( &Threads[ 165 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[166] ); pthread_create( &Threads[ 166 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[167] ); pthread_create( &Threads[ 167 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[168] ); pthread_create( &Threads[ 168 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[169] ); pthread_create( &Threads[ 169 ], &attr, spawn_function, NULL); // 170

	clock_gettime(CLOCK_MONOTONIC, &t_end[170] ); pthread_create( &Threads[ 170 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[171] ); pthread_create( &Threads[ 171 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[172] ); pthread_create( &Threads[ 172 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[173] ); pthread_create( &Threads[ 173 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[174] ); pthread_create( &Threads[ 174 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[175] ); pthread_create( &Threads[ 175 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[176] ); pthread_create( &Threads[ 176 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[177] ); pthread_create( &Threads[ 177 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[178] ); pthread_create( &Threads[ 178 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[179] ); pthread_create( &Threads[ 179 ], &attr, spawn_function, NULL); // 180

	clock_gettime(CLOCK_MONOTONIC, &t_end[180] ); pthread_create( &Threads[ 180 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[181] ); pthread_create( &Threads[ 181 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[182] ); pthread_create( &Threads[ 182 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[183] ); pthread_create( &Threads[ 183 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[184] ); pthread_create( &Threads[ 184 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[185] ); pthread_create( &Threads[ 185 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[186] ); pthread_create( &Threads[ 186 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[187] ); pthread_create( &Threads[ 187 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[188] ); pthread_create( &Threads[ 188 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[189] ); pthread_create( &Threads[ 189 ], &attr, spawn_function, NULL); // 190

	clock_gettime(CLOCK_MONOTONIC, &t_end[190] ); pthread_create( &Threads[ 190 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[191] ); pthread_create( &Threads[ 191 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[192] ); pthread_create( &Threads[ 192 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[193] ); pthread_create( &Threads[ 193 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[194] ); pthread_create( &Threads[ 194 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[195] ); pthread_create( &Threads[ 195 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[196] ); pthread_create( &Threads[ 196 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[197] ); pthread_create( &Threads[ 197 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[198] ); pthread_create( &Threads[ 198 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[199] ); pthread_create( &Threads[ 199 ], &attr, spawn_function, NULL); // 200

	clock_gettime(CLOCK_MONOTONIC, &t_end[200] ); pthread_create( &Threads[ 200 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[201] ); pthread_create( &Threads[ 201 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[202] ); pthread_create( &Threads[ 202 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[203] ); pthread_create( &Threads[ 203 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[204] ); pthread_create( &Threads[ 204 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[205] ); pthread_create( &Threads[ 205 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[206] ); pthread_create( &Threads[ 206 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[207] ); pthread_create( &Threads[ 207 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[208] ); pthread_create( &Threads[ 208 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[209] ); pthread_create( &Threads[ 209 ], &attr, spawn_function, NULL); // 210

	clock_gettime(CLOCK_MONOTONIC, &t_end[210] ); pthread_create( &Threads[ 210 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[211] ); pthread_create( &Threads[ 211 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[212] ); pthread_create( &Threads[ 212 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[213] ); pthread_create( &Threads[ 213 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[214] ); pthread_create( &Threads[ 214 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[215] ); pthread_create( &Threads[ 215 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[216] ); pthread_create( &Threads[ 216 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[217] ); pthread_create( &Threads[ 217 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[218] ); pthread_create( &Threads[ 218 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[219] ); pthread_create( &Threads[ 219 ], &attr, spawn_function, NULL); // 220

	clock_gettime(CLOCK_MONOTONIC, &t_end[220] ); pthread_create( &Threads[ 220 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[221] ); pthread_create( &Threads[ 221 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[222] ); pthread_create( &Threads[ 222 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[223] ); pthread_create( &Threads[ 223 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[224] ); pthread_create( &Threads[ 224 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[225] ); pthread_create( &Threads[ 225 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[226] ); pthread_create( &Threads[ 226 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[227] ); pthread_create( &Threads[ 227 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[228] ); pthread_create( &Threads[ 228 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[229] ); pthread_create( &Threads[ 229 ], &attr, spawn_function, NULL); // 230

	clock_gettime(CLOCK_MONOTONIC, &t_end[230] ); pthread_create( &Threads[ 230 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[231] ); pthread_create( &Threads[ 231 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[232] ); pthread_create( &Threads[ 232 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[233] ); pthread_create( &Threads[ 233 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[234] ); pthread_create( &Threads[ 234 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[235] ); pthread_create( &Threads[ 235 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[236] ); pthread_create( &Threads[ 236 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[237] ); pthread_create( &Threads[ 237 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[238] ); pthread_create( &Threads[ 238 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[239] ); pthread_create( &Threads[ 239 ], &attr, spawn_function, NULL); // 240

	clock_gettime(CLOCK_MONOTONIC, &t_end[240] ); pthread_create( &Threads[ 240 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[241] ); pthread_create( &Threads[ 241 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[242] ); pthread_create( &Threads[ 242 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[243] ); pthread_create( &Threads[ 243 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[244] ); pthread_create( &Threads[ 244 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[245] ); pthread_create( &Threads[ 245 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[246] ); pthread_create( &Threads[ 246 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[247] ); pthread_create( &Threads[ 247 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[248] ); pthread_create( &Threads[ 248 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[249] ); pthread_create( &Threads[ 249 ], &attr, spawn_function, NULL); // 250

	clock_gettime(CLOCK_MONOTONIC, &t_end[250] ); pthread_create( &Threads[ 250 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[251] ); pthread_create( &Threads[ 251 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[252] ); pthread_create( &Threads[ 252 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[253] ); pthread_create( &Threads[ 253 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[254] ); pthread_create( &Threads[ 254 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[255] ); pthread_create( &Threads[ 255 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[256] ); pthread_create( &Threads[ 256 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[257] ); pthread_create( &Threads[ 257 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[258] ); pthread_create( &Threads[ 258 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[259] ); pthread_create( &Threads[ 259 ], &attr, spawn_function, NULL); // 260

	clock_gettime(CLOCK_MONOTONIC, &t_end[260] ); pthread_create( &Threads[ 260 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[261] ); pthread_create( &Threads[ 261 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[262] ); pthread_create( &Threads[ 262 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[263] ); pthread_create( &Threads[ 263 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[264] ); pthread_create( &Threads[ 264 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[265] ); pthread_create( &Threads[ 265 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[266] ); pthread_create( &Threads[ 266 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[267] ); pthread_create( &Threads[ 267 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[268] ); pthread_create( &Threads[ 268 ], &attr, spawn_function, NULL);
	clock_gettime(CLOCK_MONOTONIC, &t_end[269] ); pthread_create( &Threads[ 269 ], &attr, spawn_function, NULL); // 270

	clock_gettime(CLOCK_MONOTONIC, &t_end[270] ); pthread_create( &Threads[ 270 ], &attr, spawn_function, NULL);
	// clock_gettime(CLOCK_MONOTONIC, &t_end[271] ); pthread_create( &Threads[ 271 ], &attr, spawn_function, NULL); // 272
	// clock_gettime(CLOCK_MONOTONIC, &t_end[272] ); pthread_create( &Threads[ 272 ], &attr, spawn_function, NULL);


	// each thread waits until all threads have hit the barrier, then they all return
	pthread_barrier_wait(&sync_barrier);

	// pthread_destroy_barrier
	pthread_barrier_destroy(&sync_barrier);

	// destroy attr
	pthread_attr_destroy(&attr);


	printf("****\n");
	for(int i = 0; i < DEPTH; i++){

		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	}

	// printf(02C"\n");
		
	return 0;
}
