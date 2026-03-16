# OpenCilk Sync Kernels

## 01:  Spawn two functions then call and time sync function 
  - A: With print statements
  - B: No print statements
    
  **Time metric: sync time**

## 02: Spawn then call sync checkpoints several times, compare times with and without syncs
  - A: Sync checkpoints
  - G: No checkpoints

  **Time metric: Sync overhead**

## 03: Spawn thread(s), timestamp the end of each thread function, then stop time after sync command
  - A: Spawn 30 threads
  - G: Spawn 1 thread

  **Time metric: Time between end of function / return and end of sync**

## 04: Takes different measurements of one spawn, one sync, one spawn + function, spawn + sync
  - A: Take 4 time metrics
  
  **Time metric: Understand time overhead of sync + functions that surround sync**

## Other files:
- 
