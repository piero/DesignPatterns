#ifndef STOPSTATE_H_
#define STOPSTATE_H_

#include "FSMState.h"

class StopState: public FSMState {
public:
	StopState(FSMContext* const fsm);
	virtual ~StopState();

	virtual void handleEvent(const FSMEvent& event);

	virtual void enter();

	virtual std::string getName() const;
};

#endif /* STOPSTATE_H_ */
