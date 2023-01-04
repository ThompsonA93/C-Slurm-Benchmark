DIJKSTRA_VERTICES=5			# Dijkstra
SIEVE_MAX_VALUE=100			# Sieve
MATRIX_OP_DIM_1=250		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_2=250		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_3=250		# Matrix multiplication
SORTING_ELEMENTS=25000		# All sorting algorithms
THREADS=2					# OMP Threads

help:
	@echo "! Run project via make using argument: all bubble bucket counting insertion selection quick clean"
	@echo "! Always initialize running \"make mkdirs\""

all: mkdirs bubble bucket counting insertion selection quick

clean:
	rm -f *.out
	rm -rf ./build
	rm -rf ./log
	rm -rf ./profiles

mkdirs:
	mkdir -p build
	mkdir -p log
	mkdir -p profiles

bubble:
	gcc -pg -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) bubble_sort.c -o build/bubble_sort.out
	build/bubble_sort.out
	gprof build/bubble_sort.out gmon.out > profiles/bubble_sort.log
	tail -1 log/c_std.log

bucket:
	gcc -mcmodel=large -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) bucket_sort.c -o build/bucket_sort.out
	build/bucket_sort.out
	gprof build/bucket_sort.out gmon.out > profiles/bucket_sort.log
	tail -1 log/c_std.log

counting:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) counting_sort.c -o build/counting_sort.out
	build/counting_sort.out
	gprof build/counting_sort.out gmon.out > profiles/counting_sort.log
	tail -1 log/c_std.log

insertion:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) insertion_sort.c -o build/insertion_sort.out
	build/insertion_sort.out
	gprof build/insertion_sort.out gmon.out > profiles/insertion_sort.log
	tail -1 log/c_std.log

selection:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) selection_sort.c -o build/selection_sort.out
	build/selection_sort.out
	gprof build/selection_sort.out gmon.out > profiles/selection_sort.log
	tail -1 log/c_std.log

quick:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) quick_sort.c -o build/quick_sort.out
	build/quick_sort.out
	gprof build/quick_sort.out gmon.out > profiles/quick_sort.log
	tail -1 log/c_std.log
