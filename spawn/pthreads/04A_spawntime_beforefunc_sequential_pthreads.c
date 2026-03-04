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

/* Benchmark: 04A: Spawn time before function ; Sequential Spawns (Pthreads)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));


void* spawn_function(void *t_end){           // Simple Math for Spawn Function

	clock_gettime(CLOCK_MONOTONIC, (struct timespec *)t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return (void *)t_end; 
}

int main(int argc, char *argv[]){

	int DEPTH = 271;

	pthread_t Threads[ DEPTH ];


	struct timespec t_start[DEPTH]; struct timespec t_res;
	struct timespec t_end[DEPTH];

	/****/

	clock_gettime(CLOCK_MONOTONIC, &t_start[0]); pthread_create( &Threads[ 0 ], NULL, spawn_function, (void *)&t_end[0]); // all threads spawn & join
	clock_gettime(CLOCK_MONOTONIC, &t_start[1]); pthread_create( &Threads[ 1 ], NULL, spawn_function, (void *)&t_end[1]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[2]); pthread_create( &Threads[ 2 ], NULL, spawn_function, (void *)&t_end[2]); 
	clock_gettime(CLOCK_MONOTONIC, &t_start[3]); pthread_create( &Threads[ 3 ], NULL, spawn_function, (void *)&t_end[3]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[4]); pthread_create( &Threads[ 4 ], NULL, spawn_function, (void *)&t_end[4]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[5]); pthread_create( &Threads[ 5 ], NULL, spawn_function, (void *)&t_end[5]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[6]); pthread_create( &Threads[ 6 ], NULL, spawn_function, (void *)&t_end[6]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[7]); pthread_create( &Threads[ 7 ], NULL, spawn_function, (void *)&t_end[7]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[8]); pthread_create( &Threads[ 8 ], NULL, spawn_function, (void *)&t_end[8]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[9]); pthread_create( &Threads[ 9 ], NULL, spawn_function, (void *)&t_end[9]); // 10

	clock_gettime(CLOCK_MONOTONIC, &t_start[10]); pthread_create( &Threads[ 10 ], NULL, spawn_function, (void *)&t_end[10]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[11]); pthread_create( &Threads[ 11 ], NULL, spawn_function, (void *)&t_end[11]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[12]); pthread_create( &Threads[ 12 ], NULL, spawn_function, (void *)&t_end[12]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[13]); pthread_create( &Threads[ 13 ], NULL, spawn_function, (void *)&t_end[13]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[14]); pthread_create( &Threads[ 14 ], NULL, spawn_function, (void *)&t_end[14]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[15]); pthread_create( &Threads[ 15 ], NULL, spawn_function, (void *)&t_end[15]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[16]); pthread_create( &Threads[ 16 ], NULL, spawn_function, (void *)&t_end[16]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[17]); pthread_create( &Threads[ 17 ], NULL, spawn_function, (void *)&t_end[17]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[18]); pthread_create( &Threads[ 18 ], NULL, spawn_function, (void *)&t_end[18]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[19]); pthread_create( &Threads[ 19 ], NULL, spawn_function, (void *)&t_end[19]); // 20

	clock_gettime(CLOCK_MONOTONIC, &t_start[20]); pthread_create( &Threads[ 20 ], NULL, spawn_function, (void *)&t_end[20]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[21]); pthread_create( &Threads[ 21 ], NULL, spawn_function, (void *)&t_end[21]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[22]); pthread_create( &Threads[ 22 ], NULL, spawn_function, (void *)&t_end[22]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[23]); pthread_create( &Threads[ 23 ], NULL, spawn_function, (void *)&t_end[23]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[24]); pthread_create( &Threads[ 24 ], NULL, spawn_function, (void *)&t_end[24]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[25]); pthread_create( &Threads[ 25 ], NULL, spawn_function, (void *)&t_end[25]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[26]); pthread_create( &Threads[ 26 ], NULL, spawn_function, (void *)&t_end[26]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[27]); pthread_create( &Threads[ 27 ], NULL, spawn_function, (void *)&t_end[27]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[28]); pthread_create( &Threads[ 28 ], NULL, spawn_function, (void *)&t_end[28]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[29]); pthread_create( &Threads[ 29 ], NULL, spawn_function, (void *)&t_end[29]); // 30

	clock_gettime(CLOCK_MONOTONIC, &t_start[30]); pthread_create( &Threads[ 30 ], NULL, spawn_function, (void *)&t_end[30]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[31]); pthread_create( &Threads[ 31 ], NULL, spawn_function, (void *)&t_end[31]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[32]); pthread_create( &Threads[ 32 ], NULL, spawn_function, (void *)&t_end[32]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[33]); pthread_create( &Threads[ 33 ], NULL, spawn_function, (void *)&t_end[33]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[34]); pthread_create( &Threads[ 34 ], NULL, spawn_function, (void *)&t_end[34]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[35]); pthread_create( &Threads[ 35 ], NULL, spawn_function, (void *)&t_end[35]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[36]); pthread_create( &Threads[ 36 ], NULL, spawn_function, (void *)&t_end[36]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[37]); pthread_create( &Threads[ 37 ], NULL, spawn_function, (void *)&t_end[37]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[38]); pthread_create( &Threads[ 38 ], NULL, spawn_function, (void *)&t_end[38]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[39]); pthread_create( &Threads[ 39 ], NULL, spawn_function, (void *)&t_end[39]); // 40

	clock_gettime(CLOCK_MONOTONIC, &t_start[40]); pthread_create( &Threads[ 40 ], NULL, spawn_function, (void *)&t_end[40]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[41]); pthread_create( &Threads[ 41 ], NULL, spawn_function, (void *)&t_end[41]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[42]); pthread_create( &Threads[ 42 ], NULL, spawn_function, (void *)&t_end[42]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[43]); pthread_create( &Threads[ 43 ], NULL, spawn_function, (void *)&t_end[43]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[44]); pthread_create( &Threads[ 44 ], NULL, spawn_function, (void *)&t_end[44]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[45]); pthread_create( &Threads[ 45 ], NULL, spawn_function, (void *)&t_end[45]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[46]); pthread_create( &Threads[ 46 ], NULL, spawn_function, (void *)&t_end[46]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[47]); pthread_create( &Threads[ 47 ], NULL, spawn_function, (void *)&t_end[47]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[48]); pthread_create( &Threads[ 48 ], NULL, spawn_function, (void *)&t_end[48]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[49]); pthread_create( &Threads[ 49 ], NULL, spawn_function, (void *)&t_end[49]); // 50

	clock_gettime(CLOCK_MONOTONIC, &t_start[50]); pthread_create( &Threads[ 50 ], NULL, spawn_function, (void *)&t_end[50]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[51]); pthread_create( &Threads[ 51 ], NULL, spawn_function, (void *)&t_end[51]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[52]); pthread_create( &Threads[ 52 ], NULL, spawn_function, (void *)&t_end[52]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[53]); pthread_create( &Threads[ 53 ], NULL, spawn_function, (void *)&t_end[53]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[54]); pthread_create( &Threads[ 54 ], NULL, spawn_function, (void *)&t_end[54]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[55]); pthread_create( &Threads[ 55 ], NULL, spawn_function, (void *)&t_end[55]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[56]); pthread_create( &Threads[ 56 ], NULL, spawn_function, (void *)&t_end[56]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[57]); pthread_create( &Threads[ 57 ], NULL, spawn_function, (void *)&t_end[57]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[58]); pthread_create( &Threads[ 58 ], NULL, spawn_function, (void *)&t_end[58]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[59]); pthread_create( &Threads[ 59 ], NULL, spawn_function, (void *)&t_end[59]); // 60

	clock_gettime(CLOCK_MONOTONIC, &t_start[60]); pthread_create( &Threads[ 60 ], NULL, spawn_function, (void *)&t_end[60]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[61]); pthread_create( &Threads[ 61 ], NULL, spawn_function, (void *)&t_end[61]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[62]); pthread_create( &Threads[ 62 ], NULL, spawn_function, (void *)&t_end[62]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[63]); pthread_create( &Threads[ 63 ], NULL, spawn_function, (void *)&t_end[63]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[64]); pthread_create( &Threads[ 64 ], NULL, spawn_function, (void *)&t_end[64]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[65]); pthread_create( &Threads[ 65 ], NULL, spawn_function, (void *)&t_end[65]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[66]); pthread_create( &Threads[ 66 ], NULL, spawn_function, (void *)&t_end[66]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[67]); pthread_create( &Threads[ 67 ], NULL, spawn_function, (void *)&t_end[67]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[68]); pthread_create( &Threads[ 68 ], NULL, spawn_function, (void *)&t_end[68]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[69]); pthread_create( &Threads[ 69 ], NULL, spawn_function, (void *)&t_end[69]); // 70

	clock_gettime(CLOCK_MONOTONIC, &t_start[70]); pthread_create( &Threads[ 70 ], NULL, spawn_function, (void *)&t_end[70]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[71]); pthread_create( &Threads[ 71 ], NULL, spawn_function, (void *)&t_end[71]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[72]); pthread_create( &Threads[ 72 ], NULL, spawn_function, (void *)&t_end[72]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[73]); pthread_create( &Threads[ 73 ], NULL, spawn_function, (void *)&t_end[73]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[74]); pthread_create( &Threads[ 74 ], NULL, spawn_function, (void *)&t_end[74]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[75]); pthread_create( &Threads[ 75 ], NULL, spawn_function, (void *)&t_end[75]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[76]); pthread_create( &Threads[ 76 ], NULL, spawn_function, (void *)&t_end[76]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[77]); pthread_create( &Threads[ 77 ], NULL, spawn_function, (void *)&t_end[77]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[78]); pthread_create( &Threads[ 78 ], NULL, spawn_function, (void *)&t_end[78]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[79]); pthread_create( &Threads[ 79 ], NULL, spawn_function, (void *)&t_end[79]); // 80

	clock_gettime(CLOCK_MONOTONIC, &t_start[80]); pthread_create( &Threads[ 80 ], NULL, spawn_function, (void *)&t_end[80]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[81]); pthread_create( &Threads[ 81 ], NULL, spawn_function, (void *)&t_end[81]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[82]); pthread_create( &Threads[ 82 ], NULL, spawn_function, (void *)&t_end[82]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[83]); pthread_create( &Threads[ 83 ], NULL, spawn_function, (void *)&t_end[83]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[84]); pthread_create( &Threads[ 84 ], NULL, spawn_function, (void *)&t_end[84]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[85]); pthread_create( &Threads[ 85 ], NULL, spawn_function, (void *)&t_end[85]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[86]); pthread_create( &Threads[ 86 ], NULL, spawn_function, (void *)&t_end[86]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[87]); pthread_create( &Threads[ 87 ], NULL, spawn_function, (void *)&t_end[87]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[88]); pthread_create( &Threads[ 88 ], NULL, spawn_function, (void *)&t_end[88]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[89]); pthread_create( &Threads[ 89 ], NULL, spawn_function, (void *)&t_end[89]); // 90

	clock_gettime(CLOCK_MONOTONIC, &t_start[90]); pthread_create( &Threads[ 90 ], NULL, spawn_function, (void *)&t_end[90]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[91]); pthread_create( &Threads[ 91 ], NULL, spawn_function, (void *)&t_end[91]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[92]); pthread_create( &Threads[ 92 ], NULL, spawn_function, (void *)&t_end[92]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[93]); pthread_create( &Threads[ 93 ], NULL, spawn_function, (void *)&t_end[93]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[94]); pthread_create( &Threads[ 94 ], NULL, spawn_function, (void *)&t_end[94]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[95]); pthread_create( &Threads[ 95 ], NULL, spawn_function, (void *)&t_end[95]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[96]); pthread_create( &Threads[ 96 ], NULL, spawn_function, (void *)&t_end[96]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[97]); pthread_create( &Threads[ 97 ], NULL, spawn_function, (void *)&t_end[97]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[98]); pthread_create( &Threads[ 98 ], NULL, spawn_function, (void *)&t_end[98]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[99]); pthread_create( &Threads[ 99 ], NULL, spawn_function, (void *)&t_end[99]); // 100

	clock_gettime(CLOCK_MONOTONIC, &t_start[100]); pthread_create( &Threads[ 100 ], NULL, spawn_function, (void *)&t_end[100]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[101]); pthread_create( &Threads[ 101 ], NULL, spawn_function, (void *)&t_end[101]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[102]); pthread_create( &Threads[ 102 ], NULL, spawn_function, (void *)&t_end[102]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[103]); pthread_create( &Threads[ 103 ], NULL, spawn_function, (void *)&t_end[103]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[104]); pthread_create( &Threads[ 104 ], NULL, spawn_function, (void *)&t_end[104]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[105]); pthread_create( &Threads[ 105 ], NULL, spawn_function, (void *)&t_end[105]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[106]); pthread_create( &Threads[ 106 ], NULL, spawn_function, (void *)&t_end[106]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[107]); pthread_create( &Threads[ 107 ], NULL, spawn_function, (void *)&t_end[107]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[108]); pthread_create( &Threads[ 108 ], NULL, spawn_function, (void *)&t_end[108]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[109]); pthread_create( &Threads[ 109 ], NULL, spawn_function, (void *)&t_end[109]); // 110

	clock_gettime(CLOCK_MONOTONIC, &t_start[110]); pthread_create( &Threads[ 110 ], NULL, spawn_function, (void *)&t_end[110]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[111]); pthread_create( &Threads[ 111 ], NULL, spawn_function, (void *)&t_end[111]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[112]); pthread_create( &Threads[ 112 ], NULL, spawn_function, (void *)&t_end[112]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[113]); pthread_create( &Threads[ 113 ], NULL, spawn_function, (void *)&t_end[113]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[114]); pthread_create( &Threads[ 114 ], NULL, spawn_function, (void *)&t_end[114]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[115]); pthread_create( &Threads[ 115 ], NULL, spawn_function, (void *)&t_end[115]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[116]); pthread_create( &Threads[ 116 ], NULL, spawn_function, (void *)&t_end[116]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[117]); pthread_create( &Threads[ 117 ], NULL, spawn_function, (void *)&t_end[117]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[118]); pthread_create( &Threads[ 118 ], NULL, spawn_function, (void *)&t_end[118]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[119]); pthread_create( &Threads[ 119 ], NULL, spawn_function, (void *)&t_end[119]); // 120

	clock_gettime(CLOCK_MONOTONIC, &t_start[120]); pthread_create( &Threads[ 120 ], NULL, spawn_function, (void *)&t_end[120]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[121]); pthread_create( &Threads[ 121 ], NULL, spawn_function, (void *)&t_end[121]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[122]); pthread_create( &Threads[ 122 ], NULL, spawn_function, (void *)&t_end[122]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[123]); pthread_create( &Threads[ 123 ], NULL, spawn_function, (void *)&t_end[123]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[124]); pthread_create( &Threads[ 124 ], NULL, spawn_function, (void *)&t_end[124]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[125]); pthread_create( &Threads[ 125 ], NULL, spawn_function, (void *)&t_end[125]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[126]); pthread_create( &Threads[ 126 ], NULL, spawn_function, (void *)&t_end[126]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[127]); pthread_create( &Threads[ 127 ], NULL, spawn_function, (void *)&t_end[127]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[128]); pthread_create( &Threads[ 128 ], NULL, spawn_function, (void *)&t_end[128]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[129]); pthread_create( &Threads[ 129 ], NULL, spawn_function, (void *)&t_end[129]); // 130

	clock_gettime(CLOCK_MONOTONIC, &t_start[130]); pthread_create( &Threads[ 130 ], NULL, spawn_function, (void *)&t_end[130]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[131]); pthread_create( &Threads[ 131 ], NULL, spawn_function, (void *)&t_end[131]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[132]); pthread_create( &Threads[ 132 ], NULL, spawn_function, (void *)&t_end[132]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[133]); pthread_create( &Threads[ 133 ], NULL, spawn_function, (void *)&t_end[133]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[134]); pthread_create( &Threads[ 134 ], NULL, spawn_function, (void *)&t_end[134]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[135]); pthread_create( &Threads[ 135 ], NULL, spawn_function, (void *)&t_end[135]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[136]); pthread_create( &Threads[ 136 ], NULL, spawn_function, (void *)&t_end[136]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[137]); pthread_create( &Threads[ 137 ], NULL, spawn_function, (void *)&t_end[137]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[138]); pthread_create( &Threads[ 138 ], NULL, spawn_function, (void *)&t_end[138]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[139]); pthread_create( &Threads[ 139 ], NULL, spawn_function, (void *)&t_end[139]); // 140

	clock_gettime(CLOCK_MONOTONIC, &t_start[140]); pthread_create( &Threads[ 140 ], NULL, spawn_function, (void *)&t_end[140]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[141]); pthread_create( &Threads[ 141 ], NULL, spawn_function, (void *)&t_end[141]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[142]); pthread_create( &Threads[ 142 ], NULL, spawn_function, (void *)&t_end[142]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[143]); pthread_create( &Threads[ 143 ], NULL, spawn_function, (void *)&t_end[143]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[144]); pthread_create( &Threads[ 144 ], NULL, spawn_function, (void *)&t_end[144]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[145]); pthread_create( &Threads[ 145 ], NULL, spawn_function, (void *)&t_end[145]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[146]); pthread_create( &Threads[ 146 ], NULL, spawn_function, (void *)&t_end[146]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[147]); pthread_create( &Threads[ 147 ], NULL, spawn_function, (void *)&t_end[147]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[148]); pthread_create( &Threads[ 148 ], NULL, spawn_function, (void *)&t_end[148]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[149]); pthread_create( &Threads[ 149 ], NULL, spawn_function, (void *)&t_end[149]); // 150

	clock_gettime(CLOCK_MONOTONIC, &t_start[150]); pthread_create( &Threads[ 150 ], NULL, spawn_function, (void *)&t_end[150]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[151]); pthread_create( &Threads[ 151 ], NULL, spawn_function, (void *)&t_end[151]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[152]); pthread_create( &Threads[ 152 ], NULL, spawn_function, (void *)&t_end[152]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[153]); pthread_create( &Threads[ 153 ], NULL, spawn_function, (void *)&t_end[153]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[154]); pthread_create( &Threads[ 154 ], NULL, spawn_function, (void *)&t_end[154]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[155]); pthread_create( &Threads[ 155 ], NULL, spawn_function, (void *)&t_end[155]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[156]); pthread_create( &Threads[ 156 ], NULL, spawn_function, (void *)&t_end[156]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[157]); pthread_create( &Threads[ 157 ], NULL, spawn_function, (void *)&t_end[157]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[158]); pthread_create( &Threads[ 158 ], NULL, spawn_function, (void *)&t_end[158]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[159]); pthread_create( &Threads[ 159 ], NULL, spawn_function, (void *)&t_end[159]); // 160

	clock_gettime(CLOCK_MONOTONIC, &t_start[160]); pthread_create( &Threads[ 160 ], NULL, spawn_function, (void *)&t_end[160]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[161]); pthread_create( &Threads[ 161 ], NULL, spawn_function, (void *)&t_end[161]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[162]); pthread_create( &Threads[ 162 ], NULL, spawn_function, (void *)&t_end[162]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[163]); pthread_create( &Threads[ 163 ], NULL, spawn_function, (void *)&t_end[163]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[164]); pthread_create( &Threads[ 164 ], NULL, spawn_function, (void *)&t_end[164]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[165]); pthread_create( &Threads[ 165 ], NULL, spawn_function, (void *)&t_end[165]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[166]); pthread_create( &Threads[ 166 ], NULL, spawn_function, (void *)&t_end[166]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[167]); pthread_create( &Threads[ 167 ], NULL, spawn_function, (void *)&t_end[167]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[168]); pthread_create( &Threads[ 168 ], NULL, spawn_function, (void *)&t_end[168]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[169]); pthread_create( &Threads[ 169 ], NULL, spawn_function, (void *)&t_end[169]); // 170

	clock_gettime(CLOCK_MONOTONIC, &t_start[170]); pthread_create( &Threads[ 170 ], NULL, spawn_function, (void *)&t_end[170]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[171]); pthread_create( &Threads[ 171 ], NULL, spawn_function, (void *)&t_end[171]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[172]); pthread_create( &Threads[ 172 ], NULL, spawn_function, (void *)&t_end[172]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[173]); pthread_create( &Threads[ 173 ], NULL, spawn_function, (void *)&t_end[173]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[174]); pthread_create( &Threads[ 174 ], NULL, spawn_function, (void *)&t_end[174]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[175]); pthread_create( &Threads[ 175 ], NULL, spawn_function, (void *)&t_end[175]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[176]); pthread_create( &Threads[ 176 ], NULL, spawn_function, (void *)&t_end[176]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[177]); pthread_create( &Threads[ 177 ], NULL, spawn_function, (void *)&t_end[177]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[178]); pthread_create( &Threads[ 178 ], NULL, spawn_function, (void *)&t_end[178]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[179]); pthread_create( &Threads[ 179 ], NULL, spawn_function, (void *)&t_end[179]); // 180

	clock_gettime(CLOCK_MONOTONIC, &t_start[180]); pthread_create( &Threads[ 180 ], NULL, spawn_function, (void *)&t_end[180]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[181]); pthread_create( &Threads[ 181 ], NULL, spawn_function, (void *)&t_end[181]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[182]); pthread_create( &Threads[ 182 ], NULL, spawn_function, (void *)&t_end[182]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[183]); pthread_create( &Threads[ 183 ], NULL, spawn_function, (void *)&t_end[183]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[184]); pthread_create( &Threads[ 184 ], NULL, spawn_function, (void *)&t_end[184]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[185]); pthread_create( &Threads[ 185 ], NULL, spawn_function, (void *)&t_end[185]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[186]); pthread_create( &Threads[ 186 ], NULL, spawn_function, (void *)&t_end[186]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[187]); pthread_create( &Threads[ 187 ], NULL, spawn_function, (void *)&t_end[187]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[188]); pthread_create( &Threads[ 188 ], NULL, spawn_function, (void *)&t_end[188]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[189]); pthread_create( &Threads[ 189 ], NULL, spawn_function, (void *)&t_end[189]); // 190

	clock_gettime(CLOCK_MONOTONIC, &t_start[190]); pthread_create( &Threads[ 190 ], NULL, spawn_function, (void *)&t_end[190]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[191]); pthread_create( &Threads[ 191 ], NULL, spawn_function, (void *)&t_end[191]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[192]); pthread_create( &Threads[ 192 ], NULL, spawn_function, (void *)&t_end[192]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[193]); pthread_create( &Threads[ 193 ], NULL, spawn_function, (void *)&t_end[193]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[194]); pthread_create( &Threads[ 194 ], NULL, spawn_function, (void *)&t_end[194]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[195]); pthread_create( &Threads[ 195 ], NULL, spawn_function, (void *)&t_end[195]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[196]); pthread_create( &Threads[ 196 ], NULL, spawn_function, (void *)&t_end[196]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[197]); pthread_create( &Threads[ 197 ], NULL, spawn_function, (void *)&t_end[197]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[198]); pthread_create( &Threads[ 198 ], NULL, spawn_function, (void *)&t_end[198]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[199]); pthread_create( &Threads[ 199 ], NULL, spawn_function, (void *)&t_end[199]); // 200

	clock_gettime(CLOCK_MONOTONIC, &t_start[200]); pthread_create( &Threads[ 200 ], NULL, spawn_function, (void *)&t_end[200]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[201]); pthread_create( &Threads[ 201 ], NULL, spawn_function, (void *)&t_end[201]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[202]); pthread_create( &Threads[ 202 ], NULL, spawn_function, (void *)&t_end[202]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[203]); pthread_create( &Threads[ 203 ], NULL, spawn_function, (void *)&t_end[203]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[204]); pthread_create( &Threads[ 204 ], NULL, spawn_function, (void *)&t_end[204]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[205]); pthread_create( &Threads[ 205 ], NULL, spawn_function, (void *)&t_end[205]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[206]); pthread_create( &Threads[ 206 ], NULL, spawn_function, (void *)&t_end[206]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[207]); pthread_create( &Threads[ 207 ], NULL, spawn_function, (void *)&t_end[207]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[208]); pthread_create( &Threads[ 208 ], NULL, spawn_function, (void *)&t_end[208]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[209]); pthread_create( &Threads[ 209 ], NULL, spawn_function, (void *)&t_end[209]); // 210

	clock_gettime(CLOCK_MONOTONIC, &t_start[210]); pthread_create( &Threads[ 210 ], NULL, spawn_function, (void *)&t_end[210]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[211]); pthread_create( &Threads[ 211 ], NULL, spawn_function, (void *)&t_end[211]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[212]); pthread_create( &Threads[ 212 ], NULL, spawn_function, (void *)&t_end[212]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[213]); pthread_create( &Threads[ 213 ], NULL, spawn_function, (void *)&t_end[213]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[214]); pthread_create( &Threads[ 214 ], NULL, spawn_function, (void *)&t_end[214]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[215]); pthread_create( &Threads[ 215 ], NULL, spawn_function, (void *)&t_end[215]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[216]); pthread_create( &Threads[ 216 ], NULL, spawn_function, (void *)&t_end[216]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[217]); pthread_create( &Threads[ 217 ], NULL, spawn_function, (void *)&t_end[217]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[218]); pthread_create( &Threads[ 218 ], NULL, spawn_function, (void *)&t_end[218]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[219]); pthread_create( &Threads[ 219 ], NULL, spawn_function, (void *)&t_end[219]); // 220

	clock_gettime(CLOCK_MONOTONIC, &t_start[220]); pthread_create( &Threads[ 220 ], NULL, spawn_function, (void *)&t_end[220]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[221]); pthread_create( &Threads[ 221 ], NULL, spawn_function, (void *)&t_end[221]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[222]); pthread_create( &Threads[ 222 ], NULL, spawn_function, (void *)&t_end[222]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[223]); pthread_create( &Threads[ 223 ], NULL, spawn_function, (void *)&t_end[223]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[224]); pthread_create( &Threads[ 224 ], NULL, spawn_function, (void *)&t_end[224]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[225]); pthread_create( &Threads[ 225 ], NULL, spawn_function, (void *)&t_end[225]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[226]); pthread_create( &Threads[ 226 ], NULL, spawn_function, (void *)&t_end[226]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[227]); pthread_create( &Threads[ 227 ], NULL, spawn_function, (void *)&t_end[227]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[228]); pthread_create( &Threads[ 228 ], NULL, spawn_function, (void *)&t_end[228]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[229]); pthread_create( &Threads[ 229 ], NULL, spawn_function, (void *)&t_end[229]); // 230

	clock_gettime(CLOCK_MONOTONIC, &t_start[230]); pthread_create( &Threads[ 230 ], NULL, spawn_function, (void *)&t_end[230]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[231]); pthread_create( &Threads[ 231 ], NULL, spawn_function, (void *)&t_end[231]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[232]); pthread_create( &Threads[ 232 ], NULL, spawn_function, (void *)&t_end[232]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[233]); pthread_create( &Threads[ 233 ], NULL, spawn_function, (void *)&t_end[233]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[234]); pthread_create( &Threads[ 234 ], NULL, spawn_function, (void *)&t_end[234]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[235]); pthread_create( &Threads[ 235 ], NULL, spawn_function, (void *)&t_end[235]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[236]); pthread_create( &Threads[ 236 ], NULL, spawn_function, (void *)&t_end[236]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[237]); pthread_create( &Threads[ 237 ], NULL, spawn_function, (void *)&t_end[237]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[238]); pthread_create( &Threads[ 238 ], NULL, spawn_function, (void *)&t_end[238]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[239]); pthread_create( &Threads[ 239 ], NULL, spawn_function, (void *)&t_end[239]); // 240

	clock_gettime(CLOCK_MONOTONIC, &t_start[240]); pthread_create( &Threads[ 240 ], NULL, spawn_function, (void *)&t_end[240]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[241]); pthread_create( &Threads[ 241 ], NULL, spawn_function, (void *)&t_end[241]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[242]); pthread_create( &Threads[ 242 ], NULL, spawn_function, (void *)&t_end[242]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[243]); pthread_create( &Threads[ 243 ], NULL, spawn_function, (void *)&t_end[243]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[244]); pthread_create( &Threads[ 244 ], NULL, spawn_function, (void *)&t_end[244]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[245]); pthread_create( &Threads[ 245 ], NULL, spawn_function, (void *)&t_end[245]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[246]); pthread_create( &Threads[ 246 ], NULL, spawn_function, (void *)&t_end[246]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[247]); pthread_create( &Threads[ 247 ], NULL, spawn_function, (void *)&t_end[247]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[248]); pthread_create( &Threads[ 248 ], NULL, spawn_function, (void *)&t_end[248]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[249]); pthread_create( &Threads[ 249 ], NULL, spawn_function, (void *)&t_end[249]); // 250

	clock_gettime(CLOCK_MONOTONIC, &t_start[250]); pthread_create( &Threads[ 250 ], NULL, spawn_function, (void *)&t_end[250]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[251]); pthread_create( &Threads[ 251 ], NULL, spawn_function, (void *)&t_end[251]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[252]); pthread_create( &Threads[ 252 ], NULL, spawn_function, (void *)&t_end[252]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[253]); pthread_create( &Threads[ 253 ], NULL, spawn_function, (void *)&t_end[253]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[254]); pthread_create( &Threads[ 254 ], NULL, spawn_function, (void *)&t_end[254]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[255]); pthread_create( &Threads[ 255 ], NULL, spawn_function, (void *)&t_end[255]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[256]); pthread_create( &Threads[ 256 ], NULL, spawn_function, (void *)&t_end[256]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[257]); pthread_create( &Threads[ 257 ], NULL, spawn_function, (void *)&t_end[257]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[258]); pthread_create( &Threads[ 258 ], NULL, spawn_function, (void *)&t_end[258]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[259]); pthread_create( &Threads[ 259 ], NULL, spawn_function, (void *)&t_end[259]); // 260

	clock_gettime(CLOCK_MONOTONIC, &t_start[260]); pthread_create( &Threads[ 260 ], NULL, spawn_function, (void *)&t_end[260]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[261]); pthread_create( &Threads[ 261 ], NULL, spawn_function, (void *)&t_end[261]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[262]); pthread_create( &Threads[ 262 ], NULL, spawn_function, (void *)&t_end[262]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[263]); pthread_create( &Threads[ 263 ], NULL, spawn_function, (void *)&t_end[263]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[264]); pthread_create( &Threads[ 264 ], NULL, spawn_function, (void *)&t_end[264]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[265]); pthread_create( &Threads[ 265 ], NULL, spawn_function, (void *)&t_end[265]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[266]); pthread_create( &Threads[ 266 ], NULL, spawn_function, (void *)&t_end[266]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[267]); pthread_create( &Threads[ 267 ], NULL, spawn_function, (void *)&t_end[267]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[268]); pthread_create( &Threads[ 268 ], NULL, spawn_function, (void *)&t_end[268]);
	clock_gettime(CLOCK_MONOTONIC, &t_start[269]); pthread_create( &Threads[ 269 ], NULL, spawn_function, (void *)&t_end[269]); // 270

	clock_gettime(CLOCK_MONOTONIC, &t_start[270]); pthread_create( &Threads[ 270 ], NULL, spawn_function, (void *)&t_end[270]);
	// clock_gettime(CLOCK_MONOTONIC, &t_start[271]); pthread_create( &Threads[ 271 ], NULL, spawn_function, (void *)&t_end[271]); // 272
	// clock_gettime(CLOCK_MONOTONIC, &t_start[272]); pthread_create( &Threads[ 272 ], NULL, spawn_function, (void *)&t_end[272]);
	
	/****/
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
	pthread_join( Threads[ 29 ], (void *)&temp); temp = &t_end[30]; // 30

	pthread_join( Threads[ 30 ], (void *)&temp); temp = &t_end[31];
	pthread_join( Threads[ 31 ], (void *)&temp); temp = &t_end[32];
	pthread_join( Threads[ 32 ], (void *)&temp); temp = &t_end[33];
	pthread_join( Threads[ 33 ], (void *)&temp); temp = &t_end[34];
	pthread_join( Threads[ 34 ], (void *)&temp); temp = &t_end[35];
	pthread_join( Threads[ 35 ], (void *)&temp); temp = &t_end[36];
	pthread_join( Threads[ 36 ], (void *)&temp); temp = &t_end[37];
	pthread_join( Threads[ 37 ], (void *)&temp); temp = &t_end[38];
	pthread_join( Threads[ 38 ], (void *)&temp); temp = &t_end[39];
	pthread_join( Threads[ 39 ], (void *)&temp); temp = &t_end[40]; // 40

	pthread_join( Threads[ 40 ], (void *)&temp); temp = &t_end[41];
	pthread_join( Threads[ 41 ], (void *)&temp); temp = &t_end[42];
	pthread_join( Threads[ 42 ], (void *)&temp); temp = &t_end[43];
	pthread_join( Threads[ 43 ], (void *)&temp); temp = &t_end[44];
	pthread_join( Threads[ 44 ], (void *)&temp); temp = &t_end[45];
	pthread_join( Threads[ 45 ], (void *)&temp); temp = &t_end[46];
	pthread_join( Threads[ 46 ], (void *)&temp); temp = &t_end[47];
	pthread_join( Threads[ 47 ], (void *)&temp); temp = &t_end[48];
	pthread_join( Threads[ 48 ], (void *)&temp); temp = &t_end[49];
	pthread_join( Threads[ 49 ], (void *)&temp); temp = &t_end[50]; // 50

	pthread_join( Threads[ 50 ], (void *)&temp); temp = &t_end[51];
	pthread_join( Threads[ 51 ], (void *)&temp); temp = &t_end[52];
	pthread_join( Threads[ 52 ], (void *)&temp); temp = &t_end[53];
	pthread_join( Threads[ 53 ], (void *)&temp); temp = &t_end[54];
	pthread_join( Threads[ 54 ], (void *)&temp); temp = &t_end[55];
	pthread_join( Threads[ 55 ], (void *)&temp); temp = &t_end[56];
	pthread_join( Threads[ 56 ], (void *)&temp); temp = &t_end[57];
	pthread_join( Threads[ 57 ], (void *)&temp); temp = &t_end[58];
	pthread_join( Threads[ 58 ], (void *)&temp); temp = &t_end[59];
	pthread_join( Threads[ 59 ], (void *)&temp); temp = &t_end[60]; // 60

	pthread_join( Threads[ 60 ], (void *)&temp); temp = &t_end[61];
	pthread_join( Threads[ 61 ], (void *)&temp); temp = &t_end[62];
	pthread_join( Threads[ 62 ], (void *)&temp); temp = &t_end[63];
	pthread_join( Threads[ 63 ], (void *)&temp); temp = &t_end[64];
	pthread_join( Threads[ 64 ], (void *)&temp); temp = &t_end[65];
	pthread_join( Threads[ 65 ], (void *)&temp); temp = &t_end[66];
	pthread_join( Threads[ 66 ], (void *)&temp); temp = &t_end[67];
	pthread_join( Threads[ 67 ], (void *)&temp); temp = &t_end[68];
	pthread_join( Threads[ 68 ], (void *)&temp); temp = &t_end[69];
	pthread_join( Threads[ 69 ], (void *)&temp); temp = &t_end[70]; // 70

	pthread_join( Threads[ 70 ], (void *)&temp); temp = &t_end[71];
	pthread_join( Threads[ 71 ], (void *)&temp); temp = &t_end[72];
	pthread_join( Threads[ 72 ], (void *)&temp); temp = &t_end[73];
	pthread_join( Threads[ 73 ], (void *)&temp); temp = &t_end[74];
	pthread_join( Threads[ 74 ], (void *)&temp); temp = &t_end[75];
	pthread_join( Threads[ 75 ], (void *)&temp); temp = &t_end[76];
	pthread_join( Threads[ 76 ], (void *)&temp); temp = &t_end[77];
	pthread_join( Threads[ 77 ], (void *)&temp); temp = &t_end[78];
	pthread_join( Threads[ 78 ], (void *)&temp); temp = &t_end[79];
	pthread_join( Threads[ 79 ], (void *)&temp); temp = &t_end[80]; // 80

	pthread_join( Threads[ 80 ], (void *)&temp); temp = &t_end[81];
	pthread_join( Threads[ 81 ], (void *)&temp); temp = &t_end[82];
	pthread_join( Threads[ 82 ], (void *)&temp); temp = &t_end[83];
	pthread_join( Threads[ 83 ], (void *)&temp); temp = &t_end[84];
	pthread_join( Threads[ 84 ], (void *)&temp); temp = &t_end[85];
	pthread_join( Threads[ 85 ], (void *)&temp); temp = &t_end[86];
	pthread_join( Threads[ 86 ], (void *)&temp); temp = &t_end[87];
	pthread_join( Threads[ 87 ], (void *)&temp); temp = &t_end[88];
	pthread_join( Threads[ 88 ], (void *)&temp); temp = &t_end[89];
	pthread_join( Threads[ 89 ], (void *)&temp); temp = &t_end[90]; // 90

	pthread_join( Threads[ 90 ], (void *)&temp); temp = &t_end[91];
	pthread_join( Threads[ 91 ], (void *)&temp); temp = &t_end[92];
	pthread_join( Threads[ 92 ], (void *)&temp); temp = &t_end[93];
	pthread_join( Threads[ 93 ], (void *)&temp); temp = &t_end[94];
	pthread_join( Threads[ 94 ], (void *)&temp); temp = &t_end[95];
	pthread_join( Threads[ 95 ], (void *)&temp); temp = &t_end[96];
	pthread_join( Threads[ 96 ], (void *)&temp); temp = &t_end[97];
	pthread_join( Threads[ 97 ], (void *)&temp); temp = &t_end[98];
	pthread_join( Threads[ 98 ], (void *)&temp); temp = &t_end[99];
	pthread_join( Threads[ 99 ], (void *)&temp); temp = &t_end[100]; // 100

	pthread_join( Threads[ 100 ], (void *)&temp); temp = &t_end[101];
	pthread_join( Threads[ 101 ], (void *)&temp); temp = &t_end[102];
	pthread_join( Threads[ 102 ], (void *)&temp); temp = &t_end[103];
	pthread_join( Threads[ 103 ], (void *)&temp); temp = &t_end[104];
	pthread_join( Threads[ 104 ], (void *)&temp); temp = &t_end[105];
	pthread_join( Threads[ 105 ], (void *)&temp); temp = &t_end[106];
	pthread_join( Threads[ 106 ], (void *)&temp); temp = &t_end[107];
	pthread_join( Threads[ 107 ], (void *)&temp); temp = &t_end[108];
	pthread_join( Threads[ 108 ], (void *)&temp); temp = &t_end[109];
	pthread_join( Threads[ 109 ], (void *)&temp); temp = &t_end[110]; // 110

	pthread_join( Threads[ 110 ], (void *)&temp); temp = &t_end[111];
	pthread_join( Threads[ 111 ], (void *)&temp); temp = &t_end[112];
	pthread_join( Threads[ 112 ], (void *)&temp); temp = &t_end[113];
	pthread_join( Threads[ 113 ], (void *)&temp); temp = &t_end[114];
	pthread_join( Threads[ 114 ], (void *)&temp); temp = &t_end[115];
	pthread_join( Threads[ 115 ], (void *)&temp); temp = &t_end[116];
	pthread_join( Threads[ 116 ], (void *)&temp); temp = &t_end[117];
	pthread_join( Threads[ 117 ], (void *)&temp); temp = &t_end[118];
	pthread_join( Threads[ 118 ], (void *)&temp); temp = &t_end[119];
	pthread_join( Threads[ 119 ], (void *)&temp); temp = &t_end[120]; // 120

	pthread_join( Threads[ 120 ], (void *)&temp); temp = &t_end[121];
	pthread_join( Threads[ 121 ], (void *)&temp); temp = &t_end[122];
	pthread_join( Threads[ 122 ], (void *)&temp); temp = &t_end[123];
	pthread_join( Threads[ 123 ], (void *)&temp); temp = &t_end[124];
	pthread_join( Threads[ 124 ], (void *)&temp); temp = &t_end[125];
	pthread_join( Threads[ 125 ], (void *)&temp); temp = &t_end[126];
	pthread_join( Threads[ 126 ], (void *)&temp); temp = &t_end[127];
	pthread_join( Threads[ 127 ], (void *)&temp); temp = &t_end[128];
	pthread_join( Threads[ 128 ], (void *)&temp); temp = &t_end[129];
	pthread_join( Threads[ 129 ], (void *)&temp); temp = &t_end[130]; // 130

	pthread_join( Threads[ 130 ], (void *)&temp); temp = &t_end[131];
	pthread_join( Threads[ 131 ], (void *)&temp); temp = &t_end[132];
	pthread_join( Threads[ 132 ], (void *)&temp); temp = &t_end[133];
	pthread_join( Threads[ 133 ], (void *)&temp); temp = &t_end[134];
	pthread_join( Threads[ 134 ], (void *)&temp); temp = &t_end[135];
	pthread_join( Threads[ 135 ], (void *)&temp); temp = &t_end[136];
	pthread_join( Threads[ 136 ], (void *)&temp); temp = &t_end[137];
	pthread_join( Threads[ 137 ], (void *)&temp); temp = &t_end[138];
	pthread_join( Threads[ 138 ], (void *)&temp); temp = &t_end[139];
	pthread_join( Threads[ 139 ], (void *)&temp); temp = &t_end[140]; // 140

	pthread_join( Threads[ 140 ], (void *)&temp); temp = &t_end[141];
	pthread_join( Threads[ 141 ], (void *)&temp); temp = &t_end[142];
	pthread_join( Threads[ 142 ], (void *)&temp); temp = &t_end[143];
	pthread_join( Threads[ 143 ], (void *)&temp); temp = &t_end[144];
	pthread_join( Threads[ 144 ], (void *)&temp); temp = &t_end[145];
	pthread_join( Threads[ 145 ], (void *)&temp); temp = &t_end[146];
	pthread_join( Threads[ 146 ], (void *)&temp); temp = &t_end[147];
	pthread_join( Threads[ 147 ], (void *)&temp); temp = &t_end[148];
	pthread_join( Threads[ 148 ], (void *)&temp); temp = &t_end[149];
	pthread_join( Threads[ 149 ], (void *)&temp); temp = &t_end[150]; // 150

	pthread_join( Threads[ 150 ], (void *)&temp); temp = &t_end[151];
	pthread_join( Threads[ 151 ], (void *)&temp); temp = &t_end[152];
	pthread_join( Threads[ 152 ], (void *)&temp); temp = &t_end[153];
	pthread_join( Threads[ 153 ], (void *)&temp); temp = &t_end[154];
	pthread_join( Threads[ 154 ], (void *)&temp); temp = &t_end[155];
	pthread_join( Threads[ 155 ], (void *)&temp); temp = &t_end[156];
	pthread_join( Threads[ 156 ], (void *)&temp); temp = &t_end[157];
	pthread_join( Threads[ 157 ], (void *)&temp); temp = &t_end[158];
	pthread_join( Threads[ 158 ], (void *)&temp); temp = &t_end[159];
	pthread_join( Threads[ 159 ], (void *)&temp); temp = &t_end[160]; // 160

	pthread_join( Threads[ 160 ], (void *)&temp); temp = &t_end[161];
	pthread_join( Threads[ 161 ], (void *)&temp); temp = &t_end[162];
	pthread_join( Threads[ 162 ], (void *)&temp); temp = &t_end[163];
	pthread_join( Threads[ 163 ], (void *)&temp); temp = &t_end[164];
	pthread_join( Threads[ 164 ], (void *)&temp); temp = &t_end[165];
	pthread_join( Threads[ 165 ], (void *)&temp); temp = &t_end[166];
	pthread_join( Threads[ 166 ], (void *)&temp); temp = &t_end[167];
	pthread_join( Threads[ 167 ], (void *)&temp); temp = &t_end[168];
	pthread_join( Threads[ 168 ], (void *)&temp); temp = &t_end[169];
	pthread_join( Threads[ 169 ], (void *)&temp); temp = &t_end[170]; // 170

	pthread_join( Threads[ 170 ], (void *)&temp); temp = &t_end[171];
	pthread_join( Threads[ 171 ], (void *)&temp); temp = &t_end[172];
	pthread_join( Threads[ 172 ], (void *)&temp); temp = &t_end[173];
	pthread_join( Threads[ 173 ], (void *)&temp); temp = &t_end[174];
	pthread_join( Threads[ 174 ], (void *)&temp); temp = &t_end[175];
	pthread_join( Threads[ 175 ], (void *)&temp); temp = &t_end[176];
	pthread_join( Threads[ 176 ], (void *)&temp); temp = &t_end[177];
	pthread_join( Threads[ 177 ], (void *)&temp); temp = &t_end[178];
	pthread_join( Threads[ 178 ], (void *)&temp); temp = &t_end[179];
	pthread_join( Threads[ 179 ], (void *)&temp); temp = &t_end[180]; // 180

	pthread_join( Threads[ 180 ], (void *)&temp); temp = &t_end[181];
	pthread_join( Threads[ 181 ], (void *)&temp); temp = &t_end[182];
	pthread_join( Threads[ 182 ], (void *)&temp); temp = &t_end[183];
	pthread_join( Threads[ 183 ], (void *)&temp); temp = &t_end[184];
	pthread_join( Threads[ 184 ], (void *)&temp); temp = &t_end[185];
	pthread_join( Threads[ 185 ], (void *)&temp); temp = &t_end[186];
	pthread_join( Threads[ 186 ], (void *)&temp); temp = &t_end[187];
	pthread_join( Threads[ 187 ], (void *)&temp); temp = &t_end[188];
	pthread_join( Threads[ 188 ], (void *)&temp); temp = &t_end[189];
	pthread_join( Threads[ 189 ], (void *)&temp); temp = &t_end[190]; // 190

	pthread_join( Threads[ 190 ], (void *)&temp); temp = &t_end[191];
	pthread_join( Threads[ 191 ], (void *)&temp); temp = &t_end[192];
	pthread_join( Threads[ 192 ], (void *)&temp); temp = &t_end[193];
	pthread_join( Threads[ 193 ], (void *)&temp); temp = &t_end[194];
	pthread_join( Threads[ 194 ], (void *)&temp); temp = &t_end[195];
	pthread_join( Threads[ 195 ], (void *)&temp); temp = &t_end[196];
	pthread_join( Threads[ 196 ], (void *)&temp); temp = &t_end[197];
	pthread_join( Threads[ 197 ], (void *)&temp); temp = &t_end[198];
	pthread_join( Threads[ 198 ], (void *)&temp); temp = &t_end[199];
	pthread_join( Threads[ 199 ], (void *)&temp); temp = &t_end[200]; // 200

	pthread_join( Threads[ 200 ], (void *)&temp); temp = &t_end[201];
	pthread_join( Threads[ 201 ], (void *)&temp); temp = &t_end[202];
	pthread_join( Threads[ 202 ], (void *)&temp); temp = &t_end[203];
	pthread_join( Threads[ 203 ], (void *)&temp); temp = &t_end[204];
	pthread_join( Threads[ 204 ], (void *)&temp); temp = &t_end[205];
	pthread_join( Threads[ 205 ], (void *)&temp); temp = &t_end[206];
	pthread_join( Threads[ 206 ], (void *)&temp); temp = &t_end[207];
	pthread_join( Threads[ 207 ], (void *)&temp); temp = &t_end[208];
	pthread_join( Threads[ 208 ], (void *)&temp); temp = &t_end[209];
	pthread_join( Threads[ 209 ], (void *)&temp); temp = &t_end[210]; // 210

	pthread_join( Threads[ 210 ], (void *)&temp); temp = &t_end[211];
	pthread_join( Threads[ 211 ], (void *)&temp); temp = &t_end[212];
	pthread_join( Threads[ 212 ], (void *)&temp); temp = &t_end[213];
	pthread_join( Threads[ 213 ], (void *)&temp); temp = &t_end[214];
	pthread_join( Threads[ 214 ], (void *)&temp); temp = &t_end[215];
	pthread_join( Threads[ 215 ], (void *)&temp); temp = &t_end[216];
	pthread_join( Threads[ 216 ], (void *)&temp); temp = &t_end[217];
	pthread_join( Threads[ 217 ], (void *)&temp); temp = &t_end[218];
	pthread_join( Threads[ 218 ], (void *)&temp); temp = &t_end[219];
	pthread_join( Threads[ 219 ], (void *)&temp); temp = &t_end[220]; // 220

	pthread_join( Threads[ 220 ], (void *)&temp); temp = &t_end[221];
	pthread_join( Threads[ 221 ], (void *)&temp); temp = &t_end[222];
	pthread_join( Threads[ 222 ], (void *)&temp); temp = &t_end[223];
	pthread_join( Threads[ 223 ], (void *)&temp); temp = &t_end[224];
	pthread_join( Threads[ 224 ], (void *)&temp); temp = &t_end[225];
	pthread_join( Threads[ 225 ], (void *)&temp); temp = &t_end[226];
	pthread_join( Threads[ 226 ], (void *)&temp); temp = &t_end[227];
	pthread_join( Threads[ 227 ], (void *)&temp); temp = &t_end[228];
	pthread_join( Threads[ 228 ], (void *)&temp); temp = &t_end[229];
	pthread_join( Threads[ 229 ], (void *)&temp); temp = &t_end[230]; // 230

	pthread_join( Threads[ 230 ], (void *)&temp); temp = &t_end[231];
	pthread_join( Threads[ 231 ], (void *)&temp); temp = &t_end[232];
	pthread_join( Threads[ 232 ], (void *)&temp); temp = &t_end[233];
	pthread_join( Threads[ 233 ], (void *)&temp); temp = &t_end[234];
	pthread_join( Threads[ 234 ], (void *)&temp); temp = &t_end[235];
	pthread_join( Threads[ 235 ], (void *)&temp); temp = &t_end[236];
	pthread_join( Threads[ 236 ], (void *)&temp); temp = &t_end[237];
	pthread_join( Threads[ 237 ], (void *)&temp); temp = &t_end[238];
	pthread_join( Threads[ 238 ], (void *)&temp); temp = &t_end[239];
	pthread_join( Threads[ 239 ], (void *)&temp); temp = &t_end[240]; // 240

	pthread_join( Threads[ 240 ], (void *)&temp); temp = &t_end[241];
	pthread_join( Threads[ 241 ], (void *)&temp); temp = &t_end[242];
	pthread_join( Threads[ 242 ], (void *)&temp); temp = &t_end[243];
	pthread_join( Threads[ 243 ], (void *)&temp); temp = &t_end[244];
	pthread_join( Threads[ 244 ], (void *)&temp); temp = &t_end[245];
	pthread_join( Threads[ 245 ], (void *)&temp); temp = &t_end[246];
	pthread_join( Threads[ 246 ], (void *)&temp); temp = &t_end[247];
	pthread_join( Threads[ 247 ], (void *)&temp); temp = &t_end[248];
	pthread_join( Threads[ 248 ], (void *)&temp); temp = &t_end[249];
	pthread_join( Threads[ 249 ], (void *)&temp); temp = &t_end[250]; // 250

	pthread_join( Threads[ 250 ], (void *)&temp); temp = &t_end[251];
	pthread_join( Threads[ 251 ], (void *)&temp); temp = &t_end[252];
	pthread_join( Threads[ 252 ], (void *)&temp); temp = &t_end[253];
	pthread_join( Threads[ 253 ], (void *)&temp); temp = &t_end[254];
	pthread_join( Threads[ 254 ], (void *)&temp); temp = &t_end[255];
	pthread_join( Threads[ 255 ], (void *)&temp); temp = &t_end[256];
	pthread_join( Threads[ 256 ], (void *)&temp); temp = &t_end[257];
	pthread_join( Threads[ 257 ], (void *)&temp); temp = &t_end[258];
	pthread_join( Threads[ 258 ], (void *)&temp); temp = &t_end[259];
	pthread_join( Threads[ 259 ], (void *)&temp); temp = &t_end[260]; // 260

	pthread_join( Threads[ 260 ], (void *)&temp); temp = &t_end[261];
	pthread_join( Threads[ 261 ], (void *)&temp); temp = &t_end[262];
	pthread_join( Threads[ 262 ], (void *)&temp); temp = &t_end[263];
	pthread_join( Threads[ 263 ], (void *)&temp); temp = &t_end[264];
	pthread_join( Threads[ 264 ], (void *)&temp); temp = &t_end[265];
	pthread_join( Threads[ 265 ], (void *)&temp); temp = &t_end[266];
	pthread_join( Threads[ 266 ], (void *)&temp); temp = &t_end[267];
	pthread_join( Threads[ 267 ], (void *)&temp); temp = &t_end[268];
	pthread_join( Threads[ 268 ], (void *)&temp); temp = &t_end[269];
	pthread_join( Threads[ 269 ], (void *)&temp); temp = &t_end[270]; // 270

	pthread_join( Threads[ 270 ], (void *)&temp);
	// pthread_join( Threads[ 271 ], (void *)&temp); // 272
	// pthread_join( Threads[ 272 ], (void *)&temp);


	/****/

	for(int i = 0; i < DEPTH; i++){

		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	}
			
	return 0;
}
