#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"
#include "../../include/numthreads.h"

/* Benchmark: 01A: Spawn time after ; Sequential Spawns (Serial)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

void spawn_function(){           // Simple Spawn Function
	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return; 
}

int main(int argc, char *argv[]){

    int NSERIAL = number_threads();

    // Process Command-Line Arguments
    if(argc >= 2){
        if(atoi(argv[1]) == 0){
            NSERIAL = number_threads();
        } else {
            NSERIAL = atoi(argv[1]);
            if (NSERIAL > 301){
                NSERIAL = number_threads();
            }
        }
    }

	struct timespec t_start, t_res, t_end;
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

		// sequentially spawn functions
        if(NSERIAL-1 >= 0) { spawn_function(); } // 1 // Take time stamp before each spawn
		if(NSERIAL-2 >= 0) { spawn_function(); } // 2
		if(NSERIAL-3 >= 0) { spawn_function(); } // 3
		if(NSERIAL-4 >= 0) { spawn_function(); } // 4

		if(NSERIAL-5 >= 0) { spawn_function(); } // 5
		if(NSERIAL-6 >= 0) { spawn_function(); } // 6
		if(NSERIAL-7 >= 0) { spawn_function(); } // 7
		if(NSERIAL-8 >= 0) { spawn_function(); } // 8
		if(NSERIAL-9 >= 0) { spawn_function(); } // 9
		if(NSERIAL-10 >= 0) { spawn_function(); } // 10

		if(NSERIAL-11 >= 0) { spawn_function(); } // 11
		if(NSERIAL-12 >= 0) { spawn_function(); } // 12
		if(NSERIAL-13 >= 0) { spawn_function(); } // 13
		if(NSERIAL-14 >= 0) { spawn_function(); } // 14

		if(NSERIAL-15 >= 0) { spawn_function(); } // 15
		if(NSERIAL-16 >= 0) { spawn_function(); } // 16
		if(NSERIAL-17 >= 0) { spawn_function(); } // 17
		if(NSERIAL-18 >= 0) { spawn_function(); } // 18

		if(NSERIAL-19 >= 0) { spawn_function(); } // 19
		if(NSERIAL-20 >= 0) { spawn_function(); } // 20

		if(NSERIAL-21 >= 0) { spawn_function(); } // 21
		if(NSERIAL-22 >= 0) { spawn_function(); } // 22
		if(NSERIAL-23 >= 0) { spawn_function(); } // 23
		if(NSERIAL-24 >= 0) { spawn_function(); } // 24

		if(NSERIAL-25 >= 0) { spawn_function(); } // 25
		if(NSERIAL-26 >= 0) { spawn_function(); } // 26
		if(NSERIAL-27 >= 0) { spawn_function(); } // 27
		if(NSERIAL-28 >= 0) { spawn_function(); } // 28

		if(NSERIAL-29 >= 0) { spawn_function(); } // 29
		if(NSERIAL-30 >= 0) { spawn_function(); } // 30

		if(NSERIAL-31 >= 0) { spawn_function(); } // 31
		if(NSERIAL-32 >= 0) { spawn_function(); } // 32
		if(NSERIAL-33 >= 0) { spawn_function(); } // 33
		if(NSERIAL-34 >= 0) { spawn_function(); } // 34

		if(NSERIAL-35 >= 0) { spawn_function(); } // 35
		if(NSERIAL-36 >= 0) { spawn_function(); } // 36
		if(NSERIAL-37 >= 0) { spawn_function(); } // 37
		if(NSERIAL-38 >= 0) { spawn_function(); } // 38

		if(NSERIAL-39 >= 0) { spawn_function(); } // 39
		if(NSERIAL-40 >= 0) { spawn_function(); } // 40

		if(NSERIAL-41 >= 0) { spawn_function(); } // 41
		if(NSERIAL-42 >= 0) { spawn_function(); } // 42
		if(NSERIAL-43 >= 0) { spawn_function(); } // 43
		if(NSERIAL-44 >= 0) { spawn_function(); } // 44

		if(NSERIAL-45 >= 0) { spawn_function(); } // 45
		if(NSERIAL-46 >= 0) { spawn_function(); } // 46
		if(NSERIAL-47 >= 0) { spawn_function(); } // 47
		if(NSERIAL-48 >= 0) { spawn_function(); } // 48

		if(NSERIAL-49 >= 0) { spawn_function(); } // 49
		if(NSERIAL-50 >= 0) { spawn_function(); } // 50

		if(NSERIAL-51 >= 0) { spawn_function(); } // 51
		if(NSERIAL-52 >= 0) { spawn_function(); } // 52
		if(NSERIAL-53 >= 0) { spawn_function(); } // 53
		if(NSERIAL-54 >= 0) { spawn_function(); } // 54

		if(NSERIAL-55 >= 0) { spawn_function(); } // 55
		if(NSERIAL-56 >= 0) { spawn_function(); } // 56
		if(NSERIAL-57 >= 0) { spawn_function(); } // 57
		if(NSERIAL-58 >= 0) { spawn_function(); } // 58

		if(NSERIAL-59 >= 0) { spawn_function(); } // 59
		if(NSERIAL-60 >= 0) { spawn_function(); } // 60

		if(NSERIAL-61 >= 0) { spawn_function(); } // 61
		if(NSERIAL-62 >= 0) { spawn_function(); } // 62
		if(NSERIAL-63 >= 0) { spawn_function(); } // 63
		if(NSERIAL-64 >= 0) { spawn_function(); } // 64

		if(NSERIAL-65 >= 0) { spawn_function(); } // 65
		if(NSERIAL-66 >= 0) { spawn_function(); } // 66
		if(NSERIAL-66 >= 0) { spawn_function(); } // 66
		if(NSERIAL-68 >= 0) { spawn_function(); } // 68

		if(NSERIAL-69 >= 0) { spawn_function(); } // 69
		if(NSERIAL-70 >= 0) { spawn_function(); } // 70

		if(NSERIAL-71 >= 0) { spawn_function(); } // 71
		if(NSERIAL-72 >= 0) { spawn_function(); } // 72
		if(NSERIAL-73 >= 0) { spawn_function(); } // 73
		if(NSERIAL-74 >= 0) { spawn_function(); } // 74

		if(NSERIAL-75 >= 0) { spawn_function(); } // 75
		if(NSERIAL-76 >= 0) { spawn_function(); } // 76
		if(NSERIAL-77 >= 0) { spawn_function(); } // 77
		if(NSERIAL-78 >= 0) { spawn_function(); } // 78

		if(NSERIAL-79 >= 0) { spawn_function(); } // 79
		if(NSERIAL-80 >= 0) { spawn_function(); } // 80

		if(NSERIAL-81 >= 0) { spawn_function(); } // 81
		if(NSERIAL-82 >= 0) { spawn_function(); } // 82
		if(NSERIAL-83 >= 0) { spawn_function(); } // 83
		if(NSERIAL-84 >= 0) { spawn_function(); } // 84

		if(NSERIAL-85 >= 0) { spawn_function(); } // 85
		if(NSERIAL-86 >= 0) { spawn_function(); } // 86
		if(NSERIAL-87 >= 0) { spawn_function(); } // 87
		if(NSERIAL-88 >= 0) { spawn_function(); } // 88

		if(NSERIAL-89 >= 0) { spawn_function(); } // 89
		if(NSERIAL-90 >= 0) { spawn_function(); } // 90

		if(NSERIAL-91 >= 0) { spawn_function(); } // 91
		if(NSERIAL-92 >= 0) { spawn_function(); } // 92
		if(NSERIAL-93 >= 0) { spawn_function(); } // 93
		if(NSERIAL-94 >= 0) { spawn_function(); } // 94

		if(NSERIAL-95 >= 0) { spawn_function(); } // 95
		if(NSERIAL-96 >= 0) { spawn_function(); } // 96
		if(NSERIAL-97 >= 0) { spawn_function(); } // 97
		if(NSERIAL-98 >= 0) { spawn_function(); } // 98

		if(NSERIAL-99 >= 0) { spawn_function(); } // 99
		if(NSERIAL-100 >= 0) { spawn_function(); } // 100

		if(NSERIAL-101 >= 0) { spawn_function(); } // 101
		if(NSERIAL-102 >= 0) { spawn_function(); } // 102
		if(NSERIAL-103 >= 0) { spawn_function(); } // 103
		if(NSERIAL-104 >= 0) { spawn_function(); } // 104

		if(NSERIAL-105 >= 0) { spawn_function(); } // 105
		if(NSERIAL-106 >= 0) { spawn_function(); } // 106
		if(NSERIAL-107 >= 0) { spawn_function(); } // 107
		if(NSERIAL-108 >= 0) { spawn_function(); } // 108

		if(NSERIAL-109 >= 0) { spawn_function(); } // 109
		if(NSERIAL-110 >= 0) { spawn_function(); } // 110

		if(NSERIAL-111 >= 0) { spawn_function(); } // 111
		if(NSERIAL-112 >= 0) { spawn_function(); } // 112
		if(NSERIAL-113 >= 0) { spawn_function(); } // 113
		if(NSERIAL-114 >= 0) { spawn_function(); } // 114

		if(NSERIAL-115 >= 0) { spawn_function(); } // 115
		if(NSERIAL-116 >= 0) { spawn_function(); } // 116
		if(NSERIAL-117 >= 0) { spawn_function(); } // 117
		if(NSERIAL-118 >= 0) { spawn_function(); } // 118

		if(NSERIAL-119 >= 0) { spawn_function(); } // 119
		if(NSERIAL-120 >= 0) { spawn_function(); } // 120

		if(NSERIAL-121 >= 0) { spawn_function(); } // 121
		if(NSERIAL-122 >= 0) { spawn_function(); } // 122
		if(NSERIAL-123 >= 0) { spawn_function(); } // 123
		if(NSERIAL-124 >= 0) { spawn_function(); } // 124

		if(NSERIAL-125 >= 0) { spawn_function(); } // 125
		if(NSERIAL-126 >= 0) { spawn_function(); } // 126
		if(NSERIAL-127 >= 0) { spawn_function(); } // 127
		if(NSERIAL-128 >= 0) { spawn_function(); } // 128

		if(NSERIAL-129 >= 0) { spawn_function(); } // 129
		if(NSERIAL-130 >= 0) { spawn_function(); } // 130

		if(NSERIAL-131 >= 0) { spawn_function(); } // 131
		if(NSERIAL-132 >= 0) { spawn_function(); } // 132
		if(NSERIAL-133 >= 0) { spawn_function(); } // 133
		if(NSERIAL-134 >= 0) { spawn_function(); } // 134

		if(NSERIAL-135 >= 0) { spawn_function(); } // 135
		if(NSERIAL-136 >= 0) { spawn_function(); } // 136
		if(NSERIAL-137 >= 0) { spawn_function(); } // 137
		if(NSERIAL-138 >= 0) { spawn_function(); } // 138

		if(NSERIAL-139 >= 0) { spawn_function(); } // 139
		if(NSERIAL-140 >= 0) { spawn_function(); } // 140

		if(NSERIAL-141 >= 0) { spawn_function(); } // 141
		if(NSERIAL-142 >= 0) { spawn_function(); } // 142
		if(NSERIAL-143 >= 0) { spawn_function(); } // 143
		if(NSERIAL-144 >= 0) { spawn_function(); } // 144

		if(NSERIAL-145 >= 0) { spawn_function(); } // 145
		if(NSERIAL-146 >= 0) { spawn_function(); } // 146
		if(NSERIAL-147 >= 0) { spawn_function(); } // 147
		if(NSERIAL-148 >= 0) { spawn_function(); } // 148

		if(NSERIAL-149 >= 0) { spawn_function(); } // 149
		if(NSERIAL-150 >= 0) { spawn_function(); } // 150

		if(NSERIAL-151 >= 0) { spawn_function(); } // 151
		if(NSERIAL-152 >= 0) { spawn_function(); } // 152
		if(NSERIAL-153 >= 0) { spawn_function(); } // 153
		if(NSERIAL-154 >= 0) { spawn_function(); } // 154

		if(NSERIAL-155 >= 0) { spawn_function(); } // 155
		if(NSERIAL-156 >= 0) { spawn_function(); } // 156
		if(NSERIAL-157 >= 0) { spawn_function(); } // 157
		if(NSERIAL-158 >= 0) { spawn_function(); } // 158

		if(NSERIAL-159 >= 0) { spawn_function(); } // 159
		if(NSERIAL-160 >= 0) { spawn_function(); } // 160

		if(NSERIAL-161 >= 0) { spawn_function(); } // 161
		if(NSERIAL-162 >= 0) { spawn_function(); } // 162
		if(NSERIAL-163 >= 0) { spawn_function(); } // 163
		if(NSERIAL-164 >= 0) { spawn_function(); } // 164

		if(NSERIAL-165 >= 0) { spawn_function(); } // 165
		if(NSERIAL-166 >= 0) { spawn_function(); } // 166
		if(NSERIAL-167 >= 0) { spawn_function(); } // 167
		if(NSERIAL-168 >= 0) { spawn_function(); } // 168

		if(NSERIAL-169 >= 0) { spawn_function(); } // 169
		if(NSERIAL-170 >= 0) { spawn_function(); } // 170

		if(NSERIAL-171 >= 0) { spawn_function(); } // 171
		if(NSERIAL-172 >= 0) { spawn_function(); } // 172
		if(NSERIAL-173 >= 0) { spawn_function(); } // 173
		if(NSERIAL-174 >= 0) { spawn_function(); } // 174

		if(NSERIAL-175 >= 0) { spawn_function(); } // 175
		if(NSERIAL-176 >= 0) { spawn_function(); } // 176
		if(NSERIAL-177 >= 0) { spawn_function(); } // 177
		if(NSERIAL-178 >= 0) { spawn_function(); } // 178

		if(NSERIAL-179 >= 0) { spawn_function(); } // 179
		if(NSERIAL-180 >= 0) { spawn_function(); } // 180

		if(NSERIAL-181 >= 0) { spawn_function(); } // 181
		if(NSERIAL-182 >= 0) { spawn_function(); } // 182
		if(NSERIAL-183 >= 0) { spawn_function(); } // 183
		if(NSERIAL-184 >= 0) { spawn_function(); } // 184

		if(NSERIAL-185 >= 0) { spawn_function(); } // 185
		if(NSERIAL-186 >= 0) { spawn_function(); } // 186
		if(NSERIAL-187 >= 0) { spawn_function(); } // 187
		if(NSERIAL-188 >= 0) { spawn_function(); } // 188

		if(NSERIAL-189 >= 0) { spawn_function(); } // 189
		if(NSERIAL-190 >= 0) { spawn_function(); } // 190

		if(NSERIAL-191 >= 0) { spawn_function(); } // 191
		if(NSERIAL-192 >= 0) { spawn_function(); } // 192
		if(NSERIAL-193 >= 0) { spawn_function(); } // 193
		if(NSERIAL-194 >= 0) { spawn_function(); } // 194

		if(NSERIAL-195 >= 0) { spawn_function(); } // 195
		if(NSERIAL-196 >= 0) { spawn_function(); } // 196
		if(NSERIAL-197 >= 0) { spawn_function(); } // 197
		if(NSERIAL-198 >= 0) { spawn_function(); } // 198

		if(NSERIAL-199 >= 0) { spawn_function(); } // 199
		if(NSERIAL-200 >= 0) { spawn_function(); } // 200

		if(NSERIAL-201 >= 0) { spawn_function(); } // 201
		if(NSERIAL-202 >= 0) { spawn_function(); } // 202
		if(NSERIAL-203 >= 0) { spawn_function(); } // 203
		if(NSERIAL-204 >= 0) { spawn_function(); } // 204

		if(NSERIAL-205 >= 0) { spawn_function(); } // 205
		if(NSERIAL-206 >= 0) { spawn_function(); } // 206
		if(NSERIAL-207 >= 0) { spawn_function(); } // 207
		if(NSERIAL-208 >= 0) { spawn_function(); } // 208

		if(NSERIAL-209 >= 0) { spawn_function(); } // 209
		if(NSERIAL-210 >= 0) { spawn_function(); } // 210

		if(NSERIAL-211 >= 0) { spawn_function(); } // 211
		if(NSERIAL-212 >= 0) { spawn_function(); } // 212
		if(NSERIAL-213 >= 0) { spawn_function(); } // 213
		if(NSERIAL-214 >= 0) { spawn_function(); } // 214

		if(NSERIAL-215 >= 0) { spawn_function(); } // 215
		if(NSERIAL-216 >= 0) { spawn_function(); } // 216
		if(NSERIAL-217 >= 0) { spawn_function(); } // 217
		if(NSERIAL-218 >= 0) { spawn_function(); } // 218

		if(NSERIAL-219 >= 0) { spawn_function(); } // 219
		if(NSERIAL-220 >= 0) { spawn_function(); } // 220

		if(NSERIAL-221 >= 0) { spawn_function(); } // 221
		if(NSERIAL-222 >= 0) { spawn_function(); } // 222
		if(NSERIAL-223 >= 0) { spawn_function(); } // 223
		if(NSERIAL-224 >= 0) { spawn_function(); } // 224

		if(NSERIAL-225 >= 0) { spawn_function(); } // 225
		if(NSERIAL-226 >= 0) { spawn_function(); } // 226
		if(NSERIAL-227 >= 0) { spawn_function(); } // 227
		if(NSERIAL-228 >= 0) { spawn_function(); } // 228

		if(NSERIAL-229 >= 0) { spawn_function(); } // 229
		if(NSERIAL-230 >= 0) { spawn_function(); } // 230

		if(NSERIAL-231 >= 0) { spawn_function(); } // 231
		if(NSERIAL-232 >= 0) { spawn_function(); } // 232
		if(NSERIAL-233 >= 0) { spawn_function(); } // 233
		if(NSERIAL-234 >= 0) { spawn_function(); } // 234

		if(NSERIAL-235 >= 0) { spawn_function(); } // 235
		if(NSERIAL-236 >= 0) { spawn_function(); } // 236
		if(NSERIAL-237 >= 0) { spawn_function(); } // 237
		if(NSERIAL-238 >= 0) { spawn_function(); } // 238

		if(NSERIAL-239 >= 0) { spawn_function(); } // 239
		if(NSERIAL-240 >= 0) { spawn_function(); } // 240

		if(NSERIAL-241 >= 0) { spawn_function(); } // 241
		if(NSERIAL-242 >= 0) { spawn_function(); } // 242
		if(NSERIAL-243 >= 0) { spawn_function(); } // 243
		if(NSERIAL-244 >= 0) { spawn_function(); } // 244

		if(NSERIAL-245 >= 0) { spawn_function(); } // 245
		if(NSERIAL-246 >= 0) { spawn_function(); } // 246
		if(NSERIAL-247 >= 0) { spawn_function(); } // 247
		if(NSERIAL-248 >= 0) { spawn_function(); } // 248

		if(NSERIAL-249 >= 0) { spawn_function(); } // 249
		if(NSERIAL-250 >= 0) { spawn_function(); } // 250

		if(NSERIAL-251 >= 0) { spawn_function(); } // 251
		if(NSERIAL-252 >= 0) { spawn_function(); } // 252
		if(NSERIAL-253 >= 0) { spawn_function(); } // 253
		if(NSERIAL-254 >= 0) { spawn_function(); } // 254

		if(NSERIAL-255 >= 0) { spawn_function(); } // 255
		if(NSERIAL-256 >= 0) { spawn_function(); } // 256
		if(NSERIAL-257 >= 0) { spawn_function(); } // 257
		if(NSERIAL-258 >= 0) { spawn_function(); } // 258

		if(NSERIAL-259 >= 0) { spawn_function(); } // 259
		if(NSERIAL-260 >= 0) { spawn_function(); } // 260

		if(NSERIAL-261 >= 0) { spawn_function(); } // 261
		if(NSERIAL-262 >= 0) { spawn_function(); } // 262
		if(NSERIAL-263 >= 0) { spawn_function(); } // 263
		if(NSERIAL-264 >= 0) { spawn_function(); } // 264

		if(NSERIAL-265 >= 0) { spawn_function(); } // 265
		if(NSERIAL-266 >= 0) { spawn_function(); } // 266
		if(NSERIAL-267 >= 0) { spawn_function(); } // 267
		if(NSERIAL-268 >= 0) { spawn_function(); } // 268

		if(NSERIAL-269 >= 0) { spawn_function(); } // 269
		if(NSERIAL-270 >= 0) { spawn_function(); } // 270

		if(NSERIAL-271 >= 0) { spawn_function(); } // 271
		if(NSERIAL-272 >= 0) { spawn_function(); } // 272
		if(NSERIAL-273 >= 0) { spawn_function(); } // 273
		if(NSERIAL-274 >= 0) { spawn_function(); } // 274

		if(NSERIAL-275 >= 0) { spawn_function(); } // 275
		if(NSERIAL-276 >= 0) { spawn_function(); } // 276
		if(NSERIAL-277 >= 0) { spawn_function(); } // 277
		if(NSERIAL-278 >= 0) { spawn_function(); } // 278

		if(NSERIAL-279 >= 0) { spawn_function(); } // 279
		if(NSERIAL-280 >= 0) { spawn_function(); } // 280

		if(NSERIAL-281 >= 0) { spawn_function(); } // 281
		if(NSERIAL-282 >= 0) { spawn_function(); } // 282
		if(NSERIAL-283 >= 0) { spawn_function(); } // 283
		if(NSERIAL-284 >= 0) { spawn_function(); } // 284

		if(NSERIAL-285 >= 0) { spawn_function(); } // 285
		if(NSERIAL-286 >= 0) { spawn_function(); } // 286
		if(NSERIAL-287 >= 0) { spawn_function(); } // 287
		if(NSERIAL-288 >= 0) { spawn_function(); } // 288

		if(NSERIAL-289 >= 0) { spawn_function(); } // 289
		if(NSERIAL-290 >= 0) { spawn_function(); } // 290

		if(NSERIAL-291 >= 0) { spawn_function(); } // 291
		if(NSERIAL-292 >= 0) { spawn_function(); } // 292
		if(NSERIAL-293 >= 0) { spawn_function(); } // 293
		if(NSERIAL-294 >= 0) { spawn_function(); } // 294

		if(NSERIAL-295 >= 0) { spawn_function(); } // 295
		if(NSERIAL-296 >= 0) { spawn_function(); } // 296
		if(NSERIAL-297 >= 0) { spawn_function(); } // 297
		if(NSERIAL-298 >= 0) { spawn_function(); } // 298

		if(NSERIAL-299 >= 0) { spawn_function(); } // 299
		if(NSERIAL-300 >= 0) { spawn_function(); } // 300

		if(NSERIAL-301 >= 0) { spawn_function(); } // 301

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

	//printf("01A\n");

	
	/*clock_gettime(CLOCK_MONOTONIC, &t_start);

	int N = 271;

	for(int i=0; i<N; i++){
		spawn_function();

	}
	
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n\n", (long)t_res.tv_sec, t_res.tv_nsec);*/

	return 0;
}