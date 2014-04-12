/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "PauseState.h"
#include "PauseState.h"
#include "../FSMContext.h"
#include "PlayingState.h"
#include "StopState.h"
#include <iostream>

PauseState::PauseState(FSMContext* const fsm)
    : FSMState(STATE_PAUSE, fsm)
{}


PauseState::~PauseState()
{}


void PauseState::handleEvent(const FSMEvent& event)
{
    switch (event.getType()) {
    case EVENT_USR_PLAY:
        exitTo(new PlayingState(fsm));
        break;

    case EVENT_USR_STOP:
        exitTo(new StopState(fsm));
        break;

    default:
        break;
    }
}


void PauseState::enter()
{
    std::cout << "*** Pause State ***" << std::endl;
}


std::string PauseState::getName() const {
	return "PAUSE";
}
