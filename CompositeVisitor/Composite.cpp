#include "Composite.hpp"
#include "Visitor.hpp"


void Node::accept(class Visitor& visitor)
{
	visitor.enter(*this);
	visitor.visit(*this);

	for (size_t i=0; i < nodes_.size(); ++i) {
		nodes_[i]->accept(visitor);
	}

	visitor.leave(*this);
}



void Leaf::accept(class Visitor& visitor)
{
	visitor.enter(*this);
	visitor.visit(*this);
	visitor.leave(*this);
}
