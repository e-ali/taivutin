#include "entry.hh"

std::string Entry::sana() const
{
	return m_sana;
}
int Entry::hn() const
{
	return m_hn;
}
int Entry::n_taivutukset() const
{
	return m_n_taivutukset;
}

void Entry::sana(const std::string &sana)
{
	m_sana = sana;
}
void Entry::hn(const int hn)
{
	m_hn= hn;
}
void Entry::taivutus(const Inflection &t)
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
