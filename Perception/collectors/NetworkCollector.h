/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef NETWORKCOLLECTOR_H_
#define NETWORKCOLLECTOR_H_

#include "Collector.h"

namespace perception
{

/**
 * Container class for networking information.
 */
struct NetworkInterface
{
    NetworkInterface(const std::string& name, const std::string& mac, const std::string& ip)
        : name(name),
          macAddress(mac),
          ipAddress(ip)
    {}

    std::string name;       // Interface name
    std::string macAddress; // MAC address
    std::string ipAddress;  // IP address (either v4 or v6)
};


/**
 * Interface to retrieve networking information.
 */
class NetworkCollector : public Collector
{
public:
    NetworkCollector();
    virtual ~NetworkCollector();

    virtual void collectData(Composite& data);

protected:
    virtual void queryAvailableInterfaces() {}

    /**
     * Append the names of available interfaces to the data parameter.
     * Interface names are represented as a comma-separated string.
     */
    virtual void getInterfaceList(Composite& data) = 0;

    /**
     * Append the current IP address to the data parameter.
     */
    virtual void getCurrentIpAddress(Composite& data) = 0;

    /**
     * Append the current MAC address to the data parameter.
     */
    virtual void getCurrentMacAddress(Composite& data) = 0;

    /**
     * Get the types of internet connectivity available on the system.
     * The list is represented as a comma-separated string.
     */
    virtual void getConnectionTypeList(Composite& data) = 0;

    /**
     * Get the type of internet connectivity currently used.
     */
    virtual void getConnectionType(Composite& data) = 0;

    /**
     * Get the Wi-Fi signal strength (if Wi-Fi is available).
     */
    virtual void getWiFiSignalStrength(Composite& data) = 0;
};

} /* namespace perception */

#endif /* NETWORKCOLLECTOR_H_ */
