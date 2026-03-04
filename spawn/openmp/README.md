# OpenMP Spawn Kernels

## 01:  Start timer, Spawn all threads, then stop timer after all spawns have completed. 
  - A: Single thread spawns tasks sequentially
  - B: Parallel section where all available threads call a function
  - C: Single thread runs a regular for-loop which spawns tasks
  - D: Parallel for-loop calls the function. Grainsize = 1, Schedule=static
  - E: Time 1 spawn task call
  - F: Time 1 spawn task call with a function argument

  **Time metric: overall time**

## 02: Measure time before each spawn call -- timer; spawn x(); ... etc.
  - A: Parallel sections execute sequentially to measure the time then run the spawned function
  - B: Parallel region executes task groups to measure the itme them spawn a task function
  - C: Single thread runs a regular for-loop which measures the time the spawns tasks
  - D: Parallel for-loop calls the function. Grainsize = 1, Schedule=static

  **Time metric: Time between spawns**

## 04: Measure time at the start of the spawned function
  - A: Single thread spawns tasks sequentially, timestamping before each task spawn
  - B: Parallel sections execute to measure the time then spawn a task function
  - C: Single thread runs a regular for-loop which spawns tasks
  - D: Parallel for-loop calls the function. Grainsize = 1, Schedule=static
  - E: Time 1 spawn task call
  - F: Time 1 spawn task call with a function argument

  **Time metric: Time between spawn and function start**

## 05: Have a timer run for 2.0 seconds and call spawn & increment counter within loop
  - A: Single thread runs while loop and spawns tasks
  - B: Parallel region runs while loops and spawns tasks, also incrementing unlocked counter [Race Condition]
  
  **Time metric: # threads able to be spawned in a time window**

## 06: Recursive spawn tree
  - A: Spawn tree with parallel region spawns two tasks recursively
  
  **Time metric: Recursive spawns**

## Other files:
- verbose: junk drawer tests, extra benchmarks from other papers implemented, etc.
- data & output: used in the runall script as a place to store temporary data and outputs
- test_omp.sh: test individual benchmarks

- **runall_omp.sh** + process_metrics.py: run all the benchmarks 25 times and capture their average outputs
