#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

/* Benchmark: 02A: Spawn time before ; Sequential Spawns (Cilk)
 * Launch a bunch and measure when all done
 */


void spawn_function(){           // Simple Function to Spawn

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

	printf("# Spawns: %d\n", NCILK);

	struct timespec t_start, t_res;
	struct timespec t_end[NCILK];
	clock_gettime(CLOCK_MONOTONIC, &t_start); //

	// sequentially spawn functions

		if(NCILK-1 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[0]); cilk_spawn spawn_function(); } // 1 // Take time stamp before each spawn
		if(NCILK-2 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[1]); cilk_spawn spawn_function(); } // 2
		if(NCILK-3 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[2]); cilk_spawn spawn_function(); } // 3
		if(NCILK-4 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[3]); cilk_spawn spawn_function(); } // 4

		if(NCILK-5 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[4]); cilk_spawn spawn_function(); } // 5
		if(NCILK-6 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[5]); cilk_spawn spawn_function(); } // 6
		if(NCILK-7 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[6]); cilk_spawn spawn_function(); } // 7
		if(NCILK-8 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[7]); cilk_spawn spawn_function(); } // 8
		if(NCILK-9 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[8]); cilk_spawn spawn_function(); } // 9
		if(NCILK-10 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[9]); cilk_spawn spawn_function(); } // 10

		if(NCILK-11 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[10]); cilk_spawn spawn_function(); } // 11
		if(NCILK-12 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[11]); cilk_spawn spawn_function(); } // 12
		if(NCILK-13 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[12]); cilk_spawn spawn_function(); } // 13
		if(NCILK-14 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[13]); cilk_spawn spawn_function(); } // 14

		if(NCILK-15 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[14]); cilk_spawn spawn_function(); } // 15
		if(NCILK-16 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[15]); cilk_spawn spawn_function(); } // 16
		if(NCILK-17 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[16]); cilk_spawn spawn_function(); } // 17
		if(NCILK-18 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[17]); cilk_spawn spawn_function(); } // 18

		if(NCILK-19 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[18]); cilk_spawn spawn_function(); } // 19
		if(NCILK-20 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[19]); cilk_spawn spawn_function(); } // 20

		if(NCILK-21 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[20]); cilk_spawn spawn_function(); } // 21
		if(NCILK-22 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[21]); cilk_spawn spawn_function(); } // 22
		if(NCILK-23 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[22]); cilk_spawn spawn_function(); } // 23
		if(NCILK-24 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[23]); cilk_spawn spawn_function(); } // 24

		if(NCILK-25 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[24]); cilk_spawn spawn_function(); } // 25
		if(NCILK-26 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[25]); cilk_spawn spawn_function(); } // 26
		if(NCILK-27 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[26]); cilk_spawn spawn_function(); } // 27
		if(NCILK-28 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[27]); cilk_spawn spawn_function(); } // 28

		if(NCILK-29 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[28]); cilk_spawn spawn_function(); } // 29
		if(NCILK-30 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[29]); cilk_spawn spawn_function(); } // 30

		if(NCILK-31 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[30]); cilk_spawn spawn_function(); } // 31
		if(NCILK-32 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[31]); cilk_spawn spawn_function(); } // 32
		if(NCILK-33 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[32]); cilk_spawn spawn_function(); } // 33
		if(NCILK-34 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[33]); cilk_spawn spawn_function(); } // 34

		if(NCILK-35 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[34]); cilk_spawn spawn_function(); } // 35
		if(NCILK-36 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[35]); cilk_spawn spawn_function(); } // 36
		if(NCILK-37 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[36]); cilk_spawn spawn_function(); } // 37
		if(NCILK-38 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[37]); cilk_spawn spawn_function(); } // 38

		if(NCILK-39 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[38]); cilk_spawn spawn_function(); } // 39
		if(NCILK-40 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[39]); cilk_spawn spawn_function(); } // 40

		if(NCILK-41 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[40]); cilk_spawn spawn_function(); } // 41
		if(NCILK-42 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[41]); cilk_spawn spawn_function(); } // 42
		if(NCILK-43 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[42]); cilk_spawn spawn_function(); } // 43
		if(NCILK-44 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[43]); cilk_spawn spawn_function(); } // 44

		if(NCILK-45 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[44]); cilk_spawn spawn_function(); } // 45
		if(NCILK-46 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[45]); cilk_spawn spawn_function(); } // 46
		if(NCILK-47 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[46]); cilk_spawn spawn_function(); } // 47
		if(NCILK-48 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[47]); cilk_spawn spawn_function(); } // 48

		if(NCILK-49 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[48]); cilk_spawn spawn_function(); } // 49
		if(NCILK-50 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[49]); cilk_spawn spawn_function(); } // 50

		if(NCILK-51 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[50]); cilk_spawn spawn_function(); } // 51
		if(NCILK-52 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[51]); cilk_spawn spawn_function(); } // 52
		if(NCILK-53 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[52]); cilk_spawn spawn_function(); } // 53
		if(NCILK-54 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[53]); cilk_spawn spawn_function(); } // 54

		if(NCILK-55 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[54]); cilk_spawn spawn_function(); } // 55
		if(NCILK-56 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[55]); cilk_spawn spawn_function(); } // 56
		if(NCILK-57 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[56]); cilk_spawn spawn_function(); } // 57
		if(NCILK-58 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[57]); cilk_spawn spawn_function(); } // 58

		if(NCILK-59 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[58]); cilk_spawn spawn_function(); } // 59
		if(NCILK-60 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[59]); cilk_spawn spawn_function(); } // 60

		if(NCILK-61 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[60]); cilk_spawn spawn_function(); } // 61
		if(NCILK-62 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[61]); cilk_spawn spawn_function(); } // 62
		if(NCILK-63 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[62]); cilk_spawn spawn_function(); } // 63
		if(NCILK-64 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[63]); cilk_spawn spawn_function(); } // 64

		if(NCILK-65 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[64]); cilk_spawn spawn_function(); } // 65
		if(NCILK-66 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[65]); cilk_spawn spawn_function(); } // 66
		if(NCILK-66 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[66]); cilk_spawn spawn_function(); } // 66
		if(NCILK-68 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[67]); cilk_spawn spawn_function(); } // 68

		if(NCILK-69 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[68]); cilk_spawn spawn_function(); } // 69
		if(NCILK-70 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[69]); cilk_spawn spawn_function(); } // 70

		if(NCILK-71 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[70]); cilk_spawn spawn_function(); } // 71
		if(NCILK-72 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[71]); cilk_spawn spawn_function(); } // 72
		if(NCILK-73 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[72]); cilk_spawn spawn_function(); } // 73
		if(NCILK-74 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[73]); cilk_spawn spawn_function(); } // 74

		if(NCILK-75 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[74]); cilk_spawn spawn_function(); } // 75
		if(NCILK-76 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[75]); cilk_spawn spawn_function(); } // 76
		if(NCILK-77 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[76]); cilk_spawn spawn_function(); } // 77
		if(NCILK-78 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[77]); cilk_spawn spawn_function(); } // 78

		if(NCILK-79 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[78]); cilk_spawn spawn_function(); } // 79
		if(NCILK-80 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[79]); cilk_spawn spawn_function(); } // 80

		if(NCILK-81 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[80]); cilk_spawn spawn_function(); } // 81
		if(NCILK-82 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[81]); cilk_spawn spawn_function(); } // 82
		if(NCILK-83 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[82]); cilk_spawn spawn_function(); } // 83
		if(NCILK-84 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[83]); cilk_spawn spawn_function(); } // 84

		if(NCILK-85 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[84]); cilk_spawn spawn_function(); } // 85
		if(NCILK-86 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[85]); cilk_spawn spawn_function(); } // 86
		if(NCILK-87 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[86]); cilk_spawn spawn_function(); } // 87
		if(NCILK-88 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[87]); cilk_spawn spawn_function(); } // 88

		if(NCILK-89 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[88]); cilk_spawn spawn_function(); } // 89
		if(NCILK-90 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[89]); cilk_spawn spawn_function(); } // 90

		if(NCILK-91 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[90]); cilk_spawn spawn_function(); } // 91
		if(NCILK-92 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[91]); cilk_spawn spawn_function(); } // 92
		if(NCILK-93 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[92]); cilk_spawn spawn_function(); } // 93
		if(NCILK-94 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[93]); cilk_spawn spawn_function(); } // 94

		if(NCILK-95 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[94]); cilk_spawn spawn_function(); } // 95
		if(NCILK-96 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[95]); cilk_spawn spawn_function(); } // 96
		if(NCILK-97 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[96]); cilk_spawn spawn_function(); } // 97
		if(NCILK-98 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[97]); cilk_spawn spawn_function(); } // 98

		if(NCILK-99 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[98]); cilk_spawn spawn_function(); } // 99
		if(NCILK-100 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[99]); cilk_spawn spawn_function(); } // 100

		if(NCILK-101 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[100]); cilk_spawn spawn_function(); } // 101
		if(NCILK-102 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[101]); cilk_spawn spawn_function(); } // 102
		if(NCILK-103 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[102]); cilk_spawn spawn_function(); } // 103
		if(NCILK-104 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[103]); cilk_spawn spawn_function(); } // 104

		if(NCILK-105 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[104]); cilk_spawn spawn_function(); } // 105
		if(NCILK-106 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[105]); cilk_spawn spawn_function(); } // 106
		if(NCILK-107 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[106]); cilk_spawn spawn_function(); } // 107
		if(NCILK-108 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[107]); cilk_spawn spawn_function(); } // 108

		if(NCILK-109 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[108]); cilk_spawn spawn_function(); } // 109
		if(NCILK-110 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[109]); cilk_spawn spawn_function(); } // 110

		if(NCILK-111 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[110]); cilk_spawn spawn_function(); } // 111
		if(NCILK-112 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[111]); cilk_spawn spawn_function(); } // 112
		if(NCILK-113 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[112]); cilk_spawn spawn_function(); } // 113
		if(NCILK-114 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[113]); cilk_spawn spawn_function(); } // 114

		if(NCILK-115 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[114]); cilk_spawn spawn_function(); } // 115
		if(NCILK-116 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[115]); cilk_spawn spawn_function(); } // 116
		if(NCILK-117 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[116]); cilk_spawn spawn_function(); } // 117
		if(NCILK-118 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[117]); cilk_spawn spawn_function(); } // 118

		if(NCILK-119 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[118]); cilk_spawn spawn_function(); } // 119
		if(NCILK-120 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[119]); cilk_spawn spawn_function(); } // 120

		if(NCILK-121 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[120]); cilk_spawn spawn_function(); } // 121
		if(NCILK-122 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[121]); cilk_spawn spawn_function(); } // 122
		if(NCILK-123 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[122]); cilk_spawn spawn_function(); } // 123
		if(NCILK-124 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[123]); cilk_spawn spawn_function(); } // 124

		if(NCILK-125 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[124]); cilk_spawn spawn_function(); } // 125
		if(NCILK-126 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[125]); cilk_spawn spawn_function(); } // 126
		if(NCILK-127 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[126]); cilk_spawn spawn_function(); } // 127
		if(NCILK-128 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[127]); cilk_spawn spawn_function(); } // 128

		if(NCILK-129 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[128]); cilk_spawn spawn_function(); } // 129
		if(NCILK-130 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[129]); cilk_spawn spawn_function(); } // 130

		if(NCILK-131 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[130]); cilk_spawn spawn_function(); } // 131
		if(NCILK-132 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[131]); cilk_spawn spawn_function(); } // 132
		if(NCILK-133 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[132]); cilk_spawn spawn_function(); } // 133
		if(NCILK-134 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[133]); cilk_spawn spawn_function(); } // 134

		if(NCILK-135 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[134]); cilk_spawn spawn_function(); } // 135
		if(NCILK-136 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[135]); cilk_spawn spawn_function(); } // 136
		if(NCILK-137 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[136]); cilk_spawn spawn_function(); } // 137
		if(NCILK-138 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[137]); cilk_spawn spawn_function(); } // 138

		if(NCILK-139 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[138]); cilk_spawn spawn_function(); } // 139
		if(NCILK-140 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[139]); cilk_spawn spawn_function(); } // 140

		if(NCILK-141 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[140]); cilk_spawn spawn_function(); } // 141
		if(NCILK-142 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[141]); cilk_spawn spawn_function(); } // 142
		if(NCILK-143 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[142]); cilk_spawn spawn_function(); } // 143
		if(NCILK-144 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[143]); cilk_spawn spawn_function(); } // 144

		if(NCILK-145 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[144]); cilk_spawn spawn_function(); } // 145
		if(NCILK-146 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[145]); cilk_spawn spawn_function(); } // 146
		if(NCILK-147 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[146]); cilk_spawn spawn_function(); } // 147
		if(NCILK-148 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[147]); cilk_spawn spawn_function(); } // 148

		if(NCILK-149 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[148]); cilk_spawn spawn_function(); } // 149
		if(NCILK-150 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[149]); cilk_spawn spawn_function(); } // 150

		if(NCILK-151 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[150]); cilk_spawn spawn_function(); } // 151
		if(NCILK-152 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[151]); cilk_spawn spawn_function(); } // 152
		if(NCILK-153 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[152]); cilk_spawn spawn_function(); } // 153
		if(NCILK-154 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[153]); cilk_spawn spawn_function(); } // 154

		if(NCILK-155 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[154]); cilk_spawn spawn_function(); } // 155
		if(NCILK-156 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[155]); cilk_spawn spawn_function(); } // 156
		if(NCILK-157 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[156]); cilk_spawn spawn_function(); } // 157
		if(NCILK-158 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[157]); cilk_spawn spawn_function(); } // 158

		if(NCILK-159 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[158]); cilk_spawn spawn_function(); } // 159
		if(NCILK-160 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[159]); cilk_spawn spawn_function(); } // 160

		if(NCILK-161 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[160]); cilk_spawn spawn_function(); } // 161
		if(NCILK-162 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[161]); cilk_spawn spawn_function(); } // 162
		if(NCILK-163 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[162]); cilk_spawn spawn_function(); } // 163
		if(NCILK-164 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[163]); cilk_spawn spawn_function(); } // 164

		if(NCILK-165 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[164]); cilk_spawn spawn_function(); } // 165
		if(NCILK-166 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[165]); cilk_spawn spawn_function(); } // 166
		if(NCILK-167 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[166]); cilk_spawn spawn_function(); } // 167
		if(NCILK-168 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[167]); cilk_spawn spawn_function(); } // 168

		if(NCILK-169 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[168]); cilk_spawn spawn_function(); } // 169
		if(NCILK-170 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[169]); cilk_spawn spawn_function(); } // 170

		if(NCILK-171 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[170]); cilk_spawn spawn_function(); } // 171
		if(NCILK-172 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[171]); cilk_spawn spawn_function(); } // 172
		if(NCILK-173 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[172]); cilk_spawn spawn_function(); } // 173
		if(NCILK-174 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[173]); cilk_spawn spawn_function(); } // 174

		if(NCILK-175 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[174]); cilk_spawn spawn_function(); } // 175
		if(NCILK-176 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[175]); cilk_spawn spawn_function(); } // 176
		if(NCILK-177 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[176]); cilk_spawn spawn_function(); } // 177
		if(NCILK-178 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[177]); cilk_spawn spawn_function(); } // 178

		if(NCILK-179 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[178]); cilk_spawn spawn_function(); } // 179
		if(NCILK-180 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[179]); cilk_spawn spawn_function(); } // 180

		if(NCILK-181 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[180]); cilk_spawn spawn_function(); } // 181
		if(NCILK-182 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[181]); cilk_spawn spawn_function(); } // 182
		if(NCILK-183 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[182]); cilk_spawn spawn_function(); } // 183
		if(NCILK-184 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[183]); cilk_spawn spawn_function(); } // 184

		if(NCILK-185 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[184]); cilk_spawn spawn_function(); } // 185
		if(NCILK-186 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[185]); cilk_spawn spawn_function(); } // 186
		if(NCILK-187 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[186]); cilk_spawn spawn_function(); } // 187
		if(NCILK-188 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[187]); cilk_spawn spawn_function(); } // 188

		if(NCILK-189 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[188]); cilk_spawn spawn_function(); } // 189
		if(NCILK-190 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[189]); cilk_spawn spawn_function(); } // 190

		if(NCILK-191 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[190]); cilk_spawn spawn_function(); } // 191
		if(NCILK-192 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[191]); cilk_spawn spawn_function(); } // 192
		if(NCILK-193 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[192]); cilk_spawn spawn_function(); } // 193
		if(NCILK-194 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[193]); cilk_spawn spawn_function(); } // 194

		if(NCILK-195 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[194]); cilk_spawn spawn_function(); } // 195
		if(NCILK-196 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[195]); cilk_spawn spawn_function(); } // 196
		if(NCILK-197 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[196]); cilk_spawn spawn_function(); } // 197
		if(NCILK-198 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[197]); cilk_spawn spawn_function(); } // 198

		if(NCILK-199 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[198]); cilk_spawn spawn_function(); } // 199
		if(NCILK-200 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[199]); cilk_spawn spawn_function(); } // 200

		if(NCILK-201 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[200]); cilk_spawn spawn_function(); } // 201
		if(NCILK-202 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[201]); cilk_spawn spawn_function(); } // 202
		if(NCILK-203 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[202]); cilk_spawn spawn_function(); } // 203
		if(NCILK-204 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[203]); cilk_spawn spawn_function(); } // 204

		if(NCILK-205 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[204]); cilk_spawn spawn_function(); } // 205
		if(NCILK-206 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[205]); cilk_spawn spawn_function(); } // 206
		if(NCILK-207 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[206]); cilk_spawn spawn_function(); } // 207
		if(NCILK-208 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[207]); cilk_spawn spawn_function(); } // 208

		if(NCILK-209 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[208]); cilk_spawn spawn_function(); } // 209
		if(NCILK-210 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[209]); cilk_spawn spawn_function(); } // 210

		if(NCILK-211 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[210]); cilk_spawn spawn_function(); } // 211
		if(NCILK-212 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[211]); cilk_spawn spawn_function(); } // 212
		if(NCILK-213 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[212]); cilk_spawn spawn_function(); } // 213
		if(NCILK-214 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[213]); cilk_spawn spawn_function(); } // 214

		if(NCILK-215 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[214]); cilk_spawn spawn_function(); } // 215
		if(NCILK-216 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[215]); cilk_spawn spawn_function(); } // 216
		if(NCILK-217 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[216]); cilk_spawn spawn_function(); } // 217
		if(NCILK-218 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[217]); cilk_spawn spawn_function(); } // 218

		if(NCILK-219 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[218]); cilk_spawn spawn_function(); } // 219
		if(NCILK-220 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[219]); cilk_spawn spawn_function(); } // 220

		if(NCILK-221 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[220]); cilk_spawn spawn_function(); } // 221
		if(NCILK-222 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[221]); cilk_spawn spawn_function(); } // 222
		if(NCILK-223 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[222]); cilk_spawn spawn_function(); } // 223
		if(NCILK-224 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[223]); cilk_spawn spawn_function(); } // 224

		if(NCILK-225 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[224]); cilk_spawn spawn_function(); } // 225
		if(NCILK-226 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[225]); cilk_spawn spawn_function(); } // 226
		if(NCILK-227 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[226]); cilk_spawn spawn_function(); } // 227
		if(NCILK-228 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[227]); cilk_spawn spawn_function(); } // 228

		if(NCILK-229 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[228]); cilk_spawn spawn_function(); } // 229
		if(NCILK-230 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[229]); cilk_spawn spawn_function(); } // 230

		if(NCILK-231 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[230]); cilk_spawn spawn_function(); } // 231
		if(NCILK-232 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[231]); cilk_spawn spawn_function(); } // 232
		if(NCILK-233 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[232]); cilk_spawn spawn_function(); } // 233
		if(NCILK-234 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[233]); cilk_spawn spawn_function(); } // 234

		if(NCILK-235 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[234]); cilk_spawn spawn_function(); } // 235
		if(NCILK-236 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[235]); cilk_spawn spawn_function(); } // 236
		if(NCILK-237 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[236]); cilk_spawn spawn_function(); } // 237
		if(NCILK-238 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[237]); cilk_spawn spawn_function(); } // 238

		if(NCILK-239 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[238]); cilk_spawn spawn_function(); } // 239
		if(NCILK-240 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[239]); cilk_spawn spawn_function(); } // 240

		if(NCILK-241 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[240]); cilk_spawn spawn_function(); } // 241
		if(NCILK-242 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[241]); cilk_spawn spawn_function(); } // 242
		if(NCILK-243 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[242]); cilk_spawn spawn_function(); } // 243
		if(NCILK-244 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[243]); cilk_spawn spawn_function(); } // 244

		if(NCILK-245 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[244]); cilk_spawn spawn_function(); } // 245
		if(NCILK-246 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[245]); cilk_spawn spawn_function(); } // 246
		if(NCILK-247 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[246]); cilk_spawn spawn_function(); } // 247
		if(NCILK-248 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[247]); cilk_spawn spawn_function(); } // 248

		if(NCILK-249 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[248]); cilk_spawn spawn_function(); } // 249
		if(NCILK-250 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[249]); cilk_spawn spawn_function(); } // 250

		if(NCILK-251 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[250]); cilk_spawn spawn_function(); } // 251
		if(NCILK-252 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[251]); cilk_spawn spawn_function(); } // 252
		if(NCILK-253 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[252]); cilk_spawn spawn_function(); } // 253
		if(NCILK-254 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[253]); cilk_spawn spawn_function(); } // 254

		if(NCILK-255 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[254]); cilk_spawn spawn_function(); } // 255
		if(NCILK-256 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[255]); cilk_spawn spawn_function(); } // 256
		if(NCILK-257 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[256]); cilk_spawn spawn_function(); } // 257
		if(NCILK-258 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[257]); cilk_spawn spawn_function(); } // 258

		if(NCILK-259 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[258]); cilk_spawn spawn_function(); } // 259
		if(NCILK-260 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[259]); cilk_spawn spawn_function(); } // 260

		if(NCILK-261 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[260]); cilk_spawn spawn_function(); } // 261
		if(NCILK-262 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[261]); cilk_spawn spawn_function(); } // 262
		if(NCILK-263 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[262]); cilk_spawn spawn_function(); } // 263
		if(NCILK-264 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[263]); cilk_spawn spawn_function(); } // 264

		if(NCILK-265 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[264]); cilk_spawn spawn_function(); } // 265
		if(NCILK-266 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[265]); cilk_spawn spawn_function(); } // 266
		if(NCILK-267 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[266]); cilk_spawn spawn_function(); } // 267
		if(NCILK-268 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[267]); cilk_spawn spawn_function(); } // 268

		if(NCILK-269 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[268]); cilk_spawn spawn_function(); } // 269
		if(NCILK-270 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[269]); cilk_spawn spawn_function(); } // 270

		if(NCILK-271 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[270]); cilk_spawn spawn_function(); } // 271
		if(NCILK-272 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[271]); cilk_spawn spawn_function(); } // 272
		if(NCILK-273 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[272]); cilk_spawn spawn_function(); } // 273
		if(NCILK-274 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[273]); cilk_spawn spawn_function(); } // 274

		if(NCILK-275 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[274]); cilk_spawn spawn_function(); } // 275
		if(NCILK-276 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[275]); cilk_spawn spawn_function(); } // 276
		if(NCILK-277 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[276]); cilk_spawn spawn_function(); } // 277
		if(NCILK-278 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[277]); cilk_spawn spawn_function(); } // 278

		if(NCILK-279 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[278]); cilk_spawn spawn_function(); } // 279
		if(NCILK-280 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[279]); cilk_spawn spawn_function(); } // 280

		if(NCILK-281 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[280]); cilk_spawn spawn_function(); } // 281
		if(NCILK-282 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[281]); cilk_spawn spawn_function(); } // 282
		if(NCILK-283 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[282]); cilk_spawn spawn_function(); } // 283
		if(NCILK-284 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[283]); cilk_spawn spawn_function(); } // 284

		if(NCILK-285 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[284]); cilk_spawn spawn_function(); } // 285
		if(NCILK-286 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[285]); cilk_spawn spawn_function(); } // 286
		if(NCILK-287 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[286]); cilk_spawn spawn_function(); } // 287
		if(NCILK-288 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[287]); cilk_spawn spawn_function(); } // 288

		if(NCILK-289 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[288]); cilk_spawn spawn_function(); } // 289
		if(NCILK-290 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[289]); cilk_spawn spawn_function(); } // 290

		if(NCILK-291 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[290]); cilk_spawn spawn_function(); } // 291
		if(NCILK-292 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[291]); cilk_spawn spawn_function(); } // 292
		if(NCILK-293 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[292]); cilk_spawn spawn_function(); } // 293
		if(NCILK-294 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[293]); cilk_spawn spawn_function(); } // 294

		if(NCILK-295 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[294]); cilk_spawn spawn_function(); } // 295
		if(NCILK-296 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[295]); cilk_spawn spawn_function(); } // 296
		if(NCILK-297 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[296]); cilk_spawn spawn_function(); } // 297
		if(NCILK-298 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[297]); cilk_spawn spawn_function(); } // 298

		if(NCILK-299 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[298]); cilk_spawn spawn_function(); } // 299
		if(NCILK-300 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[299]); cilk_spawn spawn_function(); } // 300

		if(NCILK-301 >= 0) { clock_gettime(CLOCK_MONOTONIC, &t_end[300]); cilk_spawn spawn_function(); }// 301 // 1 // Take time stamp before each spawn

    // end: // unused label 

	cilk_sync; 

	printf("****\n");
	for(int i = 0; i < NCILK; i++){
		
		timespec_sub(&t_res, t_end[i], t_start);

		printf("%ld.%09ld\n", (long)t_res.tv_sec, t_res.tv_nsec);
	
	}
	
	// printf("02A\n");
	
	return 0;
}



