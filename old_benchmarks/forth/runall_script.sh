#!/bin/sh

make fib

ITERATIONS=(36)
THREADS=(2 4 8 16 32 48 64 128 256 512 1000 1024 2048 16000)

RUNS=5

for th in "${THREADS[@]}"; do
    for num in "${ITERATIONS[@]}"; do
        touch "output/frun0/fib_${th}_$num.txt"
        for (( i=0; i<$RUNS; i++ )); do
            # echo $(basename "$var")
            echo "$num iters" >> output/frun0/fib_${th}_$num.txt
            NCILKWORKERS=$th ./fib $num >> output/frun0/fib_${th}_$num.txt
        done
        echo "thread $num done"
    done
    echo "done"
done

# echo "2 threads, >= 1 core" >> output/for_cilk_N.txt

make clean


BDIR=$(ls -p output/frun0/ | grep -v /)
echo $BDIR
for bnchmrk in $BDIR; do
    echo "add output/frun0/$bnchmrk to sheet"
    python3 ./read2csv.py output/frun0/$bnchmrk
done
