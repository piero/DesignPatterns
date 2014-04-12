#ifndef COMPOSITE_HPP_
#define COMPOSITE_HPP_

#include <string>
#include <vector>
#include <iostream>

class Composite {
public:
	virtual ~Composite() {}

	virtual std::string getName() const
	{ return name_; }

	// Uniformity vs Safety
//	virtual void add(Composite* c) = 0;

	virtual void dump() = 0;

protected:
	Composite(const std::string& name)
	: name_(name) {}

	std::string name_;

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

	/*virtual*/ void add(Composite* c)
	{ nodes_.push_back(c); }

	virtual void dump()
	{
		std::cout << name_ << "/" << std::endl;
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

//	virtual void add(Composite* c) {}

	virtual void dump()
	{ std::cout << "[" << name_ << "]" << std::endl; }

private:
	Leaf(const Leaf& other);
	Leaf& operator=(const Leaf& rhs);
};

#endif /* COMPOSITE_HPP_ */