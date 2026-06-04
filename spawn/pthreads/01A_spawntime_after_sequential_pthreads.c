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
/* Benchmark: 01A: Spawn time after ; Sequential Spawns (Pthreads)
 * Launch a bunch and measure when all done
 */

// pthread_barrier_t sync_barrier; /* to sync */

void* spawn_function(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	// pthread_barrier_wait
	// pthread_barrier_wait(&sync_barrier);

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
	// pthread_barrier_init(&sync_barrier, NULL, PTH+1);

    int k = 1;

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

    while(1){
        pthread_create( &Threads[ k-1 ], &attr, spawn_function, NULL); 
        k++;
        if(PTH-k >= 0){ break; }
    }

	/****/ 
    // all threads spawn detached,
    // hit the barrier,
    // and are immmediately freed w/o joining

/*    if(PTH-1 >= 0){ pthread_create( &Threads[ 0 ], &attr, spawn_function, NULL); }
	if(PTH-2 >= 0){ pthread_create( &Threads[ 1 ], &attr, spawn_function, NULL); }
	if(PTH-3 >= 0){ pthread_create( &Threads[ 2 ], &attr, spawn_function, NULL); }
	if(PTH-4 >= 0){ pthread_create( &Threads[ 3 ], &attr, spawn_function, NULL); }
	if(PTH-5 >= 0){ pthread_create( &Threads[ 4 ], &attr, spawn_function, NULL); }
	if(PTH-6 >= 0){ pthread_create( &Threads[ 5 ], &attr, spawn_function, NULL); }
	if(PTH-7 >= 0){ pthread_create( &Threads[ 6 ], &attr, spawn_function, NULL); }
	if(PTH-8 >= 0){ pthread_create( &Threads[ 7 ], &attr, spawn_function, NULL); }
	if(PTH-9 >= 0){ pthread_create( &Threads[ 8 ], &attr, spawn_function, NULL); } 
	if(PTH-10 >= 0){ pthread_create( &Threads[ 9 ], &attr, spawn_function, NULL); } // 10

	if(PTH-11 >= 0){ pthread_create( &Threads[ 10 ], &attr, spawn_function, NULL); }
	if(PTH-12 >= 0){ pthread_create( &Threads[ 11 ], &attr, spawn_function, NULL); }
	if(PTH-13 >= 0){ pthread_create( &Threads[ 12 ], &attr, spawn_function, NULL); }
	if(PTH-14 >= 0){ pthread_create( &Threads[ 13 ], &attr, spawn_function, NULL); }
	if(PTH-15 >= 0){ pthread_create( &Threads[ 14 ], &attr, spawn_function, NULL); }
	if(PTH-16 >= 0){ pthread_create( &Threads[ 15 ], &attr, spawn_function, NULL); }
	if(PTH-17 >= 0){ pthread_create( &Threads[ 16 ], &attr, spawn_function, NULL); }
	if(PTH-18 >= 0){ pthread_create( &Threads[ 17 ], &attr, spawn_function, NULL); }
	if(PTH-19 >= 0){ pthread_create( &Threads[ 18 ], &attr, spawn_function, NULL); }
	if(PTH-20 >= 0){ pthread_create( &Threads[ 19 ], &attr, spawn_function, NULL); } // 20

	if(PTH-21 >= 0){ pthread_create( &Threads[ 20 ], &attr, spawn_function, NULL); }
	if(PTH-22 >= 0){ pthread_create( &Threads[ 21 ], &attr, spawn_function, NULL); }
	if(PTH-23 >= 0){ pthread_create( &Threads[ 22 ], &attr, spawn_function, NULL); }
	if(PTH-24 >= 0){ pthread_create( &Threads[ 23 ], &attr, spawn_function, NULL); }
	if(PTH-25 >= 0){ pthread_create( &Threads[ 24 ], &attr, spawn_function, NULL); }
	if(PTH-26 >= 0){ pthread_create( &Threads[ 25 ], &attr, spawn_function, NULL); }
	if(PTH-27 >= 0){ pthread_create( &Threads[ 26 ], &attr, spawn_function, NULL); }
	if(PTH-28 >= 0){ pthread_create( &Threads[ 27 ], &attr, spawn_function, NULL); }
	if(PTH-29 >= 0){ pthread_create( &Threads[ 28 ], &attr, spawn_function, NULL); }
	if(PTH-30 >= 0){ pthread_create( &Threads[ 29 ], &attr, spawn_function, NULL); } // 30

	if(PTH-31 >= 0){ pthread_create( &Threads[ 30 ], &attr, spawn_function, NULL); }
	if(PTH-32 >= 0){ pthread_create( &Threads[ 31 ], &attr, spawn_function, NULL); }
	if(PTH-33 >= 0){ pthread_create( &Threads[ 32 ], &attr, spawn_function, NULL); }
	if(PTH-34 >= 0){ pthread_create( &Threads[ 33 ], &attr, spawn_function, NULL); }
	if(PTH-35 >= 0){ pthread_create( &Threads[ 34 ], &attr, spawn_function, NULL); }
	if(PTH-36 >= 0){ pthread_create( &Threads[ 35 ], &attr, spawn_function, NULL); }
	if(PTH-37 >= 0){ pthread_create( &Threads[ 36 ], &attr, spawn_function, NULL); }
	if(PTH-38 >= 0){ pthread_create( &Threads[ 37 ], &attr, spawn_function, NULL); }
	if(PTH-39 >= 0){ pthread_create( &Threads[ 38 ], &attr, spawn_function, NULL); }
	if(PTH-40 >= 0){ pthread_create( &Threads[ 39 ], &attr, spawn_function, NULL); } // 40

	if(PTH-41 >= 0){ pthread_create( &Threads[ 40 ], &attr, spawn_function, NULL); }
	if(PTH-42 >= 0){ pthread_create( &Threads[ 41 ], &attr, spawn_function, NULL); }
	if(PTH-43 >= 0){ pthread_create( &Threads[ 42 ], &attr, spawn_function, NULL); }
	if(PTH-44 >= 0){ pthread_create( &Threads[ 43 ], &attr, spawn_function, NULL); }
	if(PTH-45 >= 0){ pthread_create( &Threads[ 44 ], &attr, spawn_function, NULL); }
	if(PTH-46 >= 0){ pthread_create( &Threads[ 45 ], &attr, spawn_function, NULL); }
	if(PTH-47 >= 0){ pthread_create( &Threads[ 46 ], &attr, spawn_function, NULL); }
	if(PTH-48 >= 0){ pthread_create( &Threads[ 47 ], &attr, spawn_function, NULL); }
	if(PTH-49 >= 0){ pthread_create( &Threads[ 48 ], &attr, spawn_function, NULL); }
	if(PTH-50 >= 0){ pthread_create( &Threads[ 49 ], &attr, spawn_function, NULL); } // 50

	if(PTH-51 >= 0){ pthread_create( &Threads[ 50 ], &attr, spawn_function, NULL); }
	if(PTH-52 >= 0){ pthread_create( &Threads[ 51 ], &attr, spawn_function, NULL); }
	if(PTH-53 >= 0){ pthread_create( &Threads[ 52 ], &attr, spawn_function, NULL); }
	if(PTH-54 >= 0){ pthread_create( &Threads[ 53 ], &attr, spawn_function, NULL); }
	if(PTH-55 >= 0){ pthread_create( &Threads[ 54 ], &attr, spawn_function, NULL); }
	if(PTH-56 >= 0){ pthread_create( &Threads[ 55 ], &attr, spawn_function, NULL); }
	if(PTH-57 >= 0){ pthread_create( &Threads[ 56 ], &attr, spawn_function, NULL); }
	if(PTH-58 >= 0){ pthread_create( &Threads[ 57 ], &attr, spawn_function, NULL); }
	if(PTH-59 >= 0){ pthread_create( &Threads[ 58 ], &attr, spawn_function, NULL); }
	if(PTH-60 >= 0){ pthread_create( &Threads[ 59 ], &attr, spawn_function, NULL); } // 60

	if(PTH-61 >= 0){ pthread_create( &Threads[ 60 ], &attr, spawn_function, NULL); }
	if(PTH-62 >= 0){ pthread_create( &Threads[ 61 ], &attr, spawn_function, NULL); }
	if(PTH-63 >= 0){ pthread_create( &Threads[ 62 ], &attr, spawn_function, NULL); }
	if(PTH-64 >= 0){ pthread_create( &Threads[ 63 ], &attr, spawn_function, NULL); }
	if(PTH-65 >= 0){ pthread_create( &Threads[ 64 ], &attr, spawn_function, NULL); }
	if(PTH-66 >= 0){ pthread_create( &Threads[ 65 ], &attr, spawn_function, NULL); }
	if(PTH-67 >= 0){ pthread_create( &Threads[ 66 ], &attr, spawn_function, NULL); }
	if(PTH-68 >= 0){ pthread_create( &Threads[ 67 ], &attr, spawn_function, NULL); }
	if(PTH-69 >= 0){ pthread_create( &Threads[ 68 ], &attr, spawn_function, NULL); }
	if(PTH-70 >= 0){ pthread_create( &Threads[ 69 ], &attr, spawn_function, NULL); } // 70

	if(PTH-71 >= 0){ pthread_create( &Threads[ 70 ], &attr, spawn_function, NULL); }
	if(PTH-72 >= 0){ pthread_create( &Threads[ 71 ], &attr, spawn_function, NULL); }
	if(PTH-73 >= 0){ pthread_create( &Threads[ 72 ], &attr, spawn_function, NULL); }
	if(PTH-74 >= 0){ pthread_create( &Threads[ 73 ], &attr, spawn_function, NULL); }
	if(PTH-75 >= 0){ pthread_create( &Threads[ 74 ], &attr, spawn_function, NULL); }
	if(PTH-76 >= 0){ pthread_create( &Threads[ 75 ], &attr, spawn_function, NULL); }
	if(PTH-77 >= 0){ pthread_create( &Threads[ 76 ], &attr, spawn_function, NULL); }
	if(PTH-78 >= 0){ pthread_create( &Threads[ 77 ], &attr, spawn_function, NULL); }
	if(PTH-79 >= 0){ pthread_create( &Threads[ 78 ], &attr, spawn_function, NULL); }
	if(PTH-80 >= 0){ pthread_create( &Threads[ 79 ], &attr, spawn_function, NULL); } // 80

	if(PTH-81 >= 0){ pthread_create( &Threads[ 80 ], &attr, spawn_function, NULL); }
	if(PTH-82 >= 0){ pthread_create( &Threads[ 81 ], &attr, spawn_function, NULL); }
	if(PTH-83 >= 0){ pthread_create( &Threads[ 82 ], &attr, spawn_function, NULL); }
	if(PTH-84 >= 0){ pthread_create( &Threads[ 83 ], &attr, spawn_function, NULL); }
	if(PTH-85 >= 0){ pthread_create( &Threads[ 84 ], &attr, spawn_function, NULL); }
	if(PTH-86 >= 0){ pthread_create( &Threads[ 85 ], &attr, spawn_function, NULL); }
	if(PTH-87 >= 0){ pthread_create( &Threads[ 86 ], &attr, spawn_function, NULL); }
	if(PTH-88 >= 0){ pthread_create( &Threads[ 87 ], &attr, spawn_function, NULL); }
	if(PTH-89 >= 0){ pthread_create( &Threads[ 88 ], &attr, spawn_function, NULL); }
	if(PTH-90 >= 0){ pthread_create( &Threads[ 89 ], &attr, spawn_function, NULL); } // 90

	if(PTH-91 >= 0){ pthread_create( &Threads[ 90 ], &attr, spawn_function, NULL); }
	if(PTH-92 >= 0){ pthread_create( &Threads[ 91 ], &attr, spawn_function, NULL); }
	if(PTH-93 >= 0){ pthread_create( &Threads[ 92 ], &attr, spawn_function, NULL); }
	if(PTH-94 >= 0){ pthread_create( &Threads[ 93 ], &attr, spawn_function, NULL); }
	if(PTH-95 >= 0){ pthread_create( &Threads[ 94 ], &attr, spawn_function, NULL); }
	if(PTH-96 >= 0){ pthread_create( &Threads[ 95 ], &attr, spawn_function, NULL); }
	if(PTH-97 >= 0){ pthread_create( &Threads[ 96 ], &attr, spawn_function, NULL); }
	if(PTH-98 >= 0){ pthread_create( &Threads[ 97 ], &attr, spawn_function, NULL); }
	if(PTH-99 >= 0){ pthread_create( &Threads[ 98 ], &attr, spawn_function, NULL); }
	if(PTH-100 >= 0){ pthread_create( &Threads[ 99 ], &attr, spawn_function, NULL); } // 100

	if(PTH-101 >= 0){ pthread_create( &Threads[ 100 ], &attr, spawn_function, NULL); }
	if(PTH-102 >= 0){ pthread_create( &Threads[ 101 ], &attr, spawn_function, NULL); }
	if(PTH-103 >= 0){ pthread_create( &Threads[ 102 ], &attr, spawn_function, NULL); }
	if(PTH-104 >= 0){ pthread_create( &Threads[ 103 ], &attr, spawn_function, NULL); }
	if(PTH-105 >= 0){ pthread_create( &Threads[ 104 ], &attr, spawn_function, NULL); }
	if(PTH-106 >= 0){ pthread_create( &Threads[ 105 ], &attr, spawn_function, NULL); }
	if(PTH-107 >= 0){ pthread_create( &Threads[ 106 ], &attr, spawn_function, NULL); }
	if(PTH-108 >= 0){ pthread_create( &Threads[ 107 ], &attr, spawn_function, NULL); }
	if(PTH-109 >= 0){ pthread_create( &Threads[ 108 ], &attr, spawn_function, NULL); }
	if(PTH-110 >= 0){ pthread_create( &Threads[ 109 ], &attr, spawn_function, NULL); } // 110

	if(PTH-111 >= 0){ pthread_create( &Threads[ 110 ], &attr, spawn_function, NULL); }
	if(PTH-112 >= 0){ pthread_create( &Threads[ 111 ], &attr, spawn_function, NULL); }
	if(PTH-113 >= 0){ pthread_create( &Threads[ 112 ], &attr, spawn_function, NULL); }
	if(PTH-114 >= 0){ pthread_create( &Threads[ 113 ], &attr, spawn_function, NULL); }
	if(PTH-115 >= 0){ pthread_create( &Threads[ 114 ], &attr, spawn_function, NULL); }
	if(PTH-116 >= 0){ pthread_create( &Threads[ 115 ], &attr, spawn_function, NULL); }
	if(PTH-117 >= 0){ pthread_create( &Threads[ 116 ], &attr, spawn_function, NULL); }
	if(PTH-118 >= 0){ pthread_create( &Threads[ 117 ], &attr, spawn_function, NULL); }
	if(PTH-119 >= 0){ pthread_create( &Threads[ 118 ], &attr, spawn_function, NULL); }
	if(PTH-120 >= 0){ pthread_create( &Threads[ 119 ], &attr, spawn_function, NULL); } // 120

	if(PTH-121 >= 0){ pthread_create( &Threads[ 120 ], &attr, spawn_function, NULL); }
	if(PTH-122 >= 0){ pthread_create( &Threads[ 121 ], &attr, spawn_function, NULL); }
	if(PTH-123 >= 0){ pthread_create( &Threads[ 122 ], &attr, spawn_function, NULL); }
	if(PTH-124 >= 0){ pthread_create( &Threads[ 123 ], &attr, spawn_function, NULL); }
	if(PTH-125 >= 0){ pthread_create( &Threads[ 124 ], &attr, spawn_function, NULL); }
	if(PTH-126 >= 0){ pthread_create( &Threads[ 125 ], &attr, spawn_function, NULL); }
	if(PTH-127 >= 0){ pthread_create( &Threads[ 126 ], &attr, spawn_function, NULL); }
	if(PTH-128 >= 0){ pthread_create( &Threads[ 127 ], &attr, spawn_function, NULL); }
	if(PTH-129 >= 0){ pthread_create( &Threads[ 128 ], &attr, spawn_function, NULL); }
	if(PTH-130 >= 0){ pthread_create( &Threads[ 129 ], &attr, spawn_function, NULL); } // 130

	if(PTH-131 >= 0){ pthread_create( &Threads[ 130 ], &attr, spawn_function, NULL); }
	if(PTH-132 >= 0){ pthread_create( &Threads[ 131 ], &attr, spawn_function, NULL); }
	if(PTH-133 >= 0){ pthread_create( &Threads[ 132 ], &attr, spawn_function, NULL); }
	if(PTH-134 >= 0){ pthread_create( &Threads[ 133 ], &attr, spawn_function, NULL); }
	if(PTH-135 >= 0){ pthread_create( &Threads[ 134 ], &attr, spawn_function, NULL); }
	if(PTH-136 >= 0){ pthread_create( &Threads[ 135 ], &attr, spawn_function, NULL); }
	if(PTH-137 >= 0){ pthread_create( &Threads[ 136 ], &attr, spawn_function, NULL); }
	if(PTH-138 >= 0){ pthread_create( &Threads[ 137 ], &attr, spawn_function, NULL); }
	if(PTH-139 >= 0){ pthread_create( &Threads[ 138 ], &attr, spawn_function, NULL); }
	if(PTH-140 >= 0){ pthread_create( &Threads[ 139 ], &attr, spawn_function, NULL); } // 140

	if(PTH-141 >= 0){ pthread_create( &Threads[ 140 ], &attr, spawn_function, NULL); }
	if(PTH-142 >= 0){ pthread_create( &Threads[ 141 ], &attr, spawn_function, NULL); }
	if(PTH-143 >= 0){ pthread_create( &Threads[ 142 ], &attr, spawn_function, NULL); }
	if(PTH-144 >= 0){ pthread_create( &Threads[ 143 ], &attr, spawn_function, NULL); }
	if(PTH-145 >= 0){ pthread_create( &Threads[ 144 ], &attr, spawn_function, NULL); }
	if(PTH-146 >= 0){ pthread_create( &Threads[ 145 ], &attr, spawn_function, NULL); }
	if(PTH-147 >= 0){ pthread_create( &Threads[ 146 ], &attr, spawn_function, NULL); }
	if(PTH-148 >= 0){ pthread_create( &Threads[ 147 ], &attr, spawn_function, NULL); }
	if(PTH-149 >= 0){ pthread_create( &Threads[ 148 ], &attr, spawn_function, NULL); }
	if(PTH-150 >= 0){ pthread_create( &Threads[ 149 ], &attr, spawn_function, NULL); } // 150

	if(PTH-151 >= 0){ pthread_create( &Threads[ 150 ], &attr, spawn_function, NULL); }
	if(PTH-152 >= 0){ pthread_create( &Threads[ 151 ], &attr, spawn_function, NULL); }
	if(PTH-153 >= 0){ pthread_create( &Threads[ 152 ], &attr, spawn_function, NULL); }
	if(PTH-154 >= 0){ pthread_create( &Threads[ 153 ], &attr, spawn_function, NULL); }
	if(PTH-155 >= 0){ pthread_create( &Threads[ 154 ], &attr, spawn_function, NULL); }
	if(PTH-156 >= 0){ pthread_create( &Threads[ 155 ], &attr, spawn_function, NULL); }
	if(PTH-157 >= 0){ pthread_create( &Threads[ 156 ], &attr, spawn_function, NULL); }
	if(PTH-158 >= 0){ pthread_create( &Threads[ 157 ], &attr, spawn_function, NULL); }
	if(PTH-159 >= 0){ pthread_create( &Threads[ 158 ], &attr, spawn_function, NULL); }
	if(PTH-160 >= 0){ pthread_create( &Threads[ 159 ], &attr, spawn_function, NULL); } // 160

	if(PTH-161 >= 0){ pthread_create( &Threads[ 160 ], &attr, spawn_function, NULL); }
	if(PTH-162 >= 0){ pthread_create( &Threads[ 161 ], &attr, spawn_function, NULL); }
	if(PTH-163 >= 0){ pthread_create( &Threads[ 162 ], &attr, spawn_function, NULL); }
	if(PTH-164 >= 0){ pthread_create( &Threads[ 163 ], &attr, spawn_function, NULL); }
	if(PTH-165 >= 0){ pthread_create( &Threads[ 164 ], &attr, spawn_function, NULL); }
	if(PTH-166 >= 0){ pthread_create( &Threads[ 165 ], &attr, spawn_function, NULL); }
	if(PTH-167 >= 0){ pthread_create( &Threads[ 166 ], &attr, spawn_function, NULL); }
	if(PTH-168 >= 0){ pthread_create( &Threads[ 167 ], &attr, spawn_function, NULL); }
	if(PTH-169 >= 0){ pthread_create( &Threads[ 168 ], &attr, spawn_function, NULL); }
	if(PTH-170 >= 0){ pthread_create( &Threads[ 169 ], &attr, spawn_function, NULL); } // 170

	if(PTH-171 >= 0){ pthread_create( &Threads[ 170 ], &attr, spawn_function, NULL); }
	if(PTH-172 >= 0){ pthread_create( &Threads[ 171 ], &attr, spawn_function, NULL); }
	if(PTH-173 >= 0){ pthread_create( &Threads[ 172 ], &attr, spawn_function, NULL); }
	if(PTH-174 >= 0){ pthread_create( &Threads[ 173 ], &attr, spawn_function, NULL); }
	if(PTH-175 >= 0){ pthread_create( &Threads[ 174 ], &attr, spawn_function, NULL); }
	if(PTH-176 >= 0){ pthread_create( &Threads[ 175 ], &attr, spawn_function, NULL); }
	if(PTH-177 >= 0){ pthread_create( &Threads[ 176 ], &attr, spawn_function, NULL); }
	if(PTH-178 >= 0){ pthread_create( &Threads[ 177 ], &attr, spawn_function, NULL); }
	if(PTH-179 >= 0){ pthread_create( &Threads[ 178 ], &attr, spawn_function, NULL); }
	if(PTH-180 >= 0){ pthread_create( &Threads[ 179 ], &attr, spawn_function, NULL); } // 180

	if(PTH-181 >= 0){ pthread_create( &Threads[ 180 ], &attr, spawn_function, NULL); }
	if(PTH-182 >= 0){ pthread_create( &Threads[ 181 ], &attr, spawn_function, NULL); }
	if(PTH-183 >= 0){ pthread_create( &Threads[ 182 ], &attr, spawn_function, NULL); }
	if(PTH-184 >= 0){ pthread_create( &Threads[ 183 ], &attr, spawn_function, NULL); }
	if(PTH-185 >= 0){ pthread_create( &Threads[ 184 ], &attr, spawn_function, NULL); }
	if(PTH-186 >= 0){ pthread_create( &Threads[ 185 ], &attr, spawn_function, NULL); }
	if(PTH-187 >= 0){ pthread_create( &Threads[ 186 ], &attr, spawn_function, NULL); }
	if(PTH-188 >= 0){ pthread_create( &Threads[ 187 ], &attr, spawn_function, NULL); }
	if(PTH-189 >= 0){ pthread_create( &Threads[ 188 ], &attr, spawn_function, NULL); }
	if(PTH-190 >= 0){ pthread_create( &Threads[ 189 ], &attr, spawn_function, NULL); } // 190

	if(PTH-191 >= 0){ pthread_create( &Threads[ 190 ], &attr, spawn_function, NULL); }
	if(PTH-192 >= 0){ pthread_create( &Threads[ 191 ], &attr, spawn_function, NULL); }
	if(PTH-193 >= 0){ pthread_create( &Threads[ 192 ], &attr, spawn_function, NULL); }
	if(PTH-194 >= 0){ pthread_create( &Threads[ 193 ], &attr, spawn_function, NULL); }
	if(PTH-195 >= 0){ pthread_create( &Threads[ 194 ], &attr, spawn_function, NULL); }
	if(PTH-196 >= 0){ pthread_create( &Threads[ 195 ], &attr, spawn_function, NULL); }
	if(PTH-197 >= 0){ pthread_create( &Threads[ 196 ], &attr, spawn_function, NULL); }
	if(PTH-198 >= 0){ pthread_create( &Threads[ 197 ], &attr, spawn_function, NULL); }
	if(PTH-199 >= 0){ pthread_create( &Threads[ 198 ], &attr, spawn_function, NULL); }
	if(PTH-200 >= 0){ pthread_create( &Threads[ 199 ], &attr, spawn_function, NULL); } // 200

	if(PTH-201 >= 0){ pthread_create( &Threads[ 200 ], &attr, spawn_function, NULL); }
	if(PTH-202 >= 0){ pthread_create( &Threads[ 201 ], &attr, spawn_function, NULL); }
	if(PTH-203 >= 0){ pthread_create( &Threads[ 202 ], &attr, spawn_function, NULL); }
	if(PTH-204 >= 0){ pthread_create( &Threads[ 203 ], &attr, spawn_function, NULL); }
	if(PTH-205 >= 0){ pthread_create( &Threads[ 204 ], &attr, spawn_function, NULL); }
	if(PTH-206 >= 0){ pthread_create( &Threads[ 205 ], &attr, spawn_function, NULL); }
	if(PTH-207 >= 0){ pthread_create( &Threads[ 206 ], &attr, spawn_function, NULL); }
	if(PTH-208 >= 0){ pthread_create( &Threads[ 207 ], &attr, spawn_function, NULL); }
	if(PTH-209 >= 0){ pthread_create( &Threads[ 208 ], &attr, spawn_function, NULL); }
	if(PTH-210 >= 0){ pthread_create( &Threads[ 209 ], &attr, spawn_function, NULL); } // 210

	if(PTH-211 >= 0){ pthread_create( &Threads[ 210 ], &attr, spawn_function, NULL); }
	if(PTH-212 >= 0){ pthread_create( &Threads[ 211 ], &attr, spawn_function, NULL); }
	if(PTH-213 >= 0){ pthread_create( &Threads[ 212 ], &attr, spawn_function, NULL); }
	if(PTH-214 >= 0){ pthread_create( &Threads[ 213 ], &attr, spawn_function, NULL); }
	if(PTH-215 >= 0){ pthread_create( &Threads[ 214 ], &attr, spawn_function, NULL); }
	if(PTH-216 >= 0){ pthread_create( &Threads[ 215 ], &attr, spawn_function, NULL); }
	if(PTH-217 >= 0){ pthread_create( &Threads[ 216 ], &attr, spawn_function, NULL); }
	if(PTH-218 >= 0){ pthread_create( &Threads[ 217 ], &attr, spawn_function, NULL); }
	if(PTH-219 >= 0){ pthread_create( &Threads[ 218 ], &attr, spawn_function, NULL); }
	if(PTH-220 >= 0){ pthread_create( &Threads[ 219 ], &attr, spawn_function, NULL); } // 220

	if(PTH-221 >= 0){ pthread_create( &Threads[ 220 ], &attr, spawn_function, NULL); }
	if(PTH-222 >= 0){ pthread_create( &Threads[ 221 ], &attr, spawn_function, NULL); }
	if(PTH-223 >= 0){ pthread_create( &Threads[ 222 ], &attr, spawn_function, NULL); }
	if(PTH-224 >= 0){ pthread_create( &Threads[ 223 ], &attr, spawn_function, NULL); }
	if(PTH-225 >= 0){ pthread_create( &Threads[ 224 ], &attr, spawn_function, NULL); }
	if(PTH-226 >= 0){ pthread_create( &Threads[ 225 ], &attr, spawn_function, NULL); }
	if(PTH-227 >= 0){ pthread_create( &Threads[ 226 ], &attr, spawn_function, NULL); }
	if(PTH-228 >= 0){ pthread_create( &Threads[ 227 ], &attr, spawn_function, NULL); }
	if(PTH-229 >= 0){ pthread_create( &Threads[ 228 ], &attr, spawn_function, NULL); }
	if(PTH-230 >= 0){ pthread_create( &Threads[ 229 ], &attr, spawn_function, NULL); } // 230

	if(PTH-231 >= 0){ pthread_create( &Threads[ 230 ], &attr, spawn_function, NULL); }
	if(PTH-232 >= 0){ pthread_create( &Threads[ 231 ], &attr, spawn_function, NULL); }
	if(PTH-233 >= 0){ pthread_create( &Threads[ 232 ], &attr, spawn_function, NULL); }
	if(PTH-234 >= 0){ pthread_create( &Threads[ 233 ], &attr, spawn_function, NULL); }
	if(PTH-235 >= 0){ pthread_create( &Threads[ 234 ], &attr, spawn_function, NULL); }
	if(PTH-236 >= 0){ pthread_create( &Threads[ 235 ], &attr, spawn_function, NULL); }
	if(PTH-237 >= 0){ pthread_create( &Threads[ 236 ], &attr, spawn_function, NULL); }
	if(PTH-238 >= 0){ pthread_create( &Threads[ 237 ], &attr, spawn_function, NULL); }
	if(PTH-239 >= 0){ pthread_create( &Threads[ 238 ], &attr, spawn_function, NULL); }
	if(PTH-240 >= 0){ pthread_create( &Threads[ 239 ], &attr, spawn_function, NULL); } // 240

	if(PTH-241 >= 0){ pthread_create( &Threads[ 240 ], &attr, spawn_function, NULL); }
	if(PTH-242 >= 0){ pthread_create( &Threads[ 241 ], &attr, spawn_function, NULL); }
	if(PTH-243 >= 0){ pthread_create( &Threads[ 242 ], &attr, spawn_function, NULL); }
	if(PTH-244 >= 0){ pthread_create( &Threads[ 243 ], &attr, spawn_function, NULL); }
	if(PTH-245 >= 0){ pthread_create( &Threads[ 244 ], &attr, spawn_function, NULL); }
	if(PTH-246 >= 0){ pthread_create( &Threads[ 245 ], &attr, spawn_function, NULL); }
	if(PTH-247 >= 0){ pthread_create( &Threads[ 246 ], &attr, spawn_function, NULL); }
	if(PTH-248 >= 0){ pthread_create( &Threads[ 247 ], &attr, spawn_function, NULL); }
	if(PTH-249 >= 0){ pthread_create( &Threads[ 248 ], &attr, spawn_function, NULL); }
	if(PTH-250 >= 0){ pthread_create( &Threads[ 249 ], &attr, spawn_function, NULL); } // 250

	if(PTH-251 >= 0){ pthread_create( &Threads[ 250 ], &attr, spawn_function, NULL); }
	if(PTH-252 >= 0){ pthread_create( &Threads[ 251 ], &attr, spawn_function, NULL); }
	if(PTH-253 >= 0){ pthread_create( &Threads[ 252 ], &attr, spawn_function, NULL); }
	if(PTH-254 >= 0){ pthread_create( &Threads[ 253 ], &attr, spawn_function, NULL); }
	if(PTH-255 >= 0){ pthread_create( &Threads[ 254 ], &attr, spawn_function, NULL); }
	if(PTH-256 >= 0){ pthread_create( &Threads[ 255 ], &attr, spawn_function, NULL); }
	if(PTH-257 >= 0){ pthread_create( &Threads[ 256 ], &attr, spawn_function, NULL); }
	if(PTH-258 >= 0){ pthread_create( &Threads[ 257 ], &attr, spawn_function, NULL); }
	if(PTH-259 >= 0){ pthread_create( &Threads[ 258 ], &attr, spawn_function, NULL); }
	if(PTH-260 >= 0){ pthread_create( &Threads[ 259 ], &attr, spawn_function, NULL); } // 260

	if(PTH-261 >= 0){ pthread_create( &Threads[ 260 ], &attr, spawn_function, NULL); }
	if(PTH-262 >= 0){ pthread_create( &Threads[ 261 ], &attr, spawn_function, NULL); }
	if(PTH-263 >= 0){ pthread_create( &Threads[ 262 ], &attr, spawn_function, NULL); }
	if(PTH-264 >= 0){ pthread_create( &Threads[ 263 ], &attr, spawn_function, NULL); }
	if(PTH-265 >= 0){ pthread_create( &Threads[ 264 ], &attr, spawn_function, NULL); }
	if(PTH-266 >= 0){ pthread_create( &Threads[ 265 ], &attr, spawn_function, NULL); }
	if(PTH-267 >= 0){ pthread_create( &Threads[ 266 ], &attr, spawn_function, NULL); }
	if(PTH-268 >= 0){ pthread_create( &Threads[ 267 ], &attr, spawn_function, NULL); }
	if(PTH-269 >= 0){ pthread_create( &Threads[ 268 ], &attr, spawn_function, NULL); }
	if(PTH-270 >= 0){ pthread_create( &Threads[ 269 ], &attr, spawn_function, NULL); } // 270

	if(PTH-271 >= 0){ pthread_create( &Threads[ 270 ], &attr, spawn_function, NULL); }
	if(PTH-272 >= 0){ pthread_create( &Threads[ 271 ], &attr, spawn_function, NULL); }
	if(PTH-273 >= 0){ pthread_create( &Threads[ 272 ], &attr, spawn_function, NULL); }
	if(PTH-274 >= 0){ pthread_create( &Threads[ 273 ], &attr, spawn_function, NULL); }
	if(PTH-275 >= 0){ pthread_create( &Threads[ 274 ], &attr, spawn_function, NULL); }
	if(PTH-276 >= 0){ pthread_create( &Threads[ 275 ], &attr, spawn_function, NULL); }
	if(PTH-277 >= 0){ pthread_create( &Threads[ 276 ], &attr, spawn_function, NULL); }
	if(PTH-278 >= 0){ pthread_create( &Threads[ 277 ], &attr, spawn_function, NULL); }
	if(PTH-279 >= 0){ pthread_create( &Threads[ 278 ], &attr, spawn_function, NULL); }
	if(PTH-280 >= 0){ pthread_create( &Threads[ 279 ], &attr, spawn_function, NULL); } // 270

	if(PTH-281 >= 0){ pthread_create( &Threads[ 280 ], &attr, spawn_function, NULL); }
	if(PTH-282 >= 0){ pthread_create( &Threads[ 281 ], &attr, spawn_function, NULL); }
	if(PTH-283 >= 0){ pthread_create( &Threads[ 282 ], &attr, spawn_function, NULL); }
	if(PTH-284 >= 0){ pthread_create( &Threads[ 283 ], &attr, spawn_function, NULL); }
	if(PTH-285 >= 0){ pthread_create( &Threads[ 284 ], &attr, spawn_function, NULL); }
	if(PTH-286 >= 0){ pthread_create( &Threads[ 285 ], &attr, spawn_function, NULL); }
	if(PTH-287 >= 0){ pthread_create( &Threads[ 286 ], &attr, spawn_function, NULL); }
	if(PTH-288 >= 0){ pthread_create( &Threads[ 287 ], &attr, spawn_function, NULL); }
	if(PTH-289 >= 0){ pthread_create( &Threads[ 288 ], &attr, spawn_function, NULL); }
	if(PTH-290 >= 0){ pthread_create( &Threads[ 289 ], &attr, spawn_function, NULL); } // 280

	if(PTH-291 >= 0){ pthread_create( &Threads[ 290 ], &attr, spawn_function, NULL); }
	if(PTH-292 >= 0){ pthread_create( &Threads[ 291 ], &attr, spawn_function, NULL); }
	if(PTH-293 >= 0){ pthread_create( &Threads[ 292 ], &attr, spawn_function, NULL); }
	if(PTH-294 >= 0){ pthread_create( &Threads[ 293 ], &attr, spawn_function, NULL); }
	if(PTH-295 >= 0){ pthread_create( &Threads[ 294 ], &attr, spawn_function, NULL); }
	if(PTH-296 >= 0){ pthread_create( &Threads[ 295 ], &attr, spawn_function, NULL); }
	if(PTH-297 >= 0){ pthread_create( &Threads[ 296 ], &attr, spawn_function, NULL); }
	if(PTH-298 >= 0){ pthread_create( &Threads[ 297 ], &attr, spawn_function, NULL); }
	if(PTH-299 >= 0){ pthread_create( &Threads[ 298 ], &attr, spawn_function, NULL); }
	if(PTH-300 >= 0){ pthread_create( &Threads[ 299 ], &attr, spawn_function, NULL); } // 300

	if(PTH-301 >= 0){ pthread_create( &Threads[ 300 ], &attr, spawn_function, NULL); } // 301

// end:
*/
    clock_gettime(CLOCK_MONOTONIC, &t_end);
	
    // each thread waits until all threads have hit the barrier, then they all return
	//pthread_barrier_wait(&sync_barrier);

	// pthread_destroy_barrier
	//pthread_barrier_destroy(&sync_barrier);

	// destroy attr
	pthread_attr_destroy(&attr);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
		
	return 0;
}