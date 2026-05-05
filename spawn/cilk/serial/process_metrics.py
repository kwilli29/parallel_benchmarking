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

def long_metrics(filename, runs): # for 02 benchmarks --> get the difference between time measurements

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
                    #print(prevline, cntr)
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

    print(f'*AVBW,{avgdiff_overall:.1f},ns, ',end='') 

    return

def long_overhead(parallel_filename, serial_filename, runs):

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
    with open(serial_filename, 'r') as file:
        for line in file:
            if line[0] == '*':
                if SERI_ACC > 0.0: 
                    # accum. data in some way
                    #print(prevline, cntr)
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
                SERI_ACC += ( float(line.strip()) - float(prevline) )
                thcnt += 1
            prevline = line.strip()

    avgdiff_overhead= sum(PARA_AVGDIFFS) - (sum(SERI_AVGDIFFS) / NUM_PROCS) 
    avgdiff_overhead = avgdiff_overhead*1000000000.0  

    print(f'*LOV,{avgdiff_overhead:.1f},ns, ',end='')
    print(f'*LOV/#R,{(avgdiff_overhead/len(PARA_AVGDIFFS)):.1f},ns, ',end='') 

    return

def long_tpts(parallel_filename, serial_filename, runs):

    # (Tp) - (Ts / #procs)
    # (Time of #runs parallel fcns) - (Time #runs serial fcns / #procs)

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
    with open(serial_filename, 'r') as file:
        for line in file:
            if line[0] == '*':
                if SERI_ACC > 0.0: 
                    # accum. data in some way
                    #print(prevline, cntr)
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
                SERI_ACC += ( float(line.strip()) - float(prevline) )
                thcnt += 1
            prevline = line.strip()

    samediff = (sum(PARA_AVGDIFFS) - sum(SERI_AVGDIFFS))/float(len(PARA_AVGDIFFS))
    samediff = samediff*1000000000.0   

    print(f'*LTPTS,{samediff:.1f},ns')

    return

def thread_metrics(filename, runs): # Time window metric
    # METRICS
    AVG = 0.0

    with open(filename, 'r') as file:
        for line in file:
            AVG += float(line.strip())

    AVG = (AVG / float(runs))
   
    print(f'*AV#TH,{AVG:.2f},') 

    return

def short_metrics(filename): # average times
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
   
    print(f'*SHAV,{AVG:.1f},ns, ',end='')
 
    return

def short_overhead(parallel_filename, serial_filename,runs):

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

    print(f'*SHOV,{AVG:.1f},ns, ',end='') 
    print(f'*SHOV/#R,{(AVG/float(runs)):.1f},ns, ',end='')
    return

def short_tpts(parallel_filename, serial_filename,runs):

    # (Tp) - (Ts / #procs)
    # (Time of #runs parallel fcns) - (Time #runs serial fcns / #procs)

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

    samediff = (PARA_ACC - SERI_ACC)/(linecnt*1.0)
    samediff = samediff*1000000000.0   

    print(f'*SHTPTS,{samediff:.1f},' ,end='')

    return

def main():

    # sys.argv = [ ./X , #runs , parallel filename , # , serial filename , flag ]

    # AVERAGES 
    print('avg, tpts, overhead')
    
    # AVERAGES   
    if sys.argv[3] == '2': 
        long_metrics(sys.argv[2],sys.argv[1])
    elif sys.argv[3] == '5':
        thread_metrics(sys.argv[2],sys.argv[1])
    else:
        short_metrics(sys.argv[2])

    # Tp-Ts & OVERHEADS
    if len(sys.argv) > 5:
        
        flag = sys.argv[5]

        if sys.argv[3] == '5':
            pass # 
        elif flag == '0': # neither
            pass
        elif flag == '1': # just Tp-Ts
            if sys.argv[3] == '2':
                pass #long_tpts(sys.argv[2],sys.argv[4],sys.argv[1])
            else:
                pass #short_tpts(sys.argv[2], sys.argv[4],sys.argv[1])
        elif flag == '2': # just overhead
            if sys.argv[3] == '2':
                long_overhead(sys.argv[2],sys.argv[4],sys.argv[1])
            else:
                short_overhead(sys.argv[2], sys.argv[4],sys.argv[1])
        else: # both
            if sys.argv[3] == '2':
                #long_tpts(sys.argv[2],sys.argv[4],sys.argv[1])
                long_overhead(sys.argv[2],sys.argv[4],sys.argv[1])
            else:
                #short_tpts(sys.argv[2], sys.argv[4],sys.argv[1])
                short_overhead(sys.argv[2], sys.argv[4],sys.argv[1])
        print()

    return

# average outputs
# computing any other metrics
#   time
#   “overhead”
#   code size?

if __name__== '__main__':
    main()
