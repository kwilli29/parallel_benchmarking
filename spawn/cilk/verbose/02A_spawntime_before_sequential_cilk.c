#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Benchmark: 02A: Spawn time before ; Sequential Spawns (Cilk)
 * Launch a bunch and measure when all done
 */

void spawn_function(){           // Simple Function to Spawn

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

    int NCILK = __cilkrts_get_nworkers();

	printf("# Spawns: %d\n", NCILK);

	struct timespec t_start, t_res;
	struct timespec t_end[NCILK];
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

	// sequentially spawn functions

		clock_gettime(CLOCK_MONOTONIC, &t_end[0]); cilk_spawn spawn_function(); // 1 // Take time stamp before each spawn
		clock_gettime(CLOCK_MONOTONIC, &t_end[1]); cilk_spawn spawn_function(); // 2
		clock_gettime(CLOCK_MONOTONIC, &t_end[2]); cilk_spawn spawn_function(); // 3
		clock_gettime(CLOCK_MONOTONIC, &t_end[3]); cilk_spawn spawn_function(); // 4

		clock_gettime(CLOCK_MONOTONIC, &t_end[4]); cilk_spawn spawn_function(); // 5
		clock_gettime(CLOCK_MONOTONIC, &t_end[5]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[6]); cilk_spawn spawn_function(); // 7
		clock_gettime(CLOCK_MONOTONIC, &t_end[7]); cilk_spawn spawn_function(); // 8
		clock_gettime(CLOCK_MONOTONIC, &t_end[8]); cilk_spawn spawn_function(); // 9
		clock_gettime(CLOCK_MONOTONIC, &t_end[9]); cilk_spawn spawn_function(); // if(NCILK-10 <= 0) { goto end; } // 10

		clock_gettime(CLOCK_MONOTONIC, &t_end[10]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[11]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[12]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[13]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[14]); cilk_spawn spawn_function(); // 15
		clock_gettime(CLOCK_MONOTONIC, &t_end[15]); cilk_spawn spawn_function(); // 16
		clock_gettime(CLOCK_MONOTONIC, &t_end[16]); cilk_spawn spawn_function(); // 17
		clock_gettime(CLOCK_MONOTONIC, &t_end[17]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[18]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[19]); cilk_spawn spawn_function(); // if(NCILK-20 <= 0) { goto end; } // 20

		clock_gettime(CLOCK_MONOTONIC, &t_end[20]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[21]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[22]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[23]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[24]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[25]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[26]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[27]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[28]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[29]); cilk_spawn spawn_function(); // if(NCILK-30 <= 0) { goto end; } // 30

		clock_gettime(CLOCK_MONOTONIC, &t_end[30]); cilk_spawn spawn_function(); // 31
		clock_gettime(CLOCK_MONOTONIC, &t_end[31]); cilk_spawn spawn_function(); // 32
		clock_gettime(CLOCK_MONOTONIC, &t_end[32]); cilk_spawn spawn_function(); // 33
		clock_gettime(CLOCK_MONOTONIC, &t_end[33]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[34]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[35]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[36]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[37]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[38]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[39]); cilk_spawn spawn_function(); // if(NCILK-40 <= 0) { goto end; } // 40

		clock_gettime(CLOCK_MONOTONIC, &t_end[40]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[41]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[42]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[43]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[44]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[45]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[46]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[47]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[48]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[49]); cilk_spawn spawn_function(); // if(NCILK-50 <= 0) { goto end; } // 50

		clock_gettime(CLOCK_MONOTONIC, &t_end[50]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[51]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[52]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[53]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[54]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[55]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[56]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[57]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[58]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[59]); cilk_spawn spawn_function(); // if(NCILK-60 <= 0) { goto end; } // 60

		clock_gettime(CLOCK_MONOTONIC, &t_end[60]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[61]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[62]); cilk_spawn spawn_function(); // 63
		clock_gettime(CLOCK_MONOTONIC, &t_end[63]); cilk_spawn spawn_function(); // 64

		clock_gettime(CLOCK_MONOTONIC, &t_end[64]); cilk_spawn spawn_function(); // 65
		clock_gettime(CLOCK_MONOTONIC, &t_end[65]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[66]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[67]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[68]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[69]); cilk_spawn spawn_function(); // if(NCILK-70 <= 0) { goto end; } // 70

		clock_gettime(CLOCK_MONOTONIC, &t_end[70]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[71]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[72]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[73]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[74]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[75]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[76]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[77]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[78]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[79]); cilk_spawn spawn_function(); // if(NCILK-80 <= 0) { goto end; } // 80

		clock_gettime(CLOCK_MONOTONIC, &t_end[80]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[81]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[82]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[83]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[84]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[85]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[86]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[87]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[88]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[89]); cilk_spawn spawn_function(); // if(NCILK-90 <= 0) { goto end; } // 90

		clock_gettime(CLOCK_MONOTONIC, &t_end[90]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[91]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[92]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[93]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[94]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[95]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[96]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[97]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[98]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[99]); cilk_spawn spawn_function(); //  if(NCILK-100 <= 0) { goto end; } // 100

		clock_gettime(CLOCK_MONOTONIC, &t_end[100]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[101]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[102]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[103]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[104]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[105]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[106]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[107]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[108]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[109]); cilk_spawn spawn_function(); // if(NCILK-110 <= 0) { goto end; } // 110

		clock_gettime(CLOCK_MONOTONIC, &t_end[110]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[111]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[112]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[113]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[114]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[115]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[116]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[117]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[118]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[119]); cilk_spawn spawn_function(); // if(NCILK-120 <= 0) { goto end; } // 120

		clock_gettime(CLOCK_MONOTONIC, &t_end[120]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[121]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[122]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[123]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[124]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[125]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[126]); cilk_spawn spawn_function(); // 127
		clock_gettime(CLOCK_MONOTONIC, &t_end[127]); cilk_spawn spawn_function(); // 128

		clock_gettime(CLOCK_MONOTONIC, &t_end[128]); cilk_spawn spawn_function(); // 129
		clock_gettime(CLOCK_MONOTONIC, &t_end[129]); cilk_spawn spawn_function(); // if(NCILK-130 <= 0) { goto end; } // 130

		clock_gettime(CLOCK_MONOTONIC, &t_end[130]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[131]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[132]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[133]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[134]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[135]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[136]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[137]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[138]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[139]); cilk_spawn spawn_function(); // if(NCILK-140 <= 0) { goto end; } // 140

		clock_gettime(CLOCK_MONOTONIC, &t_end[140]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[141]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[142]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[143]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[144]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[145]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[146]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[147]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[148]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[149]); cilk_spawn spawn_function(); // if(NCILK-150 <= 0) { goto end; } // 150

		clock_gettime(CLOCK_MONOTONIC, &t_end[150]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[151]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[152]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[153]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[154]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[155]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[156]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[157]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[158]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[159]); cilk_spawn spawn_function(); // if(NCILK-160 <= 0) { goto end; } // 160

		clock_gettime(CLOCK_MONOTONIC, &t_end[160]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[161]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[162]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[163]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[164]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[165]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[166]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[167]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[168]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[169]); cilk_spawn spawn_function(); // if(NCILK-170 <= 0) { goto end; } // 170

		clock_gettime(CLOCK_MONOTONIC, &t_end[170]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[171]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[172]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[173]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[174]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[175]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[176]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[177]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[178]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[179]); cilk_spawn spawn_function(); // if(NCILK-180 <= 0) { goto end; } // 180

		clock_gettime(CLOCK_MONOTONIC, &t_end[180]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[181]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[182]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[183]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[184]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[185]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[186]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[187]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[188]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[189]); cilk_spawn spawn_function(); // if(NCILK-190 <= 0) { goto end; } // 190

		clock_gettime(CLOCK_MONOTONIC, &t_end[190]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[191]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[192]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[193]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[194]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[195]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[196]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[197]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[198]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[199]); cilk_spawn spawn_function(); // if(NCILK-200 <= 0) { goto end; } // 200

		clock_gettime(CLOCK_MONOTONIC, &t_end[200]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[201]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[202]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[203]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[204]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[205]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[206]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[207]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[208]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[209]); cilk_spawn spawn_function(); // if(NCILK-210 <= 0) { goto end; } // 210

		clock_gettime(CLOCK_MONOTONIC, &t_end[210]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[211]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[212]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[213]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[214]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[215]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[216]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[217]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[218]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[219]); cilk_spawn spawn_function(); // if(NCILK-220 <= 0) { goto end; } // 220

		clock_gettime(CLOCK_MONOTONIC, &t_end[220]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[221]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[222]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[223]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[224]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[225]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[226]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[227]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[228]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[229]); cilk_spawn spawn_function(); // if(NCILK-230 <= 0) { goto end; } // 230

		clock_gettime(CLOCK_MONOTONIC, &t_end[230]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[231]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[232]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[233]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[234]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[235]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[236]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[237]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[238]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[239]); cilk_spawn spawn_function(); // if(NCILK-240 <= 0) { goto end; } // 240

		clock_gettime(CLOCK_MONOTONIC, &t_end[240]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[241]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[242]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[243]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[244]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[245]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[246]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[247]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[248]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[249]); cilk_spawn spawn_function(); // if(NCILK-250 <= 0) { goto end; } // 250

		clock_gettime(CLOCK_MONOTONIC, &t_end[250]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[251]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[252]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[253]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[254]); cilk_spawn spawn_function(); // 255
		clock_gettime(CLOCK_MONOTONIC, &t_end[255]); cilk_spawn spawn_function(); // 256
		clock_gettime(CLOCK_MONOTONIC, &t_end[256]); cilk_spawn spawn_function(); // 257
		clock_gettime(CLOCK_MONOTONIC, &t_end[257]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[258]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[259]); cilk_spawn spawn_function(); // if(NCILK-260 <= 0) { goto end; } // 260

		clock_gettime(CLOCK_MONOTONIC, &t_end[260]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[261]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[262]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[263]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[264]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[265]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[266]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[267]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[268]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[269]); cilk_spawn spawn_function(); // if(NCILK-270 <= 0) { goto end; } // 270

		clock_gettime(CLOCK_MONOTONIC, &t_end[270]); cilk_spawn spawn_function(); // 271
		clock_gettime(CLOCK_MONOTONIC, &t_end[271]); cilk_spawn spawn_function(); // 272
		/* clock_gettime(CLOCK_MONOTONIC, &t_end[272]); cilk_spawn spawn_function(); // 273
		clock_gettime(CLOCK_MONOTONIC, &t_end[273]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[274]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[275]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[276]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[277]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[278]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[279]); cilk_spawn spawn_function(); // if(NCILK-280 <= 0) { goto end; } // 280

		clock_gettime(CLOCK_MONOTONIC, &t_end[280]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[281]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[282]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[283]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[284]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[285]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[286]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[287]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[288]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[289]); cilk_spawn spawn_function(); // if(NCILK-290 <= 0) { goto end; } // 290

		clock_gettime(CLOCK_MONOTONIC, &t_end[290]); cilk_spawn spawn_function(); 
		clock_gettime(CLOCK_MONOTONIC, &t_end[291]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[292]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[293]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[294]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[295]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[296]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[297]); cilk_spawn spawn_function();

		clock_gettime(CLOCK_MONOTONIC, &t_end[298]); cilk_spawn spawn_function();
		clock_gettime(CLOCK_MONOTONIC, &t_end[299]); cilk_spawn spawn_function(); // if(NCILK-300 <= 0) { goto end; } // 300

		clock_gettime(CLOCK_MONOTONIC, &t_end[300]); cilk_spawn spawn_function(); // 301


    end: */ // unused label 

	cilk_sync; 

	printf("****\n");
	for(int i = 0; i < NCILK; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}
	
	// printf("02A\n");
	
	return 0;
}



