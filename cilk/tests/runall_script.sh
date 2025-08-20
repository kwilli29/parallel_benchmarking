#!/bin/sh

make all

EXECS=$(ls -p | grep -v / | grep -E '*_cilk$')

THPCORE=4
THREADS=(2 4 8 16 32 64 128 256 272)

#for file in sample/*; do
#    echo "$(basename "$file")"
#done

for v in $EXECS; do
	echo $v
done

for var in $EXECS; do
	for num in "${THREADS[@]}"; do
		echo $(basename "$var")
		if (($num/$THPCORE == 0)); then
			res=1
		else
  			res=$(($num/$THPCORE))
		fi
		echo "$num threads -- >= $res core" >> output/$(basename "$var")_N.txt
		./$var $num >> output/$(basename "$var")_N.txt
	done
done

#echo "2 threads, >= 1 core" >> output/for_cilk_N.txt
#./for_cilk 2 >> output/for_cilk_N.txt

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
