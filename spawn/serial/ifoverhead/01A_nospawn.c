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
#include "../../../include/numthreads.h"

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

    if(NSERIAL-1 >= 0) { } // 1 // Take time stamp before each spawn
		if(NSERIAL-2 >= 0) { } // 2
		if(NSERIAL-3 >= 0) { } // 3
		if(NSERIAL-4 >= 0) { } // 4

		if(NSERIAL-5 >= 0) { } // 5
		if(NSERIAL-6 >= 0) { } // 6
		if(NSERIAL-7 >= 0) { } // 7
		if(NSERIAL-8 >= 0) { } // 8
		if(NSERIAL-9 >= 0) { } // 9
		if(NSERIAL-10 >= 0) { } // 10

		if(NSERIAL-11 >= 0) { } // 11
		if(NSERIAL-12 >= 0) { } // 12
		if(NSERIAL-13 >= 0) { } // 13
		if(NSERIAL-14 >= 0) { } // 14

		if(NSERIAL-15 >= 0) { } // 15
		if(NSERIAL-16 >= 0) { } // 16
		if(NSERIAL-17 >= 0) { } // 17
		if(NSERIAL-18 >= 0) { } // 18

		if(NSERIAL-19 >= 0) { } // 19
		if(NSERIAL-20 >= 0) { } // 20

		if(NSERIAL-21 >= 0) { } // 21
		if(NSERIAL-22 >= 0) { } // 22
		if(NSERIAL-23 >= 0) { } // 23
		if(NSERIAL-24 >= 0) { } // 24

		if(NSERIAL-25 >= 0) { } // 25
		if(NSERIAL-26 >= 0) { } // 26
		if(NSERIAL-27 >= 0) { } // 27
		if(NSERIAL-28 >= 0) { } // 28

		if(NSERIAL-29 >= 0) { } // 29
		if(NSERIAL-30 >= 0) { } // 30

		if(NSERIAL-31 >= 0) { } // 31
		if(NSERIAL-32 >= 0) { } // 32
		if(NSERIAL-33 >= 0) { } // 33
		if(NSERIAL-34 >= 0) { } // 34

		if(NSERIAL-35 >= 0) { } // 35
		if(NSERIAL-36 >= 0) { } // 36
		if(NSERIAL-37 >= 0) { } // 37
		if(NSERIAL-38 >= 0) { } // 38

		if(NSERIAL-39 >= 0) { } // 39
		if(NSERIAL-40 >= 0) { } // 40

		if(NSERIAL-41 >= 0) { } // 41
		if(NSERIAL-42 >= 0) { } // 42
		if(NSERIAL-43 >= 0) { } // 43
		if(NSERIAL-44 >= 0) { } // 44

		if(NSERIAL-45 >= 0) { } // 45
		if(NSERIAL-46 >= 0) { } // 46
		if(NSERIAL-47 >= 0) { } // 47
		if(NSERIAL-48 >= 0) { } // 48

		if(NSERIAL-49 >= 0) { } // 49
		if(NSERIAL-50 >= 0) { } // 50

		if(NSERIAL-51 >= 0) { } // 51
		if(NSERIAL-52 >= 0) { } // 52
		if(NSERIAL-53 >= 0) { } // 53
		if(NSERIAL-54 >= 0) { } // 54

		if(NSERIAL-55 >= 0) { } // 55
		if(NSERIAL-56 >= 0) { } // 56
		if(NSERIAL-57 >= 0) { } // 57
		if(NSERIAL-58 >= 0) { } // 58

		if(NSERIAL-59 >= 0) { } // 59
		if(NSERIAL-60 >= 0) { } // 60

		if(NSERIAL-61 >= 0) { } // 61
		if(NSERIAL-62 >= 0) { } // 62
		if(NSERIAL-63 >= 0) { } // 63
		if(NSERIAL-64 >= 0) { } // 64

		if(NSERIAL-65 >= 0) { } // 65
		if(NSERIAL-66 >= 0) { } // 66
		if(NSERIAL-66 >= 0) { } // 66
		if(NSERIAL-68 >= 0) { } // 68

		if(NSERIAL-69 >= 0) { } // 69
		if(NSERIAL-70 >= 0) { } // 70

		if(NSERIAL-71 >= 0) { } // 71
		if(NSERIAL-72 >= 0) { } // 72
		if(NSERIAL-73 >= 0) { } // 73
		if(NSERIAL-74 >= 0) { } // 74

		if(NSERIAL-75 >= 0) { } // 75
		if(NSERIAL-76 >= 0) { } // 76
		if(NSERIAL-77 >= 0) { } // 77
		if(NSERIAL-78 >= 0) { } // 78

		if(NSERIAL-79 >= 0) { } // 79
		if(NSERIAL-80 >= 0) { } // 80

		if(NSERIAL-81 >= 0) { } // 81
		if(NSERIAL-82 >= 0) { } // 82
		if(NSERIAL-83 >= 0) { } // 83
		if(NSERIAL-84 >= 0) { } // 84

		if(NSERIAL-85 >= 0) { } // 85
		if(NSERIAL-86 >= 0) { } // 86
		if(NSERIAL-87 >= 0) { } // 87
		if(NSERIAL-88 >= 0) { } // 88

		if(NSERIAL-89 >= 0) { } // 89
		if(NSERIAL-90 >= 0) { } // 90

		if(NSERIAL-91 >= 0) { } // 91
		if(NSERIAL-92 >= 0) { } // 92
		if(NSERIAL-93 >= 0) { } // 93
		if(NSERIAL-94 >= 0) { } // 94

		if(NSERIAL-95 >= 0) { } // 95
		if(NSERIAL-96 >= 0) { } // 96
		if(NSERIAL-97 >= 0) { } // 97
		if(NSERIAL-98 >= 0) { } // 98

		if(NSERIAL-99 >= 0) { } // 99
		if(NSERIAL-100 >= 0) { } // 100

		if(NSERIAL-101 >= 0) { } // 101
		if(NSERIAL-102 >= 0) { } // 102
		if(NSERIAL-103 >= 0) { } // 103
		if(NSERIAL-104 >= 0) { } // 104

		if(NSERIAL-105 >= 0) { } // 105
		if(NSERIAL-106 >= 0) { } // 106
		if(NSERIAL-107 >= 0) { } // 107
		if(NSERIAL-108 >= 0) { } // 108

		if(NSERIAL-109 >= 0) { } // 109
		if(NSERIAL-110 >= 0) { } // 110

		if(NSERIAL-111 >= 0) { } // 111
		if(NSERIAL-112 >= 0) { } // 112
		if(NSERIAL-113 >= 0) { } // 113
		if(NSERIAL-114 >= 0) { } // 114

		if(NSERIAL-115 >= 0) { } // 115
		if(NSERIAL-116 >= 0) { } // 116
		if(NSERIAL-117 >= 0) { } // 117
		if(NSERIAL-118 >= 0) { } // 118

		if(NSERIAL-119 >= 0) { } // 119
		if(NSERIAL-120 >= 0) { } // 120

		if(NSERIAL-121 >= 0) { } // 121
		if(NSERIAL-122 >= 0) { } // 122
		if(NSERIAL-123 >= 0) { } // 123
		if(NSERIAL-124 >= 0) { } // 124

		if(NSERIAL-125 >= 0) { } // 125
		if(NSERIAL-126 >= 0) { } // 126
		if(NSERIAL-127 >= 0) { } // 127
		if(NSERIAL-128 >= 0) { } // 128

		if(NSERIAL-129 >= 0) { } // 129
		if(NSERIAL-130 >= 0) { } // 130

		if(NSERIAL-131 >= 0) { } // 131
		if(NSERIAL-132 >= 0) { } // 132
		if(NSERIAL-133 >= 0) { } // 133
		if(NSERIAL-134 >= 0) { } // 134

		if(NSERIAL-135 >= 0) { } // 135
		if(NSERIAL-136 >= 0) { } // 136
		if(NSERIAL-137 >= 0) { } // 137
		if(NSERIAL-138 >= 0) { } // 138

		if(NSERIAL-139 >= 0) { } // 139
		if(NSERIAL-140 >= 0) { } // 140

		if(NSERIAL-141 >= 0) { } // 141
		if(NSERIAL-142 >= 0) { } // 142
		if(NSERIAL-143 >= 0) { } // 143
		if(NSERIAL-144 >= 0) { } // 144

		if(NSERIAL-145 >= 0) { } // 145
		if(NSERIAL-146 >= 0) { } // 146
		if(NSERIAL-147 >= 0) { } // 147
		if(NSERIAL-148 >= 0) { } // 148

		if(NSERIAL-149 >= 0) { } // 149
		if(NSERIAL-150 >= 0) { } // 150

		if(NSERIAL-151 >= 0) { } // 151
		if(NSERIAL-152 >= 0) { } // 152
		if(NSERIAL-153 >= 0) { } // 153
		if(NSERIAL-154 >= 0) { } // 154

		if(NSERIAL-155 >= 0) { } // 155
		if(NSERIAL-156 >= 0) { } // 156
		if(NSERIAL-157 >= 0) { } // 157
		if(NSERIAL-158 >= 0) { } // 158

		if(NSERIAL-159 >= 0) { } // 159
		if(NSERIAL-160 >= 0) { } // 160

		if(NSERIAL-161 >= 0) { } // 161
		if(NSERIAL-162 >= 0) { } // 162
		if(NSERIAL-163 >= 0) { } // 163
		if(NSERIAL-164 >= 0) { } // 164

		if(NSERIAL-165 >= 0) { } // 165
		if(NSERIAL-166 >= 0) { } // 166
		if(NSERIAL-167 >= 0) { } // 167
		if(NSERIAL-168 >= 0) { } // 168

		if(NSERIAL-169 >= 0) { } // 169
		if(NSERIAL-170 >= 0) { } // 170

		if(NSERIAL-171 >= 0) { } // 171
		if(NSERIAL-172 >= 0) { } // 172
		if(NSERIAL-173 >= 0) { } // 173
		if(NSERIAL-174 >= 0) { } // 174

		if(NSERIAL-175 >= 0) { } // 175
		if(NSERIAL-176 >= 0) { } // 176
		if(NSERIAL-177 >= 0) { } // 177
		if(NSERIAL-178 >= 0) { } // 178

		if(NSERIAL-179 >= 0) { } // 179
		if(NSERIAL-180 >= 0) { } // 180

		if(NSERIAL-181 >= 0) { } // 181
		if(NSERIAL-182 >= 0) { } // 182
		if(NSERIAL-183 >= 0) { } // 183
		if(NSERIAL-184 >= 0) { } // 184

		if(NSERIAL-185 >= 0) { } // 185
		if(NSERIAL-186 >= 0) { } // 186
		if(NSERIAL-187 >= 0) { } // 187
		if(NSERIAL-188 >= 0) { } // 188

		if(NSERIAL-189 >= 0) { } // 189
		if(NSERIAL-190 >= 0) { } // 190

		if(NSERIAL-191 >= 0) { } // 191
		if(NSERIAL-192 >= 0) { } // 192
		if(NSERIAL-193 >= 0) { } // 193
		if(NSERIAL-194 >= 0) { } // 194

		if(NSERIAL-195 >= 0) { } // 195
		if(NSERIAL-196 >= 0) { } // 196
		if(NSERIAL-197 >= 0) { } // 197
		if(NSERIAL-198 >= 0) { } // 198

		if(NSERIAL-199 >= 0) { } // 199
		if(NSERIAL-200 >= 0) { } // 200

		if(NSERIAL-201 >= 0) { } // 201
		if(NSERIAL-202 >= 0) { } // 202
		if(NSERIAL-203 >= 0) { } // 203
		if(NSERIAL-204 >= 0) { } // 204

		if(NSERIAL-205 >= 0) { } // 205
		if(NSERIAL-206 >= 0) { } // 206
		if(NSERIAL-207 >= 0) { } // 207
		if(NSERIAL-208 >= 0) { } // 208

		if(NSERIAL-209 >= 0) { } // 209
		if(NSERIAL-210 >= 0) { } // 210

		if(NSERIAL-211 >= 0) { } // 211
		if(NSERIAL-212 >= 0) { } // 212
		if(NSERIAL-213 >= 0) { } // 213
		if(NSERIAL-214 >= 0) { } // 214

		if(NSERIAL-215 >= 0) { } // 215
		if(NSERIAL-216 >= 0) { } // 216
		if(NSERIAL-217 >= 0) { } // 217
		if(NSERIAL-218 >= 0) { } // 218

		if(NSERIAL-219 >= 0) { } // 219
		if(NSERIAL-220 >= 0) { } // 220

		if(NSERIAL-221 >= 0) { } // 221
		if(NSERIAL-222 >= 0) { } // 222
		if(NSERIAL-223 >= 0) { } // 223
		if(NSERIAL-224 >= 0) { } // 224

		if(NSERIAL-225 >= 0) { } // 225
		if(NSERIAL-226 >= 0) { } // 226
		if(NSERIAL-227 >= 0) { } // 227
		if(NSERIAL-228 >= 0) { } // 228

		if(NSERIAL-229 >= 0) { } // 229
		if(NSERIAL-230 >= 0) { } // 230

		if(NSERIAL-231 >= 0) { } // 231
		if(NSERIAL-232 >= 0) { } // 232
		if(NSERIAL-233 >= 0) { } // 233
		if(NSERIAL-234 >= 0) { } // 234

		if(NSERIAL-235 >= 0) { } // 235
		if(NSERIAL-236 >= 0) { } // 236
		if(NSERIAL-237 >= 0) { } // 237
		if(NSERIAL-238 >= 0) { } // 238

		if(NSERIAL-239 >= 0) { } // 239
		if(NSERIAL-240 >= 0) { } // 240

		if(NSERIAL-241 >= 0) { } // 241
		if(NSERIAL-242 >= 0) { } // 242
		if(NSERIAL-243 >= 0) { } // 243
		if(NSERIAL-244 >= 0) { } // 244

		if(NSERIAL-245 >= 0) { } // 245
		if(NSERIAL-246 >= 0) { } // 246
		if(NSERIAL-247 >= 0) { } // 247
		if(NSERIAL-248 >= 0) { } // 248

		if(NSERIAL-249 >= 0) { } // 249
		if(NSERIAL-250 >= 0) { } // 250

		if(NSERIAL-251 >= 0) { } // 251
		if(NSERIAL-252 >= 0) { } // 252
		if(NSERIAL-253 >= 0) { } // 253
		if(NSERIAL-254 >= 0) { } // 254

		if(NSERIAL-255 >= 0) { } // 255
		if(NSERIAL-256 >= 0) { } // 256
		if(NSERIAL-257 >= 0) { } // 257
		if(NSERIAL-258 >= 0) { } // 258

		if(NSERIAL-259 >= 0) { } // 259
		if(NSERIAL-260 >= 0) { } // 260

		if(NSERIAL-261 >= 0) { } // 261
		if(NSERIAL-262 >= 0) { } // 262
		if(NSERIAL-263 >= 0) { } // 263
		if(NSERIAL-264 >= 0) { } // 264

		if(NSERIAL-265 >= 0) { } // 265
		if(NSERIAL-266 >= 0) { } // 266
		if(NSERIAL-267 >= 0) { } // 267
		if(NSERIAL-268 >= 0) { } // 268

		if(NSERIAL-269 >= 0) { } // 269
		if(NSERIAL-270 >= 0) { } // 270

		if(NSERIAL-271 >= 0) { } // 271
		if(NSERIAL-272 >= 0) { } // 272
		if(NSERIAL-273 >= 0) { } // 273
		if(NSERIAL-274 >= 0) { } // 274

		if(NSERIAL-275 >= 0) { } // 275
		if(NSERIAL-276 >= 0) { } // 276
		if(NSERIAL-277 >= 0) { } // 277
		if(NSERIAL-278 >= 0) { } // 278

		if(NSERIAL-279 >= 0) { } // 279
		if(NSERIAL-280 >= 0) { } // 280

		if(NSERIAL-281 >= 0) { } // 281
		if(NSERIAL-282 >= 0) { } // 282
		if(NSERIAL-283 >= 0) { } // 283
		if(NSERIAL-284 >= 0) { } // 284

		if(NSERIAL-285 >= 0) { } // 285
		if(NSERIAL-286 >= 0) { } // 286
		if(NSERIAL-287 >= 0) { } // 287
		if(NSERIAL-288 >= 0) { } // 288

		if(NSERIAL-289 >= 0) { } // 289
		if(NSERIAL-290 >= 0) { } // 290

		if(NSERIAL-291 >= 0) { } // 291
		if(NSERIAL-292 >= 0) { } // 292
		if(NSERIAL-293 >= 0) { } // 293
		if(NSERIAL-294 >= 0) { } // 294

		if(NSERIAL-295 >= 0) { } // 295
		if(NSERIAL-296 >= 0) { } // 296
		if(NSERIAL-297 >= 0) { } // 297
		if(NSERIAL-298 >= 0) { } // 298

		if(NSERIAL-299 >= 0) { } // 299
		if(NSERIAL-300 >= 0) { } // 300

		if(NSERIAL-301 >= 0) { } // 301

	clock_gettime(CLOCK_MONOTONIC, &t_end);

	timespec_sub(&t_res, t_end, t_start);
	printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);

    return 0;

}