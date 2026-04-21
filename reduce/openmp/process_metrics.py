#!/usr/bin/python3

import sys
import time

NUM_PROCS=68

def short_metrics(filename):
    # METRICS
    AVG = 0.0
    linecnt = 0

    with open(filename, 'r') as file:
        for line in file:
            if line[0] == '*': continue
            if line:
                AVG += float(line.strip())
                linecnt += 1

    AVG = (AVG / float(linecnt))
    
    AVG = AVG*1000000000.0
   
    print(f'AVERAGE TIME: {AVG:.1f} ns') 
    return

def short_overhead(parallel_filename, serial_filename, runs):
    # (Tp - (Ts / p))
    # Time of 25 parallel fcns - Time 25 serial fcns / p

    # METRICS
    PARA_ACC = 0.0
    SERI_ACC = 0.0
    linecnt = 0

    with open(parallel_filename, 'r') as file:
        for line in file:
            if line[0] == '*': continue
            if line:
                PARA_ACC += float(line.strip())
                linecnt += 1

    with open(serial_filename, 'r') as file:
        for line in file:
            if line[0] == '*': continue
            if line:
                SERI_ACC += float(line.strip())

    AVG = (PARA_ACC) - (SERI_ACC / NUM_PROCS) # # of processors
    AVG = AVG*1000000000.0
    
    samediff = (PARA_ACC - SERI_ACC)/float(linecnt)
    samediff = samediff*1000000000.0   

    print(f'*SAME DIFF AVG ?? : {samediff:.1f} ns')
    print(f'*OVERHEAD TIME: {AVG:.1f} ns') 
    print(f'*OVERHEAD TIME / # runs: {(AVG/float(runs)):.1f} ns')
    
    return

def main():
        
    # AVERAGES   
    if sys.argv[3] == '4': #or sys.argv[3] == '2':
        long_metrics(sys.argv[2],sys.argv[1])

    #elif sys.argv[3] == '5':
    #    thread_metrics(sys.argv[2],sys.argv[1])

    else:
        short_metrics(sys.argv[2])

    # OVERHEADS
    if len(sys.argv) > 4:
        if sys.argv[3] == '4': #or sys.argv[3] == '2':
            long_overhead(sys.argv[2],sys.argv[4],sys.argv[1])
        elif sys.argv[3] == '5':
            pass # thread_metrics(sys.argv[2],sys.argv[1])
        else:
            short_overhead(sys.argv[2], sys.argv[4],sys.argv[1])

    return

# average outputs
# computing any other metrics
#   time
#   “overhead”
#   code size?


if __name__== '__main__':
    main()
