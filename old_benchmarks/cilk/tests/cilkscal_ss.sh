#!/bin/sh

make all

EXECS=$(ls -p | grep -v / | grep -E '*_cilk$')

#THREADS=(2 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72 76 80 84 88 92 96 100 104 108 112 116 120 124 128 132 136 140 144 148 152 156 160 164 168 172 176 180 184 188 192 196 200 204 208 212 216 220 224 228 232 236 240 244 248 252 256 260 264 268 272)

ARR=(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68)


#for file in sample/*; do
#    echo "$(basename "$file")"
#done

for var in $EXECS; do
	echo "$var"
done

CNT=1

for var in $EXECS; do

	python3 /opt/opencilk-2/share/Cilkscale_vis/cilkscale.py -c ./"$var" -b ./"$var"_b -ocsv output/cs_run1/"$var".csv -oplot output/cs_run1/"$var".pdf
	

	echo "$var done"
done


make clean
