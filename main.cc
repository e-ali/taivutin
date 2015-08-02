#include <iostream>

#include "entry.hh"
#include "kotus.hh"
#include "inflect.hh"

int main()
{
	Kotus kotus;

	std::string word;
	while (std::cin >> word)
	{
		if (word == "q")
			break;
        else {
            inflect(word, kotus);
        }
	}

	return 0;
}
