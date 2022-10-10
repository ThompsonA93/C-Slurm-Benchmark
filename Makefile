help:
	@echo "Run project via make using command: all matmul sieve bubble quick"

all: matmul sieve bubble quick insertion

clean:
	rm -f *.out
	rm -rf ./gprof
	rm -rf ./build

lint:
	cppcheck . -i ./log 

mkdirs:
	mkdir -p gprof
	mkdir -p build
	mkdir -p log

matmul: mkdirs
	gcc -pg matrix_mult.c -o build/matrix_mult.out; build/matrix_mult.out
	gprof build/matrix_mult.out gmon.out > log/matrix_mult.log

sieve: mkdirs
	gcc -pg eratostenes_sieve.c -o build/eratostenes_sieve.out; build/eratostenes_sieve.out
	gprof build/eratostenes_sieve.out gmon.out > log/eratostenes_sieve.log

bubble: mkdirs
	gcc -pg bubble_sort.c -o build/bubble_sort.out; build/bubble_sort.out
	gprof build/bubble_sort.out gmon.out > log/bubble_sort.log

quick: mkdirs
	gcc -pg quick_sort.c -o build/quick_sort.out; build/quick_sort.out
	gprof build/quick_sort.out gmon.out > log/quick_sort.log

insertion: mkdirs
	gcc -pg insertion_sort.c -o build/insertion_sort.out; build/insertion_sort.out
	gprof build/insertion_sort.out gmon.out > log/insertion_sort.log

