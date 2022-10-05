help:
	@echo "Run project via make using command: all, build, run, profile, clean"

all: build run profile
	
build:
	gcc -pg matrix_mult.c -o matrix_mult.out

run:
	./matrix_mult.out

profile:
	mkdir -p gprof
	gprof matrix_mult.out gmon.out > gprof/matrix_mult.log

clean:
	rm -f *.out
	rm -rf ./gprof