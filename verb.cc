#include <iostream>

#include "verb.hh"

Verb::Verb(Entry &e) {
	m_e = e;
}

void Verb::conjugate() {
}

void Verb::print(std::ostream &os)
{
	std::cout << "The word is a verb.\n";
	std::cout << "Verb inflection not yet implemented. Printing the Kotus data instead.\n";
	m_e.print(std::cout);
}
