# OpenCilk Spawn Kernels

## 01:  Start timer, Spawn all threads, then stop timer after all spawns hve completed. 
  - A: Individual cilk_spawn calls made sequentially
  - B: Individual cilk_spawn calls made within a cilk_scope parallel region
  - C: Regular for-loop cilk_spawn calls
  - D: cilk_for-loop calls the function. Grainsize = 1
  - E: Time 1 spawn call
  - F: Time 1 spawn call with a function argument

  **Time metric: overall time**

## 02: Measure time before each spawn call -- timer; spawn x(); ... etc.
  - A: Individual cilk_spawn calls made sequentially
  - B: Individual cilk_spawn calls made within a cilk_scope parallel region
  - C: Regular for-loop cilk_spawn calls
  - D: cilk_for-loop calls the function. Grainsize = 1

  **Time metric: Time between spawns**

## 04: Measure time at the start of the spawned function
  - A: Individual cilk_spawn calls made sequentially
  - B: Individual cilk_spawn calls made within a cilk_scope parallel region
  - C: Regular for-loop cilk_spawn calls
  - D: cilk_for-loop calls the function. Grainsize = 1
  - E: Time 1 spawn call
  - F: Time 1 spawn call with a function argument

  **Time metric: Time between spawn and function start**

## 05: Have a timer run for 2.0 seconds and call spawn & increment counter within loop
  - A: cilk_spawn called within a while loop
  
  **Time metric: # threads able to be spawned in a time window**

## 06: Recursive spawn tree
  - A: Spawn tree with cilk_scope around the spawn calls
  
  **Time metric: Recursive spawns**

## Other files:
- verbose: junk drawer tests, extra benchmarks from other papers implemented, etc.
- data & output: used in the runall script as a place to store temporary data and outputs
- test_cilk.sh: test individual benchmarks

- **runall_cilk.sh** + process_metrics.py: run all the benchmarks 25 times and capture their average outputs
