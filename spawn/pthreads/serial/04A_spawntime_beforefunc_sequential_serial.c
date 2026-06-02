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

/* Benchmark: 04A: Spawn time beforefunc ; Sequential Spawns (Serial)
 * Launch a bunch and measure when all done - don’t necessarily get just spawn time
 */

struct timespec spawn_function(){           // Simple Spawn Function

	struct timespec t_end; 						  
	clock_gettime(CLOCK_MONOTONIC, &t_end);

	int x = 100; int y = 5000; int z = 1000000;

	x = x + y + z;

	y = y + x + z;

	z = z + y + x;	

	return t_end; 
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

	struct timespec t_start[NSERIAL];
    struct timespec t_res;
	struct timespec t_end[NSERIAL];


	if(NSERIAL-1 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[0]); t_end[0] =  spawn_function(); } // 1 // Take time stamp before each spawn
		if(NSERIAL-2 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[1]); t_end[1] =  spawn_function(); } // 2
		if(NSERIAL-3 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[2]); t_end[2] =  spawn_function(); } // 3
		if(NSERIAL-4 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[3]); t_end[3] =  spawn_function(); } // 4

		if(NSERIAL-5 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[4]); t_end[4] =  spawn_function(); } // 5
		if(NSERIAL-6 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[5]); t_end[5] =  spawn_function(); } // 6
		if(NSERIAL-7 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[6]); t_end[6] =  spawn_function(); } // 7
		if(NSERIAL-8 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[7]); t_end[7] =  spawn_function(); } // 8
		if(NSERIAL-9 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[8]); t_end[8] =  spawn_function(); } // 9
		if(NSERIAL-10 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[9]); t_end[9] =  spawn_function(); } // 10

		if(NSERIAL-11 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[10]); t_end[10] =  spawn_function(); } // 11
		if(NSERIAL-12 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[11]); t_end[11] =  spawn_function(); } // 12
		if(NSERIAL-13 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[12]); t_end[12] =  spawn_function(); } // 13
		if(NSERIAL-14 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[13]); t_end[13] =  spawn_function(); } // 14

		if(NSERIAL-15 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[14]); t_end[14] =  spawn_function(); } // 15
		if(NSERIAL-16 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[15]); t_end[15] =  spawn_function(); } // 16
		if(NSERIAL-17 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[16]); t_end[16] =  spawn_function(); } // 17
		if(NSERIAL-18 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[17]); t_end[17] =  spawn_function(); } // 18

		if(NSERIAL-19 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[18]); t_end[18] =  spawn_function(); } // 19
		if(NSERIAL-20 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[19]); t_end[19] =  spawn_function(); } // 20

		if(NSERIAL-21 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[20]); t_end[20] =  spawn_function(); } // 21
		if(NSERIAL-22 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[21]); t_end[21] =  spawn_function(); } // 22
		if(NSERIAL-23 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[22]); t_end[22] =  spawn_function(); } // 23
		if(NSERIAL-24 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[23]); t_end[23] =  spawn_function(); } // 24

		if(NSERIAL-25 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[24]); t_end[24] =  spawn_function(); } // 25
		if(NSERIAL-26 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[25]); t_end[25] =  spawn_function(); } // 26
		if(NSERIAL-27 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[26]); t_end[26] =  spawn_function(); } // 27
		if(NSERIAL-28 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[27]); t_end[27] =  spawn_function(); } // 28

		if(NSERIAL-29 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[28]); t_end[28] =  spawn_function(); } // 29
		if(NSERIAL-30 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[29]); t_end[29] =  spawn_function(); } // 30

		if(NSERIAL-31 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[30]); t_end[30] =  spawn_function(); } // 31
		if(NSERIAL-32 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[31]); t_end[31] =  spawn_function(); } // 32
		if(NSERIAL-33 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[32]); t_end[32] =  spawn_function(); } // 33
		if(NSERIAL-34 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[33]); t_end[33] =  spawn_function(); } // 34

		if(NSERIAL-35 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[34]); t_end[34] =  spawn_function(); } // 35
		if(NSERIAL-36 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[35]); t_end[35] =  spawn_function(); } // 36
		if(NSERIAL-37 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[36]); t_end[36] =  spawn_function(); } // 37
		if(NSERIAL-38 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[37]); t_end[37] =  spawn_function(); } // 38

		if(NSERIAL-39 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[38]); t_end[38] =  spawn_function(); } // 39
		if(NSERIAL-40 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[39]); t_end[39] =  spawn_function(); } // 40

		if(NSERIAL-41 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[40]); t_end[40] =  spawn_function(); } // 41
		if(NSERIAL-42 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[41]); t_end[41] =  spawn_function(); } // 42
		if(NSERIAL-43 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[42]); t_end[42] =  spawn_function(); } // 43
		if(NSERIAL-44 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[43]); t_end[43] =  spawn_function(); } // 44

		if(NSERIAL-45 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[44]); t_end[44] =  spawn_function(); } // 45
		if(NSERIAL-46 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[45]); t_end[45] =  spawn_function(); } // 46
		if(NSERIAL-47 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[46]); t_end[46] =  spawn_function(); } // 47
		if(NSERIAL-48 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[47]); t_end[47] =  spawn_function(); } // 48

		if(NSERIAL-49 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[48]); t_end[48] =  spawn_function(); } // 49
		if(NSERIAL-50 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[49]); t_end[49] =  spawn_function(); } // 50

		if(NSERIAL-51 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[50]); t_end[50] =  spawn_function(); } // 51
		if(NSERIAL-52 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[51]); t_end[51] =  spawn_function(); } // 52
		if(NSERIAL-53 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[52]); t_end[52] =  spawn_function(); } // 53
		if(NSERIAL-54 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[53]); t_end[53] =  spawn_function(); } // 54

		if(NSERIAL-55 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[54]); t_end[54] =  spawn_function(); } // 55
		if(NSERIAL-56 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[55]); t_end[55] =  spawn_function(); } // 56
		if(NSERIAL-57 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[56]); t_end[56] =  spawn_function(); } // 57
		if(NSERIAL-58 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[57]); t_end[57] =  spawn_function(); } // 58

		if(NSERIAL-59 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[58]); t_end[58] =  spawn_function(); } // 59
		if(NSERIAL-60 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[59]); t_end[59] =  spawn_function(); } // 60

		if(NSERIAL-61 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[60]); t_end[60] =  spawn_function(); } // 61
		if(NSERIAL-62 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[61]); t_end[61] =  spawn_function(); } // 62
		if(NSERIAL-63 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[62]); t_end[62] =  spawn_function(); } // 63
		if(NSERIAL-64 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[63]); t_end[63] =  spawn_function(); } // 64

		if(NSERIAL-65 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[64]); t_end[64] =  spawn_function(); } // 65
		if(NSERIAL-66 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[65]); t_end[65] =  spawn_function(); } // 66
		if(NSERIAL-66 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[66]); t_end[66] =  spawn_function(); } // 66
		if(NSERIAL-68 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[67]); t_end[67] =  spawn_function(); } // 68

		if(NSERIAL-69 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[68]); t_end[68] =  spawn_function(); } // 69
		if(NSERIAL-70 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[69]); t_end[69] =  spawn_function(); } // 70

		if(NSERIAL-71 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[70]); t_end[70] =  spawn_function(); } // 71
		if(NSERIAL-72 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[71]); t_end[71] =  spawn_function(); } // 72
		if(NSERIAL-73 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[72]); t_end[72] =  spawn_function(); } // 73
		if(NSERIAL-74 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[73]); t_end[73] =  spawn_function(); } // 74

		if(NSERIAL-75 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[74]); t_end[74] =  spawn_function(); } // 75
		if(NSERIAL-76 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[75]); t_end[75] =  spawn_function(); } // 76
		if(NSERIAL-77 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[76]); t_end[76] =  spawn_function(); } // 77
		if(NSERIAL-78 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[77]); t_end[77] =  spawn_function(); } // 78

		if(NSERIAL-79 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[78]); t_end[78] =  spawn_function(); } // 79
		if(NSERIAL-80 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[79]); t_end[79] =  spawn_function(); } // 80

		if(NSERIAL-81 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[80]); t_end[80] =  spawn_function(); } // 81
		if(NSERIAL-82 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[81]); t_end[81] =  spawn_function(); } // 82
		if(NSERIAL-83 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[82]); t_end[82] =  spawn_function(); } // 83
		if(NSERIAL-84 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[83]); t_end[83] =  spawn_function(); } // 84

		if(NSERIAL-85 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[84]); t_end[84] =  spawn_function(); } // 85
		if(NSERIAL-86 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[85]); t_end[85] =  spawn_function(); } // 86
		if(NSERIAL-87 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[86]); t_end[86] =  spawn_function(); } // 87
		if(NSERIAL-88 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[87]); t_end[87] =  spawn_function(); } // 88

		if(NSERIAL-89 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[88]); t_end[88] =  spawn_function(); } // 89
		if(NSERIAL-90 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[89]); t_end[89] =  spawn_function(); } // 90

		if(NSERIAL-91 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[90]); t_end[90] =  spawn_function(); } // 91
		if(NSERIAL-92 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[91]); t_end[91] =  spawn_function(); } // 92
		if(NSERIAL-93 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[92]); t_end[92] =  spawn_function(); } // 93
		if(NSERIAL-94 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[93]); t_end[93] =  spawn_function(); } // 94

		if(NSERIAL-95 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[94]); t_end[94] =  spawn_function(); } // 95
		if(NSERIAL-96 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[95]); t_end[95] =  spawn_function(); } // 96
		if(NSERIAL-97 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[96]); t_end[96] =  spawn_function(); } // 97
		if(NSERIAL-98 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[97]); t_end[97] =  spawn_function(); } // 98

		if(NSERIAL-99 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[98]); t_end[98] =  spawn_function(); } // 99
		if(NSERIAL-100 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[99]); t_end[99] =  spawn_function(); } // 100

		if(NSERIAL-101 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[100]); t_end[100] =  spawn_function(); } // 101
		if(NSERIAL-102 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[101]); t_end[101] =  spawn_function(); } // 102
		if(NSERIAL-103 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[102]); t_end[102] =  spawn_function(); } // 103
		if(NSERIAL-104 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[103]); t_end[103] =  spawn_function(); } // 104

		if(NSERIAL-105 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[104]); t_end[104] =  spawn_function(); } // 105
		if(NSERIAL-106 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[105]); t_end[105] =  spawn_function(); } // 106
		if(NSERIAL-107 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[106]); t_end[106] =  spawn_function(); } // 107
		if(NSERIAL-108 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[107]); t_end[107] =  spawn_function(); } // 108

		if(NSERIAL-109 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[108]); t_end[108] =  spawn_function(); } // 109
		if(NSERIAL-110 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[109]); t_end[109] =  spawn_function(); } // 110

		if(NSERIAL-111 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[110]); t_end[110] =  spawn_function(); } // 111
		if(NSERIAL-112 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[111]); t_end[111] =  spawn_function(); } // 112
		if(NSERIAL-113 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[112]); t_end[112] =  spawn_function(); } // 113
		if(NSERIAL-114 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[113]); t_end[113] =  spawn_function(); } // 114

		if(NSERIAL-115 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[114]); t_end[114] =  spawn_function(); } // 115
		if(NSERIAL-116 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[115]); t_end[115] =  spawn_function(); } // 116
		if(NSERIAL-117 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[116]); t_end[116] =  spawn_function(); } // 117
		if(NSERIAL-118 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[117]); t_end[117] =  spawn_function(); } // 118

		if(NSERIAL-119 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[118]); t_end[118] =  spawn_function(); } // 119
		if(NSERIAL-120 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[119]); t_end[119] =  spawn_function(); } // 120

		if(NSERIAL-121 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[120]); t_end[120] =  spawn_function(); } // 121
		if(NSERIAL-122 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[121]); t_end[121] =  spawn_function(); } // 122
		if(NSERIAL-123 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[122]); t_end[122] =  spawn_function(); } // 123
		if(NSERIAL-124 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[123]); t_end[123] =  spawn_function(); } // 124

		if(NSERIAL-125 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[124]); t_end[124] =  spawn_function(); } // 125
		if(NSERIAL-126 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[125]); t_end[125] =  spawn_function(); } // 126
		if(NSERIAL-127 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[126]); t_end[126] =  spawn_function(); } // 127
		if(NSERIAL-128 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[127]); t_end[127] =  spawn_function(); } // 128

		if(NSERIAL-129 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[128]); t_end[128] =  spawn_function(); } // 129
		if(NSERIAL-130 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[129]); t_end[129] =  spawn_function(); } // 130

		if(NSERIAL-131 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[130]); t_end[130] =  spawn_function(); } // 131
		if(NSERIAL-132 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[131]); t_end[131] =  spawn_function(); } // 132
		if(NSERIAL-133 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[132]); t_end[132] =  spawn_function(); } // 133
		if(NSERIAL-134 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[133]); t_end[133] =  spawn_function(); } // 134

		if(NSERIAL-135 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[134]); t_end[134] =  spawn_function(); } // 135
		if(NSERIAL-136 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[135]); t_end[135] =  spawn_function(); } // 136
		if(NSERIAL-137 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[136]); t_end[136] =  spawn_function(); } // 137
		if(NSERIAL-138 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[137]); t_end[137] =  spawn_function(); } // 138

		if(NSERIAL-139 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[138]); t_end[138] =  spawn_function(); } // 139
		if(NSERIAL-140 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[139]); t_end[139] =  spawn_function(); } // 140

		if(NSERIAL-141 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[140]); t_end[140] =  spawn_function(); } // 141
		if(NSERIAL-142 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[141]); t_end[141] =  spawn_function(); } // 142
		if(NSERIAL-143 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[142]); t_end[142] =  spawn_function(); } // 143
		if(NSERIAL-144 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[143]); t_end[143] =  spawn_function(); } // 144

		if(NSERIAL-145 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[144]); t_end[144] =  spawn_function(); } // 145
		if(NSERIAL-146 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[145]); t_end[145] =  spawn_function(); } // 146
		if(NSERIAL-147 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[146]); t_end[146] =  spawn_function(); } // 147
		if(NSERIAL-148 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[147]); t_end[147] =  spawn_function(); } // 148

		if(NSERIAL-149 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[148]); t_end[148] =  spawn_function(); } // 149
		if(NSERIAL-150 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[149]); t_end[149] =  spawn_function(); } // 150

		if(NSERIAL-151 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[150]); t_end[150] =  spawn_function(); } // 151
		if(NSERIAL-152 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[151]); t_end[151] =  spawn_function(); } // 152
		if(NSERIAL-153 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[152]); t_end[152] =  spawn_function(); } // 153
		if(NSERIAL-154 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[153]); t_end[153] =  spawn_function(); } // 154

		if(NSERIAL-155 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[154]); t_end[154] =  spawn_function(); } // 155
		if(NSERIAL-156 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[155]); t_end[155] =  spawn_function(); } // 156
		if(NSERIAL-157 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[156]); t_end[156] =  spawn_function(); } // 157
		if(NSERIAL-158 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[157]); t_end[157] =  spawn_function(); } // 158

		if(NSERIAL-159 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[158]); t_end[158] =  spawn_function(); } // 159
		if(NSERIAL-160 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[159]); t_end[159] =  spawn_function(); } // 160

		if(NSERIAL-161 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[160]); t_end[160] =  spawn_function(); } // 161
		if(NSERIAL-162 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[161]); t_end[161] =  spawn_function(); } // 162
		if(NSERIAL-163 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[162]); t_end[162] =  spawn_function(); } // 163
		if(NSERIAL-164 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[163]); t_end[163] =  spawn_function(); } // 164

		if(NSERIAL-165 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[164]); t_end[164] =  spawn_function(); } // 165
		if(NSERIAL-166 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[165]); t_end[165] =  spawn_function(); } // 166
		if(NSERIAL-167 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[166]); t_end[166] =  spawn_function(); } // 167
		if(NSERIAL-168 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[167]); t_end[167] =  spawn_function(); } // 168

		if(NSERIAL-169 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[168]); t_end[168] =  spawn_function(); } // 169
		if(NSERIAL-170 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[169]); t_end[169] =  spawn_function(); } // 170

		if(NSERIAL-171 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[170]); t_end[170] =  spawn_function(); } // 171
		if(NSERIAL-172 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[171]); t_end[171] =  spawn_function(); } // 172
		if(NSERIAL-173 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[172]); t_end[172] =  spawn_function(); } // 173
		if(NSERIAL-174 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[173]); t_end[173] =  spawn_function(); } // 174

		if(NSERIAL-175 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[174]); t_end[174] =  spawn_function(); } // 175
		if(NSERIAL-176 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[175]); t_end[175] =  spawn_function(); } // 176
		if(NSERIAL-177 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[176]); t_end[176] =  spawn_function(); } // 177
		if(NSERIAL-178 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[177]); t_end[177] =  spawn_function(); } // 178

		if(NSERIAL-179 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[178]); t_end[178] =  spawn_function(); } // 179
		if(NSERIAL-180 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[179]); t_end[179] =  spawn_function(); } // 180

		if(NSERIAL-181 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[180]); t_end[180] =  spawn_function(); } // 181
		if(NSERIAL-182 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[181]); t_end[181] =  spawn_function(); } // 182
		if(NSERIAL-183 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[182]); t_end[182] =  spawn_function(); } // 183
		if(NSERIAL-184 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[183]); t_end[183] =  spawn_function(); } // 184

		if(NSERIAL-185 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[184]); t_end[184] =  spawn_function(); } // 185
		if(NSERIAL-186 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[185]); t_end[185] =  spawn_function(); } // 186
		if(NSERIAL-187 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[186]); t_end[186] =  spawn_function(); } // 187
		if(NSERIAL-188 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[187]); t_end[187] =  spawn_function(); } // 188

		if(NSERIAL-189 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[188]); t_end[188] =  spawn_function(); } // 189
		if(NSERIAL-190 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[189]); t_end[189] =  spawn_function(); } // 190

		if(NSERIAL-191 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[190]); t_end[190] =  spawn_function(); } // 191
		if(NSERIAL-192 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[191]); t_end[191] =  spawn_function(); } // 192
		if(NSERIAL-193 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[192]); t_end[192] =  spawn_function(); } // 193
		if(NSERIAL-194 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[193]); t_end[193] =  spawn_function(); } // 194

		if(NSERIAL-195 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[194]); t_end[194] =  spawn_function(); } // 195
		if(NSERIAL-196 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[195]); t_end[195] =  spawn_function(); } // 196
		if(NSERIAL-197 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[196]); t_end[196] =  spawn_function(); } // 197
		if(NSERIAL-198 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[197]); t_end[197] =  spawn_function(); } // 198

		if(NSERIAL-199 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[198]); t_end[198] =  spawn_function(); } // 199
		if(NSERIAL-200 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[199]); t_end[199] =  spawn_function(); } // 200

		if(NSERIAL-201 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[200]); t_end[200] =  spawn_function(); } // 201
		if(NSERIAL-202 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[201]); t_end[201] =  spawn_function(); } // 202
		if(NSERIAL-203 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[202]); t_end[202] =  spawn_function(); } // 203
		if(NSERIAL-204 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[203]); t_end[203] =  spawn_function(); } // 204

		if(NSERIAL-205 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[204]); t_end[204] =  spawn_function(); } // 205
		if(NSERIAL-206 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[205]); t_end[205] =  spawn_function(); } // 206
		if(NSERIAL-207 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[206]); t_end[206] =  spawn_function(); } // 207
		if(NSERIAL-208 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[207]); t_end[207] =  spawn_function(); } // 208

		if(NSERIAL-209 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[208]); t_end[208] =  spawn_function(); } // 209
		if(NSERIAL-210 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[209]); t_end[209] =  spawn_function(); } // 210

		if(NSERIAL-211 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[210]); t_end[210] =  spawn_function(); } // 211
		if(NSERIAL-212 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[211]); t_end[211] =  spawn_function(); } // 212
		if(NSERIAL-213 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[212]); t_end[212] =  spawn_function(); } // 213
		if(NSERIAL-214 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[213]); t_end[213] =  spawn_function(); } // 214

		if(NSERIAL-215 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[214]); t_end[214] =  spawn_function(); } // 215
		if(NSERIAL-216 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[215]); t_end[215] =  spawn_function(); } // 216
		if(NSERIAL-217 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[216]); t_end[216] =  spawn_function(); } // 217
		if(NSERIAL-218 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[217]); t_end[217] =  spawn_function(); } // 218

		if(NSERIAL-219 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[218]); t_end[218] =  spawn_function(); } // 219
		if(NSERIAL-220 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[219]); t_end[219] =  spawn_function(); } // 220

		if(NSERIAL-221 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[220]); t_end[220] =  spawn_function(); } // 221
		if(NSERIAL-222 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[221]); t_end[221] =  spawn_function(); } // 222
		if(NSERIAL-223 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[222]); t_end[222] =  spawn_function(); } // 223
		if(NSERIAL-224 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[223]); t_end[223] =  spawn_function(); } // 224

		if(NSERIAL-225 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[224]); t_end[224] =  spawn_function(); } // 225
		if(NSERIAL-226 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[225]); t_end[225] =  spawn_function(); } // 226
		if(NSERIAL-227 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[226]); t_end[226] =  spawn_function(); } // 227
		if(NSERIAL-228 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[227]); t_end[227] =  spawn_function(); } // 228

		if(NSERIAL-229 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[228]); t_end[228] =  spawn_function(); } // 229
		if(NSERIAL-230 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[229]); t_end[229] =  spawn_function(); } // 230

		if(NSERIAL-231 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[230]); t_end[230] =  spawn_function(); } // 231
		if(NSERIAL-232 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[231]); t_end[231] =  spawn_function(); } // 232
		if(NSERIAL-233 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[232]); t_end[232] =  spawn_function(); } // 233
		if(NSERIAL-234 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[233]); t_end[233] =  spawn_function(); } // 234

		if(NSERIAL-235 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[234]); t_end[234] =  spawn_function(); } // 235
		if(NSERIAL-236 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[235]); t_end[235] =  spawn_function(); } // 236
		if(NSERIAL-237 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[236]); t_end[236] =  spawn_function(); } // 237
		if(NSERIAL-238 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[237]); t_end[237] =  spawn_function(); } // 238

		if(NSERIAL-239 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[238]); t_end[238] =  spawn_function(); } // 239
		if(NSERIAL-240 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[239]); t_end[239] =  spawn_function(); } // 240

		if(NSERIAL-241 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[240]); t_end[240] =  spawn_function(); } // 241
		if(NSERIAL-242 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[241]); t_end[241] =  spawn_function(); } // 242
		if(NSERIAL-243 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[242]); t_end[242] =  spawn_function(); } // 243
		if(NSERIAL-244 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[243]); t_end[243] =  spawn_function(); } // 244

		if(NSERIAL-245 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[244]); t_end[244] =  spawn_function(); } // 245
		if(NSERIAL-246 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[245]); t_end[245] =  spawn_function(); } // 246
		if(NSERIAL-247 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[246]); t_end[246] =  spawn_function(); } // 247
		if(NSERIAL-248 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[247]); t_end[247] =  spawn_function(); } // 248

		if(NSERIAL-249 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[248]); t_end[248] =  spawn_function(); } // 249
		if(NSERIAL-250 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[249]); t_end[249] =  spawn_function(); } // 250

		if(NSERIAL-251 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[250]); t_end[250] =  spawn_function(); } // 251
		if(NSERIAL-252 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[251]); t_end[251] =  spawn_function(); } // 252
		if(NSERIAL-253 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[252]); t_end[252] =  spawn_function(); } // 253
		if(NSERIAL-254 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[253]); t_end[253] =  spawn_function(); } // 254

		if(NSERIAL-255 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[254]); t_end[254] =  spawn_function(); } // 255
		if(NSERIAL-256 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[255]); t_end[255] =  spawn_function(); } // 256
		if(NSERIAL-257 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[256]); t_end[256] =  spawn_function(); } // 257
		if(NSERIAL-258 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[257]); t_end[257] =  spawn_function(); } // 258

		if(NSERIAL-259 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[258]); t_end[258] =  spawn_function(); } // 259
		if(NSERIAL-260 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[259]); t_end[259] =  spawn_function(); } // 260

		if(NSERIAL-261 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[260]); t_end[260] =  spawn_function(); } // 261
		if(NSERIAL-262 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[261]); t_end[261] =  spawn_function(); } // 262
		if(NSERIAL-263 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[262]); t_end[262] =  spawn_function(); } // 263
		if(NSERIAL-264 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[263]); t_end[263] =  spawn_function(); } // 264

		if(NSERIAL-265 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[264]); t_end[264] =  spawn_function(); } // 265
		if(NSERIAL-266 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[265]); t_end[265] =  spawn_function(); } // 266
		if(NSERIAL-267 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[266]); t_end[266] =  spawn_function(); } // 267
		if(NSERIAL-268 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[267]); t_end[267] =  spawn_function(); } // 268

		if(NSERIAL-269 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[268]); t_end[268] =  spawn_function(); } // 269
		if(NSERIAL-270 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[269]); t_end[269] =  spawn_function(); } // 270

		if(NSERIAL-271 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[270]); t_end[270] =  spawn_function(); } // 271
		if(NSERIAL-272 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[271]); t_end[271] =  spawn_function(); } // 272
		if(NSERIAL-273 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[272]); t_end[272] =  spawn_function(); } // 273
		if(NSERIAL-274 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[273]); t_end[273] =  spawn_function(); } // 274

		if(NSERIAL-275 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[274]); t_end[274] =  spawn_function(); } // 275
		if(NSERIAL-276 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[275]); t_end[275] =  spawn_function(); } // 276
		if(NSERIAL-277 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[276]); t_end[276] =  spawn_function(); } // 277
		if(NSERIAL-278 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[277]); t_end[277] =  spawn_function(); } // 278

		if(NSERIAL-279 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[278]); t_end[278] =  spawn_function(); } // 279
		if(NSERIAL-280 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[279]); t_end[279] =  spawn_function(); } // 280

		if(NSERIAL-281 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[280]); t_end[280] =  spawn_function(); } // 281
		if(NSERIAL-282 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[281]); t_end[281] =  spawn_function(); } // 282
		if(NSERIAL-283 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[282]); t_end[282] =  spawn_function(); } // 283
		if(NSERIAL-284 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[283]); t_end[283] =  spawn_function(); } // 284

		if(NSERIAL-285 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[284]); t_end[284] =  spawn_function(); } // 285
		if(NSERIAL-286 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[285]); t_end[285] =  spawn_function(); } // 286
		if(NSERIAL-287 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[286]); t_end[286] =  spawn_function(); } // 287
		if(NSERIAL-288 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[287]); t_end[287] =  spawn_function(); } // 288

		if(NSERIAL-289 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[288]); t_end[288] =  spawn_function(); } // 289
		if(NSERIAL-290 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[289]); t_end[289] =  spawn_function(); } // 290

		if(NSERIAL-291 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[290]); t_end[290] =  spawn_function(); } // 291
		if(NSERIAL-292 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[291]); t_end[291] =  spawn_function(); } // 292
		if(NSERIAL-293 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[292]); t_end[292] =  spawn_function(); } // 293
		if(NSERIAL-294 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[293]); t_end[293] =  spawn_function(); } // 294

		if(NSERIAL-295 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[294]); t_end[294] =  spawn_function(); } // 295
		if(NSERIAL-296 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[295]); t_end[295] =  spawn_function(); } // 296
		if(NSERIAL-297 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[296]); t_end[296] =  spawn_function(); } // 297
		if(NSERIAL-298 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[297]); t_end[297] =  spawn_function(); } // 298

		if(NSERIAL-299 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[298]); t_end[298] =  spawn_function(); } // 299
		if(NSERIAL-300 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[299]); t_end[299] =  spawn_function(); } // 300

		if(NSERIAL-301 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_start[300]); t_end[300] =  spawn_function(); }// 301

	printf("****\n");	
	for(int i = 0; i < NSERIAL; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}

	// printf("04A\n");
	
	return 0;
}