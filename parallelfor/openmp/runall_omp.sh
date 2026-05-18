#!/bin/bash

RUNS=100
PLANG="openmp"
###############################

single_output_metrics() {	# ex. 25 data/01A_000.txt 1

	echo "Process $2 $3"

	python3 ./process_metrics.py $RUNS "$1" "$3" > output/$PLANG/"$2".txt

	cat output/$PLANG/"$2".txt

}
multi_output_metrics() {	# ex. 25 data/01A_000.txt 1 serial/data/01A_000.txt

    echo "Python Process $2 $3"
    # echo "python3 ./process_metrics.py $RUNS $1 $3 $4 $5 > output/$PLANG/R1_$2.txt"

	python3 ./process_metrics.py $RUNS "$1" "$3" "$4" "$5" >> output/$PLANG/R1_"$2".txt

	cat output/$PLANG/R1_"$2".txt
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
    rm  "output/$PLANG/R1_$CURRPROG.txt"
    touch  "output/$PLANG/R1_$CURRPROG.txt"
	
	for((i=0;i<($RUNS);i++)); 
	do	
		./$CURRPROG >> $EXEC # Capture program output
	done

	# Metrics
	EXECS="serial/data/${CURRPROG}_000.txt"
	EXECE="serial/data/${CURRPROGS}_000.txt"
    EXECA="serial/data/${CURRPROGA}_000.txt"
    
    #             TpTs     Overhead
    # 1A-E        01E        01G  #
    # 2A          02A        01G  # 
    # 2B          02B        02G
    # 2C          02C        02H
    # 2D          02D        02I
    # 2E          02E        02J
    # 3A-F        03A        01G 
    # 4A-D        04A-D      01G
    # 5A-D        03A/01E    01G

    # TpTs
    FLAG=1
	if [ "$1" == "1" ]; then
		multi_output_metrics $EXEC $CURRPROG $1 $EXECE $FLAG
    elif [ "$1" == "3" ]; then
        multi_output_metrics $EXEC $CURRPROG $1 $EXECA $FLAG
    elif [ "$1" == "5" ]; then
        multi_output_metrics $EXEC $CURRPROG $1 "serial/data/01E_000.txt" $FLAG
    else
        multi_output_metrics $EXEC $CURRPROG $1 $EXECS $FLAG
	fi

    # Overhead
    FLAG=2
	if [ "$1" != "2" ]; then	
		multi_output_metrics $EXEC $CURRPROG $1 "serial/data/01G_000.txt" $FLAG
    elif [ "$1" == "2" ]; then
        if [ "$2" == "A" ]; then
            multi_output_metrics $EXEC $CURRPROG $1 "serial/data/01G_000.txt" $FLAG
        elif [ "$2" == "B" ]; then
            multi_output_metrics $EXEC $CURRPROG $1 "serial/data/02G_000.txt" $FLAG
        elif [ "$2" == "C" ]; then
            multi_output_metrics $EXEC $CURRPROG $1 "serial/data/02H_000.txt" $FLAG
        elif [ "$2" == "D" ]; then
            multi_output_metrics $EXEC $CURRPROG $1 "serial/data/02I_000.txt" $FLAG
        elif [ "$2" == "E" ]; then
            multi_output_metrics $EXEC $CURRPROG $1 "serial/data/02J_000.txt" $FLAG
        fi
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

	# B
	run_programs 3 B 0

	# C
	run_programs 3 C 0

	# D
	run_programs 3 D 0

    # F
	run_programs 3 F 0

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

	# Cleanup
	make clean

echo "Cleanup 05_'s"
echo ""
###############################
