#!/usr/bin/python3

import sys
import time

# Get # of processors
NUM_PROCS=2
try:
    process = subprocess.Popen( "lscpu | grep -E 'Core\(s\) per socket:'", shell=True, 
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True
    )
    output, _ = process.communicate()

    NUM_PROCS= int(output.strip().split(":")[1].split(" ")[-1])
    # print('numproc: ', NUM_PROCS)
except Exception as e:
    NUM_PROCS=2

def long_metrics(filename, runs):

    avg_spsy = 0.0
    avg_sp   = 0.0
    avg_fcn  = 0.0
    avg_sy   = 0.0

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
    
            if flag == 0:
                avg_spsy += float(line.strip())
                flag = -1

            elif flag == 1:
                avg_sp += float(line.strip())
                flag = -1
       
            elif flag == 2:
                avg_fcn += float(line.strip())
                flag = -1

            elif flag == 3:
                avg_sy += float(line.strip())
                flag = -1
            else:
                continue

    avg_spsy = (avg_spsy/float(runs) ) * 1000000000.0
    avg_sp   = (avg_sp/float(runs) ) * 1000000000.0
    avg_fcn  = (avg_fcn/float(runs) ) * 1000000000.0
    avg_sy   = (avg_sy/float(runs) ) * 1000000000.0

    print(f'OVERALL AVERAGE SPAWN+SYNC+: {avg_spsy:.1f} ns') 
    print(f'OVERALL AVERAGE SPAWN*: {avg_sp:.1f} ns') 
    print(f'OVERALL AVERAGE FCN#: {avg_fcn:.1f} ns') 
    print(f'OVERALL AVERAGE SYNC-: {avg_sy:.1f} ns') 

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


def main():
        
    if sys.argv[3] == '4':
        long_metrics(sys.argv[2],sys.argv[1])

    else:
        short_metrics(sys.argv[2])

    return

# average outputs
# computing any other metrics
#   time
#   “overhead”
#   code size?


if __name__== '__main__':
    main()
