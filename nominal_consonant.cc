#include "nominal_consonant.hh"

std::array<std::string,8>
	suffixable_sg{"GEN", "INE", "ELA", "ADE", "ABL", "ALL", "TRANSL", "ABE"};
std::array<std::string,9>
	suffixable_pl{"NOM", "INE", "ELA", "ADE", "ABL", "ALL", "TRANSL", "ABE", "INS"};

void erase_or_add_one(Nominal *noun, char c)
{
	for (size_t i = noun->sg["NOM"].length()-1; i > 0; i--) {
		if (noun->sg["NOM"].at(i) == c) {
			if (noun->sg["NOM"].at(i-1) == c) {
				for (int j = 0; j < suffixable_sg.size(); j++) {
					noun->sg[suffixable_sg[j]].erase(i-1, 1);
				}
				for (int j = 0; j < suffixable_pl.size(); j++) {
					noun->pl[suffixable_pl[j]].erase(i-1, 1);
				}
			break;
			} else {
				for (int j = 0; j < suffixable_sg.size(); j++) {
					noun->sg[suffixable_sg[j]].insert(i-1, std::string(1, c));
				}
				for (int j = 0; j < suffixable_pl.size(); j++) {
					noun->pl[suffixable_pl[j]].insert(i-1, std::string(1, c));
				}
			}
			break;
		}
	}
}

void switch_one(Nominal *noun, const char a, const char b)
{
	for (size_t i = noun->sg["NOM"].length()-1; i > 0; i--) {
		if (noun->sg["NOM"].at(i) == a) {
			for (int j = 0; j < suffixable_sg.size(); j++) {
				noun->sg[suffixable_sg[j]].replace(i, 1, 1, b);
			}
			for (int j = 0; j < suffixable_pl.size(); j++) {
				noun->pl[suffixable_pl[j]].replace(i, 1, 1, b);
			}
			break;
		} else if (noun->sg["NOM"].at(i) == b)  {
			for (int j = 0; j < suffixable_sg.size(); j++) {
				noun->sg[suffixable_sg[j]].replace(i, 1, 1, a);
			}
			for (int j = 0; j < suffixable_pl.size(); j++) {
				noun->pl[suffixable_pl[j]].replace(i, 1, 1, b);
			}
			break;
		}
	}
}

void switch_two(Nominal *noun, std::string a, std::string b)
{
	for (size_t i = noun->sg["NOM"].length()-1; i > 0; i--) {
		if (noun->sg["NOM"].find_last_of(a) != std::string::npos) {
			for (int j = 0; j < suffixable_sg.size(); j++) {
				noun->sg[suffixable_sg[j]].replace(noun->sg[suffixable_sg[j]].find(a), b.length(), b);
			}
			for (int j = 0; j < suffixable_pl.size(); j++) {
				noun->pl[suffixable_pl[j]].replace(noun->pl[suffixable_pl[j]].find(a), b.length(), b);
			}
			break;
		} else if (noun->sg["NOM"].find_last_of(b) != std::string::npos) {
			for (int j = 0; j < suffixable_sg.size(); j++) {
				noun->sg[suffixable_sg[j]].replace(noun->sg[suffixable_sg[j]].find(b), a.length(), a);
			}
			for (int j = 0; j < suffixable_pl.size(); j++) {
				noun->pl[suffixable_pl[j]].replace(noun->pl[suffixable_pl[j]].find(b), a.length(), a);
			}
			break;
		}
	}
}

void replace_one(Nominal *noun, char a, char b)
{
	for (size_t i = noun->sg["NOM"].length()-1; i > 0; i--) {
		if (noun->sg["NOM"].at(i) == a) {
			for (int j = 0; j < suffixable_sg.size(); j++) {
				noun->sg[suffixable_sg[j]].replace(i, 1, 1, b);
			}
			for (int j = 0; j < suffixable_pl.size(); j++) {
				noun->pl[suffixable_pl[j]].replace(i, 1, 1, b);
			}
			break;
		}
	}
}
#include <iostream>

void remove_or_add_one(Nominal *noun, char c)
{
	for (size_t i = noun->sg["NOM"].length()-3; i > 0; i--) {
		std::cout << noun->sg["NOM"].at(i) << "\n";
		if (noun->sg["NOM"].at(i) == c) {
			for (int j = 0; j < suffixable_sg.size(); j++) {
				noun->sg[suffixable_sg[j]].erase(i, 1);
			}
			for (int j = 0; j < suffixable_pl.size(); j++) {
				noun->pl[suffixable_pl[j]].erase(i, 1);
			}
			break;
		} else {
			for (int j = 0; j < suffixable_sg.size(); j++) {
				noun->sg[suffixable_sg[j]].insert(i, std::string(1, c));
			}
			for (int j = 0; j < suffixable_pl.size(); j++) {
				noun->pl[suffixable_pl[j]].insert(i, std::string(1, c));
			}
			break;
		}
	}
}

void kv(Nominal *noun)
{
	const char tyyppi = noun->m_e.get_inflection(0).av();

	if (tyyppi == 'A') { // kk -> k | k -> kk
		erase_or_add_one(noun, 'k');
	} else if (tyyppi == 'B') { // pp -> p | p -> pp
		erase_or_add_one(noun, 'p');
	} else if (tyyppi == 'C') { // tt -> t | t -> tt
		erase_or_add_one(noun, 't');
	} else if (tyyppi == 'D') { // k ->   |   -> k
		remove_or_add_one(noun, 'k');
	} else if (tyyppi == 'E') { // p -> v | v -> p
		switch_one(noun, 'p', 'v');
	} else if (tyyppi == 'F') { // t -> d | d -> t
		switch_one(noun, 't', 'd');
	} else if (tyyppi == 'G') { // nk -> ng | ng -> nk
		switch_two(noun, "nk", "ng");
	} else if (tyyppi == 'H') { // mp -> mm | mm -> mp
		switch_two(noun, "mp", "mm");
	} else if (tyyppi == 'I') { // lt -> ll | ll -> lt
		switch_two(noun, "lt", "ll");
	} else if (tyyppi == 'J') { // nt -> nn | nn -> nt
		switch_two(noun, "nt", "nn");
	} else if (tyyppi == 'K') { // rt -> rr | rr -> rt
		switch_two(noun, "rt", "rr");
	} else if (tyyppi == 'L') { // k -> j | j -> k
		switch_one(noun, 'k', 'j');
	} else if (tyyppi == 'M') { // k -> v
		replace_one(noun, 'k', 'v');
	}
}
