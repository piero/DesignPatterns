/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef DUMPVISITOR_H_
#define DUMPVISITOR_H_

#include "Visitor.h"

namespace perception
{

class DumpVisitor: public perception::Visitor
{
public:
    DumpVisitor();
    virtual ~DumpVisitor();

    virtual void visit(CompositeLeaf& node);

    virtual void visitEnter(CompositeNode& node);
    virtual void visitLeave(CompositeNode& node);

private:
    void _dumpNode(const CompositeNode& node);
    void _dumpNode(const CompositeLeaf& node);
    std::string _addPadding();

    unsigned int _level;
};

} /* namespace perception */

#endif /* DUMPVISITOR_H_ */
