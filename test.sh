#!/bin/bash

def="$2"
range="99"
if [ "$def" == "" ]
then
def="$range"
fi
for i in $(seq $1);
do
ARG="$(ruby -e "puts (0..$def).to_a.shuffle.join(' ')")"
./push_swap $ARG | ./checker_Mac $ARG && ./push_swap $ARG | wc -l
done

# for i in $(seq $1);
# do
# ARG="$(ruby -e "puts (0..$def).to_a.shuffle.join(' ')")"
# ./push_swap $ARG | ./checker_linux $ARG && ./push_swap $ARG | wc -l
# done

# ARG="$(ruby -e "puts (0..99).to_a.shuffle.join(' ')")"