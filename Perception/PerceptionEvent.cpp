/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "PerceptionEvent.h"

#include <sstream>
#include <iomanip>

namespace perception
{

PerceptionEvent::PerceptionEvent(unsigned short category,
                                 unsigned short type,
                                 unsigned short module,
                                 std::string description)
    : _category(category),
      _type(type),
      _module(module),
      _description(description)
{
    validateParameters();
}


PerceptionEvent::~PerceptionEvent()
{}



void PerceptionEvent::validateParameters()
{
    if (_category > 99) {
        IllegalParameterError::raiseError<IllegalParameterError>("Illegal parameter", "Category must be [0-99]");
    }

    if (_type > 9999) {
        IllegalParameterError::raiseError<IllegalParameterError>("Illegal parameter", "Type must be [0-9999]");
    }

    if (_module > 99) {
        IllegalParameterError::raiseError<IllegalParameterError>("Illegal parameter", "Module must be [0-99]");
    }
}


const std::string PerceptionEvent::getCode()
{
    std::ostringstream ss;
    ss << std::setfill('0');
    ss << std::setw(2) << _category << "-";
    ss << std::setw(4) << _type << "-";
    ss << std::setw(2) << _module;
    return ss.str();
}


const std::string PerceptionEvent::getDescription() const
{
    return _description;
}

} /* namespace perception */
