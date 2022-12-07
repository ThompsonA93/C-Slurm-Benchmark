#!/bin/bash
# Test algorithm based on makefile for $Threads x $Elements
# Takes a while
make mkdirs
for threads in 1 2 
do
for elements in 250 500 
do
    make THREADS=$threads MATRIX_OP_DIM_1=$elements MATRIX_OP_DIM_2=$elements MATRIX_OP_DIM_3=$elements omp_matmul
done
done

for threads in 1 2
do
for elements in 25000 50000
do
    make THREADS=$threads SORTING_ELEMENTS=$elements omp_brick
done
done

for threads in 1 2
do
for elements in 25000 50000
do
    make THREADS=$threads SORTING_ELEMENTS=$elements omp_bucket
done
done

for threads in 1 2
do
for elements in 25000 50000
do
    make THREADS=$threads SORTING_ELEMENTS=$elements omp_counting
done
done

for threads in 1 2
do
for elements in 25000 50000
do
    make THREADS=$threads SORTING_ELEMENTS=$elements omp_insertion
done
done

for threads in 1 2
do
for elements in 25000 50000
do
    make THREADS=$threads SORTING_ELEMENTS=$elements omp_selection
done
done