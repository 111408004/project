project: make.o mini.o
	cc make.o mini.o -o project
make.o: make.c mini.h
	cc -Wall -c make.c
mini.o: mini.c mini.h
	cc -Wall -c mini.c

