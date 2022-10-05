all: build run
	
build:
	gcc -pg matrix_mult.c -o matrix_mult.out

run:
	./matrix_mult.out

profile:
	gprof matrix_mult.out gmon.out

clean:
	rm *.out