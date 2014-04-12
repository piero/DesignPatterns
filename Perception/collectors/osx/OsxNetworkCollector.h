/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef OSXNETWORKCOLLECTOR_H_
#define OSXNETWORKCOLLECTOR_H_

#include "NetworkCollector.h"
#include <vector>

namespace perception
{

class OsxNetworkCollector : public perception::NetworkCollector
{
public:
    OsxNetworkCollector();
    virtual ~OsxNetworkCollector();

protected:
    /**
     * Append the names of available interfaces to the data parameter.
     * Interface names are represented as a comma-separated string.
     */
    virtual void getInterfaceList(Composite& data);

    /**
     * Append the current IP address to the data parameter.
     */
    virtual void getCurrentIpAddress(Composite& data);

    /**
     * Append the current MAC address to the data parameter.
     */
    virtual void getCurrentMacAddress(Composite& data);

    /**
     * Get the types of internet connectivity available on the system.
     * The list is represented as a comma-separated string.
     */
    virtual void getConnectionTypeList(Composite& data);

    /**
     * Get the type of internet connectivity currently used.
     */
    virtual void getConnectionType(Composite& data);

    /**
     * Get the Wi-Fi signal strength (if Wi-Fi is available).
     */
    virtual void getWiFiSignalStrength(Composite& data);

private:
    std::vector<NetworkInterface> interfaces_;
};

} /* namespace perception */

#endif /* OSXNETWORKCOLLECTOR_H_ */
