/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "Event.hpp"
#include "EventHandler.hpp"


void ApplicationEvent::accept(EventHandler *handler)
{ handler->handle(*this); }


void UserEvent::accept(EventHandler *handler)
{ handler->handle(*this); }
