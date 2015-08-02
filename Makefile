CC=clang++
CFLAGS=-std=c++11
LDFLAGS=-lxerces-c

taivutin: inflection.o entry.o xml.o kotus.o verb.o nominal_consonant.o nominal_categories.o nominal.o inflect.o main.o
	${CC} ${CFLAGS} ${LDFLAGS} inflection.o entry.o xml.o kotus.o verb.o nominal_consonant.o nominal_categories.o nominal.o inflect.o main.o -o taivutin

main.o: main.cc
	${CC} ${CFLAGS} -c main.cc

inflect.o: inflect.cc inflect.hh
	${CC} ${CFLAGS} -c inflect.cc

nominal.o: nominal.cc nominal.hh
	${CC} ${CFLAGS} -c nominal.cc

nominal_categories.o: nominal_categories.cc nominal_categories.hh
	${CC} ${CFLAGS} -c nominal_categories.cc

nominal_consonant.o: nominal_consonant.cc nominal_consonant.hh
	${CC} ${CFLAGS} -c nominal_consonant.cc

verb.o: verb.cc verb.hh
	${CC} ${CFLAGS} -c verb.cc

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
