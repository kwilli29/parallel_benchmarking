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

/* Benchmark: 04A: Spawn time beforefunc ; Sequential Spawns (OpenMP)
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

	#pragma omp task
	t_end[0] = spawn_function(); // Take time stamp before each spawn
	#pragma omp task
	t_end[1] = spawn_function();
	#pragma omp task
	t_end[2] = spawn_function();
	#pragma omp task
	t_end[3] = spawn_function();

	#pragma omp task
	t_end[4] = spawn_function();
	#pragma omp task
	t_end[5] = spawn_function();
	#pragma omp task
	t_end[6] = spawn_function();
	#pragma omp task
	t_end[7] = spawn_function();

	#pragma omp task
	t_end[8] = spawn_function();
	#pragma omp task
	t_end[9] = spawn_function(); // 10

	#pragma omp task
	t_end[10] = spawn_function();
	#pragma omp task
	t_end[11] = spawn_function();
	#pragma omp task
	t_end[12] = spawn_function();
	#pragma omp task
	t_end[13] = spawn_function();

	#pragma omp task
	t_end[14] = spawn_function();
	#pragma omp task
	t_end[15] = spawn_function();
	#pragma omp task
	t_end[16] = spawn_function();
	#pragma omp task
	t_end[17] = spawn_function();

	#pragma omp task
	t_end[18] = spawn_function();
	#pragma omp task
	t_end[19] = spawn_function(); // 20

	#pragma omp task
	t_end[20] = spawn_function();
	#pragma omp task
	t_end[21] = spawn_function();
	#pragma omp task
	t_end[22] = spawn_function();
	#pragma omp task
	t_end[23] = spawn_function();

	#pragma omp task
	t_end[24] = spawn_function();
	#pragma omp task
	t_end[25] = spawn_function();
	#pragma omp task
	t_end[26] = spawn_function();
	#pragma omp task
	t_end[27] = spawn_function();

	#pragma omp task
	t_end[28] = spawn_function();
	#pragma omp task
	t_end[29] = spawn_function(); // 30

	#pragma omp task
	t_end[30] = spawn_function();
	#pragma omp task
	t_end[31] = spawn_function();
	#pragma omp task
	t_end[32] = spawn_function();
	#pragma omp task
	t_end[33] = spawn_function();

	#pragma omp task
	t_end[34] = spawn_function();
	#pragma omp task
	t_end[35] = spawn_function();
	#pragma omp task
	t_end[36] = spawn_function();
	#pragma omp task
	t_end[37] = spawn_function();

	#pragma omp task
	t_end[38] = spawn_function();
	#pragma omp task
	t_end[39] = spawn_function(); // 40

	#pragma omp task
	t_end[40] = spawn_function();
	#pragma omp task
	t_end[41] = spawn_function();
	#pragma omp task
	t_end[42] = spawn_function();
	#pragma omp task
	t_end[43] = spawn_function();

	#pragma omp task
	t_end[44] = spawn_function();
	#pragma omp task
	t_end[45] = spawn_function();
	#pragma omp task
	t_end[46] = spawn_function();
	#pragma omp task
	t_end[47] = spawn_function();

	#pragma omp task
	t_end[48] = spawn_function();
	#pragma omp task
	t_end[49] = spawn_function(); // 50

	#pragma omp task
	t_end[50] = spawn_function();
	#pragma omp task
	t_end[51] = spawn_function();
	#pragma omp task
	t_end[52] = spawn_function();
	#pragma omp task
	t_end[53] = spawn_function();

	#pragma omp task
	t_end[54] = spawn_function();
	#pragma omp task
	t_end[55] = spawn_function();
	#pragma omp task
	t_end[56] = spawn_function();
	#pragma omp task
	t_end[57] = spawn_function();

	#pragma omp task
	t_end[58] = spawn_function();
	#pragma omp task
	t_end[59] = spawn_function(); // 60

	#pragma omp task
	t_end[60] = spawn_function();
	#pragma omp task
	t_end[61] = spawn_function();
	#pragma omp task
	t_end[62] = spawn_function();
	#pragma omp task
	t_end[63] = spawn_function();

	#pragma omp task
	t_end[64] = spawn_function();
	#pragma omp task
	t_end[65] = spawn_function();
	#pragma omp task
	t_end[66] = spawn_function();
	#pragma omp task
	t_end[67] = spawn_function();

	#pragma omp task
	t_end[68] = spawn_function();
	#pragma omp task
	t_end[69] = spawn_function(); // 70

	#pragma omp task
	t_end[70] = spawn_function();
	#pragma omp task
	t_end[71] = spawn_function();
	#pragma omp task
	t_end[72] = spawn_function();
	#pragma omp task
	t_end[73] = spawn_function();

	#pragma omp task
	t_end[74] = spawn_function();
	#pragma omp task
	t_end[75] = spawn_function();
	#pragma omp task
	t_end[76] = spawn_function();
	#pragma omp task
	t_end[77] = spawn_function();

	#pragma omp task
	t_end[78] = spawn_function();
	#pragma omp task
	t_end[79] = spawn_function(); // 80

	#pragma omp task
	t_end[80] = spawn_function();
	#pragma omp task
	t_end[81] = spawn_function();
	#pragma omp task
	t_end[82] = spawn_function();
	#pragma omp task
	t_end[83] = spawn_function();

	#pragma omp task
	t_end[84] = spawn_function();
	#pragma omp task
	t_end[85] = spawn_function();
	#pragma omp task
	t_end[86] = spawn_function();
	#pragma omp task
	t_end[87] = spawn_function();

	#pragma omp task
	t_end[88] = spawn_function();
	#pragma omp task
	t_end[89] = spawn_function(); // 90

	#pragma omp task
	t_end[90] = spawn_function();
	#pragma omp task
	t_end[91] = spawn_function();
	#pragma omp task
	t_end[92] = spawn_function();
	#pragma omp task
	t_end[93] = spawn_function();

	#pragma omp task
	t_end[94] = spawn_function();
	#pragma omp task
	t_end[95] = spawn_function();
	#pragma omp task
	t_end[96] = spawn_function();
	#pragma omp task
	t_end[97] = spawn_function();

	#pragma omp task
	t_end[98] = spawn_function();
	#pragma omp task
	t_end[99] = spawn_function(); // 100

	#pragma omp task
	t_end[100] = spawn_function();
	#pragma omp task
	t_end[101] = spawn_function();
	#pragma omp task
	t_end[102] = spawn_function();
	#pragma omp task
	t_end[103] = spawn_function();

	#pragma omp task
	t_end[104] = spawn_function();
	#pragma omp task
	t_end[105] = spawn_function();
	#pragma omp task
	t_end[106] = spawn_function();
	#pragma omp task
	t_end[107] = spawn_function();

	#pragma omp task
	t_end[108] = spawn_function();
	#pragma omp task
	t_end[109] = spawn_function(); // 110

	#pragma omp task
	t_end[110] = spawn_function();
	#pragma omp task
	t_end[111] = spawn_function();
	#pragma omp task
	t_end[112] = spawn_function();
	#pragma omp task
	t_end[113] = spawn_function();

	#pragma omp task
	t_end[114] = spawn_function();
	#pragma omp task
	t_end[115] = spawn_function();
	#pragma omp task
	t_end[116] = spawn_function();
	#pragma omp task
	t_end[117] = spawn_function();

	#pragma omp task
	t_end[118] = spawn_function();
	#pragma omp task
	t_end[119] = spawn_function(); // 120

	#pragma omp task
	t_end[120] = spawn_function();
	#pragma omp task
	t_end[121] = spawn_function();
	#pragma omp task
	t_end[122] = spawn_function();
	#pragma omp task
	t_end[123] = spawn_function();

	#pragma omp task
	t_end[124] = spawn_function();
	#pragma omp task
	t_end[125] = spawn_function();
	#pragma omp task
	t_end[126] = spawn_function();
	#pragma omp task
	t_end[127] = spawn_function();

	#pragma omp task
	t_end[128] = spawn_function();
	#pragma omp task
	t_end[129] = spawn_function(); // 130

	#pragma omp task
	t_end[130] = spawn_function();
	#pragma omp task
	t_end[131] = spawn_function();
	#pragma omp task
	t_end[132] = spawn_function();
	#pragma omp task
	t_end[133] = spawn_function();

	#pragma omp task
	t_end[134] = spawn_function();
	#pragma omp task
	t_end[135] = spawn_function();
	#pragma omp task
	t_end[136] = spawn_function();
	#pragma omp task
	t_end[137] = spawn_function();

	#pragma omp task
	t_end[138] = spawn_function();
	#pragma omp task
	t_end[139] = spawn_function(); // 140

	#pragma omp task
	t_end[140] = spawn_function();
	#pragma omp task
	t_end[141] = spawn_function();
	#pragma omp task
	t_end[142] = spawn_function();
	#pragma omp task
	t_end[143] = spawn_function();

	#pragma omp task
	t_end[144] = spawn_function();
	#pragma omp task
	t_end[145] = spawn_function();
	#pragma omp task
	t_end[146] = spawn_function();
	#pragma omp task
	t_end[147] = spawn_function();

	#pragma omp task
	t_end[148] = spawn_function();
	#pragma omp task
	t_end[149] = spawn_function(); // 150

	#pragma omp task
	t_end[150] = spawn_function();
	#pragma omp task
	t_end[151] = spawn_function();
	#pragma omp task
	t_end[152] = spawn_function();
	#pragma omp task
	t_end[153] = spawn_function();

	#pragma omp task
	t_end[154] = spawn_function();
	#pragma omp task
	t_end[155] = spawn_function();
	#pragma omp task
	t_end[156] = spawn_function();
	#pragma omp task
	t_end[157] = spawn_function();

	#pragma omp task
	t_end[158] = spawn_function();
	#pragma omp task
	t_end[159] = spawn_function(); // 160

	#pragma omp task
	t_end[160] = spawn_function();
	#pragma omp task
	t_end[161] = spawn_function();
	#pragma omp task
	t_end[162] = spawn_function();
	#pragma omp task
	t_end[163] = spawn_function();

	#pragma omp task
	t_end[164] = spawn_function();
	#pragma omp task
	t_end[165] = spawn_function();
	#pragma omp task
	t_end[166] = spawn_function();
	#pragma omp task
	t_end[167] = spawn_function();

	#pragma omp task
	t_end[168] = spawn_function();
	#pragma omp task
	t_end[169] = spawn_function(); // 170

	#pragma omp task
	t_end[170] = spawn_function();
	#pragma omp task
	t_end[171] = spawn_function();
	#pragma omp task
	t_end[172] = spawn_function();
	#pragma omp task
	t_end[173] = spawn_function();

	#pragma omp task
	t_end[174] = spawn_function();
	#pragma omp task
	t_end[175] = spawn_function();
	#pragma omp task
	t_end[176] = spawn_function();
	#pragma omp task
	t_end[177] = spawn_function();

	#pragma omp task
	t_end[178] = spawn_function();
	#pragma omp task
	t_end[179] = spawn_function(); // 180

	#pragma omp task
	t_end[180] = spawn_function();
	#pragma omp task
	t_end[181] = spawn_function();
	#pragma omp task
	t_end[182] = spawn_function();
	#pragma omp task
	t_end[183] = spawn_function();

	#pragma omp task
	t_end[184] = spawn_function();
	#pragma omp task
	t_end[185] = spawn_function();
	#pragma omp task
	t_end[186] = spawn_function();
	#pragma omp task
	t_end[187] = spawn_function();

	#pragma omp task
	t_end[188] = spawn_function();
	#pragma omp task
	t_end[189] = spawn_function(); // 190

	#pragma omp task
	t_end[190] = spawn_function();
	#pragma omp task
	t_end[191] = spawn_function();
	#pragma omp task
	t_end[192] = spawn_function();
	#pragma omp task
	t_end[193] = spawn_function();

	#pragma omp task
	t_end[194] = spawn_function();
	#pragma omp task
	t_end[195] = spawn_function();
	#pragma omp task
	t_end[196] = spawn_function();
	#pragma omp task
	t_end[197] = spawn_function();

	#pragma omp task
	t_end[198] = spawn_function();
	#pragma omp task
	t_end[199] = spawn_function(); // 200

	#pragma omp task
	t_end[200] = spawn_function();
	#pragma omp task
	t_end[201] = spawn_function();
	#pragma omp task
	t_end[202] = spawn_function();
	#pragma omp task
	t_end[203] = spawn_function();

	#pragma omp task
	t_end[204] = spawn_function();
	#pragma omp task
	t_end[205] = spawn_function();
	#pragma omp task
	t_end[206] = spawn_function();
	#pragma omp task
	t_end[207] = spawn_function();

	#pragma omp task
	t_end[208] = spawn_function();
	#pragma omp task
	t_end[209] = spawn_function(); // 210

	#pragma omp task
	t_end[210] = spawn_function();
	#pragma omp task
	t_end[211] = spawn_function();
	#pragma omp task
	t_end[212] = spawn_function();
	#pragma omp task
	t_end[213] = spawn_function();

	#pragma omp task
	t_end[214] = spawn_function();
	#pragma omp task
	t_end[215] = spawn_function();
	#pragma omp task
	t_end[216] = spawn_function();
	#pragma omp task
	t_end[217] = spawn_function();

	#pragma omp task
	t_end[218] = spawn_function();
	#pragma omp task
	t_end[219] = spawn_function(); // 220

	#pragma omp task
	t_end[220] = spawn_function();
	#pragma omp task
	t_end[221] = spawn_function();
	#pragma omp task
	t_end[222] = spawn_function();
	#pragma omp task
	t_end[223] = spawn_function();

	#pragma omp task
	t_end[224] = spawn_function();
	#pragma omp task
	t_end[225] = spawn_function();
	#pragma omp task
	t_end[226] = spawn_function();
	#pragma omp task
	t_end[227] = spawn_function();

	#pragma omp task
	t_end[228] = spawn_function();
	#pragma omp task
	t_end[229] = spawn_function(); // 230

	#pragma omp task
	t_end[230] = spawn_function();
	#pragma omp task
	t_end[231] = spawn_function();
	#pragma omp task
	t_end[232] = spawn_function();
	#pragma omp task
	t_end[233] = spawn_function();

	#pragma omp task
	t_end[234] = spawn_function();
	#pragma omp task
	t_end[235] = spawn_function();
	#pragma omp task
	t_end[236] = spawn_function();
	#pragma omp task
	t_end[237] = spawn_function();

	#pragma omp task
	t_end[238] = spawn_function();
	#pragma omp task
	t_end[239] = spawn_function(); // 240

	#pragma omp task
	t_end[240] = spawn_function();
	#pragma omp task
	t_end[241] = spawn_function();
	#pragma omp task
	t_end[242] = spawn_function();
	#pragma omp task
	t_end[243] = spawn_function();

	#pragma omp task
	t_end[244] = spawn_function();
	#pragma omp task
	t_end[245] = spawn_function();
	#pragma omp task
	t_end[246] = spawn_function();
	#pragma omp task
	t_end[247] = spawn_function();

	#pragma omp task
	t_end[248] = spawn_function();
	#pragma omp task
	t_end[249] = spawn_function(); // 250

	#pragma omp task
	t_end[250] = spawn_function();
	#pragma omp task
	t_end[251] = spawn_function();
	#pragma omp task
	t_end[252] = spawn_function();
	#pragma omp task
	t_end[253] = spawn_function();

	#pragma omp task
	t_end[254] = spawn_function();
	#pragma omp task
	t_end[255] = spawn_function();
	#pragma omp task
	t_end[256] = spawn_function();
	#pragma omp task
	t_end[257] = spawn_function();

	#pragma omp task
	t_end[258] = spawn_function();
	#pragma omp task
	t_end[259] = spawn_function(); // 260

	#pragma omp task
	t_end[260] = spawn_function();
	#pragma omp task
	t_end[261] = spawn_function();
	#pragma omp task
	t_end[262] = spawn_function();
	#pragma omp task
	t_end[263] = spawn_function();

	#pragma omp task
	t_end[264] = spawn_function();
	#pragma omp task
	t_end[265] = spawn_function();
	#pragma omp task
	t_end[266] = spawn_function();
	#pragma omp task
	t_end[267] = spawn_function();

	#pragma omp task
	t_end[268] = spawn_function();
	#pragma omp task
	t_end[269] = spawn_function(); // 270

	#pragma omp task
	t_end[270] = spawn_function(); // 271

	

	for(int i = 0; i < DEPTH; i++){

		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	return 0;
}


