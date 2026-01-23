#!/bin/sh

EXECS=$(ls galahad-output/run3/) # | grep -v / | grep -E '*_cilk$')

for odirs in $EXECS; do
	echo $odirs
	BDIR=$(ls -p galahad-output/run3/$odirs | grep -v /)
	echo $BDIR
	for bnchmrk in $BDIR; do
		echo "add galahad-output/run3/$odirs/$bnchmrk to sheet"
		python3 ./read2csv.py galahad-output/run3/$odirs/$bnchmrk
	done

	
done
