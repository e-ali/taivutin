#ifndef NOMINAL_HH
#define NOMINAL_HH

#include <map>

#include "entry.hh"

/*
 * Singular, plural:
 *	 Nominative, genitive, partitive (NOM, GEN, PTV)
 *	 inessive, elative, illative, (INE, ELA, ILL)
 *	 adessive, ablative, allative, (ADE, ABL, ALL)
 *	 essive, translative, abessive, (ESS, TRANSL, ABE)
 * Plural:
 *	 instructive, comitative (INS, COM)
 */
class Nominal {
	Entry m_e;

	public:
	std::map<std::string, std::string> sg;
	std::map<std::string, std::string> pl;

	Nominal(Entry &e);

	void declense();
	void print(std::ostream &os);
};

#endif
