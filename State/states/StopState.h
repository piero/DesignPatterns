/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef STOPSTATE_H_
#define STOPSTATE_H_

#include "FSMState.h"

class StopState: public FSMState
{
public:
	StopState(FSMContext* const fsm);
    
	virtual ~StopState();

	virtual void handleEvent(const FSMEvent& event);

	virtual void enter();

	virtual std::string getName() const;
};

#endif /* STOPSTATE_H_ */
