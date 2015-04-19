CC=clang++
CFLAGS=-std=c++11
LDFLAGS=-lxerces-c

taivutin: inflection.o entry.o xml.o kotus.o main.o
	${CC} ${CFLAGS} ${LDFLAGS} inflection.o entry.o xml.o kotus.o main.o -o taivutin

main.o: main.cc
	${CC} ${CFLAGS} -c main.cc

kotus.o: kotus.cc kotus.hh
	${CC} ${CFLAGS} -c kotus.cc

xml.o: xml.cc xml.hh
	${CC} ${CFLAGS} ${LDFLAGS} -c xml.cc

entry.o: entry.cc entry.hh
	${CC} ${CFLAGS} -c entry.cc

inflection.o: inflection.cc inflection.hh
	${CC} ${CFLAGS} -c inflection.cc

clean:
		rm -v *.o
