all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
gauss_Test: src/mat_io.c src/gauss.c src/test_elim.c
	cc src/mat_io.c src/gauss.c src/test_elim.c -o bin/test_elim.out
