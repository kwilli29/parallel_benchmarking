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
#include "../../../include/numthreads.h"

/* Benchmark: 01A: Spawn time after ; Sequential Spawns (OpenMP)
 * Launch a bunch and measure when all done
 * This is NOT how OpenMP is meant to be used
 */

void spawn_function(){           // Simple Spawn Function

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
	printf("* # Spawns: %d\n", OMP_THREADS);

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); // struct timespec *tp

	#pragma omp parallel
	#pragma omp single   // one threads 'allocates' tasks to other threads
	{

if( (OMP_THREADS-1) >= 0 ) { }
    if( (OMP_THREADS-2) >= 0 ) { }
    if( (OMP_THREADS-3) >= 0 ) { }
    if( (OMP_THREADS-4) >= 0 ) { } 
    if( (OMP_THREADS-5) >= 0 ) { }
    if( (OMP_THREADS-6) >= 0 ) { }
    if( (OMP_THREADS-7) >= 0 ) { }
    if( (OMP_THREADS-8) >= 0 ) { }
    if( (OMP_THREADS-9) >= 0 ) { }
    if( (OMP_THREADS-10) >= 0 ) { } 
    // 10
if( (OMP_THREADS-11) >= 0 ) { }
    if( (OMP_THREADS-12) >= 0 ) { }
    if( (OMP_THREADS-13) >= 0 ) { }
    if( (OMP_THREADS-14) >= 0 ) { }
    if( (OMP_THREADS-15) >= 0 ) { }
    if( (OMP_THREADS-16) >= 0 ) { }
    if( (OMP_THREADS-17) >= 0 ) { }
    if( (OMP_THREADS-18) >= 0 ) { }
    if( (OMP_THREADS-19) >= 0 ) { }
    if( (OMP_THREADS-20) >= 0 ) { }
    // 20
if( (OMP_THREADS-21) >= 0 ) { }
    if( (OMP_THREADS-22) >= 0 ) { }
    if( (OMP_THREADS-23) >= 0 ) { }
    if( (OMP_THREADS-24) >= 0 ) { }
    if( (OMP_THREADS-25) >= 0 ) { }
    if( (OMP_THREADS-26) >= 0 ) { }
    if( (OMP_THREADS-27) >= 0 ) { }
    if( (OMP_THREADS-28) >= 0 ) { }
    if( (OMP_THREADS-29) >= 0 ) { }
    if( (OMP_THREADS-30) >= 0 ) { }
    // 30
if( (OMP_THREADS-31) >= 0 ) { }
    if( (OMP_THREADS-32) >= 0 ) { }
    if( (OMP_THREADS-33) >= 0 ) { }
    if( (OMP_THREADS-34) >= 0 ) { }
    if( (OMP_THREADS-35) >= 0 ) { }
    if( (OMP_THREADS-36) >= 0 ) { }
    if( (OMP_THREADS-37) >= 0 ) { }
    if( (OMP_THREADS-38) >= 0 ) { }
    if( (OMP_THREADS-39) >= 0 ) { }
    if( (OMP_THREADS-40) >= 0 ) { }
    // 40
if( (OMP_THREADS-41) >= 0 ) { }
    if( (OMP_THREADS-42) >= 0 ) { }
    if( (OMP_THREADS-43) >= 0 ) { }
    if( (OMP_THREADS-44) >= 0 ) { }
    if( (OMP_THREADS-45) >= 0 ) { }
    if( (OMP_THREADS-46) >= 0 ) { }
    if( (OMP_THREADS-47) >= 0 ) { }
    if( (OMP_THREADS-48) >= 0 ) { }
    if( (OMP_THREADS-49) >= 0 ) { }
    if( (OMP_THREADS-50) >= 0 ) { }
    // 50
if( (OMP_THREADS-51) >= 0 ) { }
    if( (OMP_THREADS-52) >= 0 ) { }
    if( (OMP_THREADS-53) >= 0 ) { }
    if( (OMP_THREADS-54) >= 0 ) { }
    if( (OMP_THREADS-55) >= 0 ) { }
    if( (OMP_THREADS-56) >= 0 ) { }
    if( (OMP_THREADS-57) >= 0 ) { }
    if( (OMP_THREADS-58) >= 0 ) { }
    if( (OMP_THREADS-59) >= 0 ) { }
    if( (OMP_THREADS-60) >= 0 ) { }
    // 60
if( (OMP_THREADS-61) >= 0 ) { }
    if( (OMP_THREADS-62) >= 0 ) { }
    if( (OMP_THREADS-63) >= 0 ) { }
    if( (OMP_THREADS-64) >= 0 ) { }
    if( (OMP_THREADS-65) >= 0 ) { }
    if( (OMP_THREADS-66) >= 0 ) { }
    if( (OMP_THREADS-67) >= 0 ) { }
    if( (OMP_THREADS-68) >= 0 ) { }
    if( (OMP_THREADS-69) >= 0 ) { }
    if( (OMP_THREADS-70) >= 0 ) { }
    // 70
if( (OMP_THREADS-71) >= 0 ) { }
    if( (OMP_THREADS-72) >= 0 ) { }
    if( (OMP_THREADS-73) >= 0 ) { }
    if( (OMP_THREADS-74) >= 0 ) { }
    if( (OMP_THREADS-75) >= 0 ) { }
    if( (OMP_THREADS-76) >= 0 ) { }
    if( (OMP_THREADS-77) >= 0 ) { }
    if( (OMP_THREADS-78) >= 0 ) { }
    if( (OMP_THREADS-79) >= 0 ) { }
    if( (OMP_THREADS-80) >= 0 ) { }
    // 80
if( (OMP_THREADS-81) >= 0 ) { }
    if( (OMP_THREADS-82) >= 0 ) { }
    if( (OMP_THREADS-83) >= 0 ) { }
    if( (OMP_THREADS-84) >= 0 ) { }
    if( (OMP_THREADS-85) >= 0 ) { }
    if( (OMP_THREADS-86) >= 0 ) { }
    if( (OMP_THREADS-87) >= 0 ) { }
    if( (OMP_THREADS-88) >= 0 ) { }
    if( (OMP_THREADS-89) >= 0 ) { }
    if( (OMP_THREADS-90) >= 0 ) { }
    // 90
if( (OMP_THREADS-91) >= 0 ) { }
    if( (OMP_THREADS-92) >= 0 ) { }
    if( (OMP_THREADS-93) >= 0 ) { }
    if( (OMP_THREADS-94) >= 0 ) { }
    if( (OMP_THREADS-95) >= 0 ) { }
    if( (OMP_THREADS-96) >= 0 ) { }
    if( (OMP_THREADS-97) >= 0 ) { }
    if( (OMP_THREADS-98) >= 0 ) { }
    if( (OMP_THREADS-99) >= 0 ) { }
    if( (OMP_THREADS-100) >= 0 ) { }
    // 100
if( (OMP_THREADS-101) >= 0 ) { }
    if( (OMP_THREADS-102) >= 0 ) { }
    if( (OMP_THREADS-103) >= 0 ) { }
    if( (OMP_THREADS-104) >= 0 ) { }
    if( (OMP_THREADS-105) >= 0 ) { }
    if( (OMP_THREADS-106) >= 0 ) { }
    if( (OMP_THREADS-107) >= 0 ) { }
    if( (OMP_THREADS-108) >= 0 ) { }
    if( (OMP_THREADS-109) >= 0 ) { }
    if( (OMP_THREADS-110) >= 0 ) { }
    // 110
if( (OMP_THREADS-111) >= 0 ) { }
    if( (OMP_THREADS-112) >= 0 ) { }
    if( (OMP_THREADS-113) >= 0 ) { }
    if( (OMP_THREADS-114) >= 0 ) { }
    if( (OMP_THREADS-115) >= 0 ) { }
    if( (OMP_THREADS-116) >= 0 ) { }
    if( (OMP_THREADS-117) >= 0 ) { }
    if( (OMP_THREADS-118) >= 0 ) { }
    if( (OMP_THREADS-119) >= 0 ) { }
    if( (OMP_THREADS-120) >= 0 ) { }
    // 120
if( (OMP_THREADS-121) >= 0 ) { }
    if( (OMP_THREADS-122) >= 0 ) { }
    if( (OMP_THREADS-123) >= 0 ) { }
    if( (OMP_THREADS-124) >= 0 ) { }
    if( (OMP_THREADS-125) >= 0 ) { }
    if( (OMP_THREADS-126) >= 0 ) { }
    if( (OMP_THREADS-127) >= 0 ) { }
    if( (OMP_THREADS-128) >= 0 ) { }
    if( (OMP_THREADS-129) >= 0 ) { }
    if( (OMP_THREADS-130) >= 0 ) { }
    // 130
if( (OMP_THREADS-131) >= 0 ) { }
    if( (OMP_THREADS-132) >= 0 ) { }
    if( (OMP_THREADS-133) >= 0 ) { }
    if( (OMP_THREADS-134) >= 0 ) { }
    if( (OMP_THREADS-135) >= 0 ) { }
    if( (OMP_THREADS-136) >= 0 ) { }
    if( (OMP_THREADS-137) >= 0 ) { }
    if( (OMP_THREADS-138) >= 0 ) { }
    if( (OMP_THREADS-139) >= 0 ) { }
    if( (OMP_THREADS-140) >= 0 ) { }
    // 140
if( (OMP_THREADS-141) >= 0 ) { }
    if( (OMP_THREADS-142) >= 0 ) { }
    if( (OMP_THREADS-143) >= 0 ) { }
    if( (OMP_THREADS-144) >= 0 ) { }
    if( (OMP_THREADS-145) >= 0 ) { }
    if( (OMP_THREADS-146) >= 0 ) { }
    if( (OMP_THREADS-147) >= 0 ) { }
    if( (OMP_THREADS-148) >= 0 ) { }
    if( (OMP_THREADS-149) >= 0 ) { }
    if( (OMP_THREADS-150) >= 0 ) { }
    // 150
if( (OMP_THREADS-151) >= 0 ) { }
    if( (OMP_THREADS-152) >= 0 ) { }
    if( (OMP_THREADS-153) >= 0 ) { }
    if( (OMP_THREADS-154) >= 0 ) { }
    if( (OMP_THREADS-155) >= 0 ) { }
    if( (OMP_THREADS-156) >= 0 ) { }
    if( (OMP_THREADS-157) >= 0 ) { }
    if( (OMP_THREADS-158) >= 0 ) { }
    if( (OMP_THREADS-159) >= 0 ) { }
    if( (OMP_THREADS-160) >= 0 ) { }
    // 160
if( (OMP_THREADS-161) >= 0 ) { }
    if( (OMP_THREADS-162) >= 0 ) { }
    if( (OMP_THREADS-163) >= 0 ) { }
    if( (OMP_THREADS-164) >= 0 ) { }
    if( (OMP_THREADS-165) >= 0 ) { }
    if( (OMP_THREADS-166) >= 0 ) { }
    if( (OMP_THREADS-167) >= 0 ) { }
    if( (OMP_THREADS-168) >= 0 ) { }
    if( (OMP_THREADS-169) >= 0 ) { }
    if( (OMP_THREADS-170) >= 0 ) { }
    // 170
if( (OMP_THREADS-171) >= 0 ) { }
    if( (OMP_THREADS-172) >= 0 ) { }
    if( (OMP_THREADS-173) >= 0 ) { }
    if( (OMP_THREADS-174) >= 0 ) { }
    if( (OMP_THREADS-175) >= 0 ) { }
    if( (OMP_THREADS-176) >= 0 ) { }
    if( (OMP_THREADS-177) >= 0 ) { }
    if( (OMP_THREADS-178) >= 0 ) { }
    if( (OMP_THREADS-179) >= 0 ) { }
    if( (OMP_THREADS-180) >= 0 ) { }
    // 180
if( (OMP_THREADS-181) >= 0 ) { }
    if( (OMP_THREADS-182) >= 0 ) { }
    if( (OMP_THREADS-183) >= 0 ) { }
    if( (OMP_THREADS-184) >= 0 ) { }
    if( (OMP_THREADS-185) >= 0 ) { }
    if( (OMP_THREADS-186) >= 0 ) { }
    if( (OMP_THREADS-187) >= 0 ) { }
    if( (OMP_THREADS-188) >= 0 ) { }
    if( (OMP_THREADS-189) >= 0 ) { }
    if( (OMP_THREADS-190) >= 0 ) { }
    // 190
if( (OMP_THREADS-191) >= 0 ) { }
    if( (OMP_THREADS-192) >= 0 ) { }
    if( (OMP_THREADS-193) >= 0 ) { }
    if( (OMP_THREADS-194) >= 0 ) { }
    if( (OMP_THREADS-195) >= 0 ) { }
    if( (OMP_THREADS-196) >= 0 ) { }
    if( (OMP_THREADS-197) >= 0 ) { }
    if( (OMP_THREADS-198) >= 0 ) { }
    if( (OMP_THREADS-199) >= 0 ) { }
    if( (OMP_THREADS-200) >= 0 ) { }
    // 200
if( (OMP_THREADS-201) >= 0 ) { }
    if( (OMP_THREADS-202) >= 0 ) { }
    if( (OMP_THREADS-203) >= 0 ) { }
    if( (OMP_THREADS-204) >= 0 ) { }
    if( (OMP_THREADS-205) >= 0 ) { }
    if( (OMP_THREADS-206) >= 0 ) { }
    if( (OMP_THREADS-207) >= 0 ) { }
    if( (OMP_THREADS-208) >= 0 ) { }
    if( (OMP_THREADS-209) >= 0 ) { }
    if( (OMP_THREADS-210) >= 0 ) { }
    // 210
if( (OMP_THREADS-211) >= 0 ) { }
    if( (OMP_THREADS-212) >= 0 ) { }
    if( (OMP_THREADS-213) >= 0 ) { }
    if( (OMP_THREADS-214) >= 0 ) { }
    if( (OMP_THREADS-215) >= 0 ) { }
    if( (OMP_THREADS-216) >= 0 ) { }
    if( (OMP_THREADS-217) >= 0 ) { }
    if( (OMP_THREADS-218) >= 0 ) { }
    if( (OMP_THREADS-219) >= 0 ) { }
    if( (OMP_THREADS-220) >= 0 ) { }
    // 220
if( (OMP_THREADS-221) >= 0 ) { }
    if( (OMP_THREADS-222) >= 0 ) { }
    if( (OMP_THREADS-223) >= 0 ) { }
    if( (OMP_THREADS-224) >= 0 ) { }
    if( (OMP_THREADS-225) >= 0 ) { }
    if( (OMP_THREADS-226) >= 0 ) { }
    if( (OMP_THREADS-227) >= 0 ) { }
    if( (OMP_THREADS-228) >= 0 ) { }
    if( (OMP_THREADS-229) >= 0 ) { }
    if( (OMP_THREADS-230) >= 0 ) { }
    // 230
if( (OMP_THREADS-231) >= 0 ) { }
    if( (OMP_THREADS-232) >= 0 ) { }
    if( (OMP_THREADS-233) >= 0 ) { }
    if( (OMP_THREADS-234) >= 0 ) { }
    if( (OMP_THREADS-235) >= 0 ) { }
    if( (OMP_THREADS-236) >= 0 ) { }
    if( (OMP_THREADS-237) >= 0 ) { }
    if( (OMP_THREADS-238) >= 0 ) { }
    if( (OMP_THREADS-239) >= 0 ) { }
    if( (OMP_THREADS-240) >= 0 ) { }
    // 240
if( (OMP_THREADS-241) >= 0 ) { }
    if( (OMP_THREADS-242) >= 0 ) { }
    if( (OMP_THREADS-243) >= 0 ) { }
    if( (OMP_THREADS-244) >= 0 ) { }
    if( (OMP_THREADS-245) >= 0 ) { }
    if( (OMP_THREADS-246) >= 0 ) { }
    if( (OMP_THREADS-247) >= 0 ) { }
    if( (OMP_THREADS-248) >= 0 ) { }
    if( (OMP_THREADS-249) >= 0 ) { }
    if( (OMP_THREADS-250) >= 0 ) { }
    // 250
if( (OMP_THREADS-251) >= 0 ) { }
    if( (OMP_THREADS-252) >= 0 ) { }
    if( (OMP_THREADS-253) >= 0 ) { }
    if( (OMP_THREADS-254) >= 0 ) { }
    if( (OMP_THREADS-255) >= 0 ) { }
    if( (OMP_THREADS-256) >= 0 ) { }
    if( (OMP_THREADS-257) >= 0 ) { }
    if( (OMP_THREADS-258) >= 0 ) { }
    if( (OMP_THREADS-259) >= 0 ) { }
    if( (OMP_THREADS-260) >= 0 ) { }
    // 260
if( (OMP_THREADS-261) >= 0 ) { }
    if( (OMP_THREADS-262) >= 0 ) { }
    if( (OMP_THREADS-263) >= 0 ) { }
    if( (OMP_THREADS-264) >= 0 ) { }
    if( (OMP_THREADS-265) >= 0 ) { }
    if( (OMP_THREADS-266) >= 0 ) { }
    if( (OMP_THREADS-267) >= 0 ) { }
    if( (OMP_THREADS-268) >= 0 ) { }
    if( (OMP_THREADS-269) >= 0 ) { }
    if( (OMP_THREADS-270) >= 0 ) { }
    // 270
if( (OMP_THREADS-271) >= 0 ) { }
    if( (OMP_THREADS-272) >= 0 ) { }
    if( (OMP_THREADS-273) >= 0 ) { }
    if( (OMP_THREADS-274) >= 0 ) { }
    if( (OMP_THREADS-275) >= 0 ) { }
    if( (OMP_THREADS-276) >= 0 ) { }
    if( (OMP_THREADS-277) >= 0 ) { }
    if( (OMP_THREADS-278) >= 0 ) { }
    if( (OMP_THREADS-279) >= 0 ) { }
    if( (OMP_THREADS-280) >= 0 ) { }
    // 280
    if( (OMP_THREADS-281) >= 0 ) { }
    if( (OMP_THREADS-282) >= 0 ) { }
    if( (OMP_THREADS-283) >= 0 ) { }
    if( (OMP_THREADS-284) >= 0 ) { }
    if( (OMP_THREADS-285) >= 0 ) { }
    if( (OMP_THREADS-286) >= 0 ) { }
    if( (OMP_THREADS-287) >= 0 ) { }
    if( (OMP_THREADS-288) >= 0 ) { }
    if( (OMP_THREADS-289) >= 0 ) { }
    if( (OMP_THREADS-290) >= 0 ) { }
    // 290
    if( (OMP_THREADS-291) >= 0 ) { }
    if( (OMP_THREADS-292) >= 0 ) { }
    if( (OMP_THREADS-293) >= 0 ) { }
    if( (OMP_THREADS-294) >= 0 ) { }
    if( (OMP_THREADS-295) >= 0 ) { }
    if( (OMP_THREADS-296) >= 0 ) { }
    if( (OMP_THREADS-297) >= 0 ) { }
    if( (OMP_THREADS-298) >= 0 ) { }
    if( (OMP_THREADS-299) >= 0 ) { }
    if( (OMP_THREADS-300) >= 0 ) { }
    // 300

    if( (OMP_THREADS-301) >= 0 ) { } // 301

	}	

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	return 0;
}