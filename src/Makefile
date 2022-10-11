help:
	@echo "Run project via make using command: all matmul gauss dijkstra sieve bubble bucket counting insertion selection quick"

all: matmul gauss dijkstra sieve bubble bucket counting insertion selection quick 

clean:
	rm -f *.out
	rm -rf ./gprof
	rm -rf ./build

lint:
	cppcheck .

mkdirs:
	mkdir -p gprof
	mkdir -p build
	mkdir -p profiles
	mkdir -p log

matmul: mkdirs
	gcc -pg matrix_mult.c -o build/matrix_mult.out; build/matrix_mult.out
	gprof build/matrix_mult.out gmon.out > profiles/matrix_mult.log

gauss:
	gcc -pg gaus_elim.c -o build/gaus_elim.out; build/gaus_elim.out
	gprof build/gaus_elim.out gmon.out > profiles/gaus_elim.log

dijkstra:
	gcc -pg dijkstra.c -o build/dijkstra.out; build/dijkstra.out
	gprof build/dijkstra.out gmon.out > profiles/dijkstra.log

sieve: mkdirs
	gcc -pg eratostenes_sieve.c -o build/eratostenes_sieve.out; build/eratostenes_sieve.out
	gprof build/eratostenes_sieve.out gmon.out > profiles/eratostenes_sieve.log

bubble: mkdirs
	gcc -pg bubble_sort.c -o build/bubble_sort.out; build/bubble_sort.out
	gprof build/bubble_sort.out gmon.out > profiles/bubble_sort.log

bucket:
	gcc -pg bucket_sort.c -o build/bucket_sort.out; build/bucket_sort.out
	gprof build/bucket_sort.out gmon.out > profiles/bucket_sort.log

counting: 
	gcc -pg counting_sort.c -o build/counting_sort.out; build/counting_sort.out
	gprof build/counting_sort.out gmon.out > profiles/counting_sort.log

insertion: mkdirs
	gcc -pg insertion_sort.c -o build/insertion_sort.out; build/insertion_sort.out
	gprof build/insertion_sort.out gmon.out > profiles/insertion_sort.log

selection: 
	gcc -pg selection_sort.c -o build/selection_sort.out; build/selection_sort.out
	gprof build/selection_sort.out gmon.out > profiles/selection_sort.log

quick: mkdirs
	gcc -pg quick_sort.c -o build/quick_sort.out; build/quick_sort.out
	gprof build/quick_sort.out gmon.out > profiles/quick_sort.log

