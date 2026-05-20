#!/bin/bash

# FILE=./R1_01A.txt
# echo "$FILE"
# python3 ./csv.py $FILE

# for all files in this directory starting with R1
OUTPUT_FILES=`ls ./R1_*.txt`
for FILE in $OUTPUT_FILES
do
    echo $FILE
    python3 ./csv.py $FILE
done