#!/usr/bin/python3

import sys
import time

NUM_PROCS=68

def long_metrics(filename, runs):

    avg_hello = 0.0
    avg_hi   = 0.0
    avg_greet  = 0.0
    avg_wel   = 0.0
    avg_bye   = 0.0

    flag = -1

    with open(filename, 'r') as file:
        for line in file:
            if not line: continue

            if line[0] == '+':
                flag = 0
                continue
            if line[0] == '*':
                flag = 1
                continue
            if line[0] == '#':
                flag = 2
                continue
            if line[0] == '-':
                flag = 3
                continue
            if line[0] == '&':
                flag = 4
                continue
    
            if flag == 0:
                avg_hello += float(line.strip())
                flag = -1
            elif flag == 1:
                avg_hi += float(line.strip())
                flag = -1
            elif flag == 2:
                avg_greet += float(line.strip())
                flag = -1
            elif flag == 3:
                avg_wel += float(line.strip())
                flag = -1
            elif flag == 4:
                avg_bye += float(line.strip())
                flag = -1
            else:
                continue

    avg_hello = (avg_hello/float(runs) ) * 1000000000.0
    avg_hi   = (avg_hi/float(runs) ) * 1000000000.0
    avg_greet  = (avg_greet/float(runs) ) * 1000000000.0
    avg_wel   = (avg_wel/float(runs) ) * 1000000000.0
    avg_bye   = (avg_bye/float(runs) ) * 1000000000.0

    print(f'+ OVERALL AVERAGE hello +: {avg_hello:.1f} ns') 
    print(f'* OVERALL AVERAGE hi *: {avg_hi:.1f} ns') 
    print(f'# OVERALL AVERAGE greetings #: {avg_greet:.1f} ns') 
    print(f'- OVERALL AVERAGE welcome -: {avg_wel:.1f} ns') 
    print(f'& OVERALL AVERAGE bye &: {avg_bye:.1f} ns')

    return

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

def short_overhead(parallel_filename, serial_filename,runs):

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

    samediff = ((PARA_ACC-SERI_ACC)/float(linecnt))*1000000000.0
    print(f'*Tparallel - Tserial: {samediff:.1f} ns')

    print(f'*OVERHEAD TIME: {AVG:.1f} ns') 
    print(f'*OVERHEAD TIME / # runs: {(AVG/float(runs)):.1f} ns')

    return

def main():
        
    # sys.argv = [ ./X , #runs , filename , # , 'Letter']

    # AVERAGES
    if (sys.argv[3] == '1' and sys.argv[4] == 'G') or ((sys.argv[3] == '2' and sys.argv[4] == 'C')): # 01G or 02C so far
        long_metrics(sys.argv[2],sys.argv[1])
    else:
        short_metrics(sys.argv[2])
    return

# average outputs
# computing any other metrics
#   time
#   “overhead” --> Tp - (Ts/innerreps)
#   code size?

if __name__== '__main__':
    main()
