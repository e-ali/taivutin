#ifndef KOTUS_HH
#define KOTUS_HH

#include <string>
#include <stdexcept>
#include <vector>

#include "entry.hh" 

class Kotus {
	public:
	Kotus();

	std::vector<Entry> wordlist;
	size_t get_size() const;

	Entry search(const std::string &) const;

	private:
	int size;
};

#endif
