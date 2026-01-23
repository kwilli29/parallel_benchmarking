#!/bin/sh

EXECS=$(ls cilk/output/runprag1) # | grep -v / | grep -E '*_cilk$')

for odirs in $EXECS; do
	echo $odirs
	BDIR=$(ls -p cilk/output/runprag1/$odirs | grep -v /)
	echo $BDIR
	for bnchmrk in $BDIR; do
		echo "add cilk/output/runprag1/$odirs/$bnchmrk to sheet"
		python3 ./read2csv.py cilk/output/runprag1/$odirs/$bnchmrk
	done

	
done
