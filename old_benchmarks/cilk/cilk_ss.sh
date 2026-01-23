#!/bin/sh

EXECS=$(ls output/run1) # | grep -v / | grep -E '*_cilk$')

for odirs in $EXECS; do
	echo $odirs
	BDIR=$(ls -p output/run1/$odirs | grep -v /)
	for bnchmrk in $BDIR; do
		./read2csv.py $bnchmrk
	done

	
done
