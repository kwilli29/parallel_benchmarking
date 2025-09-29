#!/bin/sh


BDIR=$(ls -p output/run0/ | grep -v /)
echo $BDIR
for bnchmrk in $BDIR; do
    echo "add output/run0/$bnchmrk to sheet"
    python3 ./read2csv.py output/run0/$bnchmrk
done