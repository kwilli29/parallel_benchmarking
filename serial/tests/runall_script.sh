#!/bin/sh

make all

EXECS=$(ls -p | grep -v / | grep -E '*_serial$')

#for file in sample/*; do
#    echo "$(basename "$file")"
#done

for v in $EXECS; do
	echo $v
done

res=1

for var in $EXECS; do
	echo $(basename "$var")
	echo "serial -- == $res core" >> output/$(basename "$var")_N.txt
	./$var >> output/$(basename "$var")_N.txt
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
