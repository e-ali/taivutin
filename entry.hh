#ifndef ENTRY_HH
#define ENTRY_HH

#include <ostream>
#include <stdexcept>
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

	std::string get_sana() const;
	int get_hn() const;
	int get_inflections() const;
	Inflection get_inflection(const size_t) const;

	void print(std::ostream &os);
};

#endif
