#!/bin/bash

for i in $(seq $1);
do
ARG="$(ruby -e "puts (0..99).to_a.shuffle.join(' ')")"
./push_swap $ARG | ./checker_Mac $ARG && ./push_swap $ARG | wc -l
# echo $ARG
done

# for i in $(seq $1);
# do
# ARG="$(ruby -e "puts (0..99).to_a.shuffle.join(' ')")"
# ./push_swap $ARG | ./checker_linux $ARG && ./push_swap $ARG | wc -l
# # echo $ARG
# done