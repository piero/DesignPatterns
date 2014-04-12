/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "NetworkCollector.h"

namespace perception
{

NetworkCollector::NetworkCollector()
{}


NetworkCollector::~NetworkCollector()
{}


void NetworkCollector::collectData(Composite& data)
{
	queryAvailableInterfaces();
    getInterfaceList(data);
    getCurrentIpAddress(data);
    getCurrentMacAddress(data);
    getConnectionTypeList(data);
    getConnectionType(data);
    getWiFiSignalStrength(data);
}

} /* namespace perception */
