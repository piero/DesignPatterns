#include "Event.hpp"
#include "EventHandler.hpp"


void ApplicationEvent::accept(EventHandler *handler)
{ handler->handle(*this); }


void UserEvent::accept(EventHandler *handler)
{ handler->handle(*this); }
