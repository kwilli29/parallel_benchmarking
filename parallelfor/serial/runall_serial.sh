#!/bin/sh

RUNS=100
PLANG="serial"
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
	if [ "$2" == 'E' ]; then
		single_output_metrics $EXEC $CURRPROG 1
	elif [ "$2" == 'F' ]; then
		single_output_metrics $EXEC $CURRPROG 1
	else	
		single_output_metrics $EXEC $CURRPROG $1
	fi

	#rm $EXEC
}

make clean
###############################

echo "Starting benchmark on 01_'s"

	# E
	run_programs 1 E 0

	# Cleanup
	make clean


echo "Cleanup 01_'s"
echo ""

###############################

echo "Starting benchmark on 02_'s"

	# A
	run_programs 2 A 0
	
	# B
	run_programs 2 B 0

	# C
	run_programs 2 C 0

	# D
	run_programs 2 D 0

	# E
	run_programs 2 E 0

	# Cleanup
	make clean

echo "Cleanup 02_'s"
echo ""
###############################

#echo "Starting benchmark on 03_'s"

#echo "Cleanup 03_'s"
#echo ""
###############################
