#!/bin/bash
echo "! Fetching CPU Information"
rm AUTOTEST_CPU_INFO.txt
lshw -C CPU >> AUTOTEST_CPU_INFO.txt
cat /proc/cpuinfo >> AUTOTEST_CPU_INFO.txt

for DIM in 50000 100000 150000 200000 250000
do
for THREADS in 1 2 4 8
do
    make THREADS=$THREADS DIM=$DIM quick
done
done

for DIM in 10000000 20000000 30000000 40000000 50000000
do
for THREADS in 1 2 4 8
do
    make THREADS=$THREADS DIM=$DIM sieve
done
done

for DIM in 10000 20000 30000 40000 500000
do
for THREADS in 1 2 4 8
do
    make THREADS=$THREADS DIM=$DIM dijkstra
done
done

for DIM in 500 1000 1500 2000 2500
do
for THREADS in 1 2 4 8
do
    make THREADS=$THREADS DIM=$DIM gauss
done
done