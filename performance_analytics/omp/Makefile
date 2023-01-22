DIJKSTRA_VERTICES=5			# Dijkstra
SIEVE_MAX_VALUE=100			# Sieve
MATRIX_OP_DIM_1=250		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_2=250		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_3=250		# Matrix multiplication


SORTING_ELEMENTS=50000		# All sorting algorithms
THREADS=2					# OMP Threads

help:
	@echo "! Run project via make using command: all mkdirs matmul brick bucket selection insertion counting clean"
	@echo "! Always initialize running \"make mkdirs\""

all: mkdirs matmul brick bucket selection insertion counting

clean:
	rm -f *.out
	rm -rf ./build
	rm -rf ./log
	rm -rf ./profiles

mkdirs:
	mkdir -p build
	mkdir -p log
	mkdir -p profiles

matmul:
	gcc -fopenmp -D M=$(MATRIX_OP_DIM_1) -D N=$(MATRIX_OP_DIM_2) -D P=$(MATRIX_OP_DIM_3) -D OMP_THREADS=$(THREADS) omp_matrix_mult.c -o build/omp_matrix_mult.out
	build/omp_matrix_mult.out
	tail -1 log/c_std.csv

bubble:
	gcc -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_bubble_sort.c -o build/omp_bubble_sort.out
	build/omp_bubble_sort.out
	tail -1 log/c_std.csv

brick:
	gcc -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_brick_sort.c -o build/brick_sort.out
	build/brick_sort.out
	tail -1 log/c_std.csv

bucket:
	gcc -mcmodel=large -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_bucket_sort.c -o build/bucket_sort.out
	build/bucket_sort.out
	tail -1 log/c_std.csv

counting:
	gcc -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_counting_sort.c -o build/counting_sort.out
	build/counting_sort.out
	tail -1 log/c_std.csv

insertion:
	gcc -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_insertion_sort.c -o build/insertion_sort.out
	build/insertion_sort.out
	tail -1 log/c_std.csv

selection:
	gcc -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_selection_sort.c -o build/selection_sort.out
	build/selection_sort.out
	tail -1 log/c_std.csv

quick:
	gcc -mcmodel=large -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_quick_sort.c -o build/quick_sort.out
	build/quick_sort.out
	tail -1 log/c_std.csv

sieve:
	gcc -mcmodel=large -fopenmp -D SIEVE_MAX_VALUE=$(SIEVE_MAX_VALUE) -D OMP_THREADS=$(THREADS) omp_sieve.c -o build/omp_sieve.out
	build/omp_sieve.out
	tail -1 log/c_std.csv