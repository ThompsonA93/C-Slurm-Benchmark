#!/bin/bash
# Test omp algorithms based on makefile for $Threads x $Elements
# Takes a while
cd performance_analytics/omp
make mkdirs
for threads in 1 2 
do
for elements in 250 500 
do
    make THREADS=$threads MATRIX_OP_DIM_1=$elements MATRIX_OP_DIM_2=$elements MATRIX_OP_DIM_3=$elements matmul
done
done

for threads in 1 2
do
for elements in 25000 50000
do
    make THREADS=$threads SORTING_ELEMENTS=$elements brick
done
done

for threads in 1 2
do
for elements in 25000 50000
do
    make THREADS=$threads SORTING_ELEMENTS=$elements bucket
done
done

for threads in 1 2
do
for elements in 25000 50000
do
    make THREADS=$threads SORTING_ELEMENTS=$elements counting
done
done

for threads in 1 2
do
for elements in 25000 50000
do
    make THREADS=$threads SORTING_ELEMENTS=$elements insertion
done
done

for threads in 1 2
do
for elements in 25000 50000
do
    make THREADS=$threads SORTING_ELEMENTS=$elements selection
done
done