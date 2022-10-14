help:
	@echo "Run project via make using command: all matmul gauss dijkstra sieve bubble bucket counting insertion selection quick"

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
	gcc -pg arithmetic/matrix_mult.c -o build/matrix_mult.out; build/matrix_mult.out
	gprof build/matrix_mult.out gmon.out > profiles/matrix_mult.log

gauss: mkdirs
	gcc -pg arithmetic/gaus_elim.c -o build/gaus_elim.out; build/gaus_elim.out
	gprof build/gaus_elim.out gmon.out > profiles/gaus_elim.log

dijkstra: mkdirs
	gcc -pg arithmetic/dijkstra.c -o build/dijkstra.out; build/dijkstra.out
	gprof build/dijkstra.out gmon.out > profiles/dijkstra.log

sieve: mkdirs
	gcc -pg arithmetic/eratostenes_sieve.c -o build/eratostenes_sieve.out; build/eratostenes_sieve.out
	gprof build/eratostenes_sieve.out gmon.out > profiles/eratostenes_sieve.log


bubble: mkdirs
	gcc -pg sorting/bubble_sort.c -o build/bubble_sort.out; build/bubble_sort.out
	gprof build/bubble_sort.out gmon.out > profiles/bubble_sort.log

bucket: mkdirs
	gcc -pg sorting/bucket_sort.c -o build/bucket_sort.out; build/bucket_sort.out
	gprof build/bucket_sort.out gmon.out > profiles/bucket_sort.log

counting: mkdirs
	gcc -pg sorting/counting_sort.c -o build/counting_sort.out; build/counting_sort.out
	gprof build/counting_sort.out gmon.out > profiles/counting_sort.log

insertion: mkdirs
	gcc -pg sorting/insertion_sort.c -o build/insertion_sort.out; build/insertion_sort.out
	gprof build/insertion_sort.out gmon.out > profiles/insertion_sort.log

selection: mkdirs
	gcc -pg sorting/selection_sort.c -o build/selection_sort.out; build/selection_sort.out
	gprof build/selection_sort.out gmon.out > profiles/selection_sort.log

quick: mkdirs
	gcc -pg sorting/quick_sort.c -o build/quick_sort.out; build/quick_sort.out
	gprof build/quick_sort.out gmon.out > profiles/quick_sort.log

