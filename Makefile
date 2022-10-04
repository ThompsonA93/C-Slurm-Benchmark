all: build run
	
build:
	gcc -pg matrix_mult.c -o matrix_mult.o

run:
	./matrix_mult.o 2 2 2 2

profile:
	gprof matrix_mult.o gmon.out

clean:
	rm *.o