#!/bin/sh

make all

EXECS=$(ls -p | grep -v / | grep -E '^.*_cilk$')

THPCORE=4

# Threads = # cilk_for iterations in this case

#THREADS=(256 260 264 268 272 280 288 296 300 340 380 420 480 520 544 600 640 700 740 800 840 900 940 1000 1500 2000 2048 2500 3000 3500 4000)
THREADS=(1 2 4 8 16 64 128 256 272)
PRAGMAS=(1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16000 16384)
# (# cilk_for iterations / grain size ) = # of chunks 
# grain size = size of the serial chunks

RUNS=10

for v in $EXECS; do
	echo $v
done

for var in $EXECS; do
	for num in "${THREADS[@]}"; do
		touch "output/run1/$(basename "$var")/$(basename "$var")_t$num+p$grs.txt"
		for prag in "${PRAGMAS[@]}"; do
			grs=$prag #$(( prag <= num ? prag : num ))
			for (( i=0; i<$RUNS; i++ )); do
				# echo $(basename "$var")
				echo "thread: $num, pragma: $grs"
				if (($num/$THPCORE == 0)); then
					res=1
				else
  					res=$(($num/$THPCORE))
				fi
				echo "$num threads -- >= $res core" >> output/run1/$(basename "$var")/$(basename "$var")_t$num+p$grs.txt
				./$var $num $grs >> output/run1/$(basename "$var")/$(basename "$var")_t$num+p$grs.txt
			done
			echo "$(basename "$var") thread $num done"
		done
	done
	echo "$(basename "$var") done"
done

make clean
