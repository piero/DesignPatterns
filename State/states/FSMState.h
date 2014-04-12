#ifndef FSMSTATE_H_
#define FSMSTATE_H_

#include "../FSMEvent.h"
#include <string>

typedef enum {
    STATE_INVALID = 0,
    STATE_INIT,
    STATE_CONNECTING,
    STATE_BUFFERING,
    STATE_PLAYING,
    STATE_PAUSE,
    STATE_STOP,
    STATE_DOWNSHIFT,
    STATE_INVALID_DATA,
    STATE_EXIT,
    STATE_TEST              // Used by unit tests
} StateType;


// Forward declaration
class FSMContext;


class FSMState {
public:
	FSMState(const StateType type, FSMContext* const fsm);
	virtual ~FSMState();

	/**
	 * Each state must override this method to define its own handling.
	 *
	 * @param event The event to handle.
	 */
	virtual void handleEvent(const FSMEvent& event) = 0;

	/**
	 * Convenience method: for DEMO purpose only.
	 */
	virtual std::string getName() const = 0;

	/**
	 * This method is called by the FSM Context when entering a state.
	 */
	virtual void enter();

	/**
	 * This method is called by the FSM Context when leaving a state.
	 */
	virtual void leave();

	/**
	 * This method implements a state transition.
	 *
	 * @param nextState The state to transit to.
	 */
	virtual void exitTo(FSMState* const nextState);

	const StateType getType() const throw()
	{ return type; }

protected:
    const StateType type;
    FSMContext* const fsm;
};

#endif /* FSMSTATE_H_ */
