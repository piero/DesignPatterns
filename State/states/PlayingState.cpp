/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "PlayingState.h"
#include "../FSMContext.h"
#include "PauseState.h"
#include "StopState.h"
#include <iostream>

PlayingState::PlayingState(FSMContext* const fsm)
    : FSMState(STATE_PLAYING, fsm)
{}


PlayingState::~PlayingState()
{}


void PlayingState::handleEvent(const FSMEvent& event)
{
    switch (event.getType()) {
    case EVENT_USR_PAUSE:
        exitTo(new PauseState(_fsm));
        break;

    case EVENT_USR_STOP:
        exitTo(new StopState(_fsm));
        break;

    default:
        break;
    }
}


void PlayingState::enter()
{
    std::cout << "*** Playing State ***" << std::endl;
}


std::string PlayingState::getName() const
{
	return "PLAYING";
}
