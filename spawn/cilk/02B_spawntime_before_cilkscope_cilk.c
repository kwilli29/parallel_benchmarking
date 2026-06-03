#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include "ctimer.h"
#include <math.h>

/* Benchmark: 02B: Spawn time before ; CilkScope Spawns (Cilk)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 *
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

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            NCILK = __cilkrts_get_nworkers();
        } else {
            NCILK = atoi(argv[1]);
            if (NCILK > 301){
                NCILK = __cilkrts_get_nworkers();
            }
        }
    }

	printf("# Spawns: %d\n", NCILK);

	struct timespec t_start, t_res;
	struct timespec t_end[NCILK];
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	// the brackets are so the spawns can be parallel, but there is a guarantee that a time is marked before the spawn

	cilk_scope{

		// {  time ; spawn ; }

		{ if( (NCILK-1) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[0]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-2) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[1]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-3) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[2]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-4) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[3]); cilk_spawn spawn_function(); } } 
		 { if( (NCILK-5) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[4]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-6) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[5]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-7) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[6]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-8) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[7]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-9) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[8]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-10) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[9]); cilk_spawn spawn_function(); } } 
		 // 10
		{ if( (NCILK-11) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[10]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-12) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[11]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-13) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[12]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-14) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[13]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-15) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[14]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-16) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[15]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-17) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[16]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-18) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[17]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-19) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[18]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-20) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[19]); cilk_spawn spawn_function(); } }
		 // 20
		{ if( (NCILK-21) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[20]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-22) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[21]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-23) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[22]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-24) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[23]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-25) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[24]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-26) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[25]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-27) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[26]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-28) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[27]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-29) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[28]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-30) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[29]); cilk_spawn spawn_function(); } }
		 // 30
		{ if( (NCILK-31) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[30]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-32) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[31]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-33) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[32]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-34) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[33]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-35) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[34]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-36) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[35]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-37) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[36]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-38) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[37]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-39) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[38]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-40) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[39]); cilk_spawn spawn_function(); } }
		 // 40
		{ if( (NCILK-41) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[40]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-42) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[41]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-43) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[42]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-44) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[43]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-45) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[44]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-46) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[45]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-47) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[46]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-48) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[47]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-49) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[48]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-50) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[49]); cilk_spawn spawn_function(); } }
		 // 50
		{ if( (NCILK-51) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[50]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-52) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[51]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-53) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[52]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-54) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[53]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-55) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[54]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-56) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[55]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-57) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[56]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-58) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[57]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-59) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[58]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-60) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[59]); cilk_spawn spawn_function(); } }
		 // 60
		{ if( (NCILK-61) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[60]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-62) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[61]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-63) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[62]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-64) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[63]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-65) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[64]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-66) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[65]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-67) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[66]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-68) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[67]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-69) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[68]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-70) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[69]); cilk_spawn spawn_function(); } }
		 // 70
		{ if( (NCILK-71) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[70]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-72) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[71]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-73) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[72]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-74) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[73]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-75) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[74]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-76) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[75]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-77) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[76]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-78) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[77]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-79) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[78]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-80) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[79]); cilk_spawn spawn_function(); } }
		 // 80
		{ if( (NCILK-81) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[80]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-82) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[81]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-83) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[82]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-84) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[83]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-85) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[84]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-86) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[85]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-87) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[86]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-88) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[87]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-89) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[88]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-90) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[89]); cilk_spawn spawn_function(); } }
		 // 90
		{ if( (NCILK-91) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[90]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-92) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[91]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-93) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[92]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-94) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[93]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-95) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[94]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-96) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[95]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-97) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[96]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-98) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[97]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-99) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[98]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-100) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[99]); cilk_spawn spawn_function(); } }
		 // 100
		{ if( (NCILK-101) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[100]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-102) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[101]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-103) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[102]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-104) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[103]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-105) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[104]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-106) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[105]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-107) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[106]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-108) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[107]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-109) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[108]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-110) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[109]); cilk_spawn spawn_function(); } }
		 // 110
		{ if( (NCILK-111) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[110]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-112) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[111]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-113) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[112]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-114) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[113]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-115) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[114]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-116) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[115]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-117) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[116]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-118) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[117]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-119) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[118]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-120) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[119]); cilk_spawn spawn_function(); } }
		 // 120
		{ if( (NCILK-121) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[120]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-122) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[121]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-123) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[122]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-124) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[123]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-125) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[124]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-126) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[125]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-127) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[126]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-128) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[127]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-129) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[128]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-130) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[129]); cilk_spawn spawn_function(); } }
		 // 130
		{ if( (NCILK-131) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[130]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-132) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[131]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-133) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[132]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-134) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[133]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-135) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[134]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-136) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[135]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-137) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[136]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-138) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[137]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-139) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[138]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-140) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[139]); cilk_spawn spawn_function(); } }
		 // 140
		{ if( (NCILK-141) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[140]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-142) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[141]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-143) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[142]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-144) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[143]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-145) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[144]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-146) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[145]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-147) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[146]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-148) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[147]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-149) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[148]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-150) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[149]); cilk_spawn spawn_function(); } }
		 // 150
		{ if( (NCILK-151) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[150]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-152) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[151]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-153) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[152]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-154) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[153]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-155) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[154]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-156) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[155]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-157) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[156]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-158) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[157]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-159) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[158]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-160) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[159]); cilk_spawn spawn_function(); } }
		 // 160
		{ if( (NCILK-161) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[160]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-162) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[161]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-163) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[162]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-164) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[163]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-165) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[164]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-166) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[165]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-167) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[166]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-168) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[167]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-169) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[168]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-170) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[169]); cilk_spawn spawn_function(); } }
		 // 170
		{ if( (NCILK-171) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[170]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-172) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[171]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-173) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[172]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-174) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[173]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-175) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[174]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-176) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[175]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-177) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[176]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-178) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[177]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-179) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[178]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-180) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[179]); cilk_spawn spawn_function(); } }
		 // 180
		{ if( (NCILK-181) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[180]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-182) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[181]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-183) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[182]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-184) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[183]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-185) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[184]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-186) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[185]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-187) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[186]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-188) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[187]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-189) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[188]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-190) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[189]); cilk_spawn spawn_function(); } }
		 // 190
		{ if( (NCILK-191) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[190]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-192) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[191]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-193) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[192]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-194) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[193]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-195) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[194]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-196) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[195]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-197) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[196]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-198) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[197]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-199) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[198]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-200) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[199]); cilk_spawn spawn_function(); } }
		 // 200
		{ if( (NCILK-201) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[200]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-202) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[201]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-203) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[202]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-204) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[203]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-205) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[204]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-206) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[205]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-207) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[206]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-208) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[207]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-209) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[208]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-210) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[209]); cilk_spawn spawn_function(); } }
		 // 210
		{ if( (NCILK-211) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[210]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-212) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[211]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-213) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[212]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-214) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[213]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-215) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[214]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-216) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[215]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-217) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[216]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-218) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[217]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-219) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[218]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-220) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[219]); cilk_spawn spawn_function(); } }
		 // 220
		{ if( (NCILK-221) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[220]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-222) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[221]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-223) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[222]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-224) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[223]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-225) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[224]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-226) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[225]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-227) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[226]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-228) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[227]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-229) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[228]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-230) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[229]); cilk_spawn spawn_function(); } }
		 // 230
		{ if( (NCILK-231) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[230]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-232) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[231]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-233) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[232]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-234) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[233]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-235) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[234]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-236) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[235]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-237) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[236]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-238) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[237]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-239) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[238]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-240) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[239]); cilk_spawn spawn_function(); } }
		 // 240
		{ if( (NCILK-241) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[240]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-242) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[241]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-243) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[242]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-244) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[243]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-245) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[244]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-246) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[245]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-247) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[246]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-248) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[247]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-249) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[248]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-250) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[249]); cilk_spawn spawn_function(); } }
		 // 250
		{ if( (NCILK-251) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[250]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-252) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[251]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-253) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[252]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-254) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[253]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-255) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[254]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-256) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[255]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-257) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[256]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-258) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[257]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-259) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[258]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-260) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[259]); cilk_spawn spawn_function(); } }
		 // 260
		{ if( (NCILK-261) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[260]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-262) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[261]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-263) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[262]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-264) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[263]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-265) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[264]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-266) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[265]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-267) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[266]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-268) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[267]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-269) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[268]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-270) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[269]); cilk_spawn spawn_function(); } }
		 // 270
		{ if( (NCILK-271) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[270]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-272) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[271]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-273) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[272]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-274) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[273]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-275) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[274]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-276) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[275]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-277) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[276]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-278) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[277]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-279) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[278]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-280) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[279]); cilk_spawn spawn_function(); } }
		 // 280
		 { if( (NCILK-281) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[280]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-282) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[281]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-283) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[282]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-284) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[283]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-285) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[284]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-286) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[285]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-287) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[286]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-288) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[287]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-289) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[288]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-290) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[289]); cilk_spawn spawn_function(); } }
		 // 290
		 { if( (NCILK-291) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[290]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-292) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[291]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-293) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[292]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-294) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[293]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-295) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[294]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-296) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[295]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-297) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[296]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-298) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[297]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-299) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[298]); cilk_spawn spawn_function(); } }
		 { if( (NCILK-300) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[299]); cilk_spawn spawn_function(); } }
		 // 300

		 { if( (NCILK-301) >= 0 ) { clock_gettime(CLOCK_MONOTONIC, &t_end[300]); cilk_spawn spawn_function(); } } // 301

	}

	printf("****\n");
	for(int i = 0; i < NCILK; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);
		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}
	
	// printf("02B\n");

	return 0;
}

// cilk_rts_getworker_number;