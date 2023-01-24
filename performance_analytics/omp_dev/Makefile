THREADS=2
DIM=5

all: gauss sieve quick dijkstra

mkdirs:
	mkdir -p log

gauss: mkdirs
	gcc -mcmodel=large -fopenmp -DTHREADS=$(THREADS) -DDIM=$(DIM) gauss.c -o gauss.out
	./gauss.out

sieve: mkdirs
	gcc -mcmodel=large -fopenmp -DTHREADS=$(THREADS) -DDIM=$(DIM) sieve.c -o sieve.out
	./sieve.out

quick: mkdirs
	gcc -mcmodel=large -fopenmp -DTHREADS=$(THREADS) -DDIM=$(DIM) quick.c -o quick.out
	./quick.out

dijkstra: mkdirs
	gcc -mcmodel=large -fopenmp -DTHREADS=$(THREADS) -DDIM=$(DIM) dijkstra.c -o dijkstra.out
	./dijkstra.out

clean:
	rm -f *.out
	rm -f log/*.csv