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

	int PTH = 100;

	pthread_t Threads[ PTH ];


	struct timespec t_start[PTH]; struct timespec t_res;
	struct timespec t_end[PTH];

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


	/****/

	for(int i = 0; i < PTH; i++){

		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);	

	}
			
	return 0;
}
