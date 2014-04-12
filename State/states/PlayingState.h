#ifndef PLAYINGSTATE_H_
#define PLAYINGSTATE_H_

#include "FSMState.h"

class PlayingState: public FSMState {
public:
	PlayingState(FSMContext* const fsm);
	virtual ~PlayingState();

	virtual void handleEvent(const FSMEvent& event);

	virtual void enter();

	virtual std::string getName() const;
};

#endif /* PLAYINGSTATE_H_ */
