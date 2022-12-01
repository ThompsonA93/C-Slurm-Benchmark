DIJKSTRA_VERTICES=5			# Dijkstra
SIEVE_MAX_VALUE=100			# Sieve
MATRIX_OP_DIM_1=2000			# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_2=2000		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_3=2000			# Matrix multiplication
SORTING_ELEMENTS=100000		# All sorting algorithms

help:
	@echo "Run project via make using command: all matmul gauss dijkstra sieve bubble bucket counting insertion selection quick clean"

all: matmul gauss dijkstra sieve bubble bucket counting insertion selection quick 

lint:
	cppcheck .

clean:
	rm -f *.out
	rm -rf ./build
	rm -rf ./log
	rm -rf ./profiles

mkdirs:
	mkdir -p build
	mkdir -p log
	mkdir -p profiles

matmul: mkdirs
	gcc -pg -D M=$(MATRIX_OP_DIM_1) -D N=$(MATRIX_OP_DIM_2) -D P=$(MATRIX_OP_DIM_3) arithmetic/matrix_mult.c -o build/matrix_mult.out
	build/matrix_mult.out
	gprof build/matrix_mult.out gmon.out > profiles/matrix_mult.log
	sed -n '5,11p' < profiles/matrix_mult.log

omp_matmul: mkdirs
	gcc -pg -fopenmp -D M=$(MATRIX_OP_DIM_1) -D N=$(MATRIX_OP_DIM_2) -D P=$(MATRIX_OP_DIM_3) arithmetic/omp_matrix_mult.c -o build/omp_matrix_mult.out
	build/omp_matrix_mult.out
	gprof build/omp_matrix_mult.out gmon.out > profiles/omp_matrix_mult.log
	sed -n '5,11p' < profiles/omp_matrix_mult.log


gauss: mkdirs
	gcc -pg -D M=$(MATRIX_OP_DIM_1) -D N=$(MATRIX_OP_DIM_2) arithmetic/gaus_elim.c -o build/gaus_elim.out
	build/gaus_elim.out
	gprof build/gaus_elim.out gmon.out > profiles/gaus_elim.log
	sed -n '5,11p' < profiles/gaus_elim.log

dijkstra: mkdirs
	gcc -pg -D VERTICE=$(DIJKSTRA_VERTICES) arithmetic/dijkstra.c -o build/dijkstra.out
	build/dijkstra.out
	gprof build/dijkstra.out gmon.out > profiles/dijkstra.log
	sed -n '5,11p' < profiles/dijkstra.log

sieve: mkdirs
	gcc -pg -D MAX_VALUE=$(SIEVE_MAX_VALUE) arithmetic/eratostenes_sieve.c -o build/eratostenes_sieve.out
	build/eratostenes_sieve.out
	gprof build/eratostenes_sieve.out gmon.out > profiles/eratostenes_sieve.log
	sed -n '5,9p' < profiles/eratostenes_sieve.log

bubble: mkdirs
	gcc -pg -fopenmp -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) sorting/bubble_sort.c -o build/bubble_sort.out
	build/bubble_sort.out
	gprof build/bubble_sort.out gmon.out > profiles/bubble_sort.log
	sed -n '5,13p' < profiles/bubble_sort.log

bucket: mkdirs
	gcc -pg -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) sorting/bucket_sort.c -o build/bucket_sort.out
	build/bucket_sort.out
	gprof build/bucket_sort.out gmon.out > profiles/bucket_sort.log
	sed -n '5,14p' < profiles/bucket_sort.log

counting: mkdirs
	gcc -pg -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) sorting/counting_sort.c -o build/counting_sort.out
	build/counting_sort.out
	gprof build/counting_sort.out gmon.out > profiles/counting_sort.log
	sed -n '5,12p' < profiles/counting_sort.log

insertion: mkdirs
	gcc -pg -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) sorting/insertion_sort.c -o build/insertion_sort.out
	build/insertion_sort.out
	gprof build/insertion_sort.out gmon.out > profiles/insertion_sort.log
	sed -n '5,12p' < profiles/insertion_sort.log

selection: mkdirs
	gcc -pg -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) sorting/selection_sort.c -o build/selection_sort.out
	build/selection_sort.out
	gprof build/selection_sort.out gmon.out > profiles/selection_sort.log
	sed -n '5,13p' < profiles/selection_sort.log

quick: mkdirs
	gcc -pg -D MAX_ARRAY_ELEMENTS=$(SORTING_ELEMENTS) sorting/quick_sort.c -o build/quick_sort.out
	build/quick_sort.out
	gprof build/quick_sort.out gmon.out > profiles/quick_sort.log
	sed -n '5,14p' < profiles/quick_sort.log
