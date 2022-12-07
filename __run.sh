#!/bin/bash
cd src
if [[ -z "$(gcc --version)" ]]; then
    echo "GCC not installed. Omitting performance analytics run."
else
    (cd performance_analytics && make all)
    (cd performance_analytics && make all-omp)
fi

if [[ -z "$(pgcc --version)" ]]; then
    echo "PGCC not installed. Omitting dependency analytics run."
else
    (cd dependence_analytics && make all)
fi