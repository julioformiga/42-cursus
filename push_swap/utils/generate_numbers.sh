#!/bin/bash

R=1000
PERM_OR_COMB=perm

if [ $PERM_OR_COMB = perm ]; then
    C_RANGE=$#
else
    C_RANGE=$(seq 0 $#)
fi

for C in $C_RANGE; do
    for I in $(seq 1 $R); do
        echo "$(for X in "$@"; do echo "$X"; done | shuf -n $C | paste -s -d' ')"
    done | sort -u
done
