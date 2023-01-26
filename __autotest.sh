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

# for elements in 400000 800000 1600000 3200000
# do
# for threads in 1 2 4 8
# do
#     (cd omp && make THREADS=$threads SORTING_ELEMENTS=$elements quick)
# done
# done


# for threads in 1 2 4 8
# do
# for elements in 100000000 100000000 100000000 100000000 200000000 200000000 200000000 200000000
# do
#     (cd omp && make THREADS=$threads SIEVE_MAX_VALUE=$elements sieve)
# done
# done

# for elements in 2000 4000 8000 16000
# do
# for threads in 1 2 4 8
# do
#     (cd omp && make THREADS=$threads SIZE=$elements dijkstra)
# done
# done

for elements in 2000 4000 8000 16000
do
for threads in 1 2 4 8
do
    (cd omp && make THREADS=$threads M=$elements N=$elements gauss)
done
done
