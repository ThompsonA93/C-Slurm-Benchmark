THREADS=1
DIM=100

gauss:
	gcc -mcmodel=large -fopenmp gauss.c -o gauss.o
	./gauss.o

sieve:
	gcc -mcmodel=large -fopenmp sieve.c -o sieve.o
	./sieve.o

quick:
	gcc -mcmodel=large -fopenmp -DTHREADS=$(THREADS) -DDIM=$(DIM) quick.c -o quick.o
	./quick.o

clean:
	rm *.o