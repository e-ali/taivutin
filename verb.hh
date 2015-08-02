#ifndef VERB_HH
#define VERB_HH

#include "entry.hh"

class Verb {
	Entry m_e;

	public:
	Verb(Entry &e);

	void conjugate();
	void print(std::ostream &os);
};

#endif
