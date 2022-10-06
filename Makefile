help:
	@echo "Run project via make using command: matmul sieve"


matmul: 
	mkdir -p gprof; mkdir -p build;
	gcc -pg matrix_mult.c -o matrix_mult.out
	./matrix_mult.out
	gprof matrix_mult.out gmon.out > gprof/matrix_mult.log

sieve:
	mkdir -p gprof; mkdir -p build;
	gcc -pg eratostenes_sieve.c -o build/eratostenes_sieve.out; build/eratostenes_sieve.out
	gprof build/eratostenes_sieve.out gprof/gmon.out > gprof/eratostenes_sieve.log



clean:
	rm -f *.out
	rm -rf ./gprof
	rm -rf ./build

lint:
	cppcheck . -i ./log 