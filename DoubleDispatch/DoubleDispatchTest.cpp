#include "EventHandler.hpp"
#include "EventDispatcher.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	EventDispatcher dispatcher;

	FirstEventHandler first;
	SecondEventHandler second;

	dispatcher.subscribe(EVT_TYPE_APPLICATION, first);
	dispatcher.subscribe(EVT_TYPE_APPLICATION, second);
	dispatcher.subscribe(EVT_TYPE_USER, second);

	ApplicationEvent appEvent("APP");
	UserEvent usrEvent("USER");

	dispatcher.dispatch(appEvent);
	dispatcher.dispatch(usrEvent);

	cout << "[?] Press ENTER to continue..." << endl;
	cin.ignore(1);

	dispatcher.unsubscribe(EVT_TYPE_APPLICATION, second);

	dispatcher.dispatch(appEvent);
	dispatcher.dispatch(usrEvent);
}
