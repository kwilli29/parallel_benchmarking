#!/bin/sh

RUNS=25
PLANG="cilk"
###############################

single_output_metrics() {	# ex. 25 data/01A_000.txt 1

	echo "Process $2 $3"

	python3 ./process_metrics.py $RUNS "$1" "$3" > output/$PLANG/"$2".txt

	cat output/$PLANG/"$2".txt

}

multi_output_metrics() {	# ex. 25 data/01A_000.txt 1 serial/data/01A_000.txt

	echo "Process $2 $3"

	python3 ./process_metrics.py $RUNS "$1" "$3" "$4" > output/$PLANG/"$2".txt

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

	EXECS="serial/data/${CURRPROG}_000.txt"
		
	# Metrics
	single_output_metrics $EXEC $CURRPROG $1
	# compare to same letter
	if [ "$4" == "1" ]; then
		if [ "$2" == 'E' ]; then
			multi_output_metrics $EXEC $CURRPROG 1 $EXECS
		elif [ "$2" == 'F' ]; then
			multi_output_metrics $EXEC $CURRPROG 1 $EXECS
		else	
			multi_output_metrics $EXEC $CURRPROG $1 $EXECS 
		fi
	fi

	rm $EXEC

}

make clean
###############################

echo "Starting benchmark on 01_'s"

	# A
	run_programs 1 A 0 1

	# B
	run_programs 1 B 0 1

	# C
	run_programs 1 C 0 1

	# Cleanup
	make clean


echo "Cleanup 01_'s"
echo ""

###############################

#echo "Starting benchmark on 02_'s"

	# A
#	run_programs 2 A 0 0
	
	# Cleanup
#	make clean

#echo "Cleanup 02_'s"
#echo ""
###############################

#echo "Starting benchmark on 03_'s"

	# A
#	run_programs 3 A 0 1
	
	# Cleanup
#	make clean

#echo "Cleanup 03_'s"
#echo ""
###############################

#echo "Starting benchmark on 04_'s"

	# A
#	run_programs 4 A 0 0

	# Cleanup
#	make clean

#echo "Cleanup 04_'s"
#echo ""
###############################
