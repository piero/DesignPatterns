/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_

#include "FSMState.h"

class PauseState: public FSMState
{
public:
	PauseState(FSMContext* const fsm);
	virtual ~PauseState();

	virtual void handleEvent(const FSMEvent& event);

	virtual void enter();

	virtual std::string getName() const;
};

#endif /* PAUSESTATE_H_ */
