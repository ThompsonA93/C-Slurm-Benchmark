DIJKSTRA_VERTICES=5			# Dijkstra
SIEVE_MAX_VALUE=100			# Sieve
MATRIX_OP_DIM_1=250		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_2=250		# Matrix multiplication, Gauss elimination
MATRIX_OP_DIM_3=250		# Matrix multiplication

help:
	@echo "Run project via make using command: all mkdirs matmul gauss dijkstra sieve clean"
	@echo "Always initialize running \"make mkdirs\""

all: mkdirs matmul gauss dijkstra sieve

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
	gcc -pg -D M=$(MATRIX_OP_DIM_1) -D N=$(MATRIX_OP_DIM_2) -D P=$(MATRIX_OP_DIM_3) matrix_mult.c -o build/matrix_mult.out
	build/matrix_mult.out
	gprof build/matrix_mult.out gmon.out > profiles/matrix_mult.log
	tail -1 log/c_std.log

gauss:
	gcc -pg -fopenmp -D M=$(MATRIX_OP_DIM_1) -D N=$(MATRIX_OP_DIM_2) gaus_elim.c -o build/gaus_elim.out
	build/gaus_elim.out
	gprof build/gaus_elim.out gmon.out > profiles/gaus_elim.log
	tail -1 log/c_std.log

dijkstra:
	gcc -pg -fopenmp -D VERTICE=$(DIJKSTRA_VERTICES) dijkstra.c -o build/dijkstra.out
	build/dijkstra.out
	gprof build/dijkstra.out gmon.out > profiles/dijkstra.log
	tail -1 log/c_std.log

sieve:
	gcc -pg -fopenmp -D MAX_VALUE=$(SIEVE_MAX_VALUE) eratostenes_sieve.c -o build/eratostenes_sieve.out
	build/eratostenes_sieve.out
	gprof build/eratostenes_sieve.out gmon.out > profiles/eratostenes_sieve.log
	tail -1 log/c_std.log
