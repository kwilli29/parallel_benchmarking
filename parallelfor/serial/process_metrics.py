#!/usr/bin/python3

import sys
import time

def long_metrics(filename, runs):

    ACC = 0.0
    thcnt = 0
    prevline = ''

    AVGDIFFS = [0.0]*int(runs)
    cntr = 0

    with open(filename, 'r') as file:
        for line in file:
            if line[0] == '*':
                
                if ACC > 0.0: 
                    # accum. data in some way
                    AVGDIFFS[cntr] = ACC / float(thcnt)
                    cntr+=1

                # reset individual run metrics
                ACC = 0.0
                thcnt = 0
                prevline = ''
                continue
        
            if prevline:
                # get difference b/w this and prev time
                ACC += ( float(line.strip()) - float(prevline) )
                thcnt += 1
            
            prevline = line.strip()

       
    avgdiff_overall = sum(AVGDIFFS)/len(AVGDIFFS)

    avgdiff_overall = avgdiff_overall*1000000000.0     

    print(f'*OVERALL AVERAGE TIME B/W: {avgdiff_overall:.1f} ns') 

    return

def thread_metrics(filename, runs):
    # METRICS
    AVG = 0.0

    with open(filename, 'r') as file:
        for line in file:
            AVG += float(line.strip())

    AVG = (AVG / float(runs))
   
    print(f'*AVERAGE COUNT # THREADS: {AVG:.2f}') 

    return

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
        
    if sys.argv[3] == '9':#or sys.argv[3] == '42:
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
