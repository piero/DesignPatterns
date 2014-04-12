/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef COMPOSITE_HPP_
#define COMPOSITE_HPP_

#include <string>
#include <vector>
#include <iostream>

class Composite
{
public:
	virtual ~Composite() {}

	virtual std::string getName() const
	{ return _name; }

	// Uniformity vs Safety
//	virtual void add(Composite* c) = 0;

	virtual void dump() = 0;

protected:
	Composite(const std::string& name)
	: _name(name) {}

	std::string _name;

private:
	Composite(const Composite& other);
	Composite& operator=(const Composite& rhs);
};


class Node : public Composite
{
public:
	Node(const std::string& name)
	: Composite(name) {}

	virtual ~Node()
	{ nodes_.clear(); }

    // Uniformity vs Safety
	/*virtual*/ void add(Composite* c)
	{ nodes_.push_back(c); }

	virtual void dump()
	{
		std::cout << _name << "/" << std::endl;
		for (size_t i = 0; i < nodes_.size(); ++i) {
			nodes_[i]->dump();
		}
	}

private:
	Node(const Node& other);
	Node& operator=(const Node& rhs);

	std::vector<Composite*> nodes_;
};


class Leaf : public Composite
{
public:
	Leaf(const std::string& name)
	: Composite(name) {}

	virtual ~Leaf() {}

    // Uniformity vs Safety
//	virtual void add(Composite* c) {}

	virtual void dump()
	{ std::cout << "[" << _name << "]" << std::endl; }

private:
	Leaf(const Leaf& other);
	Leaf& operator=(const Leaf& rhs);
};

#endif /* COMPOSITE_HPP_ */
