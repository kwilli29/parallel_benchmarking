#!/bin/sh


# BDIR=$(ls -p ../ricky-bobby-output/rbrun0/ | grep -v /)
# echo $BDIR
# for bnchmrk in $BDIR; do
#     echo "add ricky-bobby-output/rbrun0/$bnchmrk to sheet"
#     python3 ./read2csv.py ../ricky-bobby-output/rbrun0/$bnchmrk
# done


BDIR=$(ls -p ../galahad-output/grun0/ | grep -v /)
echo $BDIR
for bnchmrk in $BDIR; do
    echo "add output/run0/$bnchmrk to sheet"
    python3 ./read2csv.py ../galahad-output/grun0/$bnchmrk
done