#!/bin/sh

make doozy

ITERATIONS=(4 8 12 16 20 24 28 32 36 40)
THREADS=(4 8)
#THREADS=(2 4 8 16 32 48 64 128 256 512 1000 1024 2048 16000)

RUNS=5

for th in "${THREADS[@]}"; do
    for num in "${ITERATIONS[@]}"; do
        touch "output/run1/doozy_${th}_$num.txt"
        for (( i=0; i<$RUNS; i++ )); do
            # echo $(basename "$var")
            echo "$num iters" >> output/run1/doozy_${th}_$num.txt
            NCILKWORKERS=$th ./doozy $num >> output/run1/doozy_${th}_$num.txt
        done
        echo "thread $num done"
    done
    echo "done"
done

# echo "2 threads, >= 1 core" >> output/for_cilk_N.txt

make clean


BDIR=$(ls -p output/run1/ | grep -v /)
echo $BDIR
for bnchmrk in $BDIR; do
    echo "add output/run1/$bnchmrk to sheet"
    python3 ./read2csv.py output/run1/$bnchmrk
done
