/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef COLLECTORFACTORY_H_
#define COLLECTORFACTORY_H_

#include <NetworkCollector.h>
#include <SystemCollector.h>

namespace perception
{

/**
 * Abstract factory for Collector objects.
 */
class CollectorFactory
{
public:
    virtual ~CollectorFactory() {};

    virtual NetworkCollector* createNetworkCollector() = 0;
    virtual SystemCollector* createSystemCollector() = 0;
};

} /* namespace perception */

#endif /* COLLECTORFACTORY_H_ */
