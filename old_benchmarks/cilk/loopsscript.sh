#!/bin/sh

make all

./cilkfor-count_cilk
./reducersum_cilk
./while_glblcntr_race_cilk
./cilkfor_glblcntr_race_cilk
./cilkfor_cilk
./for-count_cilk
./fib_cilk
./spawntree_cilk
./cilkfor_glblcntr_norace_cilk
./while_glblcntr_norace_cilk

make clean
