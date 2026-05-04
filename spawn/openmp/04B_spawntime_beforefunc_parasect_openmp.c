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

/* Benchmark: 04B: Spawn time beforefunc ; Parallel Section Spawns (OpenMP)
 * Launch a bunch and measure when all done
 */

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

	int OMP_THREADS = number_threads()-1;

	struct timespec t_start[OMP_THREADS]; struct timespec t_res;
	struct timespec t_end[OMP_THREADS];

	// spawn tasks in parallel using sections

 #pragma omp parallel
 #pragma omp sections
 {
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[0]);
	#pragma omp task
	t_end[0] = spawn_function();
 	} // Take time stamp before each spawn
	
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[1]);
	#pragma omp task
	t_end[1] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[2]);
	#pragma omp task
	t_end[2] = spawn_function();
 	}
 	
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[3]);
	#pragma omp task
	t_end[3] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[4]);
	#pragma omp task
	t_end[4] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[5]);
	#pragma omp task
	t_end[5] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[6]);
	#pragma omp task
	t_end[6] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[7]);
	#pragma omp task
	t_end[7] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[8]);
	#pragma omp task
	t_end[8] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[9]);
	#pragma omp task
	t_end[9] = spawn_function();
 	} // 10


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[10]);
	#pragma omp task
	t_end[10] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[11]);
	#pragma omp task
	t_end[11] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[12]);
	#pragma omp task
	t_end[12] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[13]);
	#pragma omp task
	t_end[13] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[14]);
	#pragma omp task
	t_end[14] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[15]);
	#pragma omp task
	t_end[15] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[16]);
	#pragma omp task
	t_end[16] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[17]);
	#pragma omp task
	t_end[17] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[18]);
	#pragma omp task
	t_end[18] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[19]);
	#pragma omp task
	t_end[19] = spawn_function();
 	} // 20


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[20]);
	#pragma omp task
	t_end[20] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[21]);
	#pragma omp task
	t_end[21] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[22]);
	#pragma omp task
	t_end[22] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[23]);
	#pragma omp task
	t_end[23] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[24]);
	#pragma omp task
	t_end[24] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[25]);
	#pragma omp task
	t_end[25] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[26]);
	#pragma omp task
	t_end[26] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[27]);
	#pragma omp task
	t_end[27] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[28]);
	#pragma omp task
	t_end[28] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[29]);
	#pragma omp task
	t_end[29] = spawn_function();
 	} // 30


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[30]);
	#pragma omp task
	t_end[30] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[31]);
	#pragma omp task
	t_end[31] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[32]);
	#pragma omp task
	t_end[32] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[33]);
	#pragma omp task
	t_end[33] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[34]);
	#pragma omp task
	t_end[34] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[35]);
	#pragma omp task
	t_end[35] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[36]);
	#pragma omp task
	t_end[36] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[37]);
	#pragma omp task
	t_end[37] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[38]);
	#pragma omp task
	t_end[38] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[39]);
	#pragma omp task
	t_end[39] = spawn_function();
 	} // 40


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[40]);
	#pragma omp task
	t_end[40] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[41]);
	#pragma omp task
	t_end[41] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[42]);
	#pragma omp task
	t_end[42] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[43]);
	#pragma omp task
	t_end[43] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[44]);
	#pragma omp task
	t_end[44] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[45]);
	#pragma omp task
	t_end[45] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[46]);
	#pragma omp task
	t_end[46] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[47]);
	#pragma omp task
	t_end[47] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[48]);
	#pragma omp task
	t_end[48] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[49]);
	#pragma omp task
	t_end[49] = spawn_function();
 	} // 50


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[50]);
	#pragma omp task
	t_end[50] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[51]);
	#pragma omp task
	t_end[51] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[52]);
	#pragma omp task
	t_end[52] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[53]);
	#pragma omp task
	t_end[53] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[54]);
	#pragma omp task
	t_end[54] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[55]);
	#pragma omp task
	t_end[55] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[56]);
	#pragma omp task
	t_end[56] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[57]);
	#pragma omp task
	t_end[57] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[58]);
	#pragma omp task
	t_end[58] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[59]);
	#pragma omp task
	t_end[59] = spawn_function();
 	} // 60


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[60]);
	#pragma omp task
	t_end[60] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[61]);
	#pragma omp task
	t_end[61] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[62]);
	#pragma omp task
	t_end[62] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[63]);
	#pragma omp task
	t_end[63] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[64]);
	#pragma omp task
	t_end[64] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[65]);
	#pragma omp task
	t_end[65] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[66]);
	#pragma omp task
	t_end[66] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[67]);
	#pragma omp task
	t_end[67] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[68]);
	#pragma omp task
	t_end[68] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[69]);
	#pragma omp task
	t_end[69] = spawn_function();
 	} // 70


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[70]);
	#pragma omp task
	t_end[70] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[71]);
	#pragma omp task
	t_end[71] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[72]);
	#pragma omp task
	t_end[72] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[73]);
	#pragma omp task
	t_end[73] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[74]);
	#pragma omp task
	t_end[74] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[75]);
	#pragma omp task
	t_end[75] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[76]);
	#pragma omp task
	t_end[76] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[77]);
	#pragma omp task
	t_end[77] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[78]);
	#pragma omp task
	t_end[78] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[79]);
	#pragma omp task
	t_end[79] = spawn_function();
 	} // 80


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[80]);
	#pragma omp task
	t_end[80] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[81]);
	#pragma omp task
	t_end[81] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[82]);
	#pragma omp task
	t_end[82] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[83]);
	#pragma omp task
	t_end[83] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[84]);
	#pragma omp task
	t_end[84] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[85]);
	#pragma omp task
	t_end[85] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[86]);
	#pragma omp task
	t_end[86] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[87]);
	#pragma omp task
	t_end[87] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[88]);
	#pragma omp task
	t_end[88] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[89]);
	#pragma omp task
	t_end[89] = spawn_function();
 	} // 90


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[90]);
	#pragma omp task
	t_end[90] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[91]);
	#pragma omp task
	t_end[91] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[92]);
	#pragma omp task
	t_end[92] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[93]);
	#pragma omp task
	t_end[93] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[94]);
	#pragma omp task
	t_end[94] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[95]);
	#pragma omp task
	t_end[95] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[96]);
	#pragma omp task
	t_end[96] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[97]);
	#pragma omp task
	t_end[97] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[98]);
	#pragma omp task
	t_end[98] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[99]);
	#pragma omp task
	t_end[99] = spawn_function();
 	} // 100


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[100]);
	#pragma omp task
	t_end[100] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[101]);
	#pragma omp task
	t_end[101] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[102]);
	#pragma omp task
	t_end[102] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[103]);
	#pragma omp task
	t_end[103] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[104]);
	#pragma omp task
	t_end[104] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[105]);
	#pragma omp task
	t_end[105] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[106]);
	#pragma omp task
	t_end[106] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[107]);
	#pragma omp task
	t_end[107] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[108]);
	#pragma omp task
	t_end[108] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[109]);
	#pragma omp task
	t_end[109] = spawn_function();
 	} // 110


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[110]);
	#pragma omp task
	t_end[110] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[111]);
	#pragma omp task
	t_end[111] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[112]);
	#pragma omp task
	t_end[112] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[113]);
	#pragma omp task
	t_end[113] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[114]);
	#pragma omp task
	t_end[114] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[115]);
	#pragma omp task
	t_end[115] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[116]);
	#pragma omp task
	t_end[116] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[117]);
	#pragma omp task
	t_end[117] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[118]);
	#pragma omp task
	t_end[118] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[119]);
	#pragma omp task
	t_end[119] = spawn_function();
 	} // 120


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[120]);
	#pragma omp task
	t_end[120] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[121]);
	#pragma omp task
	t_end[121] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[122]);
	#pragma omp task
	t_end[122] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[123]);
	#pragma omp task
	t_end[123] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[124]);
	#pragma omp task
	t_end[124] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[125]);
	#pragma omp task
	t_end[125] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[126]);
	#pragma omp task
	t_end[126] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[127]);
	#pragma omp task
	t_end[127] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[128]);
	#pragma omp task
	t_end[128] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[129]);
	#pragma omp task
	t_end[129] = spawn_function();
 	} // 130


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[130]);
	#pragma omp task
	t_end[130] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[131]);
	#pragma omp task
	t_end[131] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[132]);
	#pragma omp task
	t_end[132] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[133]);
	#pragma omp task
	t_end[133] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[134]);
	#pragma omp task
	t_end[134] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[135]);
	#pragma omp task
	t_end[135] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[136]);
	#pragma omp task
	t_end[136] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[137]);
	#pragma omp task
	t_end[137] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[138]);
	#pragma omp task
	t_end[138] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[139]);
	#pragma omp task
	t_end[139] = spawn_function();
 	} // 140


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[140]);
	#pragma omp task
	t_end[140] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[141]);
	#pragma omp task
	t_end[141] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[142]);
	#pragma omp task
	t_end[142] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[143]);
	#pragma omp task
	t_end[143] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[144]);
	#pragma omp task
	t_end[144] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[145]);
	#pragma omp task
	t_end[145] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[146]);
	#pragma omp task
	t_end[146] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[147]);
	#pragma omp task
	t_end[147] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[148]);
	#pragma omp task
	t_end[148] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[149]);
	#pragma omp task
	t_end[149] = spawn_function();
 	} // 150


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[150]);
	#pragma omp task
	t_end[150] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[151]);
	#pragma omp task
	t_end[151] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[152]);
	#pragma omp task
	t_end[152] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[153]);
	#pragma omp task
	t_end[153] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[154]);
	#pragma omp task
	t_end[154] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[155]);
	#pragma omp task
	t_end[155] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[156]);
	#pragma omp task
	t_end[156] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[157]);
	#pragma omp task
	t_end[157] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[158]);
	#pragma omp task
	t_end[158] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[159]);
	#pragma omp task
	t_end[159] = spawn_function();
 	} // 160


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[160]);
	#pragma omp task
	t_end[160] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[161]);
	#pragma omp task
	t_end[161] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[162]);
	#pragma omp task
	t_end[162] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[163]);
	#pragma omp task
	t_end[163] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[164]);
	#pragma omp task
	t_end[164] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[165]);
	#pragma omp task
	t_end[165] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[166]);
	#pragma omp task
	t_end[166] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[167]);
	#pragma omp task
	t_end[167] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[168]);
	#pragma omp task
	t_end[168] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[169]);
	#pragma omp task
	t_end[169] = spawn_function();
 	} // 170


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[170]);
	#pragma omp task
	t_end[170] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[171]);
	#pragma omp task
	t_end[171] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[172]);
	#pragma omp task
	t_end[172] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[173]);
	#pragma omp task
	t_end[173] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[174]);
	#pragma omp task
	t_end[174] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[175]);
	#pragma omp task
	t_end[175] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[176]);
	#pragma omp task
	t_end[176] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[177]);
	#pragma omp task
	t_end[177] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[178]);
	#pragma omp task
	t_end[178] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[179]);
	#pragma omp task
	t_end[179] = spawn_function();
 	} // 180


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[180]);
	#pragma omp task
	t_end[180] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[181]);
	#pragma omp task
	t_end[181] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[182]);
	#pragma omp task
	t_end[182] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[183]);
	#pragma omp task
	t_end[183] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[184]);
	#pragma omp task
	t_end[184] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[185]);
	#pragma omp task
	t_end[185] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[186]);
	#pragma omp task
	t_end[186] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[187]);
	#pragma omp task
	t_end[187] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[188]);
	#pragma omp task
	t_end[188] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[189]);
	#pragma omp task
	t_end[189] = spawn_function();
 	} // 190


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[190]);
	#pragma omp task
	t_end[190] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[191]);
	#pragma omp task
	t_end[191] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[192]);
	#pragma omp task
	t_end[192] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[193]);
	#pragma omp task
	t_end[193] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[194]);
	#pragma omp task
	t_end[194] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[195]);
	#pragma omp task
	t_end[195] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[196]);
	#pragma omp task
	t_end[196] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[197]);
	#pragma omp task
	t_end[197] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[198]);
	#pragma omp task
	t_end[198] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[199]);
	#pragma omp task
	t_end[199] = spawn_function();
 	} // 200


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[200]);
	#pragma omp task
	t_end[200] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[201]);
	#pragma omp task
	t_end[201] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[202]);
	#pragma omp task
	t_end[202] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[203]);
	#pragma omp task
	t_end[203] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[204]);
	#pragma omp task
	t_end[204] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[205]);
	#pragma omp task
	t_end[205] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[206]);
	#pragma omp task
	t_end[206] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[207]);
	#pragma omp task
	t_end[207] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[208]);
	#pragma omp task
	t_end[208] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[209]);
	#pragma omp task
	t_end[209] = spawn_function();
 	} // 210


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[210]);
	#pragma omp task
	t_end[210] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[211]);
	#pragma omp task
	t_end[211] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[212]);
	#pragma omp task
	t_end[212] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[213]);
	#pragma omp task
	t_end[213] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[214]);
	#pragma omp task
	t_end[214] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[215]);
	#pragma omp task
	t_end[215] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[216]);
	#pragma omp task
	t_end[216] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[217]);
	#pragma omp task
	t_end[217] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[218]);
	#pragma omp task
	t_end[218] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[219]);
	#pragma omp task
	t_end[219] = spawn_function();
 	} // 220


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[220]);
	#pragma omp task
	t_end[220] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[221]);
	#pragma omp task
	t_end[221] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[222]);
	#pragma omp task
	t_end[222] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[223]);
	#pragma omp task
	t_end[223] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[224]);
	#pragma omp task
	t_end[224] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[225]);
	#pragma omp task
	t_end[225] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[226]);
	#pragma omp task
	t_end[226] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[227]);
	#pragma omp task
	t_end[227] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[228]);
	#pragma omp task
	t_end[228] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[229]);
	#pragma omp task
	t_end[229] = spawn_function();
 	} // 230


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[230]);
	#pragma omp task
	t_end[230] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[231]);
	#pragma omp task
	t_end[231] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[232]);
	#pragma omp task
	t_end[232] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[233]);
	#pragma omp task
	t_end[233] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[234]);
	#pragma omp task
	t_end[234] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[235]);
	#pragma omp task
	t_end[235] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[236]);
	#pragma omp task
	t_end[236] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[237]);
	#pragma omp task
	t_end[237] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[238]);
	#pragma omp task
	t_end[238] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[239]);
	#pragma omp task
	t_end[239] = spawn_function();
 	} // 240


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[240]);
	#pragma omp task
	t_end[240] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[241]);
	#pragma omp task
	t_end[241] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[242]);
	#pragma omp task
	t_end[242] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[243]);
	#pragma omp task
	t_end[243] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[244]);
	#pragma omp task
	t_end[244] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[245]);
	#pragma omp task
	t_end[245] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[246]);
	#pragma omp task
	t_end[246] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[247]);
	#pragma omp task
	t_end[247] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[248]);
	#pragma omp task
	t_end[248] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[249]);
	#pragma omp task
	t_end[249] = spawn_function();
 	} // 250


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[250]);
	#pragma omp task
	t_end[250] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[251]);
	#pragma omp task
	t_end[251] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[252]);
	#pragma omp task
	t_end[252] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[253]);
	#pragma omp task
	t_end[253] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[254]);
	#pragma omp task
	t_end[254] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[255]);
	#pragma omp task
	t_end[255] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[256]);
	#pragma omp task
	t_end[256] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[257]);
	#pragma omp task
	t_end[257] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[258]);
	#pragma omp task
	t_end[258] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[259]);
	#pragma omp task
	t_end[259] = spawn_function();
 	} // 260


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[260]);
	#pragma omp task
	t_end[260] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[261]);
	#pragma omp task
	t_end[261] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[262]);
	#pragma omp task
	t_end[262] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[263]);
	#pragma omp task
	t_end[263] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[264]);
	#pragma omp task
	t_end[264] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[265]);
	#pragma omp task
	t_end[265] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[266]);
	#pragma omp task
	t_end[266] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[267]);
	#pragma omp task
	t_end[267] = spawn_function();
 	}

 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[268]);
	#pragma omp task
	t_end[268] = spawn_function();
 	}
 
	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[269]);
	#pragma omp task
	t_end[269] = spawn_function();
 	} // 270


	#pragma omp section
	{
	clock_gettime(CLOCK_MONOTONIC, &t_start[270]);
	#pragma omp task
	t_end[270] = spawn_function();
 	} // 271
 }
	// printf("****\n");	
	for(int i = 0; i < OMP_THREADS; i++){

		timespec_sub(&t_res, t_end[i], t_start[i]);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	return 0;
}