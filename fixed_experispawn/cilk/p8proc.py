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

def pseudocode_metrics(pfile, runs): #

    csvdata = [0.0,0.0,runs]

    # print raw calcs then print averages before eof

    # over 100 runs: accumulate [then average]:
    # tkt1 per k per j [ V ]
    # tkt2 per k per j [ V ]
    # results per j    [ V ]
    # sync per run     [ V ]

    # METRICS
    num_threads = 2

    j = 0
    k = 0

    tkt1=[]
    tkt2=[]
    r1 =0
    r2 =0
    t5t4 = 0.0 # --> simple accumulation

    outputs = 0
    overheads = 0
    sync = 0

    # Initialize variables
    flag = 1
    with open(pfile, 'r') as file:
        for line in file:
            if line[0:3] == '* #' and flag:

                num_threads = int(line.strip().split(':')[1].strip())
                print('threads,', num_threads)

                resultst3t2t2t1 = [0.0]*num_threads # --> accumulate per index

                for i in range(num_threads):
                    tkt1.append([0.0]*(i))
                    tkt2.append([0.0]*(i))
                
                flag = 0
                continue

    with open(pfile, 'r') as file:
        for line in file:
            line = line.strip('\n ')
            
            if not line or line == '\n': 
                k = 1
                continue

            if line[0] == '$':
                # new run, reset non-accumulating variables
                j = 0
                k = 0
                outputs = 0
                overheads = 0
                sync = 0
                continue

            if line[0] == '*':
                if 'OUTPUTS' in line:
                    # increment j
                    j += 1
                    # reset k
                    k = 1
                    outputs = 1
                    sync=0
                    overheads = 0

                elif 'OVERHEADS' in line:
                    outputs = 0
                    sync = 0
                    overheads = 1
                elif 'SYNC' in line:
                    sync = 1
                    overheads = 0
                    output=0
                else:
                    sync=0
                    overheads = 0
                    outputs=1

                continue

            if line[0] == 't':
                #print(outputs, overheads, sync, line, line[0],line[1])
                if outputs:
                    if line[1] == '1':
                        #print('j,',j,'k,',k,',','tkt1[j-1][k-1],',float(line.split(',')[1]))
                        tkt1[j-1][k-1] += float(line.split(',')[1]) # t1[k]-t1[0]
                        k+=1
                    elif line[1] == '2':
                        #print('j,',j,'k,',k,',','tkt2[j-1][k-1],',float(line.split(',')[1]))
                        tkt2[j-1][k-1] += float(line.split(',')[1]) # t2[k]-t2[0]
                        k+=1
                
                if overheads:
                    if line[1] == '2' and line[3] == '0':
                        r1 = float(line.split(',')[1]) # t2[0]-t1[0]
                        # print('r1', r1)
                    elif line[1] == '3':
                        r2 = float(line.split(',')[1]) #  t3-t2[0]
                        # print('r2', r2)
                
                if sync:
                    if line[1] == '5':
                        #print('j,',j,',t5t4,',float(line.split(',')[1]))
                        t5t4 += float(line.split(',')[1]) # t5-t4
                else: pass

            if line[0] == '(' and line[1] == 't':
                if overheads:
                    result = r2-r1
                    #print('j,',j,'t3-t2-t2-t1,', result)
                    resultst3t2t2t1[j-1] += result # (t3-t2[0])-(t2[0]-t1[0])

    # AVERAGE

    print('runs,', float(runs))

    # tkt1
    for idx, i in enumerate(tkt1):
        for cnt, c in enumerate(i):
            tkt1[idx][cnt] = i[cnt]/float(runs)
    print('avg tk-t1 per j per k,',tkt1)

    # tkt2
    for idx, i in enumerate(tkt2):
        for cnt, c in enumerate(i):
            tkt2[idx][cnt] = i[cnt]/float(runs)
    print('avg tk-t2 per j per k,',tkt2)

    # t3-t2-t2-t1
    for idx, i in enumerate(resultst3t2t2t1):
        resultst3t2t2t1[idx] = i / float(runs)
    print('avg (t3-t2[0])-(t2[0]-t1[0]) per j,', resultst3t2t2t1)

    # sync
    t5t4 = t5t4/float(runs)
    print('t5t4sync per j,',t5t4)

    return #csvdata

def main():

    csvdata = [sys.argv[2]]

    # sys.argv = [ ./X , #runs , parallel filename , serial filename ]
    pseudocode_metrics(sys.argv[2] , sys.argv[1])

    #csvdata.append(sys.argv[2])

    print(sys.argv[2])

    return

# average outputs
# computing any other metrics
#   time
#   “overhead”
#   code size?

if __name__== '__main__':
    main()