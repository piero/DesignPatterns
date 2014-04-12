/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef COUNTVISITOR_HPP_
#define COUNTVISITOR_HPP_

#include "Visitor.hpp"

class CountVisitor : public Visitor
{
public:
	CountVisitor()
	: _nodeCount(0),
	  _leafCount(0)
	{}

	virtual ~CountVisitor() {}

	unsigned int getNodeCount() const
	{ return _nodeCount; }

	unsigned int getLeafCount() const
	{ return _leafCount; }

	virtual void visit(Leaf& leaf)
	{ ++_leafCount; }

	virtual void visit(Node& node)
	{ ++_nodeCount; }

	virtual void enter(Leaf& leaf) {}
	virtual void enter(Node& node) {}
	virtual void leave(Leaf& leaf) {}
	virtual void leave(Node& node) {}

private:
	unsigned int _nodeCount;
	unsigned int _leafCount;
};


#endif /* COUNTVISITOR_HPP_ */
