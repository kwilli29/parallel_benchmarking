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

    # sys.argv = [ ./X , #runs , parallel filename , # , serial filename ]

    # AVERAGES
    short_metrics(sys.argv[2])

    # OVERHEADS
    if len(sys.argv) > 4:
        short_overhead(sys.argv[2], sys.argv[4],sys.argv[1])

    return

# average outputs
# computing any other metrics
#   time
#   “overhead” --> Tp - (Ts/inerreps)
#   code size?

if __name__== '__main__':
    main()
