#ifndef VISITOR_HPP_
#define VISITOR_HPP_

#include "Composite.hpp"

class Visitor
{
public:
	Visitor() {}
	virtual ~Visitor() {}

	virtual void visit(Leaf& leaf) = 0;
	virtual void visit(Node& node) = 0;

	// Optional, for more control
	virtual void enter(Leaf& leaf) = 0;
	virtual void enter(Node& node) = 0;
	virtual void leave(Leaf& leaf) = 0;
	virtual void leave(Node& node) = 0;

private:
	Visitor(const Visitor&);
	Visitor& operator=(const Visitor&);
};


class NullVisitor : public Visitor
{
public:
	NullVisitor() {}
	virtual ~NullVisitor() {}

	virtual void visit(Leaf& leaf) {}
	virtual void visit(Node& node) {}

	virtual void enter(Leaf& leaf) {}
	virtual void enter(Node& node) {}
	virtual void leave(Leaf& leaf) {}
	virtual void leave(Node& node) {}

private:
	NullVisitor(const NullVisitor&);
	NullVisitor& operator=(const NullVisitor&);
};

#endif /* VISITOR_HPP_ */
