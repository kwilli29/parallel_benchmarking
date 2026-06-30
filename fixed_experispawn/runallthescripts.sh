#!/bin/bash

ARCH=$1

cd cilk
./runall_cilk.sh 32 $ARCH slow 100 gettimeofday
./runall_cilk.sh 272 $ARCH slow 100 gettimeofday
cd ..

cd openmp
./runall_openmp.sh 32 $ARCH slow 100 gettimeofday
./runall_openmp.sh 272 $ARCH slow 100 gettimeofday
cd ..

cd pthreads
./runall_pthreads.sh 32 $ARCH slow 100 gettimeofday
./runall_pthreads.sh 272 $ARCH slow 100 gettimeofday
cd ..

cd serial
./runall_serial.sh 32 $ARCH slow 100 gettimeofday
./runall_serial.sh 272 $ARCH slow 100 gettimeofday
cd ..