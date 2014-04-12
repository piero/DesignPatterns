/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "DumpVisitor.h"
#include <iostream>


namespace perception
{

DumpVisitor::DumpVisitor()
    : _level(0)
{}


DumpVisitor::~DumpVisitor()
{}


void DumpVisitor::visit(CompositeLeaf& node)
{
    ++_level;

    _dumpNode(node);

    --_level;
}


void DumpVisitor::visitEnter(CompositeNode& node)
{
    ++_level;

    _dumpNode(node);
}


void DumpVisitor::visitLeave(CompositeNode& node)
{
    --_level;
}


void DumpVisitor::_dumpNode(const CompositeNode& node)
{
    std::cout << _level << ":" << _addPadding() << node.getName() << std::endl;
}


void DumpVisitor::_dumpNode(const CompositeLeaf& node)
{
    std::cout << _level << ":" << _addPadding() << node.getName() << ": " << node.getValue() << std::endl;
}


std::string DumpVisitor::_addPadding()
{
    std::string padding;

    for (size_t i = 0; i < _level; ++i) {
        padding += "    ";
    }

    return padding;
}

} /* namespace perception */
