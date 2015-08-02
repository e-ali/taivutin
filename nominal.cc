#include <iostream>
#include <iomanip>

#include "nominal_categories.hh"

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
	for (int i = 0; i < all_cases.size(); i++) {
		if (all_cases[i] != "INS" && all_cases[i] != "COM")
			sg[all_cases[i]] = sg["NOM"];
		pl[all_cases[i]] = sg["NOM"];
	}
}

void Nominal::declense() {
	int tn = 0;

	if (m_e.get_inflections() > 0) {
		tn = m_e.get_inflection(0).tn();
	}

	Entry entry = m_e;

	switch (tn) {
		case  1: cat1 (this,entry); break;
		case  2: cat2 (this,entry); break;
		case  3: cat3 (this,entry); break;
		case  4: cat4 (this,entry); break;
		case  5: cat5 (this,entry); break;
		case  6: cat6 (this,entry); break;
		case  7: cat7 (this,entry); break;
		case  8: cat8 (this,entry); break;
		case  9: cat9 (this,entry); break;
		case 10: cat10(this,entry); break;
		case 11: cat11(this,entry); break;
		case 12: cat12(this,entry); break;
		case 13: cat13(this,entry); break;
		case 14: cat14(this,entry); break;
		case 15: cat15(this,entry); break;
		case 16: cat16(this,entry); break;
		case 17: cat17(this,entry); break;
		case 18: cat18(this,entry); break;
		case 19: cat19(this,entry); break;
		case 20: cat20(this,entry); break;
		case 21: cat21(this,entry); break;
		case 22: cat22(this,entry); break;
		case 23: cat23(this,entry); break;
		case 24: cat24(this,entry); break;
		case 25: cat25(this,entry); break;
		case 26: cat26(this,entry); break;
		case 27: cat27(this,entry); break;
		case 28: cat28(this,entry); break;
		case 29: cat29(this,entry); break;
		case 30: cat30(this,entry); break;
		case 31: cat31(this,entry); break;
		case 32: cat32(this,entry); break;
		case 33: cat33(this,entry); break;
		case 34: cat34(this,entry); break;
		case 35: cat35(this,entry); break;
		case 36: cat36(this,entry); break;
		case 37: cat37(this,entry); break;
		case 38: cat38(this,entry); break;
		case 39: cat39(this,entry); break;
		case 40: cat40(this,entry); break;
		case 41: cat41(this,entry); break;
		case 42: cat42(this,entry); break;
		case 43: cat43(this,entry); break;
		case 44: cat44(this,entry); break;
		case 45: cat45(this,entry); break;
		case 46: cat46(this,entry); break;
		case 47: cat47(this,entry); break;
		case 48: cat48(this,entry); break;
		case 49: cat49(this,entry); break;
		case 50: cat50(this,entry); break;
		default: break;
	}
}

void Nominal::print(std::ostream &os)
{
	std::cout << "The word is a noun.\n";

	for (int i = 0; i < 45; i++) {
		std::cout << '-';
	}
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
	for (int i = 0; i < cases.size(); i++) {
		std::cout << std::setw(12) << cases_full[i] << ": "
			<< std::setw(12) << sg[cases[i]]
			<< '\t'
			<< std::setw(12) << pl[cases[i]]
			<< std::endl;
	}
	std::cout.unsetf(std::ios::left);

	for (int i = 0; i < 45; i++) {
		std::cout << '-';
	}
	std::cout << std::endl;
}
