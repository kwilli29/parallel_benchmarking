#!/bin/sh

make all

EXECS=$(ls -p | grep -v / | grep -E '*_pthreads$')

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

#echo "2 threads, >= 1 core" >> output/for_pthreads_N.txt
#./forypthreads 2 >> output/for_pthreads_N.txt

#./forcnt_pthreads
#./whilespawn_norace_pthreads 
#./whilespawn_pthreads
#./sum_pthreads
#./loopcnt_pthreads
#./loopspawn_norace_pthreads
#./spawntree_pthreads
#./loopspawn_pthreads
#./for_pthreads

make clean
