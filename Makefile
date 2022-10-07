help:
	@echo "Run project via make using command: all matmul sieve bubble quick"

all: lint matmul sieve bubble quick

matmul: 
	mkdir -p gprof; mkdir -p build; mkdir -p log;
	gcc -pg matrix_mult.c -o build/matrix_mult.out; build/matrix_mult.out
	gprof build/matrix_mult.out gmon.out > log/matrix_mult.log

sieve:
	mkdir -p gprof; mkdir -p build; mkdir -p log;
	gcc -pg eratostenes_sieve.c -o build/eratostenes_sieve.out; build/eratostenes_sieve.out
	gprof build/eratostenes_sieve.out gmon.out > log/eratostenes_sieve.log

bubble:
	mkdir -p gprof; mkdir -p build; mkdir -p log;
	gcc -pg bubble_sort.c -o build/bubble_sort.out; build/bubble_sort.out
	gprof build/bubble_sort.out gmon.out > log/bubble_sort.log

quick:
	mkdir -p gprof; mkdir -p build; mkdir -p log;
	gcc -pg quick_sort.c -o build/quick_sort.out; build/quick_sort.out
	gprof build/quick_sort.out gmon.out > log/quick_sort.log


clean:
	rm -f *.out
	rm -rf ./gprof
	rm -rf ./build

lint:
	cppcheck . -i ./log 