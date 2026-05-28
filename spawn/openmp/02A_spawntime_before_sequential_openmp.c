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
#include "../../include/numthreads.h"
/* Benchmark: 02A: Spawn time before ; Sequential Spawns (OpenMP)
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

	int OMP_THREADS = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            OMP_THREADS = number_threads();
        } else {
            OMP_THREADS = atoi(argv[1]);
            if (OMP_THREADS > 301){
                OMP_THREADS = number_threads();;
            }
        }
    }
    printf("# Spawns: %d\n", OMP_THREADS);

	struct timespec t_start, t_res;
	struct timespec t_end[OMP_THREADS];

	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	// use sections to guarantee order of timestamp then spawn
	// sections go in order

 // Take time stamp before each spawn
 #pragma omp parallel
 #pragma omp sections
 {

	#pragma omp section
	{
	  if(OMP_THREADS-1 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[0]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-2 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[1]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-3 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[2]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-4 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[3]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-5 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[4]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-6 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[5]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-7 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[6]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-8 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[7]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-9 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[8]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-10 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[9]); 
	    spawn_function(); // 10
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-11 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[10]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-12 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[11]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-13 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[12]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-14 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[13]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-15 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[14]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-16 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[15]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-17 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[16]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-18 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[17]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-19 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[18]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-20 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[19]); 
	    spawn_function(); // 20
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-21 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[20]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-22 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[21]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-23 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[22]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-24 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[23]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-25 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[24]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-26 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[25]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-27 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[26]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-28 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[27]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-29 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[28]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-30 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[29]); 
	    spawn_function(); // 30
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-31 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[30]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-32 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[31]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-33 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[32]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-34 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[33]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-35 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[34]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-36 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[35]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-37 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[36]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-38 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[37]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-39 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[38]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-40 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[39]); 
	    spawn_function(); // 40
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-41 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[40]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-42 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[41]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-43 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[42]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-44 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[43]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-45 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[44]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-46 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[45]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-47 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[46]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-48 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[47]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-49 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[48]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-50 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[49]); 
	    spawn_function(); // 50
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-51 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[50]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-52 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[51]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-53 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[52]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-54 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[53]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-55 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[54]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-56 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[55]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-57 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[56]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-58 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[57]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-59 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[58]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-60 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[59]); 
	    spawn_function(); // 60
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-61 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[60]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-62 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[61]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-63 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[62]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-64 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[63]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-65 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[64]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-66 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[65]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-67 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[66]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-68 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[67]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-69 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[68]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-70 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[69]); 
	    spawn_function(); // 70
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-71 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[70]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-72 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[71]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-73 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[72]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-74 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[73]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-75 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[74]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-76 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[75]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-77 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[76]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-78 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[77]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-79 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[78]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-80 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[79]); 
	    spawn_function(); // 80
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-81 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[80]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-82 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[81]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-83 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[82]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-84 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[83]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-85 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[84]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-86 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[85]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-87 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[86]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-88 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[87]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-89 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[88]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-90 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[89]); 
	    spawn_function(); // 90
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-91 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[90]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-92 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[91]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-93 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[92]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-94 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[93]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-95 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[94]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-96 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[95]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-97 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[96]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-98 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[97]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-99 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[98]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-100 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[99]); 
	    spawn_function(); // 100
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-101 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[100]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-102 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[101]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-103 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[102]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-104 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[103]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-105 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[104]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-106 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[105]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-107 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[106]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-108 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[107]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-109 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[108]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-110 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[109]); 
	    spawn_function(); // 110
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-111 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[110]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-112 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[111]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-113 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[112]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-114 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[113]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-115 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[114]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-116 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[115]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-117 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[116]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-118 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[117]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-119 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[118]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-120 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[119]); 
	    spawn_function(); // 120
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-121 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[120]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-122 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[121]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-123 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[122]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-124 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[123]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-125 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[124]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-126 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[125]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-127 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[126]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-128 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[127]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-129 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[128]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-130 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[129]); 
	    spawn_function(); // 130
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-131 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[130]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-132 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[131]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-133 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[132]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-134 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[133]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-135 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[134]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-136 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[135]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-137 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[136]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-138 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[137]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-139 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[138]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-140 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[139]); 
	    spawn_function(); // 140
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-141 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[140]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-142 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[141]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-143 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[142]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-144 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[143]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-145 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[144]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-146 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[145]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-147 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[146]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-148 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[147]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-149 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[148]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-150 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[149]); 
	    spawn_function(); // 150
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-151 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[150]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-152 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[151]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-153 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[152]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-154 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[153]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-155 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[154]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-156 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[155]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-157 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[156]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-158 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[157]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-159 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[158]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-160 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[159]); 
	    spawn_function(); // 160
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-161 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[160]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-162 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[161]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-163 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[162]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-164 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[163]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-165 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[164]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-166 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[165]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-167 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[166]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-168 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[167]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-169 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[168]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-170 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[169]); 
	    spawn_function(); // 170
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-171 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[170]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-172 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[171]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-173 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[172]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-174 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[173]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-175 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[174]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-176 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[175]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-177 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[176]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-178 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[177]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-179 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[178]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-180 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[179]); 
	    spawn_function(); // 180
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-181 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[180]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-182 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[181]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-183 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[182]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-184 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[183]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-185 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[184]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-186 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[185]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-187 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[186]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-188 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[187]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-189 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[188]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-190 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[189]); 
	    spawn_function(); // 190
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-191 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[190]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-192 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[191]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-193 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[192]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-194 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[193]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-195 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[194]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-196 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[195]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-197 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[196]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-198 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[197]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-199 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[198]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-200 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[199]); 
	    spawn_function(); // 200
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-201 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[200]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-202 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[201]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-203 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[202]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-204 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[203]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-205 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[204]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-206 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[205]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-207 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[206]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-208 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[207]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-209 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[208]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-210 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[209]); 
	    spawn_function(); // 210
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-211 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[210]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-212 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[211]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-213 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[212]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-214 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[213]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-215 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[214]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-216 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[215]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-217 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[216]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-218 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[217]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-219 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[218]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-220 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[219]); 
	    spawn_function(); // 220
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-221 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[220]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-222 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[221]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-223 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[222]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-224 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[223]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-225 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[224]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-226 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[225]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-227 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[226]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-228 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[227]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-229 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[228]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-230 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[229]); 
	    spawn_function(); // 230
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-231 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[230]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-232 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[231]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-233 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[232]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-234 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[233]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-235 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[234]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-236 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[235]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-237 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[236]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-238 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[237]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-239 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[238]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-240 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[239]); 
	    spawn_function(); // 240
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-241 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[240]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-242 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[241]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-243 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[242]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-244 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[243]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-245 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[244]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-246 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[245]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-247 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[246]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-248 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[247]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-249 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[248]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-250 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[249]); 
	    spawn_function(); // 250
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-251 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[250]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-252 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[251]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-253 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[252]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-254 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[253]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-255 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[254]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-256 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[255]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-257 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[256]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-258 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[257]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-259 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[258]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-260 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[259]); 
	    spawn_function(); // 260
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-261 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[260]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-262 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[261]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-263 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[262]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-264 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[263]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-265 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[264]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-266 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[265]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-267 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[266]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-268 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[267]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-269 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[268]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-270 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[269]); 
	    spawn_function(); // 270
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-271 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[270]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-272 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[271]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-273 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[272]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-274 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[273]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-275 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[274]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-276 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[275]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-277 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[276]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-278 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[277]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-279 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[278]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-279 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[279]); 
	    spawn_function(); // 280
	  }
	} 

	#pragma omp section
	{
	  if(OMP_THREADS-281 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[280]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-282 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[281]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-283 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[282]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-284 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[283]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-285 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[284]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-286 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[285]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-287 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[286]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-288 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[287]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-289 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[288]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-290 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[289]); 
	    spawn_function(); // 290
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-291 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[290]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-292 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[291]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-293 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[292]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-294 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[293]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-295 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[294]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-296 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[295]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-297 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[296]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-298 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[297]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-299 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[298]); 
	    spawn_function();
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-300 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[299]); 
	    spawn_function(); // 300
	  }
	} 
	#pragma omp section
	{
	  if(OMP_THREADS-301 >= 0){
	    clock_gettime(CLOCK_MONOTONIC, &t_end[300]); 
	    spawn_function(); // 301
	  }
	} 

 }

	printf("****\n");
	for(int i = 0; i < OMP_THREADS; i++){

		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}
	return 0;
}