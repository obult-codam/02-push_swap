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
# 60 10 89 83 5 87 96 4 8 11 66 35 72 23 65 3 36 90 93 69 14 99 30 67 64 52 31 13 6 80 68 40 51 56 47 86 91 98 22 92 21 2 97 20 55 34 76 71 50 48 25 24 81 44 84 39 42 75 77 43 
# 28 53 26 85 1 59 12 18 79 62 15 7 54 74 0 94 38 46 73 16 27 49 29 70 17 9 82 19 63 78 32 57 45 88 41 61 95 58 33 37

# done in 709 steps is extreme case was 711 steps previously (progress!)