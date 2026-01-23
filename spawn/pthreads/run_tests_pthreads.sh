#!/bin/sh

make build

RUNS=10

for ((i=0;i< $RUNS;i++)); 
do 
   ./test_pthreads.sh >> pthreads_test_000.txt # 
done

# ./test_cilk.sh > cilk_test_000.txt


make clean
