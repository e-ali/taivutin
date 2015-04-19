#include "inflection.hh"

void Inflection::tn(const int tn)
{
	m_tn = tn;
}

void Inflection::av(const char av)
{
	m_av = av;
}

void Inflection::t_attr(const std::string &attr)
{
	m_t_attr = attr;
}

void Inflection::av_attr(const std::string &attr)
{
	m_av_attr = attr;
}

int Inflection::tn() const {
	return m_tn;
}

char Inflection::av() const {
	return m_av;
}

std::string Inflection::t_attr() const
{
	return m_t_attr;
}

std::string Inflection::av_attr() const
{
	return m_av_attr;
}

void Inflection::print(std::ostream &os) {
	os << "Inflectionnumero: " << (m_tn? m_tn : 0)
		<< " | Asevaihtelutiedot: " << (m_av? m_av : '-')
		<< " | Inflection-attribuutti: " << (m_t_attr.size()? m_t_attr : "-")
		<< " | Astevaihtelu-attribuutti: " << (m_av_attr.size()? m_av_attr : "-")
		<< "\n";
}
