#include <iostream>

#include "entry.hh"
#include "kotus.hh"

int main()
{
	Kotus kotus;

	Entry e;
	std::string word;
	while (std::cin >> word)
	{
		if (word == "q")
			break;
		try {
			e = kotus.search(word);
			e.print(std::cout);
		}
		catch (const std::range_error &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
