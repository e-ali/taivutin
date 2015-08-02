#ifndef INFLECTION_HH
#define INFLECTION_HH

#include <ostream>
#include <string>

class Inflection {
	public:
	Inflection(const int tn = 0, const char av = 0,
			const std::string t_attr = "", const std::string av_attr = "")
		: m_tn(tn), m_av(av), m_t_attr(t_attr), m_av_attr(av_attr) {}

	void tn(const int);
	void av(const char);
	void t_attr(const std::string &);
	void av_attr(const std::string &);

	int tn() const;
	char av() const;
	std::string t_attr() const;
	std::string av_attr() const;

	void print(std::ostream &os);

	private:
	int m_tn;			  // Inflection number.
	std::string m_t_attr;  // Inflection attribute.
	char m_av;			 // Consonant gradation type.
	std::string m_av_attr; // Consonant gradation attribute.
};

#endif
