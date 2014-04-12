/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef DUMPVISITOR_H_
#define DUMPVISITOR_H_

#include "Visitor.hpp"
#include <iostream>

class DumpVisitor : public Visitor
{
public:
	DumpVisitor() {}
	virtual ~DumpVisitor() {}

	virtual void visit(Leaf& leaf)
	{ std::cout << "[leaf] " << leaf.getName() << std::endl; }

	virtual void visit(Node& node)
	{ std::cout << "[NODE] " << node.getName() << std::endl; }

	virtual void enter(Leaf& leaf)
	{ std::cout << "[>] leaf" << std::endl; }

	virtual void enter(Node& node)
	{ std::cout << "[>] NODE" << std::endl; }

	virtual void leave(Leaf& leaf)
	{ std::cout << "[<] leaf" << std::endl; }

	virtual void leave(Node& node)
	{ std::cout << "[<] NODE" << std::endl; }


private:
	DumpVisitor(const DumpVisitor&);
	DumpVisitor& operator=(const DumpVisitor&);
};

#endif /* DUMPVISITOR_H_ */
