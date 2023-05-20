#!/bin/bash

CHECKER=./checker_Mac

# extremeness, how many tests are done for checking amount of operations
XTN=25

orange() {
    local orange_color='\033[38;5;214m'  # ANSI escape code for orange color
    local reset_color='\033[0m'           # ANSI escape code to reset color

    echo -e "${orange_color}$1${reset_color}"
}


# Function to print OK in green
print_ok() {
  echo -e "\033[32mOK\033[0m"
}

# Function to print KO in red and failed numbers
print_ko() {
  echo -e "\033[31mKO\033[0m"
  echo "Failed numbers: $1"
}

err_test() {
	RES=$(./push_swap $1 2>&1)
	if [ "$RES" != "Error" ]; then
		print_ko "$1"
		exit 1
	fi
	print_ok
}

no_err_test() {
	RES=$(./push_swap $1 2>&1)
	if [ "$RES" == "Error" ]; then
		print_ko "$1"
		exit 1
	fi
	print_ok
}

# Test loop for 10 times
# args 
do_tests() {

	for ((i=1; i<=$1; i++)); do

		ARG="$(ruby -e "puts (1..$2).to_a.shuffle.join(' ')")"
		RES=$(./push_swap $ARG | $CHECKER $ARG)
		if [ $RES == "KO" ]; then
			print_ko "$ARG"
			exit 1
		fi
	done
	print_ok
}

operations_test() {
	if [ $# -eq 1 ]; then
		LOOPS=1
	else
		LOOPS=$2
	fi
	echo "123: " $1 ", " $LOOPS ", " $#
	MAX=0
	for ((k=1; k<=$LOOPS; k++)); do
		ARG="$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")"
		RES=$(./push_swap $ARG | wc -l)
		if [ $RES -gt $MAX ]; then
			MAX=$RES
		fi
	done
	echo "max operations of $LOOPS tries: $MAX"
}

# Start of testing script
for ((j=1; j<=6; j++)); do
	orange "tests for $j numbers"
	do_tests 5 $j
	operations_test $j $XTN
done

echo 
orange "for 100 numbers"
do_tests 5 100
operations_test 100 $XTN

echo
orange "for 500 numbers"
do_tests 5 500
operations_test 500 $XTN

# random tests
orange "random tests"
do_tests 1 42
do_tests 1 139
do_tests 1 64
do_tests 1 33
do_tests 1 92
do_tests 1 99
do_tests 1 512
do_tests 1 477

# do the false input tests
orange "false input tests"
err_test "1 2 3 4 4"
err_test "1a 3 9"
err_test "a b c"
err_test "-1 12 one 42"
err_test "+0 -0"

# perfectly fine input
orange "perfectly fine input"
no_err_test "-1 22 3"



# # hand sorting impossible, try 10.000 args
# echo 
# ARG="$(ruby -e "puts (1..10000).to_a.shuffle.join(' ')")"
# orange "now we will test your program with 10000 arguments"
# # precision
# RES=$(./push_swap $ARG | $CHECKER $ARG)
# echo "result: $RES"
# # operations
# operations_test 10000

# # time
# echo -n "time: "
# time ./push_swap $ARG > /dev/null