#include <iostream>
#include <iomanip>

#include "nominal.hh"

Nominal::Nominal(Entry &e) {
	m_e = e;
std::array<std::string,14> all_cases{
		"NOM", "GEN", "PTV",
		"INE", "ELA", "ILL",
		"ADE", "ABL", "ALL",
		"ESS", "TRANSL", "ABE",
		"INS", "COM"};

	for (int i = 0; i < all_cases.size(); i++) {
		sg[all_cases[i]] = "-";
		pl[all_cases[i]] = "-";
	}
	sg["NOM"] = m_e.get_sana();

	/* fill all the cases */
	for (int i = 0; i < all_cases.size(); i++)
	{
		if (all_cases[i] != "INS" && all_cases[i] != "COM")
			sg[all_cases[i]] = sg["NOM"];
		pl[all_cases[i]] = sg["NOM"];
	}
}

void Nominal::declense() {
}

void Nominal::print(std::ostream &os)
{
	std::cout << "The word is a noun.\n";

	for (int i = 0; i < 45; i++)
		std::cout << '-';
	std::cout << std::endl;

	std::array<std::string,14> cases{"NOM", "GEN", "PTV",
		"INE", "ELA", "ILL",
		"ADE", "ABL", "ALL",
		"ESS", "TRANSL", "ABE",
		"INS", "COM"};
	std::array<std::string,14> cases_full{"Nominative", "Genitive", "Partitive",
		"Inessive", "Elative", "Illative",
		"Adessive", "Ablative", "Allative",
		"Essive", "Translative", "Abessive",
		"Instructive", "Comitative"};

	std::cout << "Case" << "\t\t" << "Singular" << '\t' << "Plural" << std::endl;
	std::cout.setf(std::ios::left);
	for (int i = 0; i < cases.size(); i++)
	{
		std::cout << std::setw(12) << cases_full[i] << ": "
			<< std::setw(12) << sg[cases[i]]
			<< '\t'
			<< std::setw(12) << pl[cases[i]]
			<< std::endl;
	}
	std::cout.unsetf(std::ios::left);

	for (int i = 0; i < 45; i++)
		std::cout << '-';
	std::cout << std::endl;
}
