/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "CollectorFactoryLinux.h"

namespace perception
{

CollectorFactoryLinux::~CollectorFactoryLinux()
{}


NetworkCollector* CollectorFactoryLinux::createNetworkCollector()
{
    return new LinuxNetworkCollector();
}


SystemCollector* CollectorFactoryLinux::createSystemCollector()
{
    // TODO
    return 0;
}

} /* namespace perception */
