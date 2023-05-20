#!/bin/bash

CHECKER=./checker_Mac

# Function to print OK in green
print_ok() {
  echo -e "\033[32mOK\033[0m"
}

# Function to print KO in red and failed numbers
print_ko() {
  echo -e "\033[31mKO\033[0m"
  echo "Failed numbers: $1"
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

# Start of testing script
for ((j=1; j<=5; j++)); do
	echo "tests for $j numbers"
	do_tests 5 $j
done

echo "for 100 numbers"
do_tests 5 100
echo "for 500 numbers"
do_tests 5 500

# do the false input tests

# hand sorting impossible, try 10.000 args
ARG="$(ruby -e "puts (1..10000).to_a.shuffle.join(' ')")"
echo "now we will test your program with 10000 arguments"
# precision
RES=$(./push_swap $ARG | $CHECKER $ARG)
echo "result: $RES"
# operations
RES=$(./push_swap $ARG | wc -l)
echo "operations: $RES"
# time
echo -n "time: "
time ./push_swap $ARG > /dev/null