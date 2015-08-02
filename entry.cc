#include "entry.hh"

std::string Entry::get_sana() const
{
	return m_sana;
}

int Entry::get_hn() const
{
	return m_hn;
}

int Entry::get_inflections() const
{
	return m_n_taivutukset;
}

Inflection Entry::get_inflection(size_t const i) const
{
	if (i <= m_n_taivutukset)
		return m_taivutukset[i];
	else
		throw std::out_of_range("Out of range: Inflection data doesn't exist.");
}

void Entry::sana(const std::string &sana)
{
	m_sana = sana;
}

void Entry::hn(const int hn)
{
	m_hn= hn;
}

void Entry::inflection(const Inflection &t)
{
	m_taivutukset.push_back(t);
	m_n_taivutukset++;
}

void Entry::print(std::ostream &os)
{
	os << "Sana: " << (m_sana.length()? m_sana : "")
		<< " | Homonyyminumero: " << (m_hn? m_hn : 0)
		<< '\n';
		for (int i = 0; i < m_n_taivutukset; i++)
			m_taivutukset[i].print(os);
}
