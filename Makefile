all:  lc  sd race

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

clean:
	rm lc sd race race.o locCode.o semdemo.o