#include <iostream>
#include <string>

#include "nominal.hh"
#include "nominal_categories.hh"
#include "nominal_consonant.hh"

std::array<std::string,14> all_cases{
	"NOM", "GEN", "PTV",
	"INE", "ELA", "ILL",
	"ADE", "ABL", "ALL",
	"ESS", "TRANSL", "ABE",
	"INS", "COM"};

std::string replace_substr(std::string &s,
		std::string to_replace,
		std::string replace_with)
{
	return (s.replace(s.find(to_replace), to_replace.length(), replace_with));
}

int suffix_cases(Nominal *noun)
{
	std::array<std::string,5>
		loc_abbr{"INE", "ELA", "ADE", "ABL", "ALL"};
	std::array<std::string,5>
		loc_back{"ssa", "sta", "lla", "lta", "lle"};
	std::array<std::string,5>
		loc_front{"ssä", "stä", "llä", "ltä", "lle"};

	std::array<std::string,3> misc_abbr{"TRANSL", "ESS", "ABE"};
	std::array<std::string,3> misc_back{"ksi", "na", "tta"};
	std::array<std::string,3> misc_front{"ksi", "nä", "ttä"};

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		/* locations */
		for (int i = 0; i < loc_abbr.size(); i++) {
			noun->sg[loc_abbr[i]] += loc_back[i];
			noun->pl[loc_abbr[i]] += ("i" + loc_back[i]);
		}
		/* translative, essive, abessive */
		for (int i = 0; i < misc_abbr.size(); i++) {
			noun->sg[misc_abbr[i]] += misc_back[i];
			noun->pl[misc_abbr[i]] += ("i" + misc_back[i]);
		}
	} else {
		/* locations */
		for (int i = 0; i < loc_abbr.size(); i++) {
			noun->sg[loc_abbr[i]] += loc_front[i];
			noun->pl[loc_abbr[i]] += ("i" + loc_front[i]);
		}
		/* translative, essive, abessive */
		for (int i = 0; i < misc_abbr.size(); i++) {
			noun->sg[misc_abbr[i]] += misc_front[i];
			noun->pl[misc_abbr[i]] += ("i" + misc_front[i]);
		}
	}
	return 0;
}

int cat1(Nominal *noun, Entry &entry)
{
	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "jen";

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["ILL"] += noun->sg["NOM"].back();

		noun->sg["PTV"] += 'a';
		noun->pl["PTV"] += "ja";
	} else {
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);

		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "jä";
	}
	noun->sg["ILL"] += 'n';
	noun->pl["ILL"] += "ihin";

	kv(noun);

	return 0;
}

int cat2(Nominal *noun, Entry &entry)
{
	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "jen"; /* also "uiden" and "uitten" */

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["ILL"] += noun->sg["NOM"].back();

		noun->sg["PTV"] += 'a';
		noun->pl["PTV"] += "ja"; /* also "ita" */
	} else {
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);

		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "jä";
	}
	noun->sg["ILL"] += 'n';
	noun->pl["ILL"] += "ihin";

	kv(noun);

	return 0;
}

int cat3(Nominal *noun, Entry &entry)
{
	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "iden"; /* also "itten" */

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["ILL"] += noun->sg["NOM"].back();

		noun->sg["PTV"] += "ta";
		noun->pl["PTV"] += "ita"; /* also "ita" */
	} else {
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);

		noun->sg["PTV"] += "tä";
		noun->pl["PTV"] += "itä";
	}
	noun->sg["ILL"] += 'n';
	noun->pl["ILL"] += "ihin";

	kv(noun);

	return 0;
}

int cat4(Nominal *noun, Entry &entry)
{
	/* Gradate kk -> k */
	std::string tmp =
		(noun->sg["GEN"].erase(noun->sg["GEN"].length()-2,1));

	noun->sg["GEN"] = tmp;
	noun->sg["INE"] = tmp; noun->sg["ELA"] = tmp;
	noun->sg["ADE"] = tmp; noun->sg["ABL"] = tmp; noun->sg["ALL"] = tmp;
	noun->sg["TRANSL"] = tmp; noun->sg["ABE"] = tmp;

	noun->pl["NOM"] = tmp;
	noun->pl["INE"] = tmp; noun->pl["ELA"] = tmp;
	noun->pl["ADE"] = tmp; noun->pl["ABL"] = tmp; noun->pl["ALL"] = tmp;
	noun->pl["TRANSL"] = tmp; noun->pl["ABE"] = tmp;
	noun->pl["INS"] = tmp;

	/* Inflect */
	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "jen"; /* also gradate + "iden" and "itten" */

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["ILL"] += noun->sg["NOM"].back();

		noun->sg["PTV"] += 'a';
		noun->pl["PTV"] += "ja"; /* also "ita" */
	} else {
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);

		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "jä";
	}
	noun->sg["ILL"] += 'n';
	noun->pl["ILL"] += "ihin";

	kv(noun);

	return 0;
}

int cat5(Nominal *noun, Entry &entry)
{
	/* substitute/i$/e/ */
	noun->pl["PTV"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["INE"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ELA"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ILL"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ADE"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ABL"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ALL"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ESS"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["TRANSL"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["INS"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ABE"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["COM"].replace( noun->pl["PTV"].length()-1, 1, "e");

	/* inflect */
	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "en";

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["ILL"] += noun->sg["NOM"].back();

		noun->sg["PTV"] += 'a';
		noun->pl["PTV"] += "ja";
	} else {
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);

		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "jä";
	}
	noun->sg["ILL"] += 'n';
	noun->pl["ILL"] += "ihin";

	kv(noun);

	return 0;
}

int cat6(Nominal *noun, Entry &entry)
{
	/* substitute/i$/e/ */
	noun->pl["PTV"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["INE"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ELA"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ILL"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ADE"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ABL"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ALL"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ESS"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["TRANSL"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["INS"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["ABE"].replace( noun->pl["PTV"].length()-1, 1, "e");
	noun->pl["COM"].replace( noun->pl["PTV"].length()-1, 1, "e");

	/* inflect */
	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "en"; /* also: s/i$/e + -iden or -itten */

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["ILL"] += noun->sg["NOM"].back();

		noun->sg["PTV"] += 'a';
		noun->pl["PTV"] += "ja"; /* also: -ita */
	} else {
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);

		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "jä";
	}
	noun->sg["ILL"] += 'n';
	noun->pl["ILL"] += "ihin";

	kv(noun);

	return 0;
}

int cat7(Nominal *noun, Entry &entry)
{
	for (int i = 0; i < all_cases.size(); i++) {
		if (all_cases[i] != "NOM" &&
			all_cases[i] != "INS" && all_cases[i] != "COM")
			noun->sg[all_cases[i]].replace(
					noun->sg[all_cases[i]].length()-1,
					1, "e");
		if (all_cases[i] != "NOM" && all_cases[i] != "ILL")
			noun->pl[all_cases[i]].pop_back();
	}

	/* inflect */
	noun->pl["NOM"].pop_back(); noun->pl["NOM"] += "et";
	noun->sg["GEN"] += "n";
	noun->pl["GEN"] += "ien";

	noun->sg["ILL"].pop_back(); noun->sg["ILL"] += "een";
	noun->pl["ILL"].pop_back(); noun->pl["ILL"] += "iin";

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["PTV"] += 'a';
		noun->pl["PTV"] += "ia";
	} else {
		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "iä";
	}

	kv(noun);

	return 0;
}

int cat8(Nominal *noun, Entry &entry)
{
	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "jen"; /* also: -in */

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["ILL"] += noun->sg["NOM"].back();

		noun->sg["PTV"] += 'a';
		noun->pl["PTV"] += "ja";
	} else {
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);

		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "jä";
	}
	noun->sg["ILL"] += 'n';
	noun->pl["ILL"] += "ihin";

	kv(noun);

	return 0;
}

int cat9(Nominal *noun, Entry &entry)
{
	/* for all plurals except nominal: s/a$/o/ */
	for (int i = 1; i < all_cases.size(); i++)
		noun->pl[all_cases[i]].replace(
				noun->pl[all_cases[i]].length()-1,
				1, "o");

	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "jen"; /* also: -in */

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["ILL"] += noun->sg["NOM"].back();

		noun->sg["PTV"] += 'a';
		noun->pl["PTV"] += "ja";
	} else {
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);

		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "jä";
	}
	noun->sg["ILL"] += 'n';
	noun->pl["ILL"] += "ihin";

	kv(noun);

	return 0;
}

int cat10(Nominal *noun, Entry &entry)
{
	/* for all plurals except nominal: s/a$// */
	for (int i = 1; i < all_cases.size(); i++)
		noun->pl[all_cases[i]].pop_back();

	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "ien"; /* also: -in */

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["ILL"] += noun->sg["NOM"].back();

		noun->sg["PTV"] += 'a';
		noun->pl["PTV"] += "ia";
	} else {
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);

		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "iä";
	}

	noun->sg["ILL"] += 'n';
	noun->pl["ILL"] += "iiin";

	kv(noun);
	
	return 0;
}

int cat11(Nominal *noun, Entry &entry)
{
	/* for all plurals except nominal: s/a$// */
	for (int i = 1; i < all_cases.size(); i++)
		noun->pl[all_cases[i]].pop_back();

	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "ien"; /* also: -in */

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["ILL"] += noun->sg["NOM"].back();

		noun->sg["PTV"] += 'a';
		noun->pl["PTV"] += "ia";
	} else {
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);
		noun->sg["ILL"] += noun->sg["NOM"].at(noun->sg["ILL"].length()-2);

		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "iä";
	}
	noun->sg["ILL"] += 'n';
	noun->pl["ILL"] += "iin";

	kv(noun);
	
	return 0;
}

int cat12(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat13(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat14(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat15(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat16(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat17(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat18(Nominal *noun, Entry &entry)
{
	noun->pl["PTV"].replace(noun->pl["PTV"].length()-1, 1, "i");
	noun->pl["GEN"].replace(noun->pl["GEN"].length()-1, 1, "i");
	noun->pl["ILL"].replace(noun->pl["ILL"].length()-1, 1, "i");
	for (int i = 3; i < all_cases.size(); i++)
		if (all_cases[i] != "ILL")
			noun->pl[all_cases[i]].pop_back();

	noun->pl["NOM"] += 't';
	noun->sg["GEN"] += 'n';
	noun->pl["GEN"] += "den"; /* also: -tten */

	char tmp = noun->sg["NOM"].back();
	noun->sg["ILL"] += "h" ;
	noun->sg["ILL"] += tmp;
	noun->sg["ILL"] += 'n';
	tmp = noun->pl["NOM"].back();
	noun->pl["ILL"] += "h";
	noun->pl["ILL"] += tmp;
	noun->pl["ILL"] += 'n';

	suffix_cases(noun);

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	if (noun->sg["NOM"].find_last_of("aou") != std::string::npos) {
		noun->sg["PTV"] += "ta";
		noun->pl["PTV"] += "ta";
	} else {
		noun->sg["PTV"] += "ä";
		noun->pl["PTV"] += "tä";
	}

	kv(noun);
	
	return 0;
}

int cat19(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat20(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat21(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat22(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat23(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat24(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat25(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat26(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat27(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat28(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat29(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat30(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat31(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat32(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat33(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat34(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat35(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat36(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat37(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat38(Nominal *noun, Entry &entry)
{
	// s/nen$/se/ for all cases except: SG (PTV, INS, COM), PL (GEN)
	for (int i = 0; i < all_cases.size(); i++)
	{
		// -nen -> -set
		if (all_cases[i] == "NOM")
			replace_substr(noun->pl[all_cases[i]], "nen", "set");
		// -nen -> -sten
		if (all_cases[i] == "GEN") {
			replace_substr(noun->pl[all_cases[i]], "nen", "sten");
			replace_substr(noun->sg[all_cases[i]], "nen", "sen");
		}

		// -nen -> -se
		if (all_cases[i] != "INS" && all_cases[i] != "COM"
				&& all_cases[i] != "PTV" && all_cases[i] != "NOM"
				&& all_cases[i] != "GEN")
			replace_substr(noun->sg[all_cases[i]], "nen", "se");
		// -nen -> s
		if (all_cases[i] != "GEN" && all_cases[i] != "PTV"
				&& all_cases[i] != "NOM")
			replace_substr(noun->pl[all_cases[i]], "nen", "s");
	}
	suffix_cases(noun);

	noun->sg["ILL"] += "en";
	noun->pl["ILL"] += "iin";

	noun->pl["INS"] += "in";
	noun->pl["COM"] += "ineen";

	kv(noun);

	return 0;
}

int cat39(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat40(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat41(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat42(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat43(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat44(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat45(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat46(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat47(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat48(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat49(Nominal *noun, Entry &entry)
{
	return 0;
}

int cat50(Nominal *noun, Entry &entry)
{
	return 0;
}
