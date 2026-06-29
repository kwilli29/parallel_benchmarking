#!/usr/bin/python3

import sys
import time
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from toexcel import panda_to_excel

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

def long_metrics(pfile, runs): # for 02 benchmarks --> get the difference between time measurements

    csvdata = [0.0,0.0,runs]

    # AVERAGE DIFF B/W
    PACC = 0.0
    thcnt = 0
    prevline = ''

    PARA_AVGDIFFS = [0.0]*int(runs)
    cntr = 0

    with open(pfile, 'r') as file:
        for line in file:
            if line[0] == '#' or line[0] == 't' or line[0] == '#': continue
            if line[0] == '*':
                if PACC > 0.0: 
                    # accum. data in some way
                    PARA_AVGDIFFS[cntr] = PACC / float(thcnt)
                    cntr+=1
                # reset individual run metrics
                PACC = 0.0
                thcnt = 0
                prevline = ''
                continue
            if prevline:
                # get difference b/w this and prev time
                PACC += ( float(line.strip()) - float(prevline) )
                thcnt += 1
            prevline = line.strip()

    if cntr == 0: PARA_AVGDIFFS[cntr] = PACC / float(thcnt)

    AVGDIFFOVERALL = sum(PARA_AVGDIFFS)/len(PARA_AVGDIFFS)
    AVGDIFFOVERALL = AVGDIFFOVERALL*1000000000.0   

    csvdata[0] = AVGDIFFOVERALL

    return csvdata

def thread_metrics(filename, runs): # Time window metric
    csvdata = []

    # METRICS
    AVG = 0.0

    with open(filename, 'r') as file:
        for line in file:
            if line[0] == '*' or line[0] == '#': continue
            AVG += float(line.strip())

    AVG = (AVG / float(runs))
    csvdata[0]=AVG
    # print(f'*AV#TH,{AVG:.2f},') 

    return csvdata

def short_metrics(pfile, runs): #

    csvdata = [0.0,0.0,runs]

    # METRICS
    PACC = 0.0
    SACC = 0.0
    AVG=0.0
    linecnt = 0

    # AVERAGE
    with open(pfile, 'r') as file:
        for line in file:
            if line[0] == '*' or line[0] == 't' or line[0] == '#': continue
            if line:
                PACC += float(line.strip())
                linecnt += 1

    if linecnt>0: AVG = (PACC / float(linecnt))
    AVG = AVG*1000000000.0

    csvdata[0] = AVG
   
    return csvdata

def main():

    csvdata = [sys.argv[2]]

    # sys.argv = [ ./X , #runs , parallel filename ]
    if '5' in sys.argv[2][0:7]: 
        csvdata = thread_metrics(sys.argv[2], sys.argv[1])
    if '2' in sys.argv[2][0:7]:
        csvdata = long_metrics(sys.argv[2], sys.argv[1])
    else:
        csvdata = short_metrics(sys.argv[2], sys.argv[1])

    csvdata.append(sys.argv[2])

    bk = sys.argv[2].split('/')[2][0:3]

    # B2		ARCH3		LANG4		#TH5		#RUNS1	FCN6		AVERAGE
    print(bk, sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[1], sys.argv[6], csvdata[0],sys.argv[7])

    #try:
    panda_to_excel(bk, sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[1], sys.argv[6], csvdata[0],sys.argv[7])

    #except Exception as e:
    #print('error in printing to sheet')

    print(csvdata, 'yay')

    return

# average outputs
# computing any other metrics
#   time
#   “overhead”
#   code size?

if __name__== '__main__':
    main()
