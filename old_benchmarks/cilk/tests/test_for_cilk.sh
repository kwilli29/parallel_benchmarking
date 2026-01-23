#!/bin/sh

echo "2 threads, >= 1 core" >> output/for_cilk_N.txt
./for_cilk 2 >> output/for_cilk_N.txt

 echo "4 threads, >= 1 core" >> output/for_cilk_N.txt
./for_cilk 4 >> output/for_cilk_N.txt

echo "8 threads, >= 2 cores" >> output/for_cilk_N.txt
./for_cilk 8 >> output/for_cilk_N.txt

echo "16 threads, >= 4 cores" >> output/for_cilk_N.txt
./for_cilk 16 >> output/for_cilk_N.txt

echo "32 threads, >= 8 cores" >> output/for_cilk_N.txt
./for_cilk 32 >> output/for_cilk_N.txt 

echo "64 threads, >= 16 cores" >> output/for_cilk_N.txt
./for_cilk 64 >> output/for_cilk_N.txt

echo "128 threads, >= 32 cores" >> output/for_cilk_N.txt
./for_cilk 128 >> output/for_cilk_N.txt

echo "256 threads, >= 64 cores" >> output/for_cilk_N.txt
./for_cilk 256 >> output/for_cilk_N.txt

echo "272 threads, all threads in all cores" >> output/for_cilk_N.txt
./for_cilk 272 >> output/for_cilk_N.txt

