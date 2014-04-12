/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "OsxNetworkCollector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <ifaddrs.h>
#include <errno.h>

namespace perception
{

OsxNetworkCollector::OsxNetworkCollector()
{}


OsxNetworkCollector::~OsxNetworkCollector()
{}


void OsxNetworkCollector::getInterfaceList(Composite& data)
{
    CompositeNode* ifaces = data.addNode("interfaces");

    void *tmp = 0;
    char buf[INET6_ADDRSTRLEN];

    struct ifaddrs *if_addrs;
    getifaddrs(&if_addrs);

    for (struct ifaddrs *currIf = if_addrs; currIf != 0; currIf = currIf->ifa_next) {
        // Name
        CompositeNode* ifaceName = ifaces->addNode(currIf->ifa_name);

        // IP address
        if (currIf->ifa_addr->sa_family == AF_INET) {
            tmp = &((struct sockaddr_in *) currIf->ifa_addr)->sin_addr;
        } else {
            tmp = &((struct sockaddr_in6 *) currIf->ifa_addr)->sin6_addr;
        }
        inet_ntop(currIf->ifa_addr->sa_family, tmp, buf, sizeof(buf));
        ifaceName->addLeaf("ip", buf);

        // Mask
        if (currIf->ifa_netmask != 0) {
            if (currIf->ifa_netmask->sa_family == AF_INET) {
                tmp = &((struct sockaddr_in *) currIf->ifa_netmask)->sin_addr;
            } else {
                tmp = &((struct sockaddr_in6 *) currIf->ifa_netmask)->sin6_addr;
            }
            inet_ntop(currIf->ifa_netmask->sa_family, tmp, buf, sizeof(buf));
            ifaceName->addLeaf("mask", buf);
        }

        // Mac address
        if (currIf->ifa_addr != 0 && currIf->ifa_addr->sa_family == AF_LINK) {
            struct sockaddr_dl* sdl = (struct sockaddr_dl *) currIf->ifa_addr;
            unsigned char mac[6];
            if (6 == sdl->sdl_alen) {
                memcpy(mac, LLADDR(sdl), sdl->sdl_alen);

                char macString[18];
                sprintf(macString, "%02x:%02x:%02x:%02x:%02x:%02x",
                        (unsigned char) mac[0],
                        (unsigned char) mac[1],
                        (unsigned char) mac[2],
                        (unsigned char) mac[3],
                        (unsigned char) mac[4],
                        (unsigned char) mac[5]);
                ifaceName->addLeaf("mac", macString);
            }
        }
    }
}


void OsxNetworkCollector::getCurrentIpAddress(Composite& data)
{}


void OsxNetworkCollector::getCurrentMacAddress(Composite& data)
{}


void OsxNetworkCollector::getConnectionTypeList(Composite& data)
{}


void OsxNetworkCollector::getConnectionType(Composite& data)
{}


void OsxNetworkCollector::getWiFiSignalStrength(Composite& data)
{}

} /* namespace perception */
