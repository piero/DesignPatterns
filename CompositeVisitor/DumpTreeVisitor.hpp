#ifndef DUMPTREEVISITOR_H_
#define DUMPTREEVISITOR_H_

#include "Visitor.hpp"
#include <iostream>

class DumpTreeVisitor : public Visitor
{
public:
	DumpTreeVisitor()
	: level(0) {}

	virtual ~DumpTreeVisitor() {}

	virtual void visit(Leaf& leaf)
	{ std::cout << addPadding() << "[" << leaf.getName() << "]" << std::endl; }

	virtual void visit(Node& node)
	{ std::cout << addPadding() << node.getName() << "/" << std::endl; }

	virtual void enter(Leaf& leaf)
	{ ++level; }

	virtual void enter(Node& node)
	{ ++level; }

	virtual void leave(Leaf& leaf)
	{ --level; }

	virtual void leave(Node& node)
	{ --level; }


private:
	DumpTreeVisitor(const DumpTreeVisitor&);
	DumpTreeVisitor& operator=(const DumpTreeVisitor&);

	const std::string addPadding()
	{
		std::string padding;
		for (size_t i = 1; i < level; ++i) {
			padding += "    ";
		}
		return padding;
	}

	unsigned int level;
};

#endif /* DUMPTREEVISITOR_H_ */
