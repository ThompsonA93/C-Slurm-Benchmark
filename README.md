[![C Build](https://github.com/ThompsonA93/C-Slurm-Benchmark/actions/workflows/build.yml/badge.svg)](https://github.com/ThompsonA93/C-Slurm-Benchmark/actions/workflows/build.yml)

# C-Slurm-Benchmark

| Environment | Version |
| ----------- | ------- |
| Ubuntu | 20.04.5 LTS |
| GCC | 9.4.0 |
| GNU Make | 4.2.1 |


## Todo
- []Refactor execution (Ty Laubi): 
> gcc -pg -D MATRIX_SIZE=1000 homework.c -mcmodel=large -lm -pg\
> srun out.o\
> gprof out.o gmon.out -b
- [] Slurm executions: 
> OMP_NUM_THREADS=4 srun -c 4 build/matrix_mult.out
- [x] Matrix Multiplication
- [x] Gaussian Elimination
- [x] Dijstkra
- [x] Sieve of Eratosthenes
- [x] Bubble sort
- [x] Bucket sort
- [x] Counting sort
- [x] Insertion sort
- [x] Selection sort
- [x] Quick sort
 

# Misc. Information
## Installation & Execution 
Refer to __install.sh and __run.sh respectively.

## Folder structure
```
// Generated using 'tree'
├── arithmetic      -- Arithmetic programs
├── build           -- .out directory 
├── log             -- .log directory (custom)
├── profiles        -- .gprof directory
└── sorting         -- Sorting programs
```

## C Naming Convention
```
Struct              TitleCase
Struct Members      lower_case or lowerCase

Enum                ETitleCase
Enum Members        ALL_CAPS or lowerCase

Public functions    pfx_TitleCase (pfx = two or three letter module prefix)
Private functions   TitleCase
Trivial variables   i,x,n,f etc...
Local variables     lower_case or lowerCase
Global variables    g_lowerCase or g_lower_case (searchable by g_ prefix)
```
