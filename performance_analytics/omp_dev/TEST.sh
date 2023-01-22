#!/bin/bash
for DIM in 100000 200000 300000
do
for THREADS in 1 2 4 8
do
    make THREADS=$THREADS DIM=$DIM quick
done
done
