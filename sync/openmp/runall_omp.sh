#!/bin/sh

RUNS=100
PLANG="openmp"
###############################

single_output_metrics() {	# ex. 25 data/01A_000.txt 1

	echo "Process $2 $3"

	python3 ./process_metrics.py $RUNS "$1" "$3" > output/$PLANG/"$2".txt

	cat output/$PLANG/"$2".txt

}

multi_output_metrics() {	# ex. 25 data/01A_000.txt 1 serial/data/01A_000.txt

	echo "Process $2 $3"

	python3 ./process_metrics.py $RUNS "$1" "$3" "$4" "$5" > output/$PLANG/"$2".txt

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
	EXECN="nosync/data/${CURRPROG}_000.txt"
	EXECS="../serial/data/${CURRPROG}_000.txt"
	
    # Averages
	# single_output_metrics $EXEC $CURRPROG $1

    FLAG=3

    # Tp - Ts & Overheads
    FLAG=1
    multi_output_metrics $EXEC $CURRPROG $1 $EXECS $FLAG

    FLAG=2
    multi_output_metrics $EXEC $CURRPROG $1 $EXECN $FLAG

	rm $EXEC

}

make clean
###############################

echo "Starting benchmark on 01_'s"

	# A
	run_programs 1 A 0 0

	# B
	run_programs 1 B 0 0

	# Cleanup
	make clean


echo "Cleanup 01_'s"
echo ""

###############################

echo "Starting benchmark on 02_'s"

	# A
	run_programs 2 A 0 0

	# Cleanup
	make clean

echo "Cleanup 02_'s"
echo ""
###############################

echo "Starting benchmark on 03_'s"

	# A
	run_programs 3 A 0 0

	# G
	run_programs 3 G 0 0

	# Cleanup
	make clean

echo "Cleanup 03_'s"
echo ""
###############################

echo "Starting benchmark on 04_'s"

	# A
	run_programs 4 A 0 0

	# Cleanup
	make clean

echo "Cleanup 04_'s"
echo ""
###############################