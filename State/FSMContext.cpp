/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "FSMContext.h"
#include "states/InitState.h"
#include <sstream>

FSMContext::FSMContext(const FSMData& data) {
	try {
		currentState_ = new InitState(this);

	} catch (std::bad_alloc& e) {
		handleAllocationError(e.what());
	}

	currentState_->enter();
}

FSMContext::~FSMContext() {
	delete currentState_;
}

void FSMContext::handleEvent(const FSMEvent& event) {
	currentState_->handleEvent(event);
}

void FSMContext::setState(FSMState* const newState) {
	if (newState == 0) {
		throw FSMError("Can't set a NULL state");

	} else {
		currentState_->leave();
		delete currentState_;
		currentState_ = newState;
		currentState_->enter();
	}
}

const StateType FSMContext::getStateType() const throw (FSMError) {
	if (currentState_ == 0) {
		throw FSMError("Current state is not set");
	}

	return currentState_->getType();
}

void FSMContext::handleAllocationError(const std::string& msg)
{
    std::stringstream ss;
    ss << "Error creating state machine: " << msg << std::endl;
    throw FSMError(ss.str());
}


std::string FSMContext::getStateName() const
{
	return currentState_->getName();
}
