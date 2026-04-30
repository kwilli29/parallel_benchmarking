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

def short_metrics(filename, runs):
    # METRICS
    AVG = 0.0

    with open(filename, 'r') as file:
        for line in file:
            if line[0] == '*': continue
            AVG += float(line.strip())

    AVG = (AVG / float(runs))
    
    AVG = AVG*1000000000.0
   
    print(f'*AVERAGE TIME: {AVG:.1f} ns') 
    return


def main():
        
    if sys.argv[3] == '2' or sys.argv[3] == '4':
        long_metrics(sys.argv[2],sys.argv[1])

    elif sys.argv[3] == '5':
        thread_metrics(sys.argv[2],sys.argv[1])

    else:
        short_metrics(sys.argv[2],sys.argv[1])

    return

# average outputs
# computing any other metrics
#   time
#   “overhead”
#   code size?


if __name__== '__main__':
    main()
