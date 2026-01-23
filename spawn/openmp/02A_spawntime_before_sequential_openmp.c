#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: 02A: Spawn time before ; Sequential Spawns (OpenMP)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

struct timespec spawn_function(){           // Simple Function to Spawn

	struct timespec t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; 
}

int main(int argc, char *argv[]){

	int DEPTH = 271;

	struct timespec t_start, t_res;
	struct timespec t_end[DEPTH];

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp


	clock_gettime(CLOCK_MONOTONIC, &t_end[0]); 
	#pragma omp task
		spawn_function(); // Take time stamp before each spawn
	clock_gettime(CLOCK_MONOTONIC, &t_end[1]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[2]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[3]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[4]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[5]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[6]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[7]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[8]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[9]); 
	#pragma omp task
		spawn_function(); // 10

	clock_gettime(CLOCK_MONOTONIC, &t_end[10]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[11]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[12]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[13]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[14]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[15]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[16]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[17]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[18]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[19]); 
	#pragma omp task
		spawn_function(); // 20

	clock_gettime(CLOCK_MONOTONIC, &t_end[20]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[21]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[22]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[23]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[24]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[25]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[26]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[27]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[28]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[29]); 
	#pragma omp task
		spawn_function(); // 30

	clock_gettime(CLOCK_MONOTONIC, &t_end[30]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[31]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[32]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[33]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[34]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[35]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[36]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[37]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[38]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[39]); 
	#pragma omp task
		spawn_function(); // 40

	clock_gettime(CLOCK_MONOTONIC, &t_end[40]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[41]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[42]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[43]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[44]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[45]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[46]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[47]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[48]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[49]); 
	#pragma omp task
		spawn_function(); // 50

	clock_gettime(CLOCK_MONOTONIC, &t_end[50]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[51]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[52]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[53]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[54]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[55]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[56]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[57]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[58]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[59]); 
	#pragma omp task
		spawn_function(); // 60

	clock_gettime(CLOCK_MONOTONIC, &t_end[60]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[61]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[62]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[63]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[64]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[65]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[66]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[67]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[68]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[69]); 
	#pragma omp task
		spawn_function(); // 70

	clock_gettime(CLOCK_MONOTONIC, &t_end[70]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[71]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[72]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[73]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[74]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[75]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[76]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[77]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[78]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[79]); 
	#pragma omp task
		spawn_function(); // 80

	clock_gettime(CLOCK_MONOTONIC, &t_end[80]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[81]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[82]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[83]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[84]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[85]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[86]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[87]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[88]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[89]); 
	#pragma omp task
		spawn_function(); // 90

	clock_gettime(CLOCK_MONOTONIC, &t_end[90]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[91]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[92]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[93]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[94]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[95]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[96]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[97]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[98]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[99]); 
	#pragma omp task
		spawn_function(); // 100

	clock_gettime(CLOCK_MONOTONIC, &t_end[100]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[101]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[102]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[103]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[104]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[105]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[106]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[107]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[108]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[109]); 
	#pragma omp task
		spawn_function(); // 110

	clock_gettime(CLOCK_MONOTONIC, &t_end[110]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[111]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[112]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[113]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[114]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[115]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[116]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[117]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[118]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[119]); 
	#pragma omp task
		spawn_function(); // 120

	clock_gettime(CLOCK_MONOTONIC, &t_end[120]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[121]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[122]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[123]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[124]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[125]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[126]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[127]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[128]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[129]); 
	#pragma omp task
		spawn_function(); // 130

	clock_gettime(CLOCK_MONOTONIC, &t_end[130]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[131]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[132]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[133]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[134]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[135]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[136]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[137]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[138]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[139]); 
	#pragma omp task
		spawn_function(); // 140

	clock_gettime(CLOCK_MONOTONIC, &t_end[140]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[141]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[142]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[143]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[144]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[145]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[146]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[147]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[148]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[149]); 
	#pragma omp task
		spawn_function(); // 150

	clock_gettime(CLOCK_MONOTONIC, &t_end[150]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[151]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[152]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[153]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[154]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[155]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[156]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[157]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[158]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[159]); 
	#pragma omp task
		spawn_function(); // 160

	clock_gettime(CLOCK_MONOTONIC, &t_end[160]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[161]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[162]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[163]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[164]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[165]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[166]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[167]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[168]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[169]); 
	#pragma omp task
		spawn_function(); // 170

	clock_gettime(CLOCK_MONOTONIC, &t_end[170]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[171]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[172]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[173]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[174]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[175]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[176]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[177]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[178]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[179]); 
	#pragma omp task
		spawn_function(); // 180

	clock_gettime(CLOCK_MONOTONIC, &t_end[180]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[181]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[182]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[183]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[184]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[185]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[186]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[187]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[188]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[189]); 
	#pragma omp task
		spawn_function(); // 190

	clock_gettime(CLOCK_MONOTONIC, &t_end[190]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[191]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[192]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[193]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[194]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[195]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[196]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[197]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[198]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[199]); 
	#pragma omp task
		spawn_function(); // 200

	clock_gettime(CLOCK_MONOTONIC, &t_end[200]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[201]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[202]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[203]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[204]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[205]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[206]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[207]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[208]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[209]); 
	#pragma omp task
		spawn_function(); // 210

	clock_gettime(CLOCK_MONOTONIC, &t_end[210]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[211]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[212]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[213]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[214]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[215]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[216]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[217]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[218]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[219]); 
	#pragma omp task
		spawn_function(); // 220

	clock_gettime(CLOCK_MONOTONIC, &t_end[220]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[221]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[222]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[223]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[224]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[225]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[226]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[227]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[228]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[229]); 
	#pragma omp task
		spawn_function(); // 230

	clock_gettime(CLOCK_MONOTONIC, &t_end[230]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[231]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[232]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[233]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[234]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[235]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[236]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[237]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[238]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[239]); 
	#pragma omp task
		spawn_function(); // 240

	clock_gettime(CLOCK_MONOTONIC, &t_end[240]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[241]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[242]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[243]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[244]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[245]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[246]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[247]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[248]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[249]); 
	#pragma omp task
		spawn_function(); // 250

	clock_gettime(CLOCK_MONOTONIC, &t_end[250]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[251]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[252]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[253]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[254]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[255]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[256]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[257]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[258]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[259]); 
	#pragma omp task
		spawn_function(); // 260

	clock_gettime(CLOCK_MONOTONIC, &t_end[260]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[261]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[262]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[263]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[264]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[265]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[266]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[267]); 
	#pragma omp task
		spawn_function();

	clock_gettime(CLOCK_MONOTONIC, &t_end[268]); 
	#pragma omp task
		spawn_function();
	clock_gettime(CLOCK_MONOTONIC, &t_end[269]); 
	#pragma omp task
		spawn_function(); // 270

	clock_gettime(CLOCK_MONOTONIC, &t_end[270]); 
	#pragma omp task
		spawn_function(); // 271



	for(int i = 0; i < DEPTH; i++){

		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	return 0;
}


