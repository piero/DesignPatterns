/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "FSMContext.h"
#include "states/InitState.h"
#include <sstream>

FSMContext::FSMContext(const FSMData& data)
{
	try
    {
		_currentState = new InitState(this);

	}
    catch (std::bad_alloc& e)
    {
		_handleAllocationError(e.what());
	}

	_currentState->enter();
}


FSMContext::~FSMContext()
{
	delete _currentState;
}


void FSMContext::handleEvent(const FSMEvent& event)
{
	_currentState->handleEvent(event);
}


void FSMContext::_setState(FSMState* const newState)
{
	if (newState == 0)
    {
		throw FSMError("Can't set a NULL state");

	}
    else
    {
		_currentState->leave();
		delete _currentState;
		_currentState = newState;
		_currentState->enter();
	}
}


const StateType FSMContext::getStateType() const throw (FSMError)
{
	if (_currentState == 0)
    {
		throw FSMError("Current state is not set");
	}

	return _currentState->getType();
}


void FSMContext::_handleAllocationError(const std::string& msg)
{
    std::stringstream ss;
    ss << "Error creating state machine: " << msg << std::endl;
    throw FSMError(ss.str());
}


std::string FSMContext::getStateName() const
{
	return _currentState->getName();
}
