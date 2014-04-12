/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef EVENTDISPATCHER_H_
#define EVENTDISPATCHER_H_

#include "EventHandler.hpp"

#include <list>
#include <map>

class EventDispatcher
{
public:
	EventDispatcher();
	~EventDispatcher();

	void subscribe(EventType type, EventHandler& handler);
	void unsubscribe(EventType type, EventHandler& handler);
	void dispatch(Event& event);

private:
	typedef std::list<EventHandler*> HandlerList;
	typedef std::map<EventType, HandlerList> Registrations;

	Registrations _registrations;
};

#endif /* EVENTDISPATCHER_H_ */
