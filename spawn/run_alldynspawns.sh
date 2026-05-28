#!/bin/bash


echo -e "******** Cilk Spawn Benchmarks ********"
cd cilk

    echo -e "\n**** 01: Total Time for All Spawns + Sync --> Cilk ****"
    make 1

    echo -e "\n01A: Sequential, #th = $1: "
    ./01A $1
    echo -e "\n01B: CilkScope, #th = $1: "
    ./01B $1
    echo -e "\n01C: ForLoop, #th = $1: "
    ./01C $1
    echo -e "\n01D: CilkFor, #th = $1: "
    ./01D $1
    echo -e "\n01E: Single Spawn"
    ./01E
    echo -e "\n01F: Single Spawn w/ integer argument"
    ./01F

    make clean
    
    echo -e "\n**** 02: Time from start to Before Each Spawn --> Cilk ****"
    make 2

    echo -e "\n02A: Sequential, #th = $1: "
    ./02A $1
    echo -e "\n02B: CilkScope, #th = $1: "
    ./02B $1
    echo -e "\n02C: ForLoop, #th = $1: "
    ./02C $1
    echo -e "\n02D: CilkFor, #th = $1: "
    ./02D $1

    make clean

    echo -e "\n**** 04: Time from Before Each Spawn to start of spawn Fcn() --> Cilk ****"    
    make 4

    echo -e "\n04A: Sequential, #th = $1: "
    ./04A $1
    echo -e "\n04B: CilkScope, #th = $1: "
    ./04B $1
    echo -e "\n04C: ForLoop, #th = $1: "
    ./04C $1
    echo -e "\n04D: CilkFor, #th = $1: "
    ./04D $1
    echo -e "\n04E: Single Spawn"
    ./04E $1
    echo -e "\n04F: Single Spawn w/ integer argument"
    ./04F $1

    make clean

    echo -e "\n**** 05: Spawn Window = # of spawns possible in 2.0s --> Cilk ****"     
    make 5

    ./05A

    make clean

    echo -e "\n**** 06: Spawn Tree every spawn create 2 more tasks --> Cilk ****" 
    make 6

    ./06A

    make clean
cd ..

echo -e "******** OpenMP Spawn Benchmarks ********"
cd openmp

    echo -e "\n**** 01: Total Time for All Spawns + Barrier --> OMP ****"
    make 1

    echo -e "\n01A: Sequential, #th = $1: "
    ./01A $1
    echo -e "\n01B: OMP Parallel Region, #th = $1: "
    ./01B $1
    echo -e "\n01C: ForLoop, #th = $1: "
    ./01C $1
    echo -e "\n01D: ParallelFor, #th = $1: "
    ./01D $1
    echo -e "\n01E: Single Spawn"
    ./01E
    echo -e "\n01F: Single Spawn w/ integer argument"
    ./01F

    echo -e "\n**** 02: Time from start to Before Each Task --> OMP ****"
    make 2

    echo -e "\n02A: Sequential, #th = $1: "
    ./02A $1
    echo -e "\n02B: OMP Parallel Region, #th = $1: "
    ./02B $1
    echo -e "\n02C: ForLoop, #th = $1: "
    ./02C $1
    echo -e "\n02D: ParallelFor, #th = $1: "
    ./02D $1

    make clean

    echo -e "\n**** 04: Time from Before Each Task to start of spawn Fcn() --> OMP ****"    
    make 4

    echo -e "\n04A: Sequential, #th = $1: "
    ./04A $1
    echo -e "\n04B: OMP Parallel Region, #th = $1: "
    ./04B $1
    echo -e "\n04C: ForLoop, #th = $1: "
    ./04C $1
    echo -e "\n04D: ParallelFor, #th = $1: "
    ./04D $1
    echo -e "\n04E: Single Spawn"
    ./04E $1
    echo -e "\n04F: Single Spawn w/ integer argument"
    ./04F $1

    make clean

    echo -e "\n**** 05: Spawn Window = # of Task possible in 2.0s --> OMP ****"     
    make 5

    echo -e "05A: Spawn window NO race condition"
    ./05A

    echo -e "05B: Spawn window W/ race condition"
    ./05B

    make clean

    echo -e "\n**** 06: Spawn Tree every spawn create 2 more tasks --> OMP ****" 
    make 6

    ./06A

    make clean
cd ..

echo -e "******** Pthreads Spawn Benchmarks ********"
cd pthreads

    echo -e "\n**** 01: Total Time for All Spawns (Detached) --> PTH ****"
    make 1

    echo -e "\n01A: Sequential, #th = $1: "
    ./01A $1
    echo -e "\n01C: ForLoop, #th = $1: "
    ./01C $1
    echo -e "\n01E: Single Spawn"
    ./01E
    echo -e "\n01F: Single Spawn w/ integer argument"
    ./01F

    echo -e "\n**** 02: Time from start to Before Each Task (Detached) --> PTH ****"
    make 2

    echo -e "\n02A: Sequential, #th = $1: "
    ./02A $1
    echo -e "\n02C: ForLoop, #th = $1: "
    ./02C $1

    make clean

    echo -e "\n**** 04: Time from Before Each Task to start of spawn Fcn() (Join) --> PTH ****"    
    make 4

    echo -e "\n04A: Sequential, #th = $1: "
    ./04A $1
    echo -e "\n04C: ForLoop, #th = $1: "
    ./04C $1
    echo -e "\n04E: Single Spawn"
    ./04E $1
    echo -e "\n04F: Single Spawn w/ integer argument"
    ./04F $1

    make clean

    echo -e "\n**** 05: Spawn Window = # of Task possible in 2.0s --> PTH ****"     
    make 5

    ./05A

    make clean

    echo -e "\n**** 06: Spawn Tree every spawn create 2 more tasks --> PTH ****" 
    make 6

    ./06A

    make clean

    echo -e "\n**** 07: Join version of 01C=07C and 02C=07D --> PTH ****"
    make 7

    echo -e "\n07C: Time total spawns, ForLoop w/ Join, #th = $1: "
    ./07C $1

    echo -e "\n07D: Time before each spawn, ForLoop w/ Join, #th = $1: "
    ./07D $1

    make clean
cd ..