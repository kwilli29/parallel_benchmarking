#!/usr/bin/python3

import sys
import time

NUM_PROCS=68

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

def long_overhead(parallel_filename, serial_filename, runs):

    pavg_spsy = 0.0
    pavg_sp   = 0.0
    pavg_fcn  = 0.0
    pavg_sy   = 0.0

    savg_spsy = 0.0
    savg_sp   = 0.0
    savg_fcn  = 0.0
    savg_sy   = 0.0

    pflag = -1
    sflag = -1

    with open(parallel_filename, 'r') as file:
        for line in file:
            if not line: continue
            if line[0] == '+':
                pflag = 0
                continue
            if line[0] == '*':
                pflag = 1
                continue
            if line[0] == '#':
                pflag = 2
                continue
            if line[0] == '-':
                pflag = 3
                continue
            if pflag == 0:
                pavg_spsy += float(line.strip())
                pflag = -1
            elif pflag == 1:
                pavg_sp += float(line.strip())
                pflag = -1
            elif pflag == 2:
                pavg_fcn += float(line.strip())
                pflag = -1
            elif pflag == 3:
                pavg_sy += float(line.strip())
                pflag = -1
            else:
                continue
    with open(serial_filename, 'r') as file:
        for line in file:
            if not line: continue
            if line[0] == '+':
                sflag = 0
                continue
            if line[0] == '*':
                sflag = 1
                continue
            if line[0] == '#':
                sflag = 2
                continue
            if line[0] == '-':
                sflag = 3
                continue
            if sflag == 0:
                savg_spsy += float(line.strip())
                sflag = -1
            elif sflag == 1:
                savg_sp += float(line.strip())
                sflag = -1
            elif sflag == 2:
                savg_fcn += float(line.strip())
                sflag = -1
            elif sflag == 3:
                savg_sy += float(line.strip())
                sflag = -1
            else:
                continue
   
    sd_spsy = ((pavg_spsy-savg_spsy)/float(runs) ) * 1000000000.0
    sd_sp   = ((pavg_sp-savg_sp)/float(runs) ) * 1000000000.0
    sd_fcn  = ((pavg_fcn-savg_fcn)/float(runs) ) * 1000000000.0
    sd_sy   = ((pavg_sy-savg_sy)/float(runs) ) * 1000000000.0

    avg_spsy = ((pavg_spsy) - (savg_spsy/float(NUM_PROCS)) ) * 1000000000.0
    avg_sp   = ((pavg_sp)   - (savg_sp/float(NUM_PROCS)) ) * 1000000000.0
    avg_fcn  = ((pavg_fcn)  - (savg_fcn/float(NUM_PROCS)) ) * 1000000000.0
    avg_sy   = ((pavg_sy)   - (savg_sy/float(NUM_PROCS)) ) * 1000000000.0

    print(f'SAMEDIFF AVERAGE SPAWN+SYNC+: {sd_spsy:.1f} ns') 
    print(f'SAMEDIFF AVERAGE SPAWN*: {sd_sp:.1f} ns') 
    print(f'SAMEDIFF AVERAGE FCN#: {sd_fcn:.1f} ns') 
    print(f'SAMEDIFF AVERAGE SYNC-: {sd_sy:.1f} ns') 
    print(f'\nOVERHEAD AVERAGE SPAWN+SYNC+: {avg_spsy:.1f} ns') 
    print(f'OVERHEAD AVERAGE SPAWN*: {avg_sp:.1f} ns') 
    print(f'OVERHEAD AVERAGE FCN#: {avg_fcn:.1f} ns') 
    print(f'OVERHEAD AVERAGE SYNC-: {avg_sy:.1f} ns') 
    
    ####
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

def short_overhead(parallel_filename, serial_filename, runs):
    # (Tp - Ts) / innerloop
    # (Time of 25 parallel fcns - Time 25 serial fcns) / innerloop

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
    
    samediff = (PARA_ACC - SERI_ACC)/float(linecnt)
    samediff = samediff*1000000000.0   

    print(f'*SAME DIFF AVG ?? : {samediff:.1f} ns')
    print(f'*OVERHEAD TIME: {AVG:.1f} ns') 
    print(f'*OVERHEAD TIME / # runs: {(AVG/float(runs)):.1f} ns')

    return

def main():
        
    # AVERAGES   
    if sys.argv[3] == '4': #or sys.argv[3] == '2':
        long_metrics(sys.argv[2],sys.argv[1])
    else:
        short_metrics(sys.argv[2])

    # OVERHEADS
    if len(sys.argv) > 4:
        if sys.argv[3] == '4': #or sys.argv[3] == '2':
            long_overhead(sys.argv[2],sys.argv[4],sys.argv[1])
        elif sys.argv[3] == '5':
            pass # 
        else:
            short_overhead(sys.argv[2], sys.argv[4], sys.argv[1])

    return

# average outputs
# computing any other metrics
#   time
#   “overhead”
#   code size?

if __name__== '__main__':
    main()
