/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <string>
#include <vector>

class Composite
{
public:
	virtual ~Composite() {}

	virtual std::string getName() const
	{ return _name; }

	// Uniformity vs Safety
//	virtual void add(Composite* c) = 0;

	virtual void accept(class Visitor& visitor) = 0;

protected:
	Composite(const std::string& name)
	: _name(name)
    {}

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
	{ _nodes.clear(); }

    // Uniformity vs Safety
	/* virtual */ void add(Composite* c)
	{ _nodes.push_back(c); }

	virtual void accept(class Visitor& visitor);

private:
	Node(const Node& other);
	Node& operator=(const Node& rhs);

	std::vector<Composite*> _nodes;
};



class Leaf : public Composite
{
public:
	Leaf(const std::string& name)
	: Composite(name) {}

	virtual ~Leaf() {}

    // Uniformity vs Safety
//	virtual void add(Composite* c) {}

	virtual void accept(class Visitor& visitor);

private:
	Leaf(const Leaf& other);
	Leaf& operator=(const Leaf& rhs);
};

#endif /* COMPOSITE_H_ */
