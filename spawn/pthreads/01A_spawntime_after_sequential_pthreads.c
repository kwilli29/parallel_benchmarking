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
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

// printf(“# of Cores: %ld\n”, sysconf(_SC_NPROCESSORS_ONLN));

pthread_barrier_t sync_barrier; /* to sync */

void* spawn_function(){           // Simple Math for Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	// pthread_barrier_wait ?
	pthread_barrier_wait(&sync_barrier);

	return (void*) NULL; 
}

int main(int argc, char *argv[]){

	int DEPTH = 271;

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start);	

	/****/ 

	pthread_t Threads[ DEPTH ];

	// pthread_barrier_init ?
	pthread_barrier_init(&sync_barrier, NULL, DEPTH);

	pthread_create( &Threads[ 0 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 1 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 2 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 3 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 4 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 5 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 6 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 7 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 8 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 9 ], NULL, spawn_function, NULL); // 10

	pthread_create( &Threads[ 10 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 11 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 12 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 13 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 14 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 15 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 16 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 17 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 18 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 19 ], NULL, spawn_function, NULL); // 20

	pthread_create( &Threads[ 20 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 21 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 22 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 23 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 24 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 25 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 26 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 27 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 28 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 29 ], NULL, spawn_function, NULL); // 30

	pthread_create( &Threads[ 30 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 31 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 32 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 33 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 34 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 35 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 36 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 37 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 38 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 39 ], NULL, spawn_function, NULL); // 40

	pthread_create( &Threads[ 40 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 41 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 42 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 43 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 44 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 45 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 46 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 47 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 48 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 49 ], NULL, spawn_function, NULL); // 50

	pthread_create( &Threads[ 50 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 51 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 52 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 53 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 54 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 55 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 56 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 57 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 58 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 59 ], NULL, spawn_function, NULL); // 60

	pthread_create( &Threads[ 60 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 61 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 62 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 63 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 64 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 65 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 66 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 67 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 68 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 69 ], NULL, spawn_function, NULL); // 70

	pthread_create( &Threads[ 70 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 71 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 72 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 73 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 74 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 75 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 76 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 77 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 78 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 79 ], NULL, spawn_function, NULL); // 80

	pthread_create( &Threads[ 80 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 81 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 82 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 83 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 84 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 85 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 86 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 87 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 88 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 89 ], NULL, spawn_function, NULL); // 90

	pthread_create( &Threads[ 90 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 91 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 92 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 93 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 94 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 95 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 96 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 97 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 98 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 99 ], NULL, spawn_function, NULL); // 100

	pthread_create( &Threads[ 100 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 101 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 102 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 103 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 104 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 105 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 106 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 107 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 108 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 109 ], NULL, spawn_function, NULL); // 110

	pthread_create( &Threads[ 110 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 111 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 112 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 113 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 114 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 115 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 116 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 117 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 118 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 119 ], NULL, spawn_function, NULL); // 120

	pthread_create( &Threads[ 120 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 121 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 122 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 123 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 124 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 125 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 126 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 127 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 128 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 129 ], NULL, spawn_function, NULL); // 130

	pthread_create( &Threads[ 130 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 131 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 132 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 133 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 134 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 135 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 136 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 137 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 138 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 139 ], NULL, spawn_function, NULL); // 140

	pthread_create( &Threads[ 140 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 141 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 142 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 143 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 144 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 145 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 146 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 147 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 148 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 149 ], NULL, spawn_function, NULL); // 150

	pthread_create( &Threads[ 150 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 151 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 152 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 153 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 154 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 155 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 156 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 157 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 158 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 159 ], NULL, spawn_function, NULL); // 160

	pthread_create( &Threads[ 160 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 161 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 162 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 163 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 164 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 165 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 166 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 167 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 168 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 169 ], NULL, spawn_function, NULL); // 170

	pthread_create( &Threads[ 170 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 171 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 172 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 173 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 174 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 175 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 176 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 177 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 178 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 179 ], NULL, spawn_function, NULL); // 180

	pthread_create( &Threads[ 180 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 181 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 182 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 183 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 184 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 185 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 186 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 187 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 188 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 189 ], NULL, spawn_function, NULL); // 190

	pthread_create( &Threads[ 190 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 191 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 192 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 193 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 194 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 195 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 196 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 197 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 198 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 199 ], NULL, spawn_function, NULL); // 200

	pthread_create( &Threads[ 200 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 201 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 202 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 203 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 204 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 205 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 206 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 207 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 208 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 209 ], NULL, spawn_function, NULL); // 210

	pthread_create( &Threads[ 210 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 211 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 212 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 213 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 214 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 215 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 216 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 217 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 218 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 219 ], NULL, spawn_function, NULL); // 220

	pthread_create( &Threads[ 220 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 221 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 222 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 223 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 224 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 225 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 226 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 227 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 228 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 229 ], NULL, spawn_function, NULL); // 230

	pthread_create( &Threads[ 230 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 231 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 232 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 233 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 234 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 235 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 236 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 237 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 238 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 239 ], NULL, spawn_function, NULL); // 240

	pthread_create( &Threads[ 240 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 241 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 242 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 243 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 244 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 245 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 246 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 247 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 248 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 249 ], NULL, spawn_function, NULL); // 250

	pthread_create( &Threads[ 250 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 251 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 252 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 253 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 254 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 255 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 256 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 257 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 258 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 259 ], NULL, spawn_function, NULL); // 260

	pthread_create( &Threads[ 260 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 261 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 262 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 263 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 264 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 265 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 266 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 267 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 268 ], NULL, spawn_function, NULL);
	pthread_create( &Threads[ 269 ], NULL, spawn_function, NULL); // 270

	pthread_create( &Threads[ 270 ], NULL, spawn_function, NULL);
	// pthread_create( &Threads[ 271 ], NULL, spawn_function, NULL); // 272
	// pthread_create( &Threads[ 272 ], NULL, spawn_function, NULL);


	pthread_join(Threads[ 0 ], NULL);
	pthread_join(Threads[ 1 ], NULL);
	pthread_join(Threads[ 2 ], NULL);
	pthread_join(Threads[ 3 ], NULL);
	pthread_join(Threads[ 4 ], NULL);
	pthread_join(Threads[ 5 ], NULL);
	pthread_join(Threads[ 6 ], NULL);
	pthread_join(Threads[ 7 ], NULL);
	pthread_join(Threads[ 8 ], NULL);
	pthread_join(Threads[ 9 ], NULL); // 10

	pthread_join(Threads[ 10 ], NULL);
	pthread_join(Threads[ 11 ], NULL);
	pthread_join(Threads[ 12 ], NULL);
	pthread_join(Threads[ 13 ], NULL);
	pthread_join(Threads[ 14 ], NULL);
	pthread_join(Threads[ 15 ], NULL);
	pthread_join(Threads[ 16 ], NULL);
	pthread_join(Threads[ 17 ], NULL);
	pthread_join(Threads[ 18 ], NULL);
	pthread_join(Threads[ 19 ], NULL); // 20

	pthread_join(Threads[ 20 ], NULL);
	pthread_join(Threads[ 21 ], NULL);
	pthread_join(Threads[ 22 ], NULL);
	pthread_join(Threads[ 23 ], NULL);
	pthread_join(Threads[ 24 ], NULL);
	pthread_join(Threads[ 25 ], NULL);
	pthread_join(Threads[ 26 ], NULL);
	pthread_join(Threads[ 27 ], NULL);
	pthread_join(Threads[ 28 ], NULL);
	pthread_join(Threads[ 29 ], NULL); // 30

	pthread_join(Threads[ 30 ], NULL);
	pthread_join(Threads[ 31 ], NULL);
	pthread_join(Threads[ 32 ], NULL);
	pthread_join(Threads[ 33 ], NULL);
	pthread_join(Threads[ 34 ], NULL);
	pthread_join(Threads[ 35 ], NULL);
	pthread_join(Threads[ 36 ], NULL);
	pthread_join(Threads[ 37 ], NULL);
	pthread_join(Threads[ 38 ], NULL);
	pthread_join(Threads[ 39 ], NULL); // 40

	pthread_join(Threads[ 40 ], NULL);
	pthread_join(Threads[ 41 ], NULL);
	pthread_join(Threads[ 42 ], NULL);
	pthread_join(Threads[ 43 ], NULL);
	pthread_join(Threads[ 44 ], NULL);
	pthread_join(Threads[ 45 ], NULL);
	pthread_join(Threads[ 46 ], NULL);
	pthread_join(Threads[ 47 ], NULL);
	pthread_join(Threads[ 48 ], NULL);
	pthread_join(Threads[ 49 ], NULL); // 50

	pthread_join(Threads[ 50 ], NULL);
	pthread_join(Threads[ 51 ], NULL);
	pthread_join(Threads[ 52 ], NULL);
	pthread_join(Threads[ 53 ], NULL);
	pthread_join(Threads[ 54 ], NULL);
	pthread_join(Threads[ 55 ], NULL);
	pthread_join(Threads[ 56 ], NULL);
	pthread_join(Threads[ 57 ], NULL);
	pthread_join(Threads[ 58 ], NULL);
	pthread_join(Threads[ 59 ], NULL); // 60

	pthread_join(Threads[ 60 ], NULL);
	pthread_join(Threads[ 61 ], NULL);
	pthread_join(Threads[ 62 ], NULL);
	pthread_join(Threads[ 63 ], NULL);
	pthread_join(Threads[ 64 ], NULL);
	pthread_join(Threads[ 65 ], NULL);
	pthread_join(Threads[ 66 ], NULL);
	pthread_join(Threads[ 67 ], NULL);
	pthread_join(Threads[ 68 ], NULL);
	pthread_join(Threads[ 69 ], NULL); // 70

	pthread_join(Threads[ 70 ], NULL);
	pthread_join(Threads[ 71 ], NULL);
	pthread_join(Threads[ 72 ], NULL);
	pthread_join(Threads[ 73 ], NULL);
	pthread_join(Threads[ 74 ], NULL);
	pthread_join(Threads[ 75 ], NULL);
	pthread_join(Threads[ 76 ], NULL);
	pthread_join(Threads[ 77 ], NULL);
	pthread_join(Threads[ 78 ], NULL);
	pthread_join(Threads[ 79 ], NULL); // 80

	pthread_join(Threads[ 80 ], NULL);
	pthread_join(Threads[ 81 ], NULL);
	pthread_join(Threads[ 82 ], NULL);
	pthread_join(Threads[ 83 ], NULL);
	pthread_join(Threads[ 84 ], NULL);
	pthread_join(Threads[ 85 ], NULL);
	pthread_join(Threads[ 86 ], NULL);
	pthread_join(Threads[ 87 ], NULL);
	pthread_join(Threads[ 88 ], NULL);
	pthread_join(Threads[ 89 ], NULL); // 90

	pthread_join(Threads[ 90 ], NULL);
	pthread_join(Threads[ 91 ], NULL);
	pthread_join(Threads[ 92 ], NULL);
	pthread_join(Threads[ 93 ], NULL);
	pthread_join(Threads[ 94 ], NULL);
	pthread_join(Threads[ 95 ], NULL);
	pthread_join(Threads[ 96 ], NULL);
	pthread_join(Threads[ 97 ], NULL);
	pthread_join(Threads[ 98 ], NULL);
	pthread_join(Threads[ 99 ], NULL); // 100

	pthread_join(Threads[ 100 ], NULL);
	pthread_join(Threads[ 101 ], NULL);
	pthread_join(Threads[ 102 ], NULL);
	pthread_join(Threads[ 103 ], NULL);
	pthread_join(Threads[ 104 ], NULL);
	pthread_join(Threads[ 105 ], NULL);
	pthread_join(Threads[ 106 ], NULL);
	pthread_join(Threads[ 107 ], NULL);
	pthread_join(Threads[ 108 ], NULL);
	pthread_join(Threads[ 109 ], NULL); // 110

	pthread_join(Threads[ 110 ], NULL);
	pthread_join(Threads[ 111 ], NULL);
	pthread_join(Threads[ 112 ], NULL);
	pthread_join(Threads[ 113 ], NULL);
	pthread_join(Threads[ 114 ], NULL);
	pthread_join(Threads[ 115 ], NULL);
	pthread_join(Threads[ 116 ], NULL);
	pthread_join(Threads[ 117 ], NULL);
	pthread_join(Threads[ 118 ], NULL);
	pthread_join(Threads[ 119 ], NULL); // 120

	pthread_join(Threads[ 120 ], NULL);
	pthread_join(Threads[ 121 ], NULL);
	pthread_join(Threads[ 122 ], NULL);
	pthread_join(Threads[ 123 ], NULL);
	pthread_join(Threads[ 124 ], NULL);
	pthread_join(Threads[ 125 ], NULL);
	pthread_join(Threads[ 126 ], NULL);
	pthread_join(Threads[ 127 ], NULL);
	pthread_join(Threads[ 128 ], NULL);
	pthread_join(Threads[ 129 ], NULL); // 130

	pthread_join(Threads[ 130 ], NULL);
	pthread_join(Threads[ 131 ], NULL);
	pthread_join(Threads[ 132 ], NULL);
	pthread_join(Threads[ 133 ], NULL);
	pthread_join(Threads[ 134 ], NULL);
	pthread_join(Threads[ 135 ], NULL);
	pthread_join(Threads[ 136 ], NULL);
	pthread_join(Threads[ 137 ], NULL);
	pthread_join(Threads[ 138 ], NULL);
	pthread_join(Threads[ 139 ], NULL); // 140

	pthread_join(Threads[ 140 ], NULL);
	pthread_join(Threads[ 141 ], NULL);
	pthread_join(Threads[ 142 ], NULL);
	pthread_join(Threads[ 143 ], NULL);
	pthread_join(Threads[ 144 ], NULL);
	pthread_join(Threads[ 145 ], NULL);
	pthread_join(Threads[ 146 ], NULL);
	pthread_join(Threads[ 147 ], NULL);
	pthread_join(Threads[ 148 ], NULL);
	pthread_join(Threads[ 149 ], NULL); // 150

	pthread_join(Threads[ 150 ], NULL);
	pthread_join(Threads[ 151 ], NULL);
	pthread_join(Threads[ 152 ], NULL);
	pthread_join(Threads[ 153 ], NULL);
	pthread_join(Threads[ 154 ], NULL);
	pthread_join(Threads[ 155 ], NULL);
	pthread_join(Threads[ 156 ], NULL);
	pthread_join(Threads[ 157 ], NULL);
	pthread_join(Threads[ 158 ], NULL);
	pthread_join(Threads[ 159 ], NULL); // 160

	pthread_join(Threads[ 160 ], NULL);
	pthread_join(Threads[ 161 ], NULL);
	pthread_join(Threads[ 162 ], NULL);
	pthread_join(Threads[ 163 ], NULL);
	pthread_join(Threads[ 164 ], NULL);
	pthread_join(Threads[ 165 ], NULL);
	pthread_join(Threads[ 166 ], NULL);
	pthread_join(Threads[ 167 ], NULL);
	pthread_join(Threads[ 168 ], NULL);
	pthread_join(Threads[ 169 ], NULL); // 170

	pthread_join(Threads[ 170 ], NULL);
	pthread_join(Threads[ 171 ], NULL);
	pthread_join(Threads[ 172 ], NULL);
	pthread_join(Threads[ 173 ], NULL);
	pthread_join(Threads[ 174 ], NULL);
	pthread_join(Threads[ 175 ], NULL);
	pthread_join(Threads[ 176 ], NULL);
	pthread_join(Threads[ 177 ], NULL);
	pthread_join(Threads[ 178 ], NULL);
	pthread_join(Threads[ 179 ], NULL); // 180

	pthread_join(Threads[ 180 ], NULL);
	pthread_join(Threads[ 181 ], NULL);
	pthread_join(Threads[ 182 ], NULL);
	pthread_join(Threads[ 183 ], NULL);
	pthread_join(Threads[ 184 ], NULL);
	pthread_join(Threads[ 185 ], NULL);
	pthread_join(Threads[ 186 ], NULL);
	pthread_join(Threads[ 187 ], NULL);
	pthread_join(Threads[ 188 ], NULL);
	pthread_join(Threads[ 189 ], NULL); // 190

	pthread_join(Threads[ 190 ], NULL);
	pthread_join(Threads[ 191 ], NULL);
	pthread_join(Threads[ 192 ], NULL);
	pthread_join(Threads[ 193 ], NULL);
	pthread_join(Threads[ 194 ], NULL);
	pthread_join(Threads[ 195 ], NULL);
	pthread_join(Threads[ 196 ], NULL);
	pthread_join(Threads[ 197 ], NULL);
	pthread_join(Threads[ 198 ], NULL);
	pthread_join(Threads[ 199 ], NULL); // 200

	pthread_join(Threads[ 200 ], NULL);
	pthread_join(Threads[ 201 ], NULL);
	pthread_join(Threads[ 202 ], NULL);
	pthread_join(Threads[ 203 ], NULL);
	pthread_join(Threads[ 204 ], NULL);
	pthread_join(Threads[ 205 ], NULL);
	pthread_join(Threads[ 206 ], NULL);
	pthread_join(Threads[ 207 ], NULL);
	pthread_join(Threads[ 208 ], NULL);
	pthread_join(Threads[ 209 ], NULL); // 210

	pthread_join(Threads[ 210 ], NULL);
	pthread_join(Threads[ 211 ], NULL);
	pthread_join(Threads[ 212 ], NULL);
	pthread_join(Threads[ 213 ], NULL);
	pthread_join(Threads[ 214 ], NULL);
	pthread_join(Threads[ 215 ], NULL);
	pthread_join(Threads[ 216 ], NULL);
	pthread_join(Threads[ 217 ], NULL);
	pthread_join(Threads[ 218 ], NULL);
	pthread_join(Threads[ 219 ], NULL); // 220

	pthread_join(Threads[ 220 ], NULL);
	pthread_join(Threads[ 221 ], NULL);
	pthread_join(Threads[ 222 ], NULL);
	pthread_join(Threads[ 223 ], NULL);
	pthread_join(Threads[ 224 ], NULL);
	pthread_join(Threads[ 225 ], NULL);
	pthread_join(Threads[ 226 ], NULL);
	pthread_join(Threads[ 227 ], NULL);
	pthread_join(Threads[ 228 ], NULL);
	pthread_join(Threads[ 229 ], NULL); // 230

	pthread_join(Threads[ 230 ], NULL);
	pthread_join(Threads[ 231 ], NULL);
	pthread_join(Threads[ 232 ], NULL);
	pthread_join(Threads[ 233 ], NULL);
	pthread_join(Threads[ 234 ], NULL);
	pthread_join(Threads[ 235 ], NULL);
	pthread_join(Threads[ 236 ], NULL);
	pthread_join(Threads[ 237 ], NULL);
	pthread_join(Threads[ 238 ], NULL);
	pthread_join(Threads[ 239 ], NULL); // 240

	pthread_join(Threads[ 240 ], NULL);
	pthread_join(Threads[ 241 ], NULL);
	pthread_join(Threads[ 242 ], NULL);
	pthread_join(Threads[ 243 ], NULL);
	pthread_join(Threads[ 244 ], NULL);
	pthread_join(Threads[ 245 ], NULL);
	pthread_join(Threads[ 246 ], NULL);
	pthread_join(Threads[ 247 ], NULL);
	pthread_join(Threads[ 248 ], NULL);
	pthread_join(Threads[ 249 ], NULL); // 250

	pthread_join(Threads[ 250 ], NULL);
	pthread_join(Threads[ 251 ], NULL);
	pthread_join(Threads[ 252 ], NULL);
	pthread_join(Threads[ 253 ], NULL);
	pthread_join(Threads[ 254 ], NULL);
	pthread_join(Threads[ 255 ], NULL);
	pthread_join(Threads[ 256 ], NULL);
	pthread_join(Threads[ 257 ], NULL);
	pthread_join(Threads[ 258 ], NULL);
	pthread_join(Threads[ 259 ], NULL); // 260

	pthread_join(Threads[ 260 ], NULL);
	pthread_join(Threads[ 261 ], NULL);
	pthread_join(Threads[ 262 ], NULL);
	pthread_join(Threads[ 263 ], NULL);
	pthread_join(Threads[ 264 ], NULL);
	pthread_join(Threads[ 265 ], NULL);
	pthread_join(Threads[ 266 ], NULL);
	pthread_join(Threads[ 267 ], NULL);
	pthread_join(Threads[ 268 ], NULL);
	pthread_join(Threads[ 269 ], NULL); // 270

	pthread_join(Threads[ 270 ], NULL);
	// pthread_join(Threads[ 271 ], NULL); // 272
	// pthread_join(Threads[ 272 ], NULL);	

	// pthread_destroy_barrier ?
	pthread_barrier_destroy(&sync_barrier); // sync all threads before getting endtime
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);

	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
		
	return 0;
}

