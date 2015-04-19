#include <iostream>

#include "xml.hh"

XML::XML()
{
	xercesc::XMLPlatformUtils::Initialize();
}

XML::~XML()
{
        delete parser;
	xercesc::XMLPlatformUtils::Terminate();
}

void XML::parse_file(std::string file)
{
	parser = new xercesc::XercesDOMParser();
	parser->setValidationScheme(xercesc::XercesDOMParser::Val_Never);

	parser->parse(xercesc::XMLString::transcode(file.c_str()));

	document = parser->getDocument();
	root = document->getDocumentElement();
	word_records = root->getElementsByTagName(xercesc::XMLString::transcode("st"));
	size = word_records->getLength();
}

const size_t XML::get_size() const
{
	return size;
}

Entry XML::get_entry(size_t i) const
{
	Entry e;
	xercesc::DOMNodeList* children = word_records->item(i)->getChildNodes();
	int sz = children->getLength();

	for (int i = 0; i < sz; i++) { 
		xercesc::DOMNode* cur_node = children->item(i);
		std::string name = xercesc::XMLString::transcode(cur_node->getNodeName());
		if (name == "s")
			e.sana(get_node_text(cur_node));
		if (name == "hn")
			e.hn(std::stoi(get_node_text(cur_node)));
		if (name == "t")
			e.inflection(get_inflection(cur_node));
	}
	return e;
}

Inflection XML::get_inflection(xercesc::DOMNode *node) const
{
	Inflection inflection;

	//t (tn, av?)*, t taivutus
	if (node->hasAttributes())
		inflection.t_attr(get_attribute_text(node));

	xercesc::DOMNodeList* t = node->getChildNodes();
	for (int i = 0, sz = t->getLength(); i < sz; i++) {
		xercesc::DOMNode *cur_t = t->item(i);
		std::string name = xercesc::XMLString::transcode(cur_t->getNodeName());
		if (name == "tn") { // tn (#PCDATA)
			inflection.tn(std::stoi(get_node_text(cur_t)));
		} else if (name == "av") {
			// av (#PCDATA), av astevaihtelu
			char av = get_node_text(cur_t).at(0);
			inflection.av(av);
			if (cur_t->hasAttributes())
				inflection.av_attr(get_attribute_text(cur_t));
		}
	}
	return inflection;
}

std::string XML::get_attribute_text(xercesc::DOMNode *node) const
{
	std::string attribute;
	xercesc::DOMNamedNodeMap *attrs = node->getAttributes();
	for (int i = 0; i < attrs->getLength(); i++) {
		xercesc::DOMNode *attr = attrs->item(i);
		attribute = xercesc::XMLString::transcode(attr->getTextContent());
	}
	return attribute;
}

std::string XML::get_node_text(xercesc::DOMNode *node) const
{
	return xercesc::XMLString::transcode(node->getTextContent());
}
