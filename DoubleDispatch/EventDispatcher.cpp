#include "EventDispatcher.hpp"

using namespace std;

EventDispatcher::EventDispatcher()
{}


EventDispatcher::~EventDispatcher()
{ registrations.clear(); }


void EventDispatcher::subscribe(EventType type, EventHandler& handler)
{
	registrations[type].push_back(&handler);
}


void EventDispatcher::unsubscribe(EventType type, EventHandler& handler)
{
	Registrations::iterator iter = registrations.find(type);

	if (iter != registrations.end()) {
		iter->second.remove(&handler);

		if (iter->second.size() == 0) {
			registrations.erase(iter);
		}
	}
}


void EventDispatcher::dispatch(Event& event)
{
	Registrations::iterator iter = registrations.find(event.getType());

	if (iter != registrations.end()) {
		HandlerList::iterator handlerIter;
		for (handlerIter = iter->second.begin();
				handlerIter != iter->second.end();
				++handlerIter) {
			EventHandler *currentHandler = *handlerIter;
			event.accept(currentHandler);
		}
	}
}
