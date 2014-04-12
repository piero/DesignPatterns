/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "InitState.h"
#include "../FSMContext.h"
#include "PlayingState.h"
#include <iostream>

InitState::InitState(FSMContext* const fsm)
: FSMState(STATE_INIT, fsm)
{
}

InitState::~InitState() {
}

void InitState::leave()
{
	std::cout << "[Init] Initialization complete." << std::endl;
}

void InitState::handleEvent(const FSMEvent& event)
{
    switch (event.getType()) {
    case EVENT_USR_PLAY:
        exitTo(new PlayingState(fsm));
        break;

    default:
        break;
    }
}


std::string InitState::getName() const {
	return "INIT";
}
