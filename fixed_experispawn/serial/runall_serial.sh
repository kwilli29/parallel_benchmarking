#!/bin/bash

## ./runserial.sh NT ARCH SLOW RUNS TIMER

RUNS=$4
PLANG="serial"
ARCH=$2 # galahad / rb
FCNSL="$3"
FILEEND="fixed_${3}_${1}"
OUTFILE="output/${ARCH}/${FILEEND}.txt"
TIMER=$5
NT=$1
###############################

single_output_metrics() {	# ex. 25 data/01A_000.txt

	echo "Process $1"

    # B2		ARCH3		LANG4		#TH5		#RUNS1	FCN6		AVERAGE
    python3 ./process_metrics.py $RUNS "$1" $ARCH $PLANG $NT $FCNSL $TIMER # >> $OUTFILE

	#cat $OUTFILE

}

run_programs() { # ex. 0 1 A

    make "$2" # Number
 
    echo "$3" # Letter

    CURRPROG="$1$2$3"

    DATA="data/${ARCH}/${CURRPROG}_${FILEEND}.txt"
    touch $DATA

	for((i=0;i<($RUNS);i++)); 
	do	
        ./$CURRPROG $NT >> $DATA
    done

	# Metrics

	single_output_metrics $DATA

	rm $DATA
}

make clean
###############################
rm $OUTFILE


echo "Starting benchmark on 03_'s"

	# C
	run_programs 0 3 C

	# E  -- 
	run_programs 0 3 E

	# F -- 
	run_programs 0 3 F

echo "Cleanup 03_'s"
echo ""

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

###############################

echo "Starting benchmark on 04_'s"

	# A
#	run_programs 0 4 A

	# C
	run_programs 0 4 C

	# E  -- 
	run_programs 0 4 E

	# F -- 
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

echo "Starting benchmark on 06_'s"

	# A
	run_programs 0 6 A

	# Cleanup
	make clean

echo "Cleanup 06_'s"
echo ""
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
#cat $OUTFILE