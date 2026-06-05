#!/bin/sh

RUNS=25
PLANG="serial"
OUTFILE="output/000.txt"
###############################

single_output_metrics() {	# ex. 25 data/01A_000.txt

	echo "Process $2"

	python3 ./process_metrics.py $RUNS "$1" "$1" >> $OUTFILE

	#cat $OUTFILE

}

run_programs() { # ex. 0 1 A

	make "$2" # Number
 
	echo "$3" # Letter

	#	Run the Programs

	CURRPROG="$1$2$3"

	EXEC="data/${CURRPROG}_000.txt"
	touch $EXEC 

	for((i=0;i<($RUNS);i++)); 
	do	
		./$CURRPROG >> $EXEC # Capture program output
	done

	# Metrics

	single_output_metrics $EXEC

	# rm $EXEC
}

make clean
###############################
rm $OUTFILE
###############################
echo "Starting benchmark on 01_'s"

	# A
	# run_programs 0 1 A

	# C
	run_programs 0 1 C

	# E
	run_programs 0 1 E

	# F
	run_programs 0 1 F

	# Cleanup
	make clean


echo "Cleanup 01_'s"
echo ""

###############################

echo "Starting benchmark on 02_'s"

	# A
#	run_programs 0 2 A

	# C
	run_programs 0 2 C

	# E
#	run_programs 0 2 E

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
#	run_programs 0 4 A

	# C
	run_programs 0 4 C

	# E  -- make sure it runs the single print process
	run_programs 0 4 E

	# F -- make sure it runs the single print process
	run_programs 0 4 F

	# Cleanup
	make clean

echo "Cleanup 04_'s"
echo ""
###############################

#echo "Starting benchmark on 05_'s"

	# A 
#	run_programs 0 5 A

	# Cleanup
#	make clean

#echo "Cleanup 05_'s"
#echo ""
###############################

#echo "Starting benchmark on 06_'s"

	# A
#	run_programs 0 6 A

	# Cleanup
#	make clean

#echo "Cleanup 06_'s"
#echo ""
###############################

echo "Starting benchmark on 08_'s"

	# A
	#run_programs 0 8 A

    # B
	#run_programs 0 8 B

	# Cleanup
	make clean

echo "Cleanup 08_'s"
echo ""
###############################
cat $OUTFILE