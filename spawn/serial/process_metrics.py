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

    ACC = 0.0
    thcnt = 0
    prevline = ''

    AVGDIFFS = [0.0]*int(runs)
    cntr = 0

    with open(filename, 'r') as file:
        for line in file:
            if line[0] == '#': continue
            if line[0] == '*':
                if ACC > 0.0: 
                    # accum. data in some way
                    AVGDIFFS[cntr] = ACC / float(thcnt)
                    # print(AVGDIFFS)
                    cntr+=1

                # print(prevline, cntr, ACC, thcnt)
                # reset individual run metrics
                ACC = 0.0
                thcnt = 0
                prevline = ''
                continue
        
            if prevline:
                # print('prevline: ',prevline)
                # get difference b/w this and prev time
                # print(float(line.strip()), float(prevline), (float(line.strip())-float(prevline)))
                ACC += ( float(line.strip()) - float(prevline) )
                thcnt += 1

            prevline = line.strip()
       
    avgdiff_overall = sum(AVGDIFFS)/len(AVGDIFFS)
    avgdiff_overall = avgdiff_overall*1000000000.0     

    # print(f'*AVBW,{avgdiff_overall:.1f},ns, ',end='') 

    return avgdiff_overall

def medium_metrics(filename, runs):

    ACC = 0.0
    thcnt = 0
    prevline = ''

    AVGDIFFS = [0.0]*int(runs)
    cntr = 0

    counter=0

    with open(filename, 'r') as file:
        for line in file:
            if line[0] == '#': continue
            if line[0] == '*': continue
            
            #print(line.strip())
            ACC += float(line.strip())
            counter+=1
       
    #avgdiff_overall = sum(AVGDIFFS)/len(AVGDIFFS)
    #avgdiff_overall = avgdiff_overall*1000000000.0     

    avgdiff_overall = ACC/counter
    avgdiff_overall = avgdiff_overall*1000000000.0 

    # print(f'*AVBW,{avgdiff_overall:.1f},ns, ',end='') 

    return avgdiff_overall

def thread_metrics(filename, runs):
    # METRICS
    AVG = 0.0

    with open(filename, 'r') as file:
        for line in file:
            AVG += float(line.strip())

    AVG = (AVG / float(runs))
   
    # print(f'*AVERAGE COUNT # THREADS: {AVG:.2f}') 

    return AVG

def short_metrics(filename, runs):
    # METRICS
    AVG = 0.0

    with open(filename, 'r') as file:
        for line in file:
            if line[0] == '#': continue
            if line[0] == '*': continue
            AVG += float(line.strip())

    AVG = (AVG / float(runs))
    
    AVG = AVG*1000000000.0
   
    #print(f'*AVERAGE TIME: {AVG:.1f} ns') 

    return AVG


def main():
    
    metric = 0.0

    if sys.argv[3] == '2':
        metric = long_metrics(sys.argv[2],sys.argv[1])
    elif sys.argv[3] == '4':
        metric = medium_metrics(sys.argv[2],sys.argv[1])
    elif sys.argv[3] == '5':
        metric = thread_metrics(sys.argv[2],sys.argv[1])
    else:
        metric = short_metrics(sys.argv[2],sys.argv[1])

    print('AVGMETRIC: ', metric)

    return

# average outputs
# computing any other metrics
#   time
#   “overhead”
#   code size?


if __name__== '__main__':
    main()
