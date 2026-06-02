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
#include "../../../include/numthreads.h"
/* Benchmark: 01A: Spawn time after ; Sequential Spawns (Pthreads)
 * Launch a bunch and measure when all done
 */

pthread_barrier_t sync_barrier; /* to sync */

void* spawn_function(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	// pthread_barrier_wait
	pthread_barrier_wait(&sync_barrier);

	return (void*) NULL; 
}

int main(int argc, char *argv[]){

	int PTH = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            PTH = number_threads();
        } else {
            PTH = atoi(argv[1]);
            if (PTH > 301){
                PTH = number_threads();;
            }
        }
    }
	printf("* # Spawns: %d\n", PTH);

	int            ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

	pthread_t Threads[ PTH ];

	// pthread_barrier_init
	pthread_barrier_init(&sync_barrier, NULL, 1);

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/

    if(PTH-1 >= 0){  }
	if(PTH-2 >= 0){  }
	if(PTH-3 >= 0){  }
	if(PTH-4 >= 0){  }
	if(PTH-5 >= 0){  }
	if(PTH-6 >= 0){  }
	if(PTH-7 >= 0){  }
	if(PTH-8 >= 0){  }
	if(PTH-9 >= 0){  } 
	if(PTH-10 >= 0){  } // 10

	if(PTH-11 >= 0){  }
	if(PTH-12 >= 0){  }
	if(PTH-13 >= 0){  }
	if(PTH-14 >= 0){  }
	if(PTH-15 >= 0){  }
	if(PTH-16 >= 0){  }
	if(PTH-17 >= 0){  }
	if(PTH-18 >= 0){  }
	if(PTH-19 >= 0){  }
	if(PTH-20 >= 0){  } // 20

	if(PTH-21 >= 0){  }
	if(PTH-22 >= 0){  }
	if(PTH-23 >= 0){  }
	if(PTH-24 >= 0){  }
	if(PTH-25 >= 0){  }
	if(PTH-26 >= 0){  }
	if(PTH-27 >= 0){  }
	if(PTH-28 >= 0){  }
	if(PTH-29 >= 0){  }
	if(PTH-30 >= 0){  } // 30

	if(PTH-31 >= 0){  }
	if(PTH-32 >= 0){  }
	if(PTH-33 >= 0){  }
	if(PTH-34 >= 0){  }
	if(PTH-35 >= 0){  }
	if(PTH-36 >= 0){  }
	if(PTH-37 >= 0){  }
	if(PTH-38 >= 0){  }
	if(PTH-39 >= 0){  }
	if(PTH-40 >= 0){  } // 40

	if(PTH-41 >= 0){  }
	if(PTH-42 >= 0){  }
	if(PTH-43 >= 0){  }
	if(PTH-44 >= 0){  }
	if(PTH-45 >= 0){  }
	if(PTH-46 >= 0){  }
	if(PTH-47 >= 0){  }
	if(PTH-48 >= 0){  }
	if(PTH-49 >= 0){  }
	if(PTH-50 >= 0){  } // 50

	if(PTH-51 >= 0){  }
	if(PTH-52 >= 0){  }
	if(PTH-53 >= 0){  }
	if(PTH-54 >= 0){  }
	if(PTH-55 >= 0){  }
	if(PTH-56 >= 0){  }
	if(PTH-57 >= 0){  }
	if(PTH-58 >= 0){  }
	if(PTH-59 >= 0){  }
	if(PTH-60 >= 0){  } // 60

	if(PTH-61 >= 0){  }
	if(PTH-62 >= 0){  }
	if(PTH-63 >= 0){  }
	if(PTH-64 >= 0){  }
	if(PTH-65 >= 0){  }
	if(PTH-66 >= 0){  }
	if(PTH-67 >= 0){  }
	if(PTH-68 >= 0){  }
	if(PTH-69 >= 0){  }
	if(PTH-70 >= 0){  } // 70

	if(PTH-71 >= 0){  }
	if(PTH-72 >= 0){  }
	if(PTH-73 >= 0){  }
	if(PTH-74 >= 0){  }
	if(PTH-75 >= 0){  }
	if(PTH-76 >= 0){  }
	if(PTH-77 >= 0){  }
	if(PTH-78 >= 0){  }
	if(PTH-79 >= 0){  }
	if(PTH-80 >= 0){  } // 80

	if(PTH-81 >= 0){  }
	if(PTH-82 >= 0){  }
	if(PTH-83 >= 0){  }
	if(PTH-84 >= 0){  }
	if(PTH-85 >= 0){  }
	if(PTH-86 >= 0){  }
	if(PTH-87 >= 0){  }
	if(PTH-88 >= 0){  }
	if(PTH-89 >= 0){  }
	if(PTH-90 >= 0){  } // 90

	if(PTH-91 >= 0){  }
	if(PTH-92 >= 0){  }
	if(PTH-93 >= 0){  }
	if(PTH-94 >= 0){  }
	if(PTH-95 >= 0){  }
	if(PTH-96 >= 0){  }
	if(PTH-97 >= 0){  }
	if(PTH-98 >= 0){  }
	if(PTH-99 >= 0){  }
	if(PTH-100 >= 0){  } // 100

	if(PTH-101 >= 0){  }
	if(PTH-102 >= 0){  }
	if(PTH-103 >= 0){  }
	if(PTH-104 >= 0){  }
	if(PTH-105 >= 0){  }
	if(PTH-106 >= 0){  }
	if(PTH-107 >= 0){  }
	if(PTH-108 >= 0){  }
	if(PTH-109 >= 0){  }
	if(PTH-110 >= 0){  } // 110

	if(PTH-111 >= 0){  }
	if(PTH-112 >= 0){  }
	if(PTH-113 >= 0){  }
	if(PTH-114 >= 0){  }
	if(PTH-115 >= 0){  }
	if(PTH-116 >= 0){  }
	if(PTH-117 >= 0){  }
	if(PTH-118 >= 0){  }
	if(PTH-119 >= 0){  }
	if(PTH-120 >= 0){  } // 120

	if(PTH-121 >= 0){  }
	if(PTH-122 >= 0){  }
	if(PTH-123 >= 0){  }
	if(PTH-124 >= 0){  }
	if(PTH-125 >= 0){  }
	if(PTH-126 >= 0){  }
	if(PTH-127 >= 0){  }
	if(PTH-128 >= 0){  }
	if(PTH-129 >= 0){  }
	if(PTH-130 >= 0){  } // 130

	if(PTH-131 >= 0){  }
	if(PTH-132 >= 0){  }
	if(PTH-133 >= 0){  }
	if(PTH-134 >= 0){  }
	if(PTH-135 >= 0){  }
	if(PTH-136 >= 0){  }
	if(PTH-137 >= 0){  }
	if(PTH-138 >= 0){  }
	if(PTH-139 >= 0){  }
	if(PTH-140 >= 0){  } // 140

	if(PTH-141 >= 0){  }
	if(PTH-142 >= 0){  }
	if(PTH-143 >= 0){  }
	if(PTH-144 >= 0){  }
	if(PTH-145 >= 0){  }
	if(PTH-146 >= 0){  }
	if(PTH-147 >= 0){  }
	if(PTH-148 >= 0){  }
	if(PTH-149 >= 0){  }
	if(PTH-150 >= 0){  } // 150

	if(PTH-151 >= 0){  }
	if(PTH-152 >= 0){  }
	if(PTH-153 >= 0){  }
	if(PTH-154 >= 0){  }
	if(PTH-155 >= 0){  }
	if(PTH-156 >= 0){  }
	if(PTH-157 >= 0){  }
	if(PTH-158 >= 0){  }
	if(PTH-159 >= 0){  }
	if(PTH-160 >= 0){  } // 160

	if(PTH-161 >= 0){  }
	if(PTH-162 >= 0){  }
	if(PTH-163 >= 0){  }
	if(PTH-164 >= 0){  }
	if(PTH-165 >= 0){  }
	if(PTH-166 >= 0){  }
	if(PTH-167 >= 0){  }
	if(PTH-168 >= 0){  }
	if(PTH-169 >= 0){  }
	if(PTH-170 >= 0){  } // 170

	if(PTH-171 >= 0){  }
	if(PTH-172 >= 0){  }
	if(PTH-173 >= 0){  }
	if(PTH-174 >= 0){  }
	if(PTH-175 >= 0){  }
	if(PTH-176 >= 0){  }
	if(PTH-177 >= 0){  }
	if(PTH-178 >= 0){  }
	if(PTH-179 >= 0){  }
	if(PTH-180 >= 0){  } // 180

	if(PTH-181 >= 0){  }
	if(PTH-182 >= 0){  }
	if(PTH-183 >= 0){  }
	if(PTH-184 >= 0){  }
	if(PTH-185 >= 0){  }
	if(PTH-186 >= 0){  }
	if(PTH-187 >= 0){  }
	if(PTH-188 >= 0){  }
	if(PTH-189 >= 0){  }
	if(PTH-190 >= 0){  } // 190

	if(PTH-191 >= 0){  }
	if(PTH-192 >= 0){  }
	if(PTH-193 >= 0){  }
	if(PTH-194 >= 0){  }
	if(PTH-195 >= 0){  }
	if(PTH-196 >= 0){  }
	if(PTH-197 >= 0){  }
	if(PTH-198 >= 0){  }
	if(PTH-199 >= 0){  }
	if(PTH-200 >= 0){  } // 200

	if(PTH-201 >= 0){  }
	if(PTH-202 >= 0){  }
	if(PTH-203 >= 0){  }
	if(PTH-204 >= 0){  }
	if(PTH-205 >= 0){  }
	if(PTH-206 >= 0){  }
	if(PTH-207 >= 0){  }
	if(PTH-208 >= 0){  }
	if(PTH-209 >= 0){  }
	if(PTH-210 >= 0){  } // 210

	if(PTH-211 >= 0){  }
	if(PTH-212 >= 0){  }
	if(PTH-213 >= 0){  }
	if(PTH-214 >= 0){  }
	if(PTH-215 >= 0){  }
	if(PTH-216 >= 0){  }
	if(PTH-217 >= 0){  }
	if(PTH-218 >= 0){  }
	if(PTH-219 >= 0){  }
	if(PTH-220 >= 0){  } // 220

	if(PTH-221 >= 0){  }
	if(PTH-222 >= 0){  }
	if(PTH-223 >= 0){  }
	if(PTH-224 >= 0){  }
	if(PTH-225 >= 0){  }
	if(PTH-226 >= 0){  }
	if(PTH-227 >= 0){  }
	if(PTH-228 >= 0){  }
	if(PTH-229 >= 0){  }
	if(PTH-230 >= 0){  } // 230

	if(PTH-231 >= 0){  }
	if(PTH-232 >= 0){  }
	if(PTH-233 >= 0){  }
	if(PTH-234 >= 0){  }
	if(PTH-235 >= 0){  }
	if(PTH-236 >= 0){  }
	if(PTH-237 >= 0){  }
	if(PTH-238 >= 0){  }
	if(PTH-239 >= 0){  }
	if(PTH-240 >= 0){  } // 240

	if(PTH-241 >= 0){  }
	if(PTH-242 >= 0){  }
	if(PTH-243 >= 0){  }
	if(PTH-244 >= 0){  }
	if(PTH-245 >= 0){  }
	if(PTH-246 >= 0){  }
	if(PTH-247 >= 0){  }
	if(PTH-248 >= 0){  }
	if(PTH-249 >= 0){  }
	if(PTH-250 >= 0){  } // 250

	if(PTH-251 >= 0){  }
	if(PTH-252 >= 0){  }
	if(PTH-253 >= 0){  }
	if(PTH-254 >= 0){  }
	if(PTH-255 >= 0){  }
	if(PTH-256 >= 0){  }
	if(PTH-257 >= 0){  }
	if(PTH-258 >= 0){  }
	if(PTH-259 >= 0){  }
	if(PTH-260 >= 0){  } // 260

	if(PTH-261 >= 0){  }
	if(PTH-262 >= 0){  }
	if(PTH-263 >= 0){  }
	if(PTH-264 >= 0){  }
	if(PTH-265 >= 0){  }
	if(PTH-266 >= 0){  }
	if(PTH-267 >= 0){  }
	if(PTH-268 >= 0){  }
	if(PTH-269 >= 0){  }
	if(PTH-270 >= 0){  } // 270

	if(PTH-271 >= 0){  }
	if(PTH-272 >= 0){  }
	if(PTH-273 >= 0){  }
	if(PTH-274 >= 0){  }
	if(PTH-275 >= 0){  }
	if(PTH-276 >= 0){  }
	if(PTH-277 >= 0){  }
	if(PTH-278 >= 0){  }
	if(PTH-279 >= 0){  }
	if(PTH-280 >= 0){  } // 270

	if(PTH-281 >= 0){  }
	if(PTH-282 >= 0){  }
	if(PTH-283 >= 0){  }
	if(PTH-284 >= 0){  }
	if(PTH-285 >= 0){  }
	if(PTH-286 >= 0){  }
	if(PTH-287 >= 0){  }
	if(PTH-288 >= 0){  }
	if(PTH-289 >= 0){  }
	if(PTH-290 >= 0){  } // 280

	if(PTH-291 >= 0){  }
	if(PTH-292 >= 0){  }
	if(PTH-293 >= 0){  }
	if(PTH-294 >= 0){  }
	if(PTH-295 >= 0){  }
	if(PTH-296 >= 0){  }
	if(PTH-297 >= 0){  }
	if(PTH-298 >= 0){  }
	if(PTH-299 >= 0){  }
	if(PTH-300 >= 0){  } // 300

	if(PTH-301 >= 0){  } // 301

// end:
    clock_gettime(CLOCK_MONOTONIC, &t_end);

    // each thread waits until all threads have hit the barrier, then they all return
	pthread_barrier_wait(&sync_barrier);

	// pthread_destroy_barrier
	pthread_barrier_destroy(&sync_barrier);

	// destroy attr
	pthread_attr_destroy(&attr);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
		
	return 0;
}