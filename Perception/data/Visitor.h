/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */
 
#ifndef VISITOR_H_
#define VISITOR_H_

#include "Composite.h"

namespace perception
{

class Visitor
{
public:
    virtual ~Visitor() {}

    virtual void visit(CompositeLeaf& node) = 0;

    virtual void visitEnter(CompositeNode& node) = 0;
    virtual void visitLeave(CompositeNode& node) = 0;
};


class NullVisitor : public Visitor
{
public:
    NullVisitor() {}
    virtual ~NullVisitor() {}

    virtual void visit(CompositeLeaf& node) {}

    virtual void visitEnter(CompositeNode& node) {};
    virtual void visitLeave(CompositeNode& node) {};
};

} /* namespace perception */

#endif /* VISITOR_H_ */
