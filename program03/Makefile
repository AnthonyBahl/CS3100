# Anthony Bahl
# Make File for Homework 3
# 10/3/2021

all: makeclean hw3 maxmin gendata datafile

makeclean:
	make clean

hw3: program3.o
	gcc program3.o -o hw3

program3.o: program3.c
	gcc -c program3.c

maxmin: maxmin.o
	gcc maxmin.o -o maxmin

maxmin.o: maxmin.c
	gcc -c maxmin.c

gendata: createDataFile.o
	gcc createDataFile.o -o gendata

createDataFile.o: createDataFile.c
	gcc -c createDataFile.c

datafile: gendata
	./gendata datafile 1000000

clean:
	rm -f *.o *.txt datafile gendata hw3 maxmin