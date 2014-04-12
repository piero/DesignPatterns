/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "FSMContext.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	FSMData data;

	FSMContext fsm(data);
	cout << "Current state: " << fsm.getStateName() << endl;

	FSMEvent playEvent(EVENT_USR_PLAY);
	FSMEvent pauseEvent(EVENT_USR_PAUSE);
	FSMEvent stopEvent(EVENT_USR_STOP);

	cout << endl << "Sending PLAY event..." << endl;
	cin.ignore(1);

	fsm.handleEvent(playEvent);
	cout << "Current state: " << fsm.getStateName() << endl;

	cout << endl << "Sending PAUSE event..." << endl;
	cin.ignore(1);

	fsm.handleEvent(pauseEvent);
	cout << "Current state: " << fsm.getStateName() << endl;

	cout << endl << "Sending PLAY event.." << endl;
	cin.ignore(1);

	fsm.handleEvent(playEvent);
	cout << "Current state: " << fsm.getStateName() << endl;

	cout << endl << "Sending PAUSE event..." << endl;
	cin.ignore(1);

	fsm.handleEvent(pauseEvent);
	cout << "Current state: " << fsm.getStateName() << endl;

	cout << endl << "Sending STOP event..." << endl;
	cin.ignore(1);

	fsm.handleEvent(stopEvent);
	cout << "Current state: " << fsm.getStateName() << endl;

	cout << endl << "Sending PAUSE event..." << endl;
	cin.ignore(1);

	fsm.handleEvent(pauseEvent);
	cout << "Current state: " << fsm.getStateName() << endl;
}
