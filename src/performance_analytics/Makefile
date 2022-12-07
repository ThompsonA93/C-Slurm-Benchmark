DIJKSTRA_VERTICES=5			# Dijkstra
SIEVE_MAX_VALUE=100			# Sieve
MATRIX_OP_DIM_1=250		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_2=250		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_3=250		# Matrix multiplication
SORTING_ELEMENTS=25000		# All sorting algorithms
THREADS=2					# OMP Threads

help:
	@echo "Run project via make using command: all matmul gauss dijkstra sieve bubble bucket counting insertion selection quick clean"
	@echo "Always initialize running \"make mkdirs\""

all: matmul gauss dijkstra sieve bubble bucket counting insertion selection quick omp_matmul brick omp_bucket omp_counting omp_selection

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
	gcc -pg -D M=$(MATRIX_OP_DIM_1) -D N=$(MATRIX_OP_DIM_2) -D P=$(MATRIX_OP_DIM_3) arithmetic/matrix_mult.c -o build/matrix_mult.out
	build/matrix_mult.out
	gprof build/matrix_mult.out gmon.out > profiles/matrix_mult.log
	tail -1 log/c_std.log

omp_matmul:
	gcc -pg -fopenmp -D M=$(MATRIX_OP_DIM_1) -D N=$(MATRIX_OP_DIM_2) -D P=$(MATRIX_OP_DIM_3) -D OMP_THREADS=$(THREADS) arithmetic/omp_matrix_mult.c -o build/omp_matrix_mult.out
	build/omp_matrix_mult.out
	gprof build/omp_matrix_mult.out gmon.out > profiles/omp_matrix_mult.log
	tail -1 log/c_std.log

gauss:
	gcc -pg -fopenmp -D M=$(MATRIX_OP_DIM_1) -D N=$(MATRIX_OP_DIM_2) arithmetic/gaus_elim.c -o build/gaus_elim.out
	build/gaus_elim.out
	gprof build/gaus_elim.out gmon.out > profiles/gaus_elim.log
	tail -1 log/c_std.log

dijkstra:
	gcc -pg -fopenmp -D VERTICE=$(DIJKSTRA_VERTICES) arithmetic/dijkstra.c -o build/dijkstra.out
	build/dijkstra.out
	gprof build/dijkstra.out gmon.out > profiles/dijkstra.log
	tail -1 log/c_std.log

sieve:
	gcc -pg -fopenmp -D MAX_VALUE=$(SIEVE_MAX_VALUE) arithmetic/eratostenes_sieve.c -o build/eratostenes_sieve.out
	build/eratostenes_sieve.out
	gprof build/eratostenes_sieve.out gmon.out > profiles/eratostenes_sieve.log
	tail -1 log/c_std.log

bubble:
	gcc -pg -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) sorting/bubble_sort.c -o build/bubble_sort.out
	build/bubble_sort.out
	gprof build/bubble_sort.out gmon.out > profiles/bubble_sort.log
	tail -1 log/c_std.log

brick:
	gcc -pg -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) sorting/brick_sort.c -o build/brick_sort.out
	build/brick_sort.out
	gprof build/brick_sort.out gmon.out > profiles/brick_sort.log
	tail -1 log/c_std.log


bucket:
	gcc -mcmodel=large -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) sorting/bucket_sort.c -o build/bucket_sort.out
	build/bucket_sort.out
	gprof build/bucket_sort.out gmon.out > profiles/bucket_sort.log
	tail -1 log/c_std.log

omp_bucket:
	gcc -mcmodel=large -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) sorting/omp_bucket_sort.c -o build/omp_bucket_sort.out
	build/omp_bucket_sort.out
	gprof build/bucket_sort.out gmon.out > profiles/omp_bucket_sort.log
	tail -1 log/c_std.log

counting:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) sorting/counting_sort.c -o build/counting_sort.out
	build/counting_sort.out
	gprof build/counting_sort.out gmon.out > profiles/counting_sort.log
	tail -1 log/c_std.log

omp_counting:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) sorting/omp_counting_sort.c -o build/omp_counting_sort.out
	build/omp_counting_sort.out
	gprof build/omp_counting_sort.out gmon.out > profiles/omp_counting_sort.log
	tail -1 log/c_std.log


insertion:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) sorting/insertion_sort.c -o build/insertion_sort.out
	build/insertion_sort.out
	gprof build/insertion_sort.out gmon.out > profiles/insertion_sort.log
	tail -1 log/c_std.log

selection:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) -D OMP_THREADS=$(THREADS) sorting/selection_sort.c -o build/selection_sort.out
	build/selection_sort.out
	gprof build/selection_sort.out gmon.out > profiles/selection_sort.log
	tail -1 log/c_std.log

quick:
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) sorting/quick_sort.c -o build/quick_sort.out
	build/quick_sort.out
	gprof build/quick_sort.out gmon.out > profiles/quick_sort.log
	tail -1 log/c_std.log
