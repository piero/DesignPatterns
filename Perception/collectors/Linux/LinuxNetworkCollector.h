/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef LINUXNETWORKCOLLECTOR_H_
#define LINUXNETWORKCOLLECTOR_H_

#include <net/if.h>         // struct ifconf
#include <netinet/in.h>     // struct sockaddr
#include <NetworkCollector.h>
#include <vector>

namespace perception
{

class LinuxNetworkCollector : public NetworkCollector
{
public:
    LinuxNetworkCollector();
    virtual ~LinuxNetworkCollector();

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
    void queryAvailableInterfaces();
    void initSocket();
    int retrieveNetworkInterfaces(const struct ifconf& retrievedInterfaces);
    std::string ipToString(const struct sockaddr* addr);
    std::string macToString(struct ifreq* item);
    void cleanUp();

    int _skt;                       // Socket used to retrieve information

    std::vector<NetworkInterface> interfaces_;
};

} /* namespace perception */

#endif /* LINUXNETWORKCOLLECTOR_H_ */
