#ifndef ENTRY_HH
#define ENTRY_HH

#include <ostream>
#include <string>
#include <vector>

#include "inflection.hh"

class Entry {
	std::string m_sana;                  // The word itself.
	int m_hn;                            // Homonym number.
	int m_n_taivutukset;                 // Number of inflections.
	std::vector<Inflection> m_taivutukset; // The inflections.

	public:
	Entry(const std::string sana = "", const int hn = 0)
		: m_sana(sana), m_hn(hn), m_n_taivutukset(0) {}

	void sana(const std::string &);
	void hn(const int);
	void inflection(const Inflection &);

	std::string sana() const;
	int hn() const;
	int n_taivutukset() const;

	void print(std::ostream &os);
};

#endif
