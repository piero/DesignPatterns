/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef FSMEVENT_H_
#define FSMEVENT_H_

typedef enum {
    EVENT_NONE = 0,

    // Internal events
    EVENT_INITIALISED,
    EVENT_CONNECTED,
    EVENT_BUFFER_EMPTY,
    EVENT_BUFFER_TIMEOUT,
    EVENT_END_OF_STREAM,

    // User events
    EVENT_USR_PLAY,
    EVENT_USR_PAUSE,
    EVENT_USR_STOP,
    EVENT_USR_DOWNSHIFT
} EventType;


class FSMEvent
{
public:
	FSMEvent(EventType type)
        : type(type)
    {}

    ~FSMEvent()
    {}

    const EventType getType() const
    { return type; }

private:
    EventType type;
};


#endif /* FSMEVENT_H_ */
