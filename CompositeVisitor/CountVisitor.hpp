#ifndef COUNTVISITOR_HPP_
#define COUNTVISITOR_HPP_

#include "Visitor.hpp"

class CountVisitor : public Visitor
{
public:
	CountVisitor()
	: nodeCount(0),
	  leafCount(0)
	{}

	virtual ~CountVisitor() {}

	unsigned int getNodeCount() const
	{ return nodeCount; }

	unsigned int getLeafCount() const
	{ return leafCount; }

	virtual void visit(Leaf& leaf)
	{ ++leafCount; }

	virtual void visit(Node& node)
	{ ++nodeCount; }

	virtual void enter(Leaf& leaf) {}
	virtual void enter(Node& node) {}
	virtual void leave(Leaf& leaf) {}
	virtual void leave(Node& node) {}

private:
	unsigned int nodeCount;
	unsigned int leafCount;
};


#endif /* COUNTVISITOR_HPP_ */
