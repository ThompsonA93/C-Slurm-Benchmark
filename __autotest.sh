#!/bin/bash
# Tests all sub-programs automatically given configured parameters below.
# View the echo commands on what each section of the script does.
echo "! Fetching CPU Information"
rm AUTOTEST_CPU_INFO.txt
lshw -C CPU >> AUTOTEST_CPU_INFO.txt
cat /proc/cpuinfo >> AUTOTEST_CPU_INFO.txt

echo "! Cleaning previous data & running setup"
cd performance_analytics
#(cd arithmetic && make clean)
#(cd omp && make clean)
#(cd sorting && make clean)

echo "! Executing OMP Performance tests"
(cd omp && make mkdirs)

for threads in 1 2 4 8
do
for elements in 50000 100000 150000 200000
do
    (cd omp && make THREADS=$threads SORTING_ELEMENTS=$elements selection)
done
done

