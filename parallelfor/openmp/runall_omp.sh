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

	python3 ./process_metrics.py $RUNS "$1" "$3" "$4" > output/$PLANG/"$2".txt

	cat output/$PLANG/"$2".txt

}
run_programs() { # ex. 1 A 0

	make "$1" # Number
 
	echo "$2" # Letter

	#	Run the Programs
	CURRPROG="$3$1$2"
	CURRPROGS="$3$1E"
    CURRPROGA="$3$1A"
	EXEC="data/${CURRPROG}_000.txt"

	touch $EXEC 
	
	for((i=0;i<($RUNS);i++)); 
	do	
		./$CURRPROG >> $EXEC # Capture program output
	done

	# Metrics
	EXECS="serial/data/${CURRPROG}_000.txt"
	EXECE="serial/data/${CURRPROGS}_000.txt"
    EXECA="serial/data/${CURRPROGA}_000.txt"
    
	if [ "$1" == "1" ]; then	
		multi_output_metrics $EXEC $CURRPROG $1 $EXECE
    elif [ "$1" == "3" ]; then
        multi_output_metrics $EXEC $CURRPROG $1 $EXECA
    elif [ "$1" == "5" ]; then
        multi_output_metrics $EXEC $CURRPROG $1 "serial/data/01E_000.txt"
    else
        multi_output_metrics $EXEC $CURRPROG $1 $EXECS
	fi

	rm $EXEC

}

make clean
###############################

echo "Starting benchmark on 01_'s"

	# A
	run_programs 1 A 0

	# B
	run_programs 1 B 0

	# C
	run_programs 1 C 0

	# D
	run_programs 1 D 0

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

echo "Starting benchmark on 03_'s"

	# A
	run_programs 3 A 0

	# Cleanup
	make clean

echo "Cleanup 03_'s"
echo ""
###############################

echo "Starting benchmark on 04_'s"

	# A
	run_programs 4 A 0
	
	# B
	run_programs 4 B 0
	
	# C
	run_programs 4 C 0
	
	# D
	run_programs 4 D 0

	# Cleanup
	make clean

echo "Cleanup 04_'s"
echo ""
###############################

echo "Starting benchmark on 05_'s"

	# A
	run_programs 5 A 0

	# B
	run_programs 5 B 0

	# C
	run_programs 5 C 0

	# D
	run_programs 5 D 0

	# E
	#run_programs 5 E 0

	# G
	#run_programs 5 G 0

	# Cleanup
	#make clean

echo "Cleanup 05_'s"
echo ""
###############################

#echo "Starting benchmark on 04_'s"

	# A
	#run_programs 4 A 0

	# Cleanup
	#make clean

#echo "Cleanup 04_'s"
#echo ""
###############################
