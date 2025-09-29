import pandas
from openpyxl import load_workbook
import random as rand
import math
import csv
import sys
from collections import defaultdict
import numpy as np

## FILE THAT CONVERTS GRAPHS AND MATRICES TO CSV OR DIFF. DATA STRUCTS ##

'''
maxiter = 0
if iter == 0: maxiter+total_iter ; maxiter = 0 ; edgeratio = 0; avg_edgecount+=totaledgecount ; avg_edgecount = 0 ; edgecount = OGMax
if iter > 0 maxiter = iter; edgeratio = curredge/edgecount ; edgecount = curredge
edgeratio+=avg_edgeratio / maxiter

maxiter = max(maxiter, curriter)

if maxiter > maxsziter and boool:
    maxcoarsesz = currcoarsesz
    boool = false

maxcoarsesz = max(maxcoarsesz, currcoarsesz)
'''

def txt_to_data(filename):

    threads=1
    iters = 0
    overall_time=0.0
    work_s = 0.0
    span_s = 0.0
    parallelism = 0
    glblcnt = 0.0
    opcnt = 0.0

    runs = 5.0

    filedata = filename.split('/')
    threads = filedata[2].split('_')[1]
    iters = filedata[2].split('_')[2].split('.')[0]

    print(filename)
    gs = 1

    print(threads, gs)

    thread_flag = True
    gcflag = True
    copflag = True

    with open(filename, 'r') as data_file:
        for data in data_file:
            #if thread_flag and data[0] == 'I': # Threads
            #    iters = int(data.strip().split(":")[1].rstrip())
            #    thread_flag = False
            if data[0] == 'W': # Overall Time
                print(data)
                overall_time += float(data.strip().split(":")[1].lstrip().split(" ")[0])
                #overall_time += float(data.strip().split("=")[1].strip())
            elif data[0] == ',':
                work_s += float(data.strip().split(',')[1])
                span_s += float(data.strip().split(',')[2])
                parallelism += float(data.strip().split(',')[3])
            elif data[0] == 'F' and gcflag:
                glblcnt = list(map(int, data.strip().split(":")[1].lstrip().split(' ')))
                gcflag = False
            elif data[0] == 'C'and copflag:
                opcnt = list(map(int, data.strip().split(":")[1].lstrip().split(' ')))
                copflag = False


        avg_overalltime = float(float(overall_time)/runs)
        avg_work = float(float(work_s)/runs)
        avg_span = float(float(span_s)/runs)
        avg_para = float(float(parallelism)/runs)

        # Wall Clock	Work	Span	GlblCnt	OpCnt	Threads	Iterations	Grain Size
        print(avg_overalltime, avg_work,avg_span,avg_para, glblcnt, opcnt, threads, iters, gs)
        panda_to_excel(avg_overalltime, avg_work,avg_span,avg_para, glblcnt, opcnt, threads, iters, gs)#,pragma, avg_work,avg_span,avg_para)

    return


def panda_to_excel(avg_overalltime, avg_work,avg_span,avg_para, glblcnt, opcnt, threads, iters, gs):#, pragma,avg_work,avg_span,avg_para):
    
    device =  'MacBook Pro' #'MacBook Pro' # 'Galahad' # 'Lucata' # 'RPi' #'Ricky-Bobby'
    compiler = 'XCRUN CLANG' #'XCRUN CLANG' #'OPT/CLANG'

    # dictionary of data  
    dct = {'Wall Clock': [avg_overalltime], 
        'Work': [avg_work],
        'Span': [avg_span],
        'Parallelism': [avg_para],
        'Iterations':[iters],
        'GlblCnt': [glblcnt], 
        'OpCnt':[opcnt],
        'Threads':[threads],
        'Grain Size':[gs],
    }
    #dct = [[b, th, c, p, avgtime,runs,device,compiler]] 
    # 	AVG. TIME	# RUNS	DEVICE	COMPILER 
    #        'AVG. OVERALL TIME':[avg_overalltime], 'PRAGMA': [pragma],
    #  'AVG. WORK':[avg_work],
    #      'AVG SPAN':[avg_span],
    # 'AVG_PARALLELISM:':[avg_para],

    ss = '~/Documents/Github/parallel_benchmarking/doozy_fib.xlsx'

    # forming dataframe 
    df = pandas.DataFrame(data=dct)  

    reader = pandas.read_excel(ss, sheet_name=['Sheet1'])

    print(type(list(reader.values())[0]))
    print(len(reader),list(reader.values())[0].shape[0])

    writer = pandas.ExcelWriter(ss, mode='a',if_sheet_exists='overlay')
    df.to_excel(writer, sheet_name='Sheet1', index=False, header=False,startrow=list(reader.values())[0].shape[0]+1)
    writer.close()

    return


def main():

    filename = sys.argv[1]
    
    txt_to_data(filename) # 
    print("\n")

    return

if __name__ == '__main__':
    main()
