#include "FSMState.h"
#include "../FSMContext.h"

FSMState::FSMState(const StateType type, FSMContext* const fsm) :
		type(type), fsm(fsm) {
}


FSMState::~FSMState()
{}


void FSMState::enter()
{}


void FSMState::leave()
{}


void FSMState::exitTo(FSMState* const nextState)
{
    if (fsm) {
        fsm->setState(nextState);
    }
}
