all:  lc  sd race p6

lc: locCode.o
	gcc -pthread locCode.o  -o lc

locCode.o: locCode.c
	gcc -c locCode.c

sd: semdemo.o
	gcc -pthread semdemo.o  -o  sd

semdemo.o: semdemo.c
	gcc -c semdemo.c

race: race.o
	gcc -pthread race.o -o race

race.o: race.c
	gcc -c race.c

p6: prog06.o
	gcc -pthread prog06.o -o p6

prog06.o: prog06.c
	gcc -c prog06.c

clean:
	rm lc sd race p6 race.o locCode.o semdemo.o prog06.o