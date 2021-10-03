# Anthony Bahl
# Make File for Homework 3
# 10/3/2021

all: hw3 maxmin

hw3: program3.o
	gcc program3.o -o hw3

program3.o: program3.c
	gcc -c program3.c

maxmin: maxmin.o
	gcc maxmin.o

maxmin.o: maxmin.c
	gcc -c maxmin.c

clean:
	rm -f hw3 maxmin *.o