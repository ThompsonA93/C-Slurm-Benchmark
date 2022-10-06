help:
	@echo "Run project via make using command: matmul sieve"


matmul: 
	gcc -pg matrix_mult.c -o matrix_mult.out
	./matrix_mult.out
	mkdir -p gprof
	gprof matrix_mult.out gmon.out > gprof/matrix_mult.log

sieve:
	gcc -pg eratostenes_sieve.c -o eratostenes_sieve.out
	./eratostenes_sieve.out
	mkdir -p gprof
	gprof eratostenes_sieve.out gmon.out > gprof/eratostenes_sieve.log



clean:
	rm -f *.out
	rm -rf ./gprof

