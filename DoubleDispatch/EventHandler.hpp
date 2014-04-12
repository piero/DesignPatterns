#ifndef EVENTHANDLER_HPP_
#define EVENTHANDLER_HPP_

#include "Event.hpp"
#include <iostream>

class EventHandler
{
public:
	virtual ~EventHandler() {}

	// Fallback method
	virtual void handle(Event& event)
	{ throw std::string("[!] Event not supported."); }

	// Mandatory
	virtual void handle(ApplicationEvent& event) = 0;

	// Optional, default to NullObjects
	virtual void handle(UserEvent& event) {}

protected:
	EventHandler() {}

private:
	EventHandler(const EventHandler&);
	EventHandler& operator=(const EventHandler&);
};



class FirstEventHandler : public EventHandler
{
public:
	FirstEventHandler() : EventHandler() {}
	virtual ~FirstEventHandler() {}

	virtual void handle(ApplicationEvent& event)
	{ std::cout << "[1] Handling Application Event: " << event.getMessage() << std::endl; }

//	virtual void handle(UserEvent& event)
//	{ std::cout << "[1] Handling User Event: " << event.getMessage() << std::endl; }

private:
	FirstEventHandler(const FirstEventHandler&);
	FirstEventHandler& operator=(const FirstEventHandler&);
};



class SecondEventHandler : public EventHandler
{
public:
	SecondEventHandler() {}
	virtual ~SecondEventHandler() {}

	virtual void handle(ApplicationEvent& event)
	{ std::cout << "[2] Handling Application Event: " << event.getMessage() << std::endl; }

	virtual void handle(UserEvent& event)
	{ std::cout << "[2] Handling User Event: " << event.getMessage() << std::endl;	}

private:
	SecondEventHandler(const SecondEventHandler&);
	SecondEventHandler& operator=(const SecondEventHandler&);
};

#endif /* EVENTHANDLER_HPP_ */
