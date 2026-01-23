#!/bin/sh

make all

EXECS=$(ls -p | grep -v / | grep -E '*_pthreads$')

THPCORE=1
THREADS=(2 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72 76 80 84 88 92 96 100 104 108 112 116 120 124 128 132 136 140 144 148 152 156 160 164 168 172 176 180 184 188 192 196 200 204 208 212 216 220 224 228 232 236 240 244 248 252 256 260 264 268 272)

RUNS=100

#for file in sample/*; do
#    echo "$(basename "$file")"
#done

for v in $EXECS; do
	echo $v
done

for var in $EXECS; do
	for num in "${THREADS[@]}"; do
		touch "output/run1/$(basename "$var")/$(basename "$var")_$num.txt"
		for (( i=0; i<$RUNS; i++ )); do
			# echo $(basename "$var")
			if (($num/$THPCORE == 0)); then
				res=1
			else
  				res=$(($num/$THPCORE))
			fi
			echo "$num threads -- >= $res core" >> output/run1/$(basename "$var")/$(basename "$var")_$num.txt
			./$var $num >> output/run1/$(basename "$var")/$(basename "$var")_$num.txt
		done
		echo "$(basename "$var") thread $num done"
	done
	echo "$(basename "$var") done"
done

#echo "2 threads, >= 1 core" >> utput/for_cilk_N.txt
#./for_cilk 2 >> utput/for_cilk_N.txt

#./forcnt_cilk
#./fib_cilk
#./whilespawn_norace_cilk 
#./whilespawn_cilk
#./sum_cilk 
#./loopcnt_cilk
#./loopspawn_norace_cilk
#./cilkspawntree
#./loopspawn_cilk
#./for_cilk

make clean
