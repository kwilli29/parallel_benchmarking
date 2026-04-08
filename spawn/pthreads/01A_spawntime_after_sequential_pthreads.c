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

	int DEPTH = 271;

	int            ds, rc;
	pthread_attr_t attr;

	rc = pthread_attr_init(&attr);
	if (rc == -1) { perror("error in pthread_attr_init"); exit(1); }

	ds = 1;
	rc = pthread_attr_setdetachstate(&attr, ds);
	if (rc == -1) { perror("error in pthread_attr_setdetachstate"); exit(2); }

	pthread_t Threads[ DEPTH ];

	// pthread_barrier_init
	pthread_barrier_init(&sync_barrier, NULL, DEPTH+1);

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	pthread_create( &Threads[ 0 ], &attr, spawn_function, NULL); // all threads spawn detached,
	pthread_create( &Threads[ 1 ], &attr, spawn_function, NULL); // hit the barrier,
	pthread_create( &Threads[ 2 ], &attr, spawn_function, NULL); // and are immmediately freed w/o joining
	pthread_create( &Threads[ 3 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 4 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 5 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 6 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 7 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 8 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 9 ], &attr, spawn_function, NULL); // 10

	pthread_create( &Threads[ 10 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 11 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 12 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 13 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 14 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 15 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 16 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 17 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 18 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 19 ], &attr, spawn_function, NULL); // 20

	pthread_create( &Threads[ 20 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 21 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 22 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 23 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 24 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 25 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 26 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 27 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 28 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 29 ], &attr, spawn_function, NULL); // 30

	pthread_create( &Threads[ 30 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 31 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 32 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 33 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 34 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 35 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 36 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 37 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 38 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 39 ], &attr, spawn_function, NULL); // 40

	pthread_create( &Threads[ 40 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 41 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 42 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 43 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 44 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 45 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 46 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 47 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 48 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 49 ], &attr, spawn_function, NULL); // 50

	pthread_create( &Threads[ 50 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 51 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 52 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 53 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 54 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 55 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 56 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 57 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 58 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 59 ], &attr, spawn_function, NULL); // 60

	pthread_create( &Threads[ 60 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 61 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 62 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 63 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 64 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 65 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 66 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 67 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 68 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 69 ], &attr, spawn_function, NULL); // 70

	pthread_create( &Threads[ 70 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 71 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 72 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 73 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 74 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 75 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 76 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 77 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 78 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 79 ], &attr, spawn_function, NULL); // 80

	pthread_create( &Threads[ 80 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 81 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 82 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 83 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 84 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 85 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 86 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 87 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 88 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 89 ], &attr, spawn_function, NULL); // 90

	pthread_create( &Threads[ 90 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 91 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 92 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 93 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 94 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 95 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 96 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 97 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 98 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 99 ], &attr, spawn_function, NULL); // 100

	pthread_create( &Threads[ 100 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 101 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 102 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 103 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 104 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 105 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 106 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 107 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 108 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 109 ], &attr, spawn_function, NULL); // 110

	pthread_create( &Threads[ 110 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 111 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 112 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 113 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 114 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 115 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 116 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 117 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 118 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 119 ], &attr, spawn_function, NULL); // 120

	pthread_create( &Threads[ 120 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 121 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 122 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 123 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 124 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 125 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 126 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 127 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 128 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 129 ], &attr, spawn_function, NULL); // 130

	pthread_create( &Threads[ 130 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 131 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 132 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 133 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 134 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 135 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 136 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 137 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 138 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 139 ], &attr, spawn_function, NULL); // 140

	pthread_create( &Threads[ 140 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 141 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 142 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 143 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 144 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 145 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 146 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 147 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 148 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 149 ], &attr, spawn_function, NULL); // 150

	pthread_create( &Threads[ 150 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 151 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 152 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 153 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 154 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 155 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 156 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 157 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 158 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 159 ], &attr, spawn_function, NULL); // 160

	pthread_create( &Threads[ 160 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 161 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 162 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 163 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 164 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 165 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 166 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 167 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 168 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 169 ], &attr, spawn_function, NULL); // 170

	pthread_create( &Threads[ 170 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 171 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 172 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 173 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 174 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 175 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 176 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 177 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 178 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 179 ], &attr, spawn_function, NULL); // 180

	pthread_create( &Threads[ 180 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 181 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 182 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 183 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 184 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 185 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 186 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 187 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 188 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 189 ], &attr, spawn_function, NULL); // 190

	pthread_create( &Threads[ 190 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 191 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 192 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 193 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 194 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 195 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 196 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 197 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 198 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 199 ], &attr, spawn_function, NULL); // 200

	pthread_create( &Threads[ 200 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 201 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 202 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 203 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 204 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 205 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 206 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 207 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 208 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 209 ], &attr, spawn_function, NULL); // 210

	pthread_create( &Threads[ 210 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 211 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 212 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 213 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 214 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 215 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 216 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 217 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 218 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 219 ], &attr, spawn_function, NULL); // 220

	pthread_create( &Threads[ 220 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 221 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 222 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 223 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 224 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 225 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 226 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 227 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 228 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 229 ], &attr, spawn_function, NULL); // 230

	pthread_create( &Threads[ 230 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 231 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 232 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 233 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 234 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 235 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 236 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 237 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 238 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 239 ], &attr, spawn_function, NULL); // 240

	pthread_create( &Threads[ 240 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 241 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 242 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 243 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 244 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 245 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 246 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 247 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 248 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 249 ], &attr, spawn_function, NULL); // 250

	pthread_create( &Threads[ 250 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 251 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 252 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 253 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 254 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 255 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 256 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 257 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 258 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 259 ], &attr, spawn_function, NULL); // 260

	pthread_create( &Threads[ 260 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 261 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 262 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 263 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 264 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 265 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 266 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 267 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 268 ], &attr, spawn_function, NULL);
	pthread_create( &Threads[ 269 ], &attr, spawn_function, NULL); // 270

	pthread_create( &Threads[ 270 ], &attr, spawn_function, NULL);
	// pthread_create( &Threads[ 271 ], &attr, spawn_function, NULL); // 272
	// pthread_create( &Threads[ 272 ], &attr, spawn_function, NULL);

	// each thread waits until all threads have hit the barrier, then they all return
	pthread_barrier_wait(&sync_barrier);

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	// pthread_destroy_barrier
	pthread_barrier_destroy(&sync_barrier);

	// destroy attr
	pthread_attr_destroy(&attr);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
		
	return 0;
}
