#!/bin/bash
# Tests all sub-programs automatically given configured parameters below.
# View the echo commands on what each section of the script does.

echo "! Fetching CPU Information"
rm AUTOTEST_CPU_INFO.txt
lshw -C CPU >> AUTOTEST_CPU_INFO.txt
cat /proc/cpuinfo >> AUTOTEST_CPU_INFO.txt

echo "! Cleaning previous data & running setup"
sleep 3
cd performance_analytics
(cd arithmetic && make clean)
(cd omp && make clean)
(cd sorting && make clean)

echo "! Executing arithmetical performance tests"
sleep 3

(cd arithmetic && make mkdirs)
for elements in 250 500 750 1000 1250 1500 1750 2000
do
    (cd arithmetic && make MATRIX_OP_DIM_1=$elements MATRIX_OP_DIM_2=$elements MATRIX_OP_DIM_3=$elements matmul)
done

for elements in 250 500 750 1000 1250 1500 1750 2000
do
    (cd arithmetic && make MATRIX_OP_DIM_1=$elements MATRIX_OP_DIM_2=$elements MATRIX_OP_DIM_3=$elements gauss)
done

for elements in 2500 5000 7500 10000 12500 15000 17500 20000
do
    (cd arithmetic && make DIJKSTRA_VERTICES=$elements dijkstra)
done

for elements in 100000 150000 200000 250000 300000 350000 400000 450000 500000
do
    (cd arithmetic && make SIEVE_MAX_VALUE=$elements sieve)
done

echo "! Executing sorting performance tests"
sleep 3

(cd sorting && make mkdirs)

for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd sorting && make SORTING_ELEMENTS=$elements bubble)
done 

for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd sorting && make SORTING_ELEMENTS=$elements bucket)
done 

for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd sorting && make SORTING_ELEMENTS=$elements counting)
done 

for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd sorting && make SORTING_ELEMENTS=$elements insertion)
done 

for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd sorting && make SORTING_ELEMENTS=$elements selection)
done 

for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd sorting && make SORTING_ELEMENTS=$elements quick)
done 

echo "! Executing OMP Performance tests"
sleep 3

(cd omp && make mkdirs)
for threads in 1 2 4 8 12 16
do
for elements in 250 500 750 1000 1250 1500 1750 2000
do
    (cd omp && make THREADS=$threads MATRIX_OP_DIM_1=$elements MATRIX_OP_DIM_2=$elements MATRIX_OP_DIM_3=$elements matmul)
done
done

for threads in 1 2 4 8 12 16
do
for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd omp && make THREADS=$threads SORTING_ELEMENTS=$elements brick)
done
done

for threads in 1 2 4 8 12 16
do
for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd omp && make THREADS=$threads SORTING_ELEMENTS=$elements bucket)
done
done

for threads in 1 2 4 8 12 16
do
for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd omp && make THREADS=$threads SORTING_ELEMENTS=$elements counting)
done
done

for threads in 1 2 4 8 12 16
do
for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd omp && make THREADS=$threads SORTING_ELEMENTS=$elements insertion)
done
done

for threads in 1 2 4 8 12 16
do
for elements in 25000 50000 75000 100000 125000 150000 175000 200000
do
    (cd omp && make THREADS=$threads SORTING_ELEMENTS=$elements selection)
done
done
