#include <iostream>

#include "entry.hh"
#include "kotus.hh"

int main()
{
	Kotus kotus;
	size_t sz = kotus.get_size();
	for (size_t i = 0; i < sz; i++)
		kotus.wordlist[i].print(std::cout);

	return 0;
}
