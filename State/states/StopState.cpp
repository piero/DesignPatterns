/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "StopState.h"
#include "PlayingState.h"
#include "../FSMContext.h"
#include <iostream>

StopState::StopState(FSMContext* const fsm) :
		FSMState(STATE_STOP, fsm) {
}

StopState::~StopState() {
}

void StopState::handleEvent(const FSMEvent& event) {
	switch (event.getType()) {
	case EVENT_USR_PLAY:
		exitTo(new PlayingState(fsm));
		break;

	default:
		break;
	}
}

void StopState::enter() {
	std::cout << "*** Stop State ***" << std::endl;
}

std::string StopState::getName() const {
	return "STOP";
}
