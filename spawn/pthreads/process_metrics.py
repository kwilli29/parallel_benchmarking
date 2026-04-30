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

def short_metrics(filename):
    # METRICS
    AVG = 0.0
    linecnt = 0

    with open(filename, 'r') as file:
        for line in file:
            if line:
                AVG += float(line.strip())
                linecnt += 1

    AVG = (AVG / float(linecnt))
    
    AVG = AVG*1000000000.0
   
    print(f'*AVERAGE TIME: {AVG:.1f} ns') 
    return

def long_overhead(parallel_filename, serial_filename, runs):

    # (Tp - Ts) / innerloop
    # (Time of #runs parallel fcns - Time #runs serial fcns) / innerloop

    PARA_ACC = 0.0
    thcnt = 0
    prevline = ''

    PARA_AVGDIFFS = [0.0]*int(runs)
    cntr = 0

    with open(parallel_filename, 'r') as file:
        for line in file:
            if line[0] == '*':
                if PARA_ACC > 0.0: 
                    # accum. data in some way
                    #print(prevline, cntr)
                    PARA_AVGDIFFS[cntr] = PARA_ACC / float(thcnt)
                    cntr+=1
                # reset individual run metrics
                PARA_ACC = 0.0
                thcnt = 0
                prevline = ''
                continue
            if prevline:
                # get difference b/w this and prev time
                PARA_ACC += ( float(line.strip()) - float(prevline) )
                thcnt += 1
            prevline = line.strip()

    SERI_ACC = 0.0
    thcnt = 0
    prevline = '' 
    SERI_AVGDIFFS = [0.0]*int(runs)
    cntr = 0
    with open(serial_filename, 'r') as sfile:
        for line in sfile:
            if line[0] == '*':
                if SERI_ACC > 0.0: 
                    # accum. data in some way
                    #print(prevline, cntr, SERI_ACC, thcnt)
                    SERI_AVGDIFFS[cntr] = SERI_ACC / float(thcnt)
                    cntr+=1

                elif prevline and SERI_ACC <= 0.0:
                    SERI_AVGDIFFS[cntr] = float(prevline)
                    cntr+=1

                # reset individual run metrics
                SERI_ACC = 0.0
                thcnt = 0
                prevline = ''
                continue
            if prevline:
                # get difference b/w this and prev time
                #print(float(line.strip()), float(prevline))
                SERI_ACC += ( float(line.strip()) - float(prevline) )
                thcnt += 1    
            prevline = line.strip()
    
    avgdiff_overhead= sum(PARA_AVGDIFFS) - (sum(SERI_AVGDIFFS) / NUM_PROCS) 
    avgdiff_overhead = avgdiff_overhead*1000000000.0     

    samediff = (sum(PARA_AVGDIFFS) - sum(SERI_AVGDIFFS))/float(len(PARA_AVGDIFFS))
    samediff = samediff*1000000000.0   

    print(f'*SAME DIFF AVG ?? : {samediff:.1f} ns')

    print(f'*OVERHEAD AVERAGE TIME B/W ??: {avgdiff_overhead:.1f} ns')
    print(f'*OVERHEAD AVERAGE TIME B/W ?? / # runs: {(avgdiff_overhead/len(PARA_AVGDIFFS)):.1f} ns') 

    return

def short_overhead(parallel_filename, serial_filename, runs):

    # (Tp - Ts) / innerloop
    # (Time of #runs parallel fcns - Time #runs serial fcns) / innerloop

    # METRICS
    PARA_ACC = 0.0
    SERI_ACC = 0.0
    linecnt = 0

    with open(parallel_filename, 'r') as file:
        for line in file:
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
    if sys.argv[3] == '2': #or sys.argv[3] == '4':
        long_metrics(sys.argv[2],sys.argv[1])

    elif sys.argv[3] == '5':
        thread_metrics(sys.argv[2],sys.argv[1])

    else:
        short_metrics(sys.argv[2])

    # OVERHEADS
    if len(sys.argv) > 4:
        if sys.argv[3] == '2': #or sys.argv[3] == '4':
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
