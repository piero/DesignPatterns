/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "JsonVisitor.h"

#include <iostream>

namespace perception
{

JsonVisitor::JsonVisitor()
    : _level(0)
{
    _json << "{" << std::endl;
}


JsonVisitor::~JsonVisitor()
{}


void JsonVisitor::visit(CompositeLeaf& node)
{
    _incrementLevel();

    _json << _addPadding();
    _json << "\"" << node.getName() << "\": ";
    _json << "\"" << node.getValue() << "\"" << _addComma() << std::endl;

    _decrementLevel();
}


void JsonVisitor::visitEnter(CompositeNode& node)
{
    _nodesPerLevel[_level] = node.size();

    _incrementLevel();

    _json << _addPadding() << "\"" << node.getName() << "\" :" << " {" << std::endl;
}


void JsonVisitor::visitLeave(CompositeNode& node)
{
    _json << _addPadding() << "}" << _addComma() << std::endl;

    _decrementLevel();
}


std::string JsonVisitor::getJsonRepresentation()
{
    _json << "}" << std::endl;
    return _json.str();
}


void JsonVisitor::_incrementLevel()
{
    ++_level;
}


void JsonVisitor::_decrementLevel()
{
    --_level;

    --_nodesPerLevel[_level];
}


std::string JsonVisitor::_addPadding()
{
    std::string padding;

    for (size_t i = 0; i < _level; ++i) {
        padding += "    ";
    }

    return padding;
}


std::string JsonVisitor::_addComma()
{
    std::string comma = "";

    if (_level > 1 && _nodesPerLevel[_level - 1] > 0) {
        comma = ",";
    }

    return comma;
}


} /* namespace perception */
