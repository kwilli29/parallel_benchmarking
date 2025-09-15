#!/bin/sh

make all

EXECS=$(ls -p | grep -v / | grep -E '^.*_cilk$')

THPCORE=4
THREADS=(256 260 264 268 272 280 288 296 300 340 380 420 480 520 544 600 640 700 740 800 840 900 940 1000)

RUNS=100

#for file in sample/*; do
#    echo "$(basename "$file")"
#done

#for v in $EXECS; do
#	echo $v
#done

for var in $EXECS; do
	for num in "${THREADS[@]}"; do
		touch "output/run3/$(basename "$var")/$(basename "$var")_$num.txt"
		for (( i=0; i<$RUNS; i++ )); do
			# echo $(basename "$var")
			if (($num/$THPCORE == 0)); then
				res=1
			else
  				res=$(($num/$THPCORE))
			fi
			echo "$num threads -- >= $res core" >> output/run3/$(basename "$var")/$(basename "$var")_$num.txt
			./$var $num >> output/run3/$(basename "$var")/$(basename "$var")_$num.txt
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
