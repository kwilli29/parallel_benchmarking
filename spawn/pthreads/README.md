# Pthreads Spawn Kernels

## 01:  Start timer, Spawn all threads, then stop timer after all spawns hve completed. -- detached threads
  - A: Individual pthread_create calls made sequentially
  - C: Regular for-loop pthread_create calls
  - E: Time 1 spawn call
  - F: Time 1 spawn call with a function argument

  **Time metric: overall time**

## 02: Measure time before each spawn call -- timer; spawn x(); ... etc. -- detached threads
  - A: Individual pthread_create calls made sequentially
  - C: Regular for-loop pthread_create calls

  **Time metric: Time between spawns**

## 04: Measure time at the start of the spawned function -- threads must be joinable
  - A: Individual pthread_create calls made sequentially
  - C: Regular for-loop pthread_create calls
  - E: Time 1 spawn call
  - F: Time 1 spawn call with a function argument

  **Time metric: Time between right before spawn and function start

## 05: Have a timer run for 2.0 seconds and call spawn & increment counter within loop
  - A: pthread_create called within a while loop
  
  **Time metric: # threads able to be spawned in a time window**

## 06: Recursive spawn tree -- joinable threads
  - A: Spawn tree around the spawn calls
  
  **Time metric: Recursive spawns**

## 07: Join versions of previous benchmarks
  - C: Version of 01C (after all spawn calls; for-loop) but instead of detached threads it creates joinable threads
  - E: Version of 02C (before spawn call; for-loop) but instead of detached threads it creates joinable threads

## Other files:
- verbose: junk drawer tests, extra benchmarks from other papers implemented, etc.
- data & output: used in the runall script as a place to store temporary data and outputs
- test_pthreads.sh: test individual benchmarks

- **runall_pthreads.sh** + process_metrics.py: run all the benchmarks 25 times and capture their average outputs
