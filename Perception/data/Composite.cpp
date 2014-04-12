/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "Composite.h"
#include "Visitor.h"
#include <algorithm>

namespace perception
{

// Element (base class)

Composite::Composite(const std::string& name)
    : _name(name)
{}


Composite::~Composite()
{}


std::string Composite::getName() const
{ return _name; }



// Leaf Element

CompositeLeaf::CompositeLeaf(const std::string& name, const std::string& value)
    : Composite(name),
      _value(value)
{}


CompositeLeaf::~CompositeLeaf()
{}


size_t CompositeLeaf::size() const
{
    return 0;
}


void CompositeLeaf::accept(Visitor& visitor)
{
    visitor.visit(*this);
}


bool CompositeLeaf::isLeaf() const
{
    return true;
}


CompositeNode* CompositeLeaf::addNode(const std::string& name)
{ return 0; }


CompositeLeaf* CompositeLeaf::addLeaf(const std::string& name, const std::string& value)
{ return 0; }


bool CompositeLeaf::has(const std::string& name) const
{
    return _name == name;
}


std::string CompositeLeaf::getValue() const
{
    return _value;
}


// Composite Element

CompositeNode::CompositeNode(const std::string& name)
    : Composite(name)
{}


CompositeNode::~CompositeNode()
{
    for (size_t iter = 0; iter < _nodes.size(); ++iter) {
        delete _nodes[iter];
    }

    _nodes.clear();
}


void CompositeNode::remove(Composite* node)
{
    if (_nodes.size() > 0 ) {
        bool found = false;
        size_t iter;

        for (iter = 0; !found && iter < _nodes.size(); ++iter) {
            if (_nodes[iter]->getName() == node->getName()) {
                delete _nodes[iter];
                _nodes.erase(_nodes.begin() + iter);
                found = true;
            }
        }
    }
}


size_t CompositeNode::size() const
{
    return _nodes.size();
}


void CompositeNode::accept(Visitor& visitor)
{
    visitor.visitEnter(*this);

    for (size_t i = 0; i < _nodes.size(); ++i) {
        _nodes[i]->accept(visitor);
    }

    visitor.visitLeave(*this);
}


bool CompositeNode::isLeaf() const
{
    return false;
}


CompositeNode* CompositeNode::addNode(const std::string& name)
{
    CompositeNode* node = new CompositeNode(name);
    _nodes.push_back(node);
    return node;
}


CompositeLeaf* CompositeNode::addLeaf(const std::string& name, const std::string& value)
{
    CompositeLeaf* leaf = new CompositeLeaf(name, value);
    _nodes.push_back(leaf);
    return leaf;
}


bool CompositeNode::has(const std::string& name) const
{
    bool found = (_name == name);

    for (size_t i = 0; !found && i < _nodes.size(); ++i) {
        found = _nodes[i]->has(name);
    }

    return found;
}


} /* namespace perception */
