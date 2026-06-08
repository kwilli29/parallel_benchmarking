**A stripped down version of the original spawn folder.**


## 01:  Start timer, Spawn all threads, then stop timer after all spawns hve completed. 

  - C: Regular for-loop individual spawn calls
  - D: parallel_for-loop calls the function. Grainsize = 1
  - E: Time 1 spawn call
  - F: Time 1 spawn call with a function argument

  **Time metric: overall time**

## 02: Measure time before each spawn call -- timer; spawn x(); ... etc.

  - B: Individual spawn calls made within a parallel region
  - C: Regular for-loop individual spawn calls
  - D: parallel_for-loop calls the function. Grainsize = 1

  **Time metric: Time between spawns**

## 04: Measure time at the start of the spawned function

  - C: Regular for-loop individual spawn calls
  - D: parallel_for-loop calls the function. Grainsize = 1
  - E: Time 1 spawn call
  - F: Time 1 spawn call with a function argument

  **Time metric: Time between spawn and function start**
