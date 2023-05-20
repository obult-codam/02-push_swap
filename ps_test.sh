#!/bin/bash

CHECKER=./checker_Mac
LOGFILE="args.log"
ROUNDS=25

orange() {
    local orange_color='\033[38;5;214m'  # ANSI escape code for orange color
    local reset_color='\033[0m'           # ANSI escape code to reset color

	echo
    echo -e "${orange_color}$1${reset_color}"
}

# Function to print OK in green
print_ok() {
  echo $1 -e "[\033[32mOK\033[0m] "
}

# Function to print KO in red and failed numbers
print_ko() {
	echo $2 -e "[\033[31mKO\033[0m] "
	echo "Failed numbers: \"$1\"" >> "$LOGFILE"
	if $PIPELINE; then
		exit 1
	fi
}

err_test() {
	RES=$(./push_swap $1 2>&1)
	if [ "$RES" != "Error" ]; then
		print_ko "$1"
	fi
	print_ok $2
}

evaluate() {
	if [ "$1" != "OK" ]; then
		print_ko "$2" $3
	fi
	print_ok $3
}

# base test give "<number array>" as input add -n for no newline
base_test() {
	RES=$(./push_swap $1 | $CHECKER $1)
	if [ "$RES" != "OK" ]; then
		print_ko "$1"
	else
		print_ok $2
	fi
}

# Test loop for 10 times
do_tests() {

	for ((i=1; i<=$1; i++)); do

		ARG="$(ruby -e "puts (1..$2).to_a.shuffle.join(' ')")"
		RES=$(./push_swap $ARG | $CHECKER $ARG)
		if [ "$RES" != "OK" ]; then
			print_ko "$ARG"
		elif [ i != $1 ]; then
			print_ok -n
		fi
	done
	print_ok $3
}

operations_benchmark() {
	if [ $# -eq 1 ]; then
		LOOPS=1
	else
		LOOPS=$2
	fi
	MAX=0
	for ((k=1; k<=$LOOPS; k++)); do
		ARG="$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")"
		RES=$(./push_swap $ARG | wc -l)
		if [ $RES -gt $MAX ]; then
			MAX=$RES
		fi
	done
	echo "max operations for $1 at $LOOPS tries: $MAX"
}

# init
if [ "$1" = "--pipeline" ] || [ "$1" = "-P" ]; then
    PIPELINE=true
else
    PIPELINE=false
fi

# Start of testing script
for ((j=1; j<=6; j++)); do
	orange "tests for $j numbers"
	do_tests 5 $j
	operations_benchmark $j $ROUNDS
done

# 100
orange "for 100 numbers"
do_tests 5 100
operations_benchmark 100 $ROUNDS

# 500
orange "for 500 numbers"
do_tests 5 500
operations_benchmark 500 $ROUNDS

# random tests
orange "random tests"
do_tests 1 42 -n
do_tests 1 139 -n
do_tests 1 64 -n
do_tests 1 33 -n
do_tests 1 92 -n
do_tests 1 99 -n
do_tests 1 512 -n
do_tests 1 477

# do the false input tests
orange "false input tests"
err_test "1 2 3 4 4" -n
err_test "1a 3 9" -n
err_test "a b c" -n
err_test "-1 12 one 42" -n
err_test "+0 -0"

# perfectly fine input
orange "perfectly fine input"
base_test "-1 22 3"
# base_test "wrong"

# hand sorting impossible? try 10.000 args
ARG="$(ruby -e "puts (1..10000).to_a.shuffle.join(' ')")"
orange "now we will test your program with 10000 arguments"
# precision
RES=$(./push_swap $ARG | $CHECKER $ARG)
evaluate "$RES" "-10000 args"
# operations
operations_benchmark 10000

# time
echo -n "time: "
time ./push_swap $ARG > /dev/null