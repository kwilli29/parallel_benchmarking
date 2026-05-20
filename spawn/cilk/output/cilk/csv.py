#!/usr/bin/python3

import sys
import string

def csvdata(filename): # [avg, tpts, ov, ovr]

    csvdict = {
        'avg': 0.0,
        'tpts': 0.0,
        'ov': 0.0,
        'ovr': 0.0,
    }

    # METRICS
    AVG = 0.0
    linecnt = 0

    with open(filename, 'r') as file:
        for line in file:
            if line and line[0] == '*':
                commastring = line.strip().split(',')
                for i, elem in enumerate(commastring):
                    #print(i, elem)
                    if not elem: continue
                    if elem[0] == '*' or elem[1] == '*':
                        # if av in string
                        if 'AV' in elem:
                            csvdict['avg'] = float(commastring[i+1])
                        # if tpts in string
                        if 'TPTS' in elem:
                            csvdict['tpts'] = float(commastring[i+1])
                        # if ov in string and not #r
                        if 'OV' in elem and '#R' not in elem:
                            csvdict['ov'] = float(commastring[i+1])
                        # if ov in string and #r
                        if 'OV' in elem and '#R' in elem:
                            csvdict['ovr'] = float(commastring[i+1])
                
                print(csvdict['avg'], csvdict['tpts'], csvdict['ov'], csvdict['ovr'])

    print(csvdict['avg'], csvdict['tpts'], csvdict['ov'], csvdict['ovr'])

    return

def main():

    csvdata(sys.argv[1])

    return

if __name__ == '__main__':
    main()