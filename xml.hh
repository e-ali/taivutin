#ifndef XML_HH
#define XML_HH

#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include "inflection.hh"
#include "entry.hh"

class XML {
	public:
	XML();
	~XML();

	void parse_file(std::string file);
	const size_t get_size() const;
	Entry get_entry(size_t i) const;

	private:
	xercesc::XercesDOMParser* parser;
	const xercesc::DOMDocument *document;
	const xercesc::DOMElement* root;
	xercesc::DOMNodeList *word_records;

	size_t size;

	Inflection get_inflection(xercesc::DOMNode *node) const;
	std::string get_attribute_text(xercesc::DOMNode *node) const;
	std::string get_node_text(xercesc::DOMNode *node) const;
};

#endif
