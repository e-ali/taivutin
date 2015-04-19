CC=g++
CFLAGS=-std=c++11

taivutin: inflection.o entry.o main.o
		${CC} ${CFLAGS} inflection.o entry.o main.o -o taivutin

main.o: main.cc
		${CC} ${CFLAGS} -c main.cc

entry.o: entry.cc entry.hh
		${CC} ${CFLAGS} -c entry.cc

inflection.o: inflection.cc inflection.hh
		${CC} ${CFLAGS} -c inflection.cc

clean:
		rm -v *.o
