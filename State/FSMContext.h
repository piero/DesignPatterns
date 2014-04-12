/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef FSMCONTEXT_H_
#define FSMCONTEXT_H_

#include "states/FSMState.h"
#include <stdexcept>

class FSMError: public std::runtime_error
{
public:
	FSMError(const std::string& msg) :
			std::runtime_error(msg) {
	}
};


/*
 * This structure is used to pass relevant data
 * to the FSMContext upon creation.
 */
struct FSMData
{};


class FSMContext
{

friend class FSMState;

public:
	/**
	 * Default constructor.
	 *
	 * @param pipeline The pipeline to control.
	 * @param ipcService Handler to the IPC Service.
	 */
	FSMContext(const FSMData& data);

	/*
	 * Using a virtual destructor, so it's possible to mock this class
	 * by simple inheritance. The alternative would be to use an unrelated
	 * class, and either adopt #ifdefs or rely on templates (which will
	 * affect all States).
	 */
	virtual ~FSMContext();

	/**
	 * Handle an event, according to the current state.
	 *
	 * @param event The event to handle.
	 */
	void handleEvent(const FSMEvent& event);

	/**
	 * @return The type of the current state.
	 *
	 * @throw FSMError If current state is NULL.
	 */
	const StateType getStateType() const throw (FSMError);


	/**
	 * Convenience method: for DEMO purpose only.
	 */
	virtual std::string getStateName() const;

private:
    /**
     * Transit to a new state.
     *
     * @param newState The state to transit to.
     */
    void _setState(FSMState* const newState);

    void _handleAllocationError(const std::string& msg);

    FSMContext(const FSMContext& other);
    FSMContext& operator=(const FSMContext& rhs);

    FSMState* _currentState;

};

#endif /* FSMCONTEXT_H_ */
