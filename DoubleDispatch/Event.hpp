/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>

typedef enum
{
	EVT_TYPE_UNKNOWN,
	EVT_TYPE_APPLICATION,
	EVT_TYPE_USER
} EventType;


class Event
{
public:
	virtual ~Event() {}

	virtual EventType getType() const
	{ return type; }

	virtual std::string getMessage() const
	{ return message; }

	virtual void accept(class EventHandler *handler) = 0;

protected:
	Event(EventType evtType, const std::string& msg)
	: type(evtType),
	  message(msg) {}

	EventType type;
	std::string message;

private:
	Event(const Event&);
	Event& operator=(const Event&);
};



class ApplicationEvent : public Event
{
public:
	ApplicationEvent(const std::string& msg)
	: Event(EVT_TYPE_APPLICATION, msg) {}

	virtual ~ApplicationEvent() {}

	virtual void accept(class EventHandler *handler);

private:
	ApplicationEvent(const ApplicationEvent&);
	ApplicationEvent& operator=(const ApplicationEvent&);
};



class UserEvent : public Event
{
public:
	UserEvent(const std::string& msg)
	: Event(EVT_TYPE_USER, msg) {}

	virtual ~UserEvent() {}

	virtual void accept(class EventHandler *handler);

private:
	UserEvent(const UserEvent&);
	UserEvent& operator=(const UserEvent&);
};


#endif /* EVENT_HPP_ */
