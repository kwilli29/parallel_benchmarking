#!/bin/sh

EXECS=$(ls pthreads/output/run1) # | grep -v / | grep -E '*_cilk$')

for odirs in $EXECS; do
	echo $odirs
	BDIR=$(ls -p pthreads/output/run1/$odirs | grep -v /)
	for bnchmrk in $BDIR; do
		echo "add pthreads/output/run1/$odirs/$bnchmrk to sheet"
		python3 ./read2csv.py pthreads/output/run1/$odirs/$bnchmrk
	done

	
done
