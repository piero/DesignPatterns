/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef COLLECTORFACTORYLINUX_H_
#define COLLECTORFACTORYLINUX_H_

#include <CollectorFactory.h>
#include "LinuxNetworkCollector.h"

namespace perception
{

class CollectorFactoryLinux : public CollectorFactory
{
public:
    virtual ~CollectorFactoryLinux();

    virtual NetworkCollector* createNetworkCollector();
    virtual SystemCollector* createSystemCollector();
};

} /* namespace perception */

#endif /* COLLECTORFACTORYLINUX_H_ */
