#!/bin/sh

RUNS=25
PLANG="openmp"
###############################

single_output_metrics() {	# ex. 25 data/01A_000.txt 1

	echo "Process $2 $3"

	python3 ./process_metrics.py $RUNS "$1" "$3" > output/$PLANG/"$2".txt

	cat output/$PLANG/"$2".txt

}

run_programs() { # ex. 1 A 0

	make "$1" # Number
 
	echo "$2" # Letter

	#	Run the Programs

	CURRPROG="$3$1$2"
	EXEC="data/${CURRPROG}_000.txt"

	touch $EXEC 

	for((i=0;i<($RUNS);i++)); 
	do	
			./$CURRPROG >> $EXEC # Capture program output
	done
	
	# Metrics
	single_output_metrics $EXEC $CURRPROG $1

	rm $EXEC

}

make clean
###############################

echo "Starting benchmark on 01_'s"

	# A
	run_programs 1 A 0

	# B
	run_programs 1 B 0


	# Cleanup
	make clean


echo "Cleanup 01_'s"
echo ""

###############################

echo "Starting benchmark on 02_'s"

	# A
	run_programs 2 A 0

	# G
	run_programs 2 G 0

	# Cleanup
	make clean

echo "Cleanup 02_'s"
echo ""
###############################

echo "Starting benchmark on 03_'s"

	# A
	run_programs 3 A 0

	# G
	run_programs 3 G 0

	# Cleanup
	make clean

echo "Cleanup 03_'s"
echo ""
###############################

echo "Starting benchmark on 04_'s"

	# A
	run_programs 4 A 0

	# Cleanup
	make clean

echo "Cleanup 04_'s"
echo ""
###############################
