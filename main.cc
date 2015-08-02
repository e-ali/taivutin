#include <iostream>

#include "kotus.hh"
#include "inflect.hh"

int main()
{
	Kotus kotus;
	std::string word;

	std::cout << "Taivitun, Finnish verb & noun inflector.\n";

	std::cout << "\nEnter a word ('q' to quit): ";
	while (std::cin >> word) {
		if (word == "q")
			break;
		else {
			inflect(word, kotus);
		}
		std::cout << "\nEnter a word ('q' to quit): ";
	}
	std::cout << "\n";

	return 0;
}
