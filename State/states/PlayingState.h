/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

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
