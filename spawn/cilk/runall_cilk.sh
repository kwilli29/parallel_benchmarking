#!/bin/sh

RUNS=100
PLANG="cilk"
###############################

single_output_metrics() {	# ex. 25 data/01A_000.txt 1

	echo "Process $2 $3"

	python3 ./process_metrics.py $RUNS "$1" "$3" > output/$PLANG/"$2".txt

	cat output/$PLANG/"$2".txt

}

multi_output_metrics() {	# ex. 25 data/01A_000.txt 1 serial/data/01A_000.txt

	echo "Python Process $2 $3"
    echo "python3 ./process_metrics.py $RUNS $1 $3 $4 $5 > output/$PLANG/R1_$2.txt"

	python3 ./process_metrics.py $RUNS "$1" "$3" "$4" "$5" > output/$PLANG/R1_"$2".txt

	cat output/$PLANG/"$2".txt

}

run_programs() { # ex. 1 A 0

	make "$1" # Number
 
	echo "$2" # Letter

	#	Run the Programs

	CURRPROG="$3$1$2"
	CURRPROGS="$3$1E"
	EXEC="data/${CURRPROG}_000.txt"

	touch $EXEC 
	
	for((i=0;i<($RUNS);i++)); 
	do	
		./$CURRPROG >> $EXEC # Capture program output
	done

	# Metrics
	EXECS="serial/data/${CURRPROG}_000.txt"
	EXECE="serial/data/${CURRPROGS}_000.txt"

	# Tp - Ts
    FLAG=1
	if [ $4 -eq 1 ]; then
		if [ "$2" == 'E' ]; then
			multi_output_metrics $EXEC $CURRPROG 1 $EXECS $FLAG
		elif [ "$2" == 'F' ]; then
			multi_output_metrics $EXEC $CURRPROG 1 $EXECS $FLAG
		else	
			multi_output_metrics $EXEC $CURRPROG $1 $EXECS $FLAG
		fi
	fi

	# Overhead -- compare to E
    FLAG=2
	if [ "$2" != E ]; then
		if [ "$2" == 'E' ]; then
			multi_output_metrics $EXEC $CURRPROG 1 $EXECE $FLAG
		elif [ "$2" == 'F' ]; then
			multi_output_metrics $EXEC $CURRPROG 1 $EXECE $FLAG
		else	
			multi_output_metrics $EXEC $CURRPROG $1 $EXECE $FLAG
		fi
	
	fi

	#echo "Deleting Data Files $3$1$2"
	rm $EXEC
	#rm "serial/${EXEC}"
}

make clean
###############################
#cd serial
#./runall_serial.sh
#cd ..
###############################

echo "Starting benchmark on 01_'s"

	# A
	run_programs 1 A 0 1

	# B
	run_programs 1 B 0 0

	# C
	run_programs 1 C 0 1

	# D
	run_programs 1 D 0 0

	# E
	run_programs 1 E 0 1

	# F
	run_programs 1 F 0 0

	# Cleanup
	make clean


echo "Cleanup 01_'s"
echo ""

###############################

echo "Starting benchmark on 02_'s"

	# A
	run_programs 2 A 0 1

	# B
	run_programs 2 B 0 0

	# C
	run_programs 2 C 0 1

	# D
	run_programs 2 D 0 0

	# Cleanup
	make clean

echo "Cleanup 02_'s"
echo ""
###############################

#echo "Starting benchmark on 03_'s"

#echo "Cleanup 03_'s"
#echo ""
###############################

echo "Starting benchmark on 04_'s"

	# A
	run_programs 4 A 0 1

	# B
	run_programs 4 B 0 0

	# C
	run_programs 4 C 0 1

	# D
	run_programs 4 D 0 0

	# E  -- make sure it runs the single print process
	run_programs 4 E 0 1

	# F -- make sure it runs the single print process
	run_programs 4 F 0 1

	# Cleanup
	make clean

echo "Cleanup 04_'s"
echo ""
###############################

echo "Starting benchmark on 05_'s"

	# A 
	run_programs 5 A 0 0

	# Cleanup
	make clean

echo "Cleanup 05_'s"
echo ""
###############################

echo "Starting benchmark on 06_'s"

	# A
	run_programs 6 A 0 0

	# Cleanup
	make clean

echo "Cleanup 06_'s"
echo ""
###############################