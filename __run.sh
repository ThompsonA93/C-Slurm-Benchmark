#!/bin/bash
if [[ -z "$(gcc --version)" ]]; then
    echo "GCC not installed. Omitting performance analytics run."
else
    (cd performance_analytics/arithmetic && make all)
    (cd performance_analytics/sorting && make all)
fi

if [[ -z "$(gcc --version)" ]]; then
    echo "GCC not installed. Omitting OMP performance analytics run."
else
    (cd performance_analytics/omp && make all)
fi

#if [[ -z "$(pgcc --version)" ]]; then
#    echo "PGCC not installed. Omitting dependency analytics run."
#else
#    (cd dependence_analytics && make all)
#fi