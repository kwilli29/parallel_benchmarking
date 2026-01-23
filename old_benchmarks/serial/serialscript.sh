#!/bin/sh

make all

./sum_serial
./loopcnt_serial
./loopspawn_serial
./for_serial
./forcnt_serial
./fib_serial
./whilespawn_serial

make clean
