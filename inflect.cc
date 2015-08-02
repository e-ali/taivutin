#include <iostream>

#include "kotus.hh"
#include "inflect.hh"
#include "entry.hh"

#include "nominal.hh"
#include "verb.hh"

void inflect(std::string word, Kotus &kotus) {
	try {
		Entry e;
		e = kotus.search(word);

		for (size_t i = 0; i < e.get_inflections(); i++) {
			Inflection inf = e.get_inflection(i);

			if (inf.tn() == 99) {
				std::cout << "Sana on taipumaton.\n";
			} else if (inf.tn() >= 1 && inf.tn() <= 51) {
				Nominal nimi(e);
				nimi.declense();
				nimi.print(std::cout);
			} else if (inf.tn() >= 52 && inf.tn() <= 78) {
				Verb verb(e);
				verb.conjugate();
				verb.print(std::cout);
			}
		}
	}
	catch (const std::range_error &e) {
		std::cout << e.what() << std::endl;
	}
}
