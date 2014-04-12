/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef XMLVISITOR_HPP_
#define XMLVISITOR_HPP_

#include "Visitor.hpp"
#include <iostream>
#include <sstream>

class XmlVisitor : public Visitor
{
public:
	XmlVisitor()
	: _level(0) {}

	~XmlVisitor() {}

	virtual void visit(Leaf& leaf)
	{
		_xml << _addPadding() << "<leaf name=\"" << leaf.getName() << "\"/>" << std::endl;
	}

	virtual void visit(Node& node)
	{}

	virtual void enter(Leaf& leaf)
	{
		++_level;
	}

	virtual void enter(Node& node)
	{
		++_level;
		_xml << _addPadding() << "<node name=\"" << node.getName() << "\">" << std::endl;
	}

	virtual void leave(Leaf& leaf)
	{
		--_level;
	}

	virtual void leave(Node& node)
	{
		_xml << _addPadding() << "</node>" << std::endl;
		--_level;
	}

	std::string getXml() const
	{ return _xml.str(); }

private:
	const std::string _addPadding()
	{
		std::string padding;
		for (size_t i = 1; i < _level; ++i) {
			padding += "    ";
		}
		return padding;
	}

	unsigned int _level;
	std::stringstream _xml;
};


#endif /* XMLVISITOR_HPP_ */
