# OpenMP Sync Kernels

## 01:  Single thread spawns tasks of two functions then call and time sync function 
  - A: With print statements
  - B: No print statements
    
  **Time metric: sync time**

## 02: Single thread spawns tasks then call sync checkpoints several times, compare times with and without syncs
  - A: Sync checkpoints
  - G: No checkpoints

  **Time metric: Sync overhead**

## 03: Single thread spawns tasks, timestamp the end of each thread function, then stop time after sync command
  - A: Spawn 30 threads
  - G: Spawn 1 thread

  **Time metric: Time between end of function / return and end of sync**

## 04: Takes different measurements of one single thread spawning tasks, one sync, one task + function, task + sync, etc.
  - A: Take time metrics and compare 'natural' syncs to explicit barrier times
  
  **Time metric: Understand time overhead of sync + functions that surround sync to barrier time**

## Other files:
- 
