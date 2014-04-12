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
	: level(0) {}

	~XmlVisitor() {}

	virtual void visit(Leaf& leaf)
	{
		xml << addPadding() << "<leaf name=\"" << leaf.getName() << "\"/>" << std::endl;
	}

	virtual void visit(Node& node)
	{}

	virtual void enter(Leaf& leaf)
	{
		++level;
	}

	virtual void enter(Node& node)
	{
		++level;
		xml << addPadding() << "<node name=\"" << node.getName() << "\">" << std::endl;
	}

	virtual void leave(Leaf& leaf)
	{
		--level;
	}

	virtual void leave(Node& node)
	{
		xml << addPadding() << "</node>" << std::endl;
		--level;
	}

	std::string getXml() const
	{ return xml.str(); }

private:
	const std::string addPadding()
	{
		std::string padding;
		for (size_t i = 1; i < level; ++i) {
			padding += "    ";
		}
		return padding;
	}

	unsigned int level;
	std::stringstream xml;
};


#endif /* XMLVISITOR_HPP_ */
