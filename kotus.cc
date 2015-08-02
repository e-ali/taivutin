#include <algorithm>

#include "xml.hh"
#include "kotus.hh"

Kotus::Kotus()
{
	XML xml;
	xml.parse_file("kotus-sanalista_v1/kotus-sanalista_v1.xml");

	for (size_t i = 0; i < xml.get_size(); i++) {
		wordlist.push_back(xml.get_entry(i));
	}

	size = wordlist.size();
}

size_t Kotus::get_size() const
{
	return size;
}

Entry Kotus::search(const std::string &word) const
{
	auto it = std::find_if(begin(wordlist), end(wordlist), [=] (Entry const& e) {
		return (e.get_sana() == word); });
	bool found = (it != end(wordlist));
 
	if (found)
		return *it;
	else
		throw std::range_error("Word not found.");
}
