/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef DUMPTREEVISITOR_H_
#define DUMPTREEVISITOR_H_

#include "Visitor.hpp"
#include <iostream>

class DumpTreeVisitor : public Visitor
{
public:
	DumpTreeVisitor()
	: _level(0) {}

	virtual ~DumpTreeVisitor() {}

	virtual void visit(Leaf& leaf)
	{ std::cout << _addPadding() << "[" << leaf.getName() << "]" << std::endl; }

	virtual void visit(Node& node)
	{ std::cout << _addPadding() << node.getName() << "/" << std::endl; }

	virtual void enter(Leaf& leaf)
	{ ++_level; }

	virtual void enter(Node& node)
	{ ++_level; }

	virtual void leave(Leaf& leaf)
	{ --_level; }

	virtual void leave(Node& node)
	{ --_level; }


private:
	DumpTreeVisitor(const DumpTreeVisitor&);
	DumpTreeVisitor& operator=(const DumpTreeVisitor&);

	const std::string _addPadding()
	{
		std::string padding;
		for (size_t i = 1; i < _level; ++i) {
			padding += "    ";
		}
		return padding;
	}

	unsigned int _level;
};

#endif /* DUMPTREEVISITOR_H_ */
