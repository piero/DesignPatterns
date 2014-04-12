/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef JSONVISITOR_H_
#define JSONVISITOR_H_

#include "Visitor.h"
#include <sstream>
#include <map>

namespace perception
{

class JsonVisitor: public perception::Visitor
{
public:
    JsonVisitor();
    virtual ~JsonVisitor();

    virtual void visit(CompositeLeaf& node);

    virtual void visitEnter(CompositeNode& node);
    virtual void visitLeave(CompositeNode& node);

    std::string getJsonRepresentation();

private:
    void _incrementLevel();
    void _decrementLevel();
    std::string _addPadding();
    std::string _addComma();

    std::stringstream _json;
    unsigned int _level;

    std::map<size_t, size_t> _nodesPerLevel;
};

} /* namespace perception */

#endif /* JSONVISITOR_H_ */
