#!/bin/sh

make all

EXECS=$(ls -p | grep -v / | grep -E '^.*_cilk$')

THPCORE=10
THREADS=(2 4 8 16 32 48 64 128 256 512 1000 1024 2048 16000)

RUNS=10

#for file in sample/*; do
#    echo "$(basename "$file")"
#done

#for v in $EXECS; do
#	echo $v
#done

for var in $EXECS; do
	for num in "${THREADS[@]}"; do
		touch "output/run4/$(basename "$var")/$(basename "$var")_$num.txt"
		for (( i=0; i<$RUNS; i++ )); do
			# echo $(basename "$var")
			if (($num/$THPCORE == 0)); then
				res=1
			else
  				res=$(($num/$THPCORE))
			fi
			echo "$num threads -- >= $res core" >> output/run4/$(basename "$var")/$(basename "$var")_$num.txt
			./$var $num >> output/run4/$(basename "$var")/$(basename "$var")_$num.txt
		done
		echo "$(basename "$var") thread $num done"
	done
	echo "$(basename "$var") done"
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
