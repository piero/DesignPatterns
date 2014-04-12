/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "EventDispatcher.hpp"

using namespace std;

EventDispatcher::EventDispatcher()
{}


EventDispatcher::~EventDispatcher()
{
    _registrations.clear();
}


void EventDispatcher::subscribe(EventType type, EventHandler& handler)
{
	_registrations[type].push_back(&handler);
}


void EventDispatcher::unsubscribe(EventType type, EventHandler& handler)
{
	Registrations::iterator iter = _registrations.find(type);

	if (iter != _registrations.end())
    {
		iter->second.remove(&handler);

		if (iter->second.size() == 0)
        {
			_registrations.erase(iter);
		}
	}
}


void EventDispatcher::dispatch(Event& event)
{
	Registrations::iterator iter = _registrations.find(event.getType());

	if (iter != _registrations.end())
    {
		HandlerList::iterator handlerIter;
		for (handlerIter = iter->second.begin();
				handlerIter != iter->second.end();
				++handlerIter)
        {
			EventHandler *currentHandler = *handlerIter;
			event.accept(currentHandler);
		}
	}
}
