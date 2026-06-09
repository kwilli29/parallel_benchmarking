#!/bin/bash

RUNS=100
PLANG="cilk"
OUTFILE="output/002.txt"
###############################

multi_output_metrics() {	# ex. #RUNS data/01A_000.txt

    echo "Python Process $1"
    # echo

	python3 ./process_metrics.py $RUNS "$1" "../serial/$1" >> $OUTFILE

	# cat $OUTFILE
}

run_programs() { # ex. 0 1 A

	make "$2" # Number
 
	echo "$3" # Letter

    CURRPROG="$1$2$3"

    DATA="data/${CURRPROG}_000.txt"
    touch $DATA

	for((i=0;i<($RUNS);i++)); 
	do	
        ./$CURRPROG 272 >> $DATA
    done 
    
    multi_output_metrics $DATA

	#echo "Deleting Data Files $1$2$3"
	rm $DATA
}

make clean
rm $OUTFILE
###############################
#cd serial
#./runall_serial.sh
#cd ..
###############################

echo "Starting benchmark on 01_'s"

	# C
	run_programs 0 1 C 

	# D
	run_programs 0 1 D

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

	# B
#	run_programs 0 2 B

	# C
	run_programs 0 2 C

	# D
	run_programs 0 2 D

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

	# B
#	run_programs 0 4 B

	# C
	run_programs 0 4 C

	# D
	run_programs 0 4 D

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
#    run_programs 0 8 A

    # B
    # run_programs 0 8 B

    # Cleanup
    make clean

echo "Cleanup 08_'s"
echo ""
###############################
