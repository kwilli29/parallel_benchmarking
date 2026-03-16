# OpenMP Sync/Join Kernels

## 01:  Spawn two functions then call and time two join functions
  - A: With print statements
  - B: No print statements
    
  **Time metric: join time**

## 02: Spawn then call join checkpoints several times, compare times with and without joins
  - A: Join checkpoints
  - G: No checkpoints -- spawns are created detached

  **Time metric: Join overhead**

## 03: Spawn threads timestamp the end of each thread function, then stop time after join command
  - A: Spawn 30 threads
  - G: Spawn 1 thread

  **Time metric: Time between end of function / return and end of join**

## 04: Takes different measurements of one spawn, one join, one spawn + function, spawn + join
  - A: Take 4 time metrics
  
  **Time metric: Understand time overhead of join + functions that surround join**

## Other files:
- 
