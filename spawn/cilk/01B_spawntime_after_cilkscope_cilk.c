#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilkscale.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Benchmark: 01B: Spawn time after ; CilkScope Spawns (Cilk)
 * Launch a bunch and measure when all done -
 */

void spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

void end_program(struct timespec* t_start, struct timespec* t_end, int NCILK){ 

    struct timespec t_res;
		
	timespec_sub(&t_res, *(struct timespec *)t_end, *(struct timespec *)t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01B\n");

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
            if(NCILK > 301){
                NCILK = __cilkrts_get_nworkers();
            }
        }
    }

	printf("* # Spawns: %d\n", NCILK);

	struct timespec t_start, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	// use cilk scope to spawn threads in a parallel region

    cilk_scope{
	    { if( (NCILK-1) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-2) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-3) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-4) >= 0 ) { cilk_spawn spawn_function(); } } 
		 { if( (NCILK-5) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-6) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-7) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-8) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-9) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-10) >= 0 ) { cilk_spawn spawn_function(); } } 
		 // 10
		{ if( (NCILK-11) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-12) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-13) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-14) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-15) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-16) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-17) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-18) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-19) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-20) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 20
		{ if( (NCILK-21) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-22) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-23) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-24) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-25) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-26) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-27) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-28) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-29) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-30) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 30
		{ if( (NCILK-31) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-32) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-33) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-34) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-35) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-36) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-37) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-38) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-39) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-40) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 40
		{ if( (NCILK-41) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-42) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-43) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-44) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-45) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-46) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-47) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-48) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-49) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-50) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 50
		{ if( (NCILK-51) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-52) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-53) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-54) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-55) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-56) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-57) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-58) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-59) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-60) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 60
		{ if( (NCILK-61) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-62) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-63) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-64) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-65) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-66) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-67) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-68) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-69) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-70) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 70
		{ if( (NCILK-71) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-72) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-73) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-74) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-75) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-76) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-77) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-78) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-79) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-80) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 80
		{ if( (NCILK-81) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-82) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-83) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-84) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-85) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-86) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-87) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-88) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-89) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-90) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 90
		{ if( (NCILK-91) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-92) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-93) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-94) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-95) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-96) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-97) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-98) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-99) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-100) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 100
		{ if( (NCILK-101) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-102) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-103) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-104) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-105) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-106) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-107) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-108) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-109) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-110) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 110
		{ if( (NCILK-111) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-112) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-113) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-114) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-115) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-116) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-117) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-118) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-119) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-120) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 120
		{ if( (NCILK-121) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-122) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-123) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-124) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-125) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-126) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-127) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-128) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-129) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-130) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 130
		{ if( (NCILK-131) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-132) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-133) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-134) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-135) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-136) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-137) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-138) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-139) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-140) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 140
		{ if( (NCILK-141) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-142) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-143) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-144) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-145) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-146) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-147) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-148) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-149) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-150) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 150
		{ if( (NCILK-151) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-152) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-153) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-154) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-155) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-156) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-157) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-158) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-159) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-160) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 160
		{ if( (NCILK-161) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-162) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-163) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-164) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-165) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-166) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-167) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-168) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-169) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-170) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 170
		{ if( (NCILK-171) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-172) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-173) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-174) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-175) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-176) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-177) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-178) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-179) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-180) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 180
		{ if( (NCILK-181) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-182) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-183) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-184) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-185) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-186) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-187) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-188) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-189) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-190) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 190
		{ if( (NCILK-191) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-192) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-193) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-194) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-195) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-196) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-197) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-198) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-199) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-200) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 200
		{ if( (NCILK-201) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-202) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-203) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-204) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-205) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-206) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-207) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-208) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-209) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-210) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 210
		{ if( (NCILK-211) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-212) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-213) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-214) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-215) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-216) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-217) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-218) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-219) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-220) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 220
		{ if( (NCILK-221) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-222) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-223) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-224) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-225) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-226) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-227) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-228) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-229) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-230) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 230
		{ if( (NCILK-231) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-232) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-233) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-234) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-235) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-236) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-237) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-238) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-239) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-240) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 240
		{ if( (NCILK-241) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-242) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-243) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-244) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-245) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-246) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-247) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-248) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-249) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-250) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 250
		{ if( (NCILK-251) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-252) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-253) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-254) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-255) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-256) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-257) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-258) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-259) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-260) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 260
		{ if( (NCILK-261) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-262) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-263) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-264) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-265) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-266) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-267) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-268) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-269) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-270) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 270
		{ if( (NCILK-271) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-272) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-273) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-274) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-275) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-276) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-277) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-278) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-279) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-280) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 280
		 { if( (NCILK-281) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-282) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-283) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-284) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-285) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-286) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-287) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-288) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-289) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-290) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 290
		 { if( (NCILK-291) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-292) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-293) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-294) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-295) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-296) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-297) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-298) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-299) >= 0 ) { cilk_spawn spawn_function(); } }
		 { if( (NCILK-300) >= 0 ) { cilk_spawn spawn_function(); } }
		 // 300

		 { if( (NCILK-301) >= 0 ) { cilk_spawn spawn_function(); } } // 301
    }

	clock_gettime(CLOCK_MONOTONIC, &t_end);

    struct timespec t_res;

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	// printf("01B\n");

	return 0;
}