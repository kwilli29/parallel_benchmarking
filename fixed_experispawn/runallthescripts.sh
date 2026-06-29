#!/bin/bash

ARCH=$1

cd cilk
#./runall_cilk.sh 32 $ARCH slow 100 clock_gettime
./runall_cilk.sh 272 $ARCH slow 100 clock_gettime
cd ..

cd openmp
./runall_openmp.sh 32 $ARCH slow 100 clock_gettime
./runall_openmp.sh 272 $ARCH slow 100 clock_gettime
cd ..

cd pthreads
./runall_pthreads.sh 32 $ARCH slow 100 clock_gettime
./runall_pthreads.sh 272 $ARCH slow 100 clock_gettime
cd ..