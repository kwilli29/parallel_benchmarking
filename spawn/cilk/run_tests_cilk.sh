#!/bin/sh

make build

RUNS=10

for ((i=0;i< $RUNS;i++)); 
do 
   ./test_cilk.sh >> cilk_test_000.csv # 
done

# ./test_cilk.sh > cilk_test_000.csv


make clean
