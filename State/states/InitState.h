#ifndef INITSTATE_H_
#define INITSTATE_H_

#include "FSMState.h"

class InitState: public FSMState {
public:
	InitState(FSMContext* const fsm);
	virtual ~InitState();

	virtual void leave();

	virtual void handleEvent(const FSMEvent& event);

	virtual std::string getName() const;
};

#endif /* INITSTATE_H_ */
