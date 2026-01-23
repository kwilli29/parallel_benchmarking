import pandas
from openpyxl import load_workbook
import random as rand
import math
import csv
import sys
from collections import defaultdict
import numpy as np

## FILE THAT CONVERTS GRAPHS AND MATRICES TO CSV OR DIFF. DATA STRUCTS ##

def read_kfile(filename):
    # read in file of:

    # N
    # num_edges
    # adj_matrix

    with open(filename) as f:
         ls = f.read()

    n, numEdges, adjMatrix = ls.splitlines()

    n = int(n)
    numEdges = int(numEdges)

    adjMatrix = map(int, adjMatrix.split(" "))

    return n, numEdges, adjMatrix

def read_file(filename):
    # read in file of g500 edgelist format

    with open(filename) as f:
         ls = f.read()

    startVerts, endVerts, weights = ls.splitlines()

    startVerts = map(float, startVerts.split(" ")[:-1])
    endVerts = map(float, endVerts.split(" ")[:-1])
    weights = map(float, weights.split(" ")[:-1])

    edgelist = [startVerts,endVerts,weights]

    return edgelist

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

    paradigm=''
    benchmark=''
    threads=1
    cores_gte=1
    overall_time=0.0
    #work_s = 0.0
    #span_s = 0.0
    #parallelism = 0

    runs = 10.0

    filedata = filename.split('/')
    benchmark = filedata[3].split('_')[0]
    paradigm = filedata[0]

    print(filename)
    #pragma = filename.split('+')[1].split('.')[0][1:]
    pragma = 'X'

    print(benchmark, paradigm, pragma)

    thread_flag = True

    with open(filename, 'r') as data_file:
        for data in data_file:
            if thread_flag and data[0] == 'N': # Threads
                threads = int(data.strip().split(":")[1])
                thread_flag = False
                pass
            elif data[0:6] == 'Time(O': # Overall Time
                print(data)
                overall_time += float(data.strip().split("=")[1].lstrip().split(" ")[0])
                #overall_time += float(data.strip().split("=")[1].strip())
            #elif data[0] == ',':
            #    work_s += float(data.strip().split(',')[1])
            #    span_s += float(data.strip().split(',')[2])
            #    parallelism += float(data.strip().split(',')[3])

        if threads > 1:
            if threads < 4:
                cores_gte = 1
            else:
                cores_gte = math.ceil(threads/4)

        avg_overalltime = float(float(overall_time)/runs)
        #avg_work = float(float(work_s)/runs)
        #avg_span = float(float(span_s)/runs)
        #avg_para = float(float(parallelism)/runs)

        print(paradigm, benchmark, avg_overalltime, threads, cores_gte, runs)#, pragma,avg_work,avg_span,avg_para)
        panda_to_excel(paradigm, benchmark, avg_overalltime, threads, cores_gte, runs)#,pragma, avg_work,avg_span,avg_para)


    std_dev_sum = 0

    with open(filename, 'r') as data_file:
        for data in data_file:
            if data[0:6] == 'Time(O': # Overall Time
                overall_time = float(data.strip().split("=")[1].lstrip().split(" ")[0])
                std_dev_sum+= ((overall_time - avg_overalltime)*(overall_time - avg_overalltime))


    std_dev = math.sqrt((std_dev_sum)/(runs-1))

    print(f"Std dev of times in {filename}: {std_dev}")


def panda_to_excel(paradigm, benchmark, avg_overalltime, threads, cores_gte, runs):#, pragma,avg_work,avg_span,avg_para):
    
    device =  'Galahad' #'MacBook Pro' # 'Galahad' # 'Lucata' # 'RPi' #'Ricky-Bobby'
    compiler = 'OPT/CLANG' #'XCRUN CLANG' #'OPT/CLANG'

    # dictionary of data  
    dct = {'BENCHMARK': [benchmark], 
        'THREADS': [threads],
        '>= CORES': [cores_gte],
        'PARADIGM': [paradigm], 
        'AVG. OVERALL TIME':[avg_overalltime],
        '# RUNS':[runs],
        'DEVICE':[device],
        'COMPILER':[compiler],
    }
    #dct = [[b, th, c, p, avgtime,runs,device,compiler]] 
    # 	AVG. TIME	# RUNS	DEVICE	COMPILER 
    #        'AVG. OVERALL TIME':[avg_overalltime], 'PRAGMA': [pragma],
    #  'AVG. WORK':[avg_work],
    #      'AVG SPAN':[avg_span],
    # 'AVG_PARALLELISM:':[avg_para],

    ss = '~/Documents/Github/parallel_benchmarking/parallelbenchmarking_times.xlsx'

    # forming dataframe 
    df = pandas.DataFrame(data=dct)  

    reader = pandas.read_excel(ss, sheet_name=['Sheet10'])

    print(type(list(reader.values())[0]))
    print(len(reader),list(reader.values())[0].shape[0])

    writer = pandas.ExcelWriter(ss, mode='a',if_sheet_exists='overlay')
    df.to_excel(writer, sheet_name='Sheet10', index=False, header=False,startrow=list(reader.values())[0].shape[0]+1)
    writer.close()

    return


def main():

    filename = sys.argv[1]
    
    txt_to_data(filename) # 
    print("\n")

    return

if __name__ == '__main__':
    main()
