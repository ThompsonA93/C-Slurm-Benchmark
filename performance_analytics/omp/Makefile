DIJKSTRA_VERTICES=5			# Dijkstra
SIEVE_MAX_VALUE=100			# Sieve
MATRIX_OP_DIM_1=250		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_2=250		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_3=250		# Matrix multiplication


SORTING_ELEMENTS=50000		# All sorting algorithms
THREADS=8					# OMP Threads

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
	gcc -pg -fopenmp -D M=$(MATRIX_OP_DIM_1) -D N=$(MATRIX_OP_DIM_2) -D P=$(MATRIX_OP_DIM_3) -D OMP_THREADS=$(THREADS) omp_matrix_mult.c -o build/omp_matrix_mult.out
	build/omp_matrix_mult.out
	gprof build/omp_matrix_mult.out gmon.out > profiles/omp_matrix_mult.log
	tail -1 log/c_std.csv

bubble:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_bubble_sort.c -o build/omp_bubble_sort.out
	build/omp_bubble_sort.out
	gprof build/omp_bubble_sort.out gmon.out > profiles/brick_sort.log
	tail -1 log/c_std.csv

brick:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_brick_sort.c -o build/brick_sort.out
	build/brick_sort.out
	gprof build/brick_sort.out gmon.out > profiles/brick_sort.log
	tail -1 log/c_std.csv

bucket:
	gcc -mcmodel=large -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_bucket_sort.c -o build/bucket_sort.out
	build/bucket_sort.out
	gprof build/bucket_sort.out gmon.out > profiles/bucket_sort.log
	tail -1 log/c_std.csv

counting:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_counting_sort.c -o build/counting_sort.out
	build/counting_sort.out
	gprof build/counting_sort.out gmon.out > profiles/counting_sort.log
	tail -1 log/c_std.csv

insertion:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_insertion_sort.c -o build/insertion_sort.out
	build/insertion_sort.out
	gprof build/insertion_sort.out gmon.out > profiles/insertion_sort.log
	tail -1 log/c_std.csv

selection:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) omp_selection_sort.c -o build/selection_sort.out
	build/selection_sort.out
	gprof build/selection_sort.out gmon.out > profiles/selection_sort.log
	tail -1 log/c_std.csv