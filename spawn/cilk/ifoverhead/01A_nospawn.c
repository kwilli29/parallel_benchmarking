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

/* Benchmark: 01A: Spawn time after ; Sequential Spawns (Cilk)
 * Launch a bunch and measure when all done 
 */

void spawn_function(){           // Simple Spawn Function -- can be changed
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

	printf("* # Spawns: %d\n", NCILK);

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

	// sequentially spawn functions
        if(NCILK-1 >= 0) {  } // 1
		if(NCILK-2 >= 0) {  } // 2
		if(NCILK-3 >= 0) {  } // 3
		if(NCILK-4 >= 0) {  } // 4

		if(NCILK-5 >= 0) {  } // 5
		if(NCILK-6 >= 0) {  } // 6
		if(NCILK-7 >= 0) {  } // 7
		if(NCILK-8 >= 0) {  } // 8
		if(NCILK-9 >= 0) {  } // 9
		if(NCILK-10 >= 0) {  } // 10

		if(NCILK-11 >= 0) {  } // 11
		if(NCILK-12 >= 0) {  } // 12
		if(NCILK-13 >= 0) {  } // 13
		if(NCILK-14 >= 0) {  } // 14

		if(NCILK-15 >= 0) {  } // 15
		if(NCILK-16 >= 0) {  } // 16
		if(NCILK-17 >= 0) {  } // 17
		if(NCILK-18 >= 0) {  } // 18

		if(NCILK-19 >= 0) {  } // 19
		if(NCILK-20 >= 0) {  } // 20

		if(NCILK-21 >= 0) {  } // 21
		if(NCILK-22 >= 0) {  } // 22
		if(NCILK-23 >= 0) {  } // 23
		if(NCILK-24 >= 0) {  } // 24

		if(NCILK-25 >= 0) {  } // 25
		if(NCILK-26 >= 0) {  } // 26
		if(NCILK-27 >= 0) {  } // 27
		if(NCILK-28 >= 0) {  } // 28

		if(NCILK-29 >= 0) {  } // 29
		if(NCILK-30 >= 0) {  } // 30

		if(NCILK-31 >= 0) {  } // 31
		if(NCILK-32 >= 0) {  } // 32
		if(NCILK-33 >= 0) {  } // 33
		if(NCILK-34 >= 0) {  } // 34

		if(NCILK-35 >= 0) {  } // 35
		if(NCILK-36 >= 0) {  } // 36
		if(NCILK-37 >= 0) {  } // 37
		if(NCILK-38 >= 0) {  } // 38

		if(NCILK-39 >= 0) {  } // 39
		if(NCILK-40 >= 0) {  } // 40

		if(NCILK-41 >= 0) {  } // 41
		if(NCILK-42 >= 0) {  } // 42
		if(NCILK-43 >= 0) {  } // 43
		if(NCILK-44 >= 0) {  } // 44

		if(NCILK-45 >= 0) {  } // 45
		if(NCILK-46 >= 0) {  } // 46
		if(NCILK-47 >= 0) {  } // 47
		if(NCILK-48 >= 0) {  } // 48

		if(NCILK-49 >= 0) {  } // 49
		if(NCILK-50 >= 0) {  } // 50

		if(NCILK-51 >= 0) {  } // 51
		if(NCILK-52 >= 0) {  } // 52
		if(NCILK-53 >= 0) {  } // 53
		if(NCILK-54 >= 0) {  } // 54

		if(NCILK-55 >= 0) {  } // 55
		if(NCILK-56 >= 0) {  } // 56
		if(NCILK-57 >= 0) {  } // 57
		if(NCILK-58 >= 0) {  } // 58

		if(NCILK-59 >= 0) {  } // 59
		if(NCILK-60 >= 0) {  } // 60

		if(NCILK-61 >= 0) {  } // 61
		if(NCILK-62 >= 0) {  } // 62
		if(NCILK-63 >= 0) {  } // 63
		if(NCILK-64 >= 0) {  } // 64

		if(NCILK-65 >= 0) {  } // 65
		if(NCILK-66 >= 0) {  } // 66
		if(NCILK-66 >= 0) {  } // 66
		if(NCILK-68 >= 0) {  } // 68

		if(NCILK-69 >= 0) {  } // 69
		if(NCILK-70 >= 0) {  } // 70

		if(NCILK-71 >= 0) {  } // 71
		if(NCILK-72 >= 0) {  } // 72
		if(NCILK-73 >= 0) {  } // 73
		if(NCILK-74 >= 0) {  } // 74

		if(NCILK-75 >= 0) {  } // 75
		if(NCILK-76 >= 0) {  } // 76
		if(NCILK-77 >= 0) {  } // 77
		if(NCILK-78 >= 0) {  } // 78

		if(NCILK-79 >= 0) {  } // 79
		if(NCILK-80 >= 0) {  } // 80

		if(NCILK-81 >= 0) {  } // 81
		if(NCILK-82 >= 0) {  } // 82
		if(NCILK-83 >= 0) {  } // 83
		if(NCILK-84 >= 0) {  } // 84

		if(NCILK-85 >= 0) {  } // 85
		if(NCILK-86 >= 0) {  } // 86
		if(NCILK-87 >= 0) {  } // 87
		if(NCILK-88 >= 0) {  } // 88

		if(NCILK-89 >= 0) {  } // 89
		if(NCILK-90 >= 0) {  } // 90

		if(NCILK-91 >= 0) {  } // 91
		if(NCILK-92 >= 0) {  } // 92
		if(NCILK-93 >= 0) {  } // 93
		if(NCILK-94 >= 0) {  } // 94

		if(NCILK-95 >= 0) {  } // 95
		if(NCILK-96 >= 0) {  } // 96
		if(NCILK-97 >= 0) {  } // 97
		if(NCILK-98 >= 0) {  } // 98

		if(NCILK-99 >= 0) {  } // 99
		if(NCILK-100 >= 0) {  } // 100

		if(NCILK-101 >= 0) {  } // 101
		if(NCILK-102 >= 0) {  } // 102
		if(NCILK-103 >= 0) {  } // 103
		if(NCILK-104 >= 0) {  } // 104

		if(NCILK-105 >= 0) {  } // 105
		if(NCILK-106 >= 0) {  } // 106
		if(NCILK-107 >= 0) {  } // 107
		if(NCILK-108 >= 0) {  } // 108

		if(NCILK-109 >= 0) {  } // 109
		if(NCILK-110 >= 0) {  } // 110

		if(NCILK-111 >= 0) {  } // 111
		if(NCILK-112 >= 0) {  } // 112
		if(NCILK-113 >= 0) {  } // 113
		if(NCILK-114 >= 0) {  } // 114

		if(NCILK-115 >= 0) {  } // 115
		if(NCILK-116 >= 0) {  } // 116
		if(NCILK-117 >= 0) {  } // 117
		if(NCILK-118 >= 0) {  } // 118

		if(NCILK-119 >= 0) {  } // 119
		if(NCILK-120 >= 0) {  } // 120

		if(NCILK-121 >= 0) {  } // 121
		if(NCILK-122 >= 0) {  } // 122
		if(NCILK-123 >= 0) {  } // 123
		if(NCILK-124 >= 0) {  } // 124

		if(NCILK-125 >= 0) {  } // 125
		if(NCILK-126 >= 0) {  } // 126
		if(NCILK-127 >= 0) {  } // 127
		if(NCILK-128 >= 0) {  } // 128

		if(NCILK-129 >= 0) {  } // 129
		if(NCILK-130 >= 0) {  } // 130

		if(NCILK-131 >= 0) {  } // 131
		if(NCILK-132 >= 0) {  } // 132
		if(NCILK-133 >= 0) {  } // 133
		if(NCILK-134 >= 0) {  } // 134

		if(NCILK-135 >= 0) {  } // 135
		if(NCILK-136 >= 0) {  } // 136
		if(NCILK-137 >= 0) {  } // 137
		if(NCILK-138 >= 0) {  } // 138

		if(NCILK-139 >= 0) {  } // 139
		if(NCILK-140 >= 0) {  } // 140

		if(NCILK-141 >= 0) {  } // 141
		if(NCILK-142 >= 0) {  } // 142
		if(NCILK-143 >= 0) {  } // 143
		if(NCILK-144 >= 0) {  } // 144

		if(NCILK-145 >= 0) {  } // 145
		if(NCILK-146 >= 0) {  } // 146
		if(NCILK-147 >= 0) {  } // 147
		if(NCILK-148 >= 0) {  } // 148

		if(NCILK-149 >= 0) {  } // 149
		if(NCILK-150 >= 0) {  } // 150

		if(NCILK-151 >= 0) {  } // 151
		if(NCILK-152 >= 0) {  } // 152
		if(NCILK-153 >= 0) {  } // 153
		if(NCILK-154 >= 0) {  } // 154

		if(NCILK-155 >= 0) {  } // 155
		if(NCILK-156 >= 0) {  } // 156
		if(NCILK-157 >= 0) {  } // 157
		if(NCILK-158 >= 0) {  } // 158

		if(NCILK-159 >= 0) {  } // 159
		if(NCILK-160 >= 0) {  } // 160

		if(NCILK-161 >= 0) {  } // 161
		if(NCILK-162 >= 0) {  } // 162
		if(NCILK-163 >= 0) {  } // 163
		if(NCILK-164 >= 0) {  } // 164

		if(NCILK-165 >= 0) {  } // 165
		if(NCILK-166 >= 0) {  } // 166
		if(NCILK-167 >= 0) {  } // 167
		if(NCILK-168 >= 0) {  } // 168

		if(NCILK-169 >= 0) {  } // 169
		if(NCILK-170 >= 0) {  } // 170

		if(NCILK-171 >= 0) {  } // 171
		if(NCILK-172 >= 0) {  } // 172
		if(NCILK-173 >= 0) {  } // 173
		if(NCILK-174 >= 0) {  } // 174

		if(NCILK-175 >= 0) {  } // 175
		if(NCILK-176 >= 0) {  } // 176
		if(NCILK-177 >= 0) {  } // 177
		if(NCILK-178 >= 0) {  } // 178

		if(NCILK-179 >= 0) {  } // 179
		if(NCILK-180 >= 0) {  } // 180

		if(NCILK-181 >= 0) {  } // 181
		if(NCILK-182 >= 0) {  } // 182
		if(NCILK-183 >= 0) {  } // 183
		if(NCILK-184 >= 0) {  } // 184

		if(NCILK-185 >= 0) {  } // 185
		if(NCILK-186 >= 0) {  } // 186
		if(NCILK-187 >= 0) {  } // 187
		if(NCILK-188 >= 0) {  } // 188

		if(NCILK-189 >= 0) {  } // 189
		if(NCILK-190 >= 0) {  } // 190

		if(NCILK-191 >= 0) {  } // 191
		if(NCILK-192 >= 0) {  } // 192
		if(NCILK-193 >= 0) {  } // 193
		if(NCILK-194 >= 0) {  } // 194

		if(NCILK-195 >= 0) {  } // 195
		if(NCILK-196 >= 0) {  } // 196
		if(NCILK-197 >= 0) {  } // 197
		if(NCILK-198 >= 0) {  } // 198

		if(NCILK-199 >= 0) {  } // 199
		if(NCILK-200 >= 0) {  } // 200

		if(NCILK-201 >= 0) {  } // 201
		if(NCILK-202 >= 0) {  } // 202
		if(NCILK-203 >= 0) {  } // 203
		if(NCILK-204 >= 0) {  } // 204

		if(NCILK-205 >= 0) {  } // 205
		if(NCILK-206 >= 0) {  } // 206
		if(NCILK-207 >= 0) {  } // 207
		if(NCILK-208 >= 0) {  } // 208

		if(NCILK-209 >= 0) {  } // 209
		if(NCILK-210 >= 0) {  } // 210

		if(NCILK-211 >= 0) {  } // 211
		if(NCILK-212 >= 0) {  } // 212
		if(NCILK-213 >= 0) {  } // 213
		if(NCILK-214 >= 0) {  } // 214

		if(NCILK-215 >= 0) {  } // 215
		if(NCILK-216 >= 0) {  } // 216
		if(NCILK-217 >= 0) {  } // 217
		if(NCILK-218 >= 0) {  } // 218

		if(NCILK-219 >= 0) {  } // 219
		if(NCILK-220 >= 0) {  } // 220

		if(NCILK-221 >= 0) {  } // 221
		if(NCILK-222 >= 0) {  } // 222
		if(NCILK-223 >= 0) {  } // 223
		if(NCILK-224 >= 0) {  } // 224

		if(NCILK-225 >= 0) {  } // 225
		if(NCILK-226 >= 0) {  } // 226
		if(NCILK-227 >= 0) {  } // 227
		if(NCILK-228 >= 0) {  } // 228

		if(NCILK-229 >= 0) {  } // 229
		if(NCILK-230 >= 0) {  } // 230

		if(NCILK-231 >= 0) {  } // 231
		if(NCILK-232 >= 0) {  } // 232
		if(NCILK-233 >= 0) {  } // 233
		if(NCILK-234 >= 0) {  } // 234

		if(NCILK-235 >= 0) {  } // 235
		if(NCILK-236 >= 0) {  } // 236
		if(NCILK-237 >= 0) {  } // 237
		if(NCILK-238 >= 0) {  } // 238

		if(NCILK-239 >= 0) {  } // 239
		if(NCILK-240 >= 0) {  } // 240

		if(NCILK-241 >= 0) {  } // 241
		if(NCILK-242 >= 0) {  } // 242
		if(NCILK-243 >= 0) {  } // 243
		if(NCILK-244 >= 0) {  } // 244

		if(NCILK-245 >= 0) {  } // 245
		if(NCILK-246 >= 0) {  } // 246
		if(NCILK-247 >= 0) {  } // 247
		if(NCILK-248 >= 0) {  } // 248

		if(NCILK-249 >= 0) {  } // 249
		if(NCILK-250 >= 0) {  } // 250

		if(NCILK-251 >= 0) {  } // 251
		if(NCILK-252 >= 0) {  } // 252
		if(NCILK-253 >= 0) {  } // 253
		if(NCILK-254 >= 0) {  } // 254

		if(NCILK-255 >= 0) {  } // 255
		if(NCILK-256 >= 0) {  } // 256
		if(NCILK-257 >= 0) {  } // 257
		if(NCILK-258 >= 0) {  } // 258

		if(NCILK-259 >= 0) {  } // 259
		if(NCILK-260 >= 0) {  } // 260

		if(NCILK-261 >= 0) {  } // 261
		if(NCILK-262 >= 0) {  } // 262
		if(NCILK-263 >= 0) {  } // 263
		if(NCILK-264 >= 0) {  } // 264

		if(NCILK-265 >= 0) {  } // 265
		if(NCILK-266 >= 0) {  } // 266
		if(NCILK-267 >= 0) {  } // 267
		if(NCILK-268 >= 0) {  } // 268

		if(NCILK-269 >= 0) {  } // 269
		if(NCILK-270 >= 0) {  } // 270

		if(NCILK-271 >= 0) {  } // 271
		if(NCILK-272 >= 0) {  } // 272
		if(NCILK-273 >= 0) {  } // 273
		if(NCILK-274 >= 0) {  } // 274

		if(NCILK-275 >= 0) {  } // 275
		if(NCILK-276 >= 0) {  } // 276
		if(NCILK-277 >= 0) {  } // 277
		if(NCILK-278 >= 0) {  } // 278

		if(NCILK-279 >= 0) {  } // 279
		if(NCILK-280 >= 0) {  } // 280

		if(NCILK-281 >= 0) {  } // 281
		if(NCILK-282 >= 0) {  } // 282
		if(NCILK-283 >= 0) {  } // 283
		if(NCILK-284 >= 0) {  } // 284

		if(NCILK-285 >= 0) {  } // 285
		if(NCILK-286 >= 0) {  } // 286
		if(NCILK-287 >= 0) {  } // 287
		if(NCILK-288 >= 0) {  } // 288

		if(NCILK-289 >= 0) {  } // 289
		if(NCILK-290 >= 0) {  } // 290

		if(NCILK-291 >= 0) {  } // 291
		if(NCILK-292 >= 0) {  } // 292
		if(NCILK-293 >= 0) {  } // 293
		if(NCILK-294 >= 0) {  } // 294

		if(NCILK-295 >= 0) {  } // 295
		if(NCILK-296 >= 0) {  } // 296
		if(NCILK-297 >= 0) {  } // 297
		if(NCILK-298 >= 0) {  } // 298

		if(NCILK-299 >= 0) {  } // 299
		if(NCILK-300 >= 0) {  } // 300

		if(NCILK-301 >= 0) {  } // 301

// end: // unused label 

    clock_gettime(CLOCK_MONOTONIC, &t_end);

	cilk_sync; 

	timespec_sub(&t_res, t_end, t_start);
    printf("ns: %.12ld\n", t_res.tv_nsec);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	//printf("01A\n");

	return 0;
}