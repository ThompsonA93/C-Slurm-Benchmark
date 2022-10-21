[![C Build](https://github.com/ThompsonA93/C-Slurm-Benchmark/actions/workflows/build.yml/badge.svg)](https://github.com/ThompsonA93/C-Slurm-Benchmark/actions/workflows/build.yml)

# C-Slurm-Benchmark

| Environment | Version |
| ----------- | ------- |
| Ubuntu | 20.04.5 LTS |
| GCC | 9.4.0 |
| GNU Make | 4.2.1 |

## Todo
- [x] Matrix Multiplication
- [~] Gaussian Elimination
    - Bugs the array to 0 on higher dimensions for some reasons.
- [ ] Dijstkra
- [x] Sieve of Eratosthenes
- [x] Bubble sort
- [x] Bucket sort
- [x] Counting sort
    - Incorrect time displayed by clock_t
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
