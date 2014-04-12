/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "LinuxNetworkCollector.h"
#include <Exceptions.h>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <sstream>

#include <Composite.h>

namespace perception
{

LinuxNetworkCollector::LinuxNetworkCollector()
: _skt(0)
{}


LinuxNetworkCollector::~LinuxNetworkCollector()
{
    cleanUp();
}


void LinuxNetworkCollector::getInterfaceList(Composite& data)
{
    CompositeNode* ifaces = data.addNode("interfaces");

    for (size_t i = 0; i < interfaces_.size(); ++i) {
        CompositeNode* ifaceName = ifaces->addNode(interfaces_[i].name);
        ifaceName->addLeaf("ip", interfaces_[i].ipAddress);
        ifaceName->addLeaf("mac", interfaces_[i].macAddress);
    }
}


void LinuxNetworkCollector::getCurrentIpAddress(Composite& data)
{}


void LinuxNetworkCollector::getCurrentMacAddress(Composite& data)
{}


void LinuxNetworkCollector::getConnectionTypeList(Composite& data)
{}


void LinuxNetworkCollector::getConnectionType(Composite& data)
{}


void LinuxNetworkCollector::getWiFiSignalStrength(Composite& data)
{}


void LinuxNetworkCollector::queryAvailableInterfaces()
{
    initSocket();

    struct ifconf retrievedInterfaces;
    char buffer[8192] = {0};
    retrievedInterfaces.ifc_len = sizeof(buffer);
    retrievedInterfaces.ifc_buf = buffer;

    int interfacesNumber = retrieveNetworkInterfaces(retrievedInterfaces);

    for (int i = 0; i < interfacesNumber; ++i) {
        struct ifreq* item = &((retrievedInterfaces.ifc_req)[i]);

        // Get the interface address for protocol family
        if (ioctl(_skt, SIOCGIFADDR, item) < 0) {
            cleanUp();
            NetworkError::raiseError<NetworkError>("Error getting interface address");
        }

        // Get the interface name
        const std::string interfaceName = std::string(item->ifr_name);

        // Get the IP address
        const struct sockaddr* addr = &(item->ifr_addr);
        const std::string ipString = ipToString(addr);

        // Get the MAC address
        if (ioctl(_skt, SIOCGIFHWADDR, item) < 0) {
            cleanUp();
            NetworkError::raiseError<NetworkError>("Error getting HW address");
        }

        const std::string macString = macToString(item);

        // Add the interface to the list
        NetworkInterface interface(interfaceName, macString, ipString);

        interfaces_.push_back(interface);
    }
}


void LinuxNetworkCollector::initSocket()
{
    _skt = socket(PF_INET, SOCK_DGRAM, 0);

    if (_skt < 0) {
        cleanUp();
        NetworkError::raiseError<NetworkError>("Error opening socket");
    }
}


int LinuxNetworkCollector::retrieveNetworkInterfaces(const struct ifconf& retrievedInterfaces)
{
    if (ioctl(_skt, SIOCGIFCONF, &retrievedInterfaces) < 0) {
        cleanUp();
        NetworkError::raiseError<NetworkError>("Error getting interfaces list");
    }

    return ( retrievedInterfaces.ifc_len / sizeof(struct ifreq) );
}


std::string LinuxNetworkCollector::ipToString(const struct sockaddr* addr)
{
    char ipString[INET6_ADDRSTRLEN] = "n/a";

    if (addr->sa_family == AF_INET) {
        inet_ntop(AF_INET, &(((struct sockaddr_in*) addr)->sin_addr), ipString, INET6_ADDRSTRLEN);

    } else if (addr->sa_family == AF_INET6) {
        inet_ntop(AF_INET6, &(((struct sockaddr_in6*) addr)->sin6_addr), ipString, INET6_ADDRSTRLEN);
    }

    return std::string(ipString);
}


std::string LinuxNetworkCollector::macToString(struct ifreq* item)
{
    char macString[18];

    sprintf(macString, "%02x:%02x:%02x:%02x:%02x:%02x",
            (unsigned char) item->ifr_hwaddr.sa_data[0],
            (unsigned char) item->ifr_hwaddr.sa_data[1],
            (unsigned char) item->ifr_hwaddr.sa_data[2],
            (unsigned char) item->ifr_hwaddr.sa_data[3],
            (unsigned char) item->ifr_hwaddr.sa_data[4],
            (unsigned char) item->ifr_hwaddr.sa_data[5]);

    return std::string(macString);
}


void LinuxNetworkCollector::cleanUp()
{
    interfaces_.clear();

    if (_skt) { close(_skt); }
}

} /* namespace perception */
