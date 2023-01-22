#!/bin/bash
for DIM in 100000
do
for THREADS in 1 2 4 8
do
    make THREADS=$THREADS DIM=$DIM quick
done
done

for DIM in 10000000
do
for THREADS in 1 2 4 8
do
    make THREADS=$THREADS DIM=$DIM sieve
done
done
